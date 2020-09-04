#include "hash.h"

HASH_NODE*Table[HASH_SIZE];

void hashInit(void) {
    int i;
    for (i=0; i<HASH_SIZE; ++i)
        Table[i] = 0;
}

int hashAddress(char *text) {
    int address = 1;
    int i;
    for (i=0; i<strlen(text); ++i)
        address = (address * text[i]) % HASH_SIZE + 1;
    return address - 1
}
