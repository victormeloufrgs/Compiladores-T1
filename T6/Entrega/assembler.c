#include <stdbool.h>
#include "val_converters.h"
#include "assembler.h"

unsigned int con_str_count = 0;

char* get_as_assembly_data(char* data, int type, char* buffer);
char* get_char_as_assembly_data(char* data, char* buffer);
char* get_float_as_assembly_data(char* data, char* buffer);
char* get_integer_as_assembly_data(char* data, char* buffer);

bool is_float(HASH_NODE* hash_node);
bool is_string(HASH_NODE* hash_node);

void generate_TAC_DIV_FLOAT(FILE* fout, TAC* tac);
void generate_TAC_DIV_INT(FILE* fout, TAC* tac);

void generate_TAC_PRINT_FLOAT(FILE* fout, TAC* tac);
void generate_TAC_PRINT_STR(FILE* fout, TAC* tac);
void generate_TAC_PRINT_INT(FILE* fout, TAC* tac);

TAC* tacReverse(TAC* tac) {
    TAC* t = tac;

    for(t = tac; t->prev; t = t->prev)
        t->prev->next = t;

    return t;
}

bool is_lit(int type) {
    return type == SYMBOL_LIT_CHAR || type == SYMBOL_LIT_FALSE || type == SYMBOL_LIT_INTEGER || type == SYMBOL_LIT_FLOAT || type == SYMBOL_LIT_STRING || type == SYMBOL_LIT_TRUE;
}

