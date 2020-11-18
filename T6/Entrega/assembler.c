#include <stdbool.h>
#include "val_converters.h"
#include "assembler.h"

unsigned int con_str_count = 0;

char* get_as_assembly_data(char* data, int type, int datatype, char* buffer);
char* get_char_as_assembly_data(char* data, char* buffer);
char* get_float_as_assembly_data(char* data, char* buffer);
char* get_integer_as_assembly_data(char* data, char* buffer);

bool is_float(HASH_NODE* hash_node);
bool is_string(HASH_NODE* hash_node);

void generate_TAC_DIV_FLOAT(FILE* fout, TAC* tac);
void generate_TAC_DIV_INT(FILE* fout, TAC* tac);
bool is_lit(int type);

TAC* tacReverse(TAC* tac) {
    TAC* t = tac;

    for(t = tac; t->prev; t = t->prev)
        t->prev->next = t;

    return t;
}


char* ass_mov_for_tac(TAC* tac, char* fst, char* snd) {
    if (is_float(tac->res)) {
        return concat_string("\tmovss\t", concat_string(fst, concat_string(", ", concat_string(snd,"\n"))));
    } else {
        return concat_string("\tmovl\t", concat_string(fst, concat_string(", ", concat_string(snd,"\n"))));
    }
}

char* ass_add_for_tac(TAC* tac, char* fst, char* snd) {
    if (is_float(tac->res)) {
        return concat_string("\taddss\t", concat_string(fst, concat_string(", ", concat_string(snd,"\n"))));
    } else {
        return concat_string("\taddl\t", concat_string(fst, concat_string(", ", concat_string(snd,"\n"))));
    }
}

char* ass_sub_for_tac(TAC* tac, char* fst, char* snd) {
    if (is_float(tac->res)) {
        return concat_string("\tsubss\t", concat_string(fst, concat_string(", ", concat_string(snd,"\n"))));
    } else {
        return concat_string("\tsubl\t", concat_string(fst, concat_string(", ", concat_string(snd,"\n"))));
    }
}

char* ass_imul_for_tac(TAC* tac, char* fst, char* snd) {
    if (is_float(tac->res)) {
        return concat_string("\tmulss\t", concat_string(fst, concat_string(", ", concat_string(snd,"\n"))));
    } else {
        return concat_string("\timull\t", concat_string(fst, concat_string(", ", concat_string(snd,"\n"))));
    }
}

char* ass_xmm0_or_eax_for_tac(TAC* tac) {
    if (is_float(tac->res)) {
        return "%xmm0";
    } else {
        return "%eax";
    }
}

char* ass_name(HASH_NODE* node, TAC* tac) {
    if (is_lit(node->type)) {
        return concat_string(concat_string("_",node->text),"(%rip)");
    } else {
        return ass_xmm0_or_eax_for_tac(tac);
    }
}

char* ass_key_for(char* text) {
    return concat_string(concat_string("_", text), "(%rip)");
}

char* get_movl_val_or_eax(TAC* arg) {
    if(arg->res) {
        return is_lit(arg->res->type) ? concat_string(concat_string("_",arg->res->text),"(%rip)") : "%eax";
    } else { // is function
        return "_0";
    }
}

char* get_movss_val_or_xmm0(TAC* arg) {
    if(arg->res) {
        return is_lit(arg->res->type) ? concat_string(concat_string("_",arg->res->text),"(%rip)") : "%xmm0";
    } else { // is function
        return "_0";
    }
}

