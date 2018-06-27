%token NUM;
%token IDENT;
%token READ;
%token PRINT;
%%
prog : IDENT '{' stlist '}' { dotree($3); return; }
;
stlist : { $$ = 0; }
| stlist stat { $$ = node(T_STLIST, $1, $2); }
;
stat : var '=' expr ';' { $$ = node(T_ASSIGN, $1, $3); }
| READ var ';' { $$ = node(T_READ, $2, 0); }
| PRINT expr ';' { $$ = node(T_PRINT, $2, 0); }
;
expr : prim { $$ = $1; }
| expr '+' prim { $$ = node(T_ADD, $1, $3); }
| expr '-' prim { $$ = node(T_SUB, $1, $3); }
;
prim : NUM { $$ = node(T_NUM, atoi(yytext), 0); }
| var { $$ = node(T_VAR, $1, 0); }
| '(' expr ')' { $$ = $2; }
;
var : IDENT { $$ = lookup(yytext); }
;
