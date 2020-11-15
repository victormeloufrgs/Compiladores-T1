#include <stdbool.h>
#include "val_converters.h"
#include "assembler.h"

char* get_as_assembly_data(char* data, int type, char* buffer);
char* get_char_as_assembly_data(char* data, char* buffer);
char* get_float_as_assembly_data(char* data, char* buffer);
char* get_integer_as_assembly_data(char* data, char* buffer);


TAC* tacReverse(TAC* tac) {
    TAC* t = tac;

    for(t = tac; t->prev; t = t->prev)
        t->prev->next = t;

    return t;
}

void generateFixedInit(FILE* fout) {
    fprintf(fout,   "## FIXED INIT\n"
                    "\t.section	__TEXT,__cstring,cstring_literals\n"
                    "\tprintintstr: .asciz	\"%%d\\n\"\n"
                    "\tprintstringstr: .asciz	\"%%s\\n\"\n"
                    "\n"
                    "\t.section	__TEXT,__text,regular,pure_instructions\n"
    );
}

void generate_TAC_FBEGIN(FILE* fout, TAC* tac) {
    fprintf(fout, 
            "## TAC_FBEGIN\n"
            "\t.globl	_%s\n"                 
            "_%s:\n"                                  
            "\tpushq	%%rbp\n"
            "\tmovq	%%rsp, %%rbp\n", 
            tac->res ? tac->res->text : 0, 
            tac->res ? tac->res->text : 0
    ); 
}

void generate_TAC_FEND(FILE* fout) {
    fprintf(fout, 
            "## TAC_FEND\n"
            "\tpopq	%%rbp\n"
            "\tretq\n"
    );
}

void generate_TAC_PRINT(FILE* fout, TAC* tac) {
    fprintf(fout,
            "## TAC_PRINTINT\n"
            "\tleaq	printintstr(%%rip), %%rdi\n"
            "\tmovl	_%s(%%rip), %%esi\n"
            "\tmovb	$0, %%al\n"
            "\tcallq	_printf\n", 
            tac->res ? tac->res->text : 0
    );
}

char* generate_TAC_VAR(char* data_section, TAC* tac) {
    char* addition = (char *) malloc(+1 +2*strlen(tac->res->text) +256);

    if (tac->res) {
        char buffer[512] = "";
        char* val = get_as_assembly_data(tac->op1 ? tac->op1->text : 0, tac->op1->type, buffer);
        sprintf(addition, "_%s:\t.long\t%s\n", tac->res->text, val);
    }
    data_section = concat_string(data_section, addition);
    free(addition);

    return data_section;
}

char* generate_TAC_ARR(char* data_section, TAC* tac) {
    char* str = malloc(+1 +strlen(tac->res->text) +3);
    sprintf(str, "_%s:\n", tac->res->text);

    int i;
    TAC* elem = tac->next;
    for(i = 0; i < atoi(tac->op1->text); i++) {
        char* tail = malloc(+1 +strlen(elem->res->text) +9);
        sprintf(tail, "\t.long\t%s\n", elem->op2->text);
        str = concat_string(str, tail);
        free(tail);
        elem = elem->next;
    }

    return str;
}

char* generateDATA_SECTION() {
    int i = 0;
    HASH_NODE* node;
    char* data_section = malloc(sizeof(char) * 40);
    
    sprintf(data_section,"## DATA SECTION\n\t.section\t__DATA,__data\n\n");

    for(i=0; i < HASH_SIZE; i++) {
        node = hash_table[i];
        if(node == NULL) continue;

        do {
            bool is_temp = node->type == SYMBOL_VARIABLE && node->datatype == 0;
            if(is_temp) {
			    char *addition = (char *)malloc(+1 +2*strlen(hash_table[i]->text) +10);
                sprintf(addition, "_%s:\t.long\t0\n", node->text);  // TODO: trocar o zero pelo símbolo de i
                data_section = concat_string(data_section, addition);
            }
            node = node->next;
        } while(node != NULL);

    }

    return data_section;
}

void generateAsm(TAC* first) {
    TAC* tac;
    FILE* fout;
    char* addition;
    fout = fopen("out.s", "w");

    char* data_section = generateDATA_SECTION();

    // Init
    generateFixedInit(fout);

    // Each Tac
    for (tac = first; tac; tac = tac->next) {
        switch(tac->type) {
			case TAC_SYMBOL: break;
			case TAC_VAR: data_section = generate_TAC_VAR(data_section, tac); break;
            case TAC_FBEGIN: generate_TAC_FBEGIN(fout, tac); break;
            case TAC_FEND: generate_TAC_FEND(fout); break;
            case TAC_PRINT: generate_TAC_PRINT(fout, tac); break;
            case TAC_ARR: data_section = generate_TAC_ARR(data_section, tac); break;
        }
    }

    // Hash Table
    fprintf(fout, "%s", data_section);
    fclose(fout);
}

char* get_as_assembly_data(char* data, int type, char* buffer) {
    switch (type) {
        case SYMBOL_LIT_CHAR: return get_char_as_assembly_data(data, buffer);
        case SYMBOL_LIT_FALSE: return "0";
        case SYMBOL_LIT_FLOAT: return get_float_as_assembly_data(data, buffer);
        case SYMBOL_LIT_INTEGER: return get_integer_as_assembly_data(data, buffer);
        case SYMBOL_LIT_TRUE: return "1";
        default:  return "0";
    }
}

char* get_char_as_assembly_data(char* data, char* buffer) {
    int response = data ? data[1] : 0;
    sprintf(buffer, "%d", response);
    return buffer;
}

char* get_float_as_assembly_data(char* data, char* buffer) {
    float response = hexFloatToDecimalFloat(data ? data : "0");
    return getIEEE(buffer, response);
}

char* get_integer_as_assembly_data(char* data, char* buffer) {
    float response = toDeci(data? data : "0", 16, 1);
    sprintf(buffer, "%d", (int)response);
    return buffer;
}