TAC* assembler_fill_parameters(TAC *arg) {
	int i = 0;
	TAC *func_call = arg;

    // obtem indice do argumento
	while(func_call->type != TAC_FCALL) {
		func_call = func_call->next;
		if(func_call->type == TAC_ARG) i++;
	}

	TAC *func_dec;

    //procura declaracao da funcao pra frente no codigo
	for(func_dec = arg; func_dec && !(func_dec->type == TAC_FBEGIN && strcmp(func_call->op1->text, func_dec->res->text) == 0); func_dec = func_dec->next);
	
	if(!func_dec)
        //procurar declaracao de funcao pra tras no codigo
		for(func_dec = arg; func_dec && !(func_dec->type == TAC_FBEGIN && strcmp(func_call->op1->text, func_dec->res->text) == 0); func_dec = func_dec->prev);

	TAC *param = func_dec;
	int j;
	for(j = 0; j<=i; j++) {
		param = param->next;
	}

	return param;
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
                    "\t.section	__TEXT,__text,regular,pure_instructions\n.globl _main\n"
    );
}

void generate_TAC_FBEGIN(FILE* fout, TAC* tac) {
    fprintf(fout, 
            "# TAC_FBEGIN\n"              
            "_%s:\n"             
            "\t.cfi_startproc\n"                     
            "\tpushq %%rbp\n"
            "\tmovq	%%rsp, %%rbp\n", 
            tac->res ? tac->res->text : 0
    ); 
}

void generate_TAC_FEND(FILE* fout) {
    fprintf(fout, 
            "# TAC_FEND\n"
            "\tpopq\t%%rbp\n"
            "\tretq\n"
            "\t.cfi_endproc\n"
    );
}

char* assembly_formatter_for_datatype(int datatype) {
    switch (datatype) {
        case DATATYPE_BOOL: return "printintstr";
        case DATATYPE_CHAR: return "printintstr";
        case DATATYPE_FLOAT: return "printfloatstr";
        case DATATYPE_STRING: return "printstringstr";
        case DATATYPE_INT: return "printintstr";
        default: return "printintstr";
    }
}

#define NUM_PARAM_REGS 6


char* generate_TAC_PRINT(FILE* fout, TAC *print, char **data_section) {

    const char *param_regs_64[] = { "%rdi", "%rsi", "%rdx", "%rcx", "%r8", "%r9" };
    const char *param_regs_32[] = { "%edi", "%esi", "%edx", "%ecx", "%r8d", "%r9d" };
    unsigned int lit_str_count = 0;

    char *assembly = malloc(sizeof(""));
    assembly[0] = '\0';

    char lit_srt_sec_dec[30];
	sprintf(lit_srt_sec_dec, "L_.str.%d: .asciz\t\"", lit_str_count);
	char *lit_srt_sec_dec_p = &lit_srt_sec_dec[0];
	char s[] = "%s";
	char d[] = "%d";

    char *addition = NULL;
	int regc = 1;
	TAC *arg;
    
    // TODO: Falta formatar o print de float e resultado de função
	for(arg = print->prev; arg->type == TAC_PRARG && regc < NUM_PARAM_REGS; arg = arg->prev) {
		HASH_NODE* symbol = arg->res;
		switch(symbol->type) {
			case SYMBOL_LIT_STRING:
				addition = realloc(addition, +strlen(symbol->text) +30);
				sprintf(addition, "_string_%d: .asciz\t%s\n", con_str_count, symbol->text);
				*data_section = concat_string(*data_section, addition);
				
				addition = realloc(addition, +strlen(param_regs_64[regc]) +34);
				sprintf(addition, "\tleaq\t_string_%d(%%rip), %s\n", hashFind(symbol->text)->id, param_regs_64[regc]);
				assembly = concat_string(assembly, addition);

				lit_srt_sec_dec_p = concat_string(lit_srt_sec_dec_p, s);
				
				con_str_count++;
				break;

			default:
				addition = realloc(addition, +17 +strlen(symbol->text) +strlen(param_regs_32[regc]));
				sprintf(addition, "\tmovl\t_%s(%%rip), %s\n", symbol->text, param_regs_32[regc]);
				assembly = concat_string(assembly, addition);
				lit_srt_sec_dec_p = concat_string(lit_srt_sec_dec_p, d);
		}
		regc++;
	}

    addition = realloc(addition, 54);
	sprintf(addition,	"\tleaq\tL_.str.%d(%%rip), %%rdi\n"
						"\tcallq\t_printf\n", lit_str_count);
	assembly = concat_string(assembly, addition);

	lit_srt_sec_dec_p = concat_string(lit_srt_sec_dec_p, "\\n\"\n");
	*data_section = concat_string(*data_section, lit_srt_sec_dec_p);

	lit_str_count++;
	free(addition);
	return assembly;
}

