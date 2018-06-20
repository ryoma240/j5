#define NUM 1
#define IDENT 2
#define RNUM 3
#define INDEX 4
#include "lex.yy.c"

int
main() { 
  int code;
  while((code = yylex()))
    switch(code) {
    case NUM: printf("num: %s\n", yytext); break;
    case RNUM: printf("rnum: %s\n", yytext); break;
    case IDENT: printf("id: %s\n", yytext); break;
    case INDEX: printf("idx: %s\n", yytext); break;
    }
  return 0;
}
