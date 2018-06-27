#include <stdio.h>

struct stab {
int val;
char name[20]; } stab[100];
struct node {
int type, left, right; } ntab[400];
int ntabuse = 1;
#define T_STLIST 1
#define T_ASSIGN 2
#define T_READ 3
#define T_PRINT 4
#define T_ADD 5
#define T_SUB 6
#define T_NUM 7
#define T_VAR 8
#define T_WHILE 9
#define T_LT 10
#define T_GT 11

int node(int t, int l, int r) {
int i = ntabuse++;
ntab[i].type = t; ntab[i].left = l; ntab[i].right = r;
return i;
}

int dotree(int i) {
switch(ntab[i].type) {
 case T_STLIST: if(ntab[i].left)  dotree(ntab[i].left); dotree(ntab[i].right); break;
 case T_ASSIGN: stab[ntab[i].left].val = dotree(ntab[i].right); break;
 case T_READ: scanf("%d", &stab[ntab[i].left].val); break;
 case T_PRINT: printf("%d\n", dotree(ntab[i].left)); break;
 case T_ADD: return dotree(ntab[i].left) + dotree(ntab[i].right);
 case T_SUB: return dotree(ntab[i].left) - dotree(ntab[i].right);
 case T_NUM: return ntab[i].left;
 case T_VAR: return stab[ntab[i].left].val; 
 case T_WHILE: while(dotree(ntab[i].left)){ dotree(ntab[i].right);} break;
 case T_LT: return dotree(ntab[i].left) < dotree(ntab[i].right); 
 case T_GT: return dotree(ntab[i].left) > dotree(ntab[i].right);
 }
}

int stabuse = 0;

extern char *yytext;

int lookup(char*);

#include "y.tab.c"
#include "lex.yy.c"

int main() {
yyparse();
return 0;
}

int lookup(char *s) {
int i;
 for(i = 0; i < stabuse; i++){
   if(strcmp(stab[i].name, s) == 0) return i;}
if(stabuse >= 99) {
printf("table overflow.\n"); exit(1); }
strcpy(stab[stabuse].name, s); return stabuse++;
}