char* generate_TAC_VAR(char* data_section, TAC* tac) {
    char* addition = (char *) malloc(+1 +2*strlen(tac->res->text) +256);

    if (tac->res) {
        char buffer[512] = "";
        char* val = get_as_assembly_data(tac->op1 ? tac->op1->text : 0, tac->op1->type, tac->res->datatype, buffer);
        sprintf(addition, "_%s:\t.long\t%s\n", tac->res->text, val);
    }
    data_section = concat_string(data_section, addition);
    free(addition);

    return data_section;
}

void generate_TAC_PARAM(char** data_section, TAC* tac) {

    char* addition = (char *) malloc(+1 +2*strlen(tac->res->text) +512);


    if(tac->op1 && tac->op1->type == SYMBOL_LIT_FLOAT) {
        char *mode = malloc(strlen(tac->op1->text)+1);
        strcpy(mode, tac->op1->text);
        mode = strtok(mode, ".");
        sprintf(addition, "_%s: .long\t%s\n", tac->res->text, tac->op1 ? mode : "0");
    } else {
        sprintf(addition, "_%s: .long\t%s\n", tac->res->text, tac->op1 ? tac->op1->text : "0");
    }

    *data_section = concat_string(*data_section, addition);
    free(addition);
}

char* generate_TAC_ARR(char* data_section, TAC* tac) {
    char* str = malloc(+1 +strlen(tac->res->text) +3);
    sprintf(str, "_%s:\n", tac->res->text);
    
    int i;
    TAC* elem = tac->next;
    for(i = 0; i < atoi(tac->op1->text); i++) {
        char buffer[256];
        char* data = get_as_assembly_data(elem->op2->text, elem->op2->type, tac->res->datatype, buffer);
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
            "# TAC_ADD\n"
            "%s"
            "%s"
            "%s",
            ass_mov_for_tac(tac, ass_key_for(tac->op1->text), ass_xmm0_or_eax_for_tac(tac)),
            ass_add_for_tac(tac, ass_key_for(tac->op2->text), ass_xmm0_or_eax_for_tac(tac)),
            ass_mov_for_tac(tac, ass_xmm0_or_eax_for_tac(tac), ass_key_for(tac->res->text))
    );
}

void generate_TAC_SUB(FILE* fout, TAC* tac) { 
    fprintf(fout, 
            "# TAC_SUB\n"
            "%s"
            "%s"
            "%s",
            ass_mov_for_tac(tac, ass_key_for(tac->op1->text), ass_xmm0_or_eax_for_tac(tac)),
            ass_sub_for_tac(tac, ass_key_for(tac->op2->text), ass_xmm0_or_eax_for_tac(tac)),
            ass_mov_for_tac(tac, ass_xmm0_or_eax_for_tac(tac), ass_key_for(tac->res->text))
    );
}


void generate_TAC_MULT(FILE* fout, TAC* tac) {
    fprintf(fout, 
        "# TAC_MULT\n"
        "%s"
        "%s"
        "%s",
        ass_mov_for_tac(tac, ass_key_for(tac->op1->text), ass_xmm0_or_eax_for_tac(tac)),
        ass_imul_for_tac(tac, ass_key_for(tac->op2->text), ass_xmm0_or_eax_for_tac(tac)),
        ass_mov_for_tac(tac, ass_xmm0_or_eax_for_tac(tac), ass_key_for(tac->res->text))
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
            "# TAC_DIV_INT\n"
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
            "# TAC_DIV_FLOAT\n"
            "\tmovss\t%s, %%xmm1\n"
            "\tdivss\t%s, %%xmm1\n"
            "\tmovss\t%%xmm1, _%s(%%rip)\n"
            "\tmovss\t_%s(%%rip), %%xmm0",
            ass_name(tac->op1, tac),
            ass_name(tac->op2, tac),
            tac->res->text,
            tac->res->text
    );
}

