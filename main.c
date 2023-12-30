#include <stdio.h>
#include <stdbool.h>
#include "simple.h"

FILE* fptr = NULL;

int main(int argc, char** argv) {

    if(argc < 2) {
        fprintf(stderr, "use: %s <file>\n", argv[0]);
        return 1;
    }

    fptr = fopen(argv[1], "r");

    pcc_context_t *parser = NULL;
    parser = pcc_create(NULL);
    while(pcc_parse(parser, NULL)) { printf("run\n"); }
    pcc_destroy(parser);

    return 0;
}