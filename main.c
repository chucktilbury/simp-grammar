#include <stdio.h>
#include <stdbool.h>
#include "parser.h"
#include "scanner.h"


int main(int argc, char** argv) {

    if(argc < 2) {
        fprintf(stderr, "use: %s <file>\n", argv[0]);
        return 1;
    }

    yydebug = 0;
    open_file(argv[1]);
    return yyparse();
}