char* generateDATA_SECTION() {
    int i = 0;
    char *addition;
    char buffer[256];
    HASH_NODE* node;

    char* data_section = malloc(sizeof(char) * 2048);
    
    sprintf(data_section,"# DATA SECTION\n\t.section\t__DATA,__data\n\n");

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
                        sprintf(addition, "_%s:\t.long\t%s\n", node->text, is_lit(node->type) ? get_as_assembly_data(node->text, node->type, node->datatype, buffer) : "0");
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
            "# TAC_AND\n"
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
            "# TAC_OR\n"
            "\tmovl\t_%s(%%rip), %%eax\n"
            "\tmovl\t_%s(%%rip), %%edx\n"
            "\torl\t\t %%edx, %%eax\n"
            "\tmovl\t%%eax, _%s(%%rip)\n", 
            tac->op1->text,
            tac->op2->text, 
            tac->res->text
    );
}

void generate_TAC_NOT(FILE* fout, TAC* tac) {
    fprintf(fout, 
            "# TAC_NOT\n"
            "\tmovb\t_%s(%%rip), %%cl\n"
            "\txorb\t$-1, %%cl\n"
            "\tandb\t$1, %%cl\n"
        	"\tmovb\t%%cl, _%s(%%rip)\n",
            tac->op1->text,
            tac->res->text
    );
}

void generate_TAC_EQ(FILE* fout, TAC* tac) {
    fprintf(fout,
            "# TAC_EQ\n"
            "\tmovl\t_%s(%%rip), %%edx\n"
            "\tcmpl\t_%s(%%rip), %%edx\n"
            "\tje\t\t_%s\n", 
            tac->op1->text, 
            tac->op2->text,
            tac->res->text
    );
}

void generate_TAC_JUMP(FILE* fout, TAC* tac) {
    fprintf(fout,
            "# TAC_JUMP\n"
            "\tjmp\t\t_%s\n",
            tac->res->text
    ); 
}

void generate_TAC_LABEL(FILE* fout, TAC* tac) {
    fprintf(fout, 	
            "# TAC_LABEL\n"
            "_%s:\n", 
            tac->res->text
    );
}

void generate_TAC_MOVE(FILE* fout, TAC* tac) {
    fprintf(fout,	
            "# TAC_MOVE\n"
            "\tmovl\t_%s(%%rip), %%eax\n"
            "\tmovl\t%%eax, _%s(%%rip)\n",
            tac->op1->text, 
            tac->res->text
    );
}

void generate_TAC_JEQ(FILE* fout, TAC* tac) {
    fprintf(fout, 
            "# TAC_JEQ\n"
            "\tmovl\t_%s(%%rip), %%edx\n"
            "\tcmpl\t_%s(%%rip), %%edx\n"
            "\tje\t\t_%s\n", tac->op1->text, tac->op2->text,
            tac->res->text);
}

void generate_TAC_JFALSE(FILE* fout, TAC* tac) {
    fprintf(fout,	
            "# TAC_JFALSE\n"
            "\tcmpl\t$0, _%s(%%rip)\n"
            "\tje\t\t_%s\n", 
            tac->op1->text, 
            tac->res->text
    );
}

void generate_TAC_LE(FILE* fout, TAC* tac) {
    fprintf(fout, 
            "# TAC_LE\n"
            "\tmovl\t_%s(%%rip), %%edx\n"
            "\tcmpl\t_%s(%%rip), %%edx\n"
            "\tjle\t\t_%s\n", 
            tac->op1->text, 
            tac->op2->text,
            tac->res->text
    );
}

