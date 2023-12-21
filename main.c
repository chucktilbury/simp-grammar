#include <stdio.h>
#include <stdbool.h>
#include "parser.h"
#include "scanner.h"


int main() {

    yydebug = 0;
    open_file("../test.in");
    yyparse();

    return 0;
}