void generateFixedInit(FILE* fout) {
    fprintf(fout,   "## FIXED INIT\n"
                    "\t.section	__TEXT,__cstring,cstring_literals\n"
                    "\tprintintstr: .asciz	\"%%d\\n\"\n"
                    "\tprintfloatstr: .asciz	\"%%f\\n\"\n"
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

    if(is_float(tac->res)) {
        generate_TAC_PRINT_FLOAT(fout, tac);

    } else if (is_string(tac->res)) {
        generate_TAC_PRINT_STR(fout, tac);

    } else {
        generate_TAC_PRINT_INT(fout, tac);
    }
}

void generate_TAC_PRINT_STR(FILE* fout, TAC* tac) {
    fprintf(fout,
            "## TAC_PRINT_STRING\n"
            "\tleaq	_string_%d(%%rip), %%rdi\n"
            "\tmovb	$0, %%al\n"
            "\tcallq	_printf\n", 
            tac->res ? hashFind(tac->res->text)->id : 0
    );
}

void generate_TAC_PRINT_FLOAT(FILE* fout, TAC* tac) {
    fprintf(fout,
            "## TAC_PRINT_FLOAT\n"
            "\tleaq	printfloatstr(%%rip), %%rdi\n"
            "\tmovl	_%s(%%rip), %%esi\n"
            "\tmovb	$1, %%al\n"
            "\tcallq	_printf\n", 
            tac->res ? tac->res->text : 0
    );
}

void generate_TAC_PRINT_INT(FILE* fout, TAC* tac) {
    fprintf(fout,
            "## TAC_PRINT_INT\n"
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
        char buffer[256];
        char* data = get_as_assembly_data(elem->op2->text, elem->op2->type, buffer);
        char* tail = malloc(8 + strlen(data));
        sprintf(tail, "\t.long\t%s\n", data);
        str = concat_string(str, tail);
        free(tail);
        elem = elem->next;
    }

    return str;
}

void generate_TAC_ADD(FILE* fout, TAC* tac) { 
        fprintf(fout, 
                "## TAC_ADD\n"
                "\tmovl\t_%s(%%rip), %%eax\n"
                "\taddl\t_%s(%%rip), %%eax\n"
                "\tmovl\t%%eax, _%s(%%rip)\n",
                tac->op1->text, 
                tac->op2->text,
                tac->res->text
        );
}

void generate_TAC_SUB(FILE* fout, TAC* tac) { 
        fprintf(fout, 
                "## TAC_SUB\n"
                "\tmovl\t_%s(%%rip), %%eax\n"
                "\tsubl\t_%s(%%rip), %%eax\n"
                "\tmovl\t%%eax, _%s(%%rip)\n",
                tac->op1->text, 
                tac->op2->text,
                tac->res->text
        );
}


void generate_TAC_MULT(FILE* fout, TAC* tac) { 
        fprintf(fout, 
                "## TAC_MUL\n"
                "\tmovl\t_%s(%%rip), %%eax\n"
                "\timull\t_%s(%%rip), %%eax\n"
                "\tmovl\t%%eax, _%s(%%rip)\n",
                tac->op1->text, 
                tac->op2->text,
                tac->res->text
        );
}

bool is_float(HASH_NODE* hash_node) {
    return hash_node->type == SYMBOL_LIT_FLOAT || hash_node->datatype == DATATYPE_FLOAT;
}

bool is_string(HASH_NODE* hash_node) {
    return hash_node->type == SYMBOL_LIT_STRING || hash_node->datatype == DATATYPE_STRING;
}

void generate_TAC_DIV(FILE* fout, TAC* tac) {
        
        bool is_float_div = is_float(tac->op1)  || is_float(tac->op2);
        if(is_float_div) {
            generate_TAC_DIV_FLOAT(fout, tac);
        } else {
            generate_TAC_DIV_INT(fout, tac);
        }
}


void generate_TAC_DIV_INT(FILE* fout, TAC* tac) {
    fprintf(fout, 
            "## TAC_DIV_INT\n"
            "\tmovl\t_%s(%%rip), %%eax\n"
            "\tcltd\n"
            "\tidivl\t_%s(%%rip)\n"
            "\tmovl\t%%eax, _%s(%%rip)\n",
            tac->op1->text, 
            tac->op2->text,
            tac->res->text
    );
}

void generate_TAC_DIV_FLOAT(FILE* fout, TAC* tac) {
    fprintf(fout, 
            "## TAC_DIV_FLOAT\n"
            "\tmovss\t_%s(%%rip), %%xmm0\n"
            "\tdivss\t_%s(%%rip), %%xmm0\n"
            "\tcvtss2sd %%xmm0, %%xmm0\n"
            "\tmovss\t%%xmm0, _%s(%%rip)\n",
            tac->op1->text, 
            tac->op2->text,
            tac->res->text
    );
}

char* generateDATA_SECTION() {
    int i = 0;
    char *addition;
    char buffer[256];
    HASH_NODE* node;

    char* data_section = malloc(sizeof(char) * 40);
    
    sprintf(data_section,"## DATA SECTION\n\t.section\t__DATA,__data\n\n");

    for(i=0; i < HASH_SIZE; i++) {

        node = hash_table[i];
        if(node == NULL) continue;


        do {
            bool is_temp = node->type == SYMBOL_VARIABLE && strstr(node->text,"1temp");
            if(is_temp || is_lit(node->type)) {
                
                switch (node->type) {
                    case SYMBOL_LIT_STRING:
                        addition = realloc(addition, +strlen(node->text) + 30);
                        sprintf(addition, "_string_%d: .asciz\t%s\n", node->id, node->text);
                        break;
                    default:
                        addition = realloc(addition, +1 +2*strlen(hash_table[i]->text) +10);
                        sprintf(addition, "_%s:\t.long\t%s\n", node->text, is_lit(node->type) ? get_as_assembly_data(node->text, node->type, buffer) : "0");
                }

                    data_section = concat_string(data_section, addition);
            }

            node = node->next;
        } while(node != NULL);
    }

    free(addition);
    return data_section;
}

void generate_TAC_AND(FILE* fout, TAC* tac) {
    fprintf(fout, 
            "## TAC_AND\n"
            "\tmovl\t_%s(%%rip), %%eax\n"
            "\tmovl\t_%s(%%rip), %%edx\n"
            "\tandl\t%%edx, %%eax\n"
            "\tmovl\t%%eax, _%s(%%rip)\n", 
            tac->op1->text,
            tac->op2->text, 
            tac->res->text
    );
}

void generate_TAC_OR(FILE* fout, TAC* tac) {
    fprintf(fout, 
            "## TAC_OR\n"
            "\tmovl\t_%s(%%rip), %%eax\n"
            "\tmovl\t_%s(%%rip), %%edx\n"
            "\torl\t\t %%edx, %%eax\n"
            "\tmovl\t%%eax, _%s(%%rip)\n", 
            tac->op1->text,
            tac->op2->text, 
            tac->res->text
    );
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
            case TAC_ADD: generate_TAC_ADD(fout, tac); break;
            case TAC_SUB: generate_TAC_SUB(fout, tac); break;
            case TAC_MULT: generate_TAC_MULT(fout, tac); break;
            case TAC_DIV: generate_TAC_DIV(fout, tac); break;
            case TAC_AND: generate_TAC_AND(fout, tac); break;
            case TAC_OR: generate_TAC_OR(fout, tac); break;
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