void generate_TAC_LT(FILE* fout, TAC* tac) {
    fprintf(fout, 
            "# TAC_LT\n"
            "\tmovl\t_%s(%%rip), %%edx\n"
            "\tcmpl\t_%s(%%rip), %%edx\n"
            "\tjl\t\t_%s\n", 
            tac->op1->text, 
            tac->op2->text,
            tac->res->text
    );
}

void generate_TAC_GE(FILE* fout, TAC* tac) {
    fprintf(fout, 
            "# TAC_GE\n"
            "\tmovl\t_%s(%%rip), %%edx\n"
            "\tcmpl\t_%s(%%rip), %%edx\n"
            "\tjge\t\t_%s\n", 
            tac->op1->text, 
            tac->op2->text,
            tac->res->text
    );
}

void generate_TAC_GT(FILE* fout, TAC* tac) {
    fprintf(fout, 
            "# TAC_GT\n"
            "\tmovl\t_%s(%%rip), %%edx\n"
            "\tcmpl\t_%s(%%rip), %%edx\n"
            "\tjg\t\t_%s\n", 
            tac->op1->text, 
            tac->op2->text,
            tac->res->text
    );
}

void generate_TAC_DIF(FILE* fout, TAC* tac) {
    fprintf(fout, 
            "# TAC_DIF\n"
            "\tmovl\t_%s(%%rip), %%edx\n"
            "\tcmpl\t_%s(%%rip), %%edx\n"
            "\tjne\t\t_%s\n", 
            tac->op1->text, 
            tac->op2->text,
            tac->res->text
    );
}

void generate_TAC_ACALL(FILE* fout, TAC* tac) {
    fprintf(fout,	
            "# TAC_ACALL\n"
            "\tleaq\t_%s(%%rip), %%rcx\n"
            "\tmovslq\t_%s(%%rip), %%rdx\n"
            "\tmovl\t(%%rcx,%%rdx,4), %%esi\n"
            "\tmovl\t%%esi, _%s(%%rip)\n", 
            tac->op1->text,
            tac->op2->text, 
            tac->res->text
    ); 
}

void generate_TAC_FCALL(FILE* fout, TAC* tac) {
    fprintf(fout,	
            "# TAC_FCALL\n"
            "\tcallq\t_%s\n", 
            tac->op1->text
    );
}

void generate_TAC_ARG(FILE* fout, TAC* tac) {
    fprintf(fout,	
            "# TAC_ARG\n"
            "\tmovl\t_%s(%%rip), %%eax\n"
            "\tmovl\t%%eax, _%s(%%rip)\n", 
            tac->res->text,
            assembler_fill_parameters(tac)->res->text
    );
}

void generate_TAC_AATTR(FILE* fout, TAC* tac) {
    fprintf(fout,	
            "# TAC_AATTR\n"
            "\tleaq\t_%s(%%rip), %%rcx\n"
            "\tmovl\t_%s(%%rip), %%edx\n"
            "\tmovslq\t_%s(%%rip), %%rsi\n"
            "\tmovl\t%%edx, (%%rcx,%%rsi,4)\n", 
            tac->res->text,
            tac->op2->text, tac->op1->text
    );
}

void generate_TAC_RET(FILE* fout, TAC* tac) {
    
    fprintf(fout,	
            "# TAC_RET\n"
            "%s",
            ass_mov_for_tac(tac, ass_key_for(tac->res->text), ass_xmm0_or_eax_for_tac(tac))
    );
}

void generate_TAC_READ(FILE* fout, TAC* tac) {
    fprintf(fout,	
            "# TAC_READ\n"
            "\tleaq\tL_.str.read(%%rip), %%rdi\n"
            "\tleaq\t_%s(%%rip), %%rsi\n"
            "\tcallq\t_scanf\n", 
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
			case TAC_SYMBOL     : break;
			case TAC_VAR        : data_section = generate_TAC_VAR(data_section, tac); break;
            case TAC_PARAM      : generate_TAC_PARAM(&data_section, tac); break;
            case TAC_ARR        : data_section = generate_TAC_ARR(data_section, tac); break;
            case TAC_FBEGIN     : generate_TAC_FBEGIN(fout, tac); break;
            case TAC_FEND       : generate_TAC_FEND(fout); break;
            case TAC_PRARG      : break;
            case TAC_PRINT      : 
                                fprintf(fout, 
                                        "# TAC_PRINT\n"
                                        "%s",
                                        generate_TAC_PRINT(fout, tac, &data_section)
                                ); 
                                break;
            case TAC_ADD        : generate_TAC_ADD(fout, tac); break;
            case TAC_SUB        : generate_TAC_SUB(fout, tac); break;
            case TAC_MULT       : generate_TAC_MULT(fout, tac);break;
            case TAC_DIV        : generate_TAC_DIV(fout, tac); break;
            case TAC_AND        : generate_TAC_AND(fout, tac); break;
            case TAC_OR         : generate_TAC_OR(fout, tac); break;
            case TAC_NOT        : generate_TAC_NOT(fout, tac); break;
            case TAC_EQ         : generate_TAC_EQ(fout, tac); break;
            case TAC_JUMP       : generate_TAC_JUMP(fout, tac); break;
            case TAC_LABEL      : generate_TAC_LABEL(fout, tac); break;
            case TAC_MOVE       : generate_TAC_MOVE(fout, tac);  break;
            case TAC_JFALSE     : generate_TAC_JFALSE(fout, tac); break;
            case TAC_JEQ        : generate_TAC_JEQ(fout, tac);

            case TAC_LE         : generate_TAC_LE(fout, tac); break; 
            case TAC_LT         : generate_TAC_LT(fout, tac); break; 
            case TAC_GE         : generate_TAC_GE(fout, tac); break; 
            case TAC_GT         : generate_TAC_GT(fout, tac); break; 
            case TAC_DIF        : generate_TAC_DIF(fout, tac); break;

            case TAC_ACALL      : generate_TAC_ACALL(fout, tac); break;
            case TAC_FCALL      : generate_TAC_FCALL(fout, tac); break;
            case TAC_ARG        : generate_TAC_ARG(fout, tac); break;

            case TAC_AATTR      : generate_TAC_AATTR(fout, tac); break;
            case TAC_RET        : generate_TAC_RET(fout, tac); break;
            case TAC_READ       : generate_TAC_READ(fout, tac);  break;

		    default: fprintf(stderr, "Assembler error: unknown intermediary code.\n"); break;
        }
    }

    // Hash Table
    fprintf(fout, "%s", data_section);
    fclose(fout);
}

char* get_as_assembly_data_from_datatype(char* data, int datatype, char* buffer) {
    switch (datatype) {
        case DATATYPE_BOOL: return strcmp(data, "TRUE") == 0 ? "1" : "0";
        case DATATYPE_CHAR: return get_char_as_assembly_data(data, buffer);
        case DATATYPE_FLOAT: return get_float_as_assembly_data(data, buffer);
        case DATATYPE_INT: return get_integer_as_assembly_data(data, buffer);
        case DATATYPE_STRING: return data;
        default:  return "0";
    }
}

char* get_as_assembly_data(char* data, int type, int datatype, char* buffer) {
    switch (type) {
        case SYMBOL_LIT_CHAR: return get_char_as_assembly_data(data, buffer);
        case SYMBOL_LIT_FALSE: return "0";
        case SYMBOL_LIT_FLOAT: return get_float_as_assembly_data(data, buffer);
        case SYMBOL_LIT_INTEGER: return get_integer_as_assembly_data(data, buffer);
        case SYMBOL_LIT_TRUE: return "1";
        case SYMBOL_PARAM: return get_as_assembly_data_from_datatype(data, datatype, buffer);
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