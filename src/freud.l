%option noyywrap yylineno
%{
   #include <string.h>
   #include "freud.tab.h"
   #include "defs.h"
   extern YYSTYPE yylval;
%}

%%

[ \t\n]+ 					{ /* skip */ }

"int"							{ yylval.i = INT; 	return _TYPE; }
"unsigned"				{ yylval.i = UINT;	return _TYPE; }
"void"						{ yylval.i = VOID;	return _TYPE; }

"function"				{ return _FUNCTION; }	
"if"							{ return _IF; }
"else"						{ return _ELSE; }
"return"					{ return _RETURN; }		

"para"						{ return _PARA; }
"switch"					{ return _SWITCH; }
"case"						{ return _CASE; }
"default"					{ return _DEFAULT; }
"finish"					{ return _FINISH; }

"do"							{ return _DO; }
"until"						{ return _UNTIL; }

"("								{ return _LPAREN; }
")"								{ return _RPAREN; }
"{"								{ return _LBRACKET; }
"}"								{ return _RBRACKET; }
"["								{ return _LSQBR; }
"]"								{ return _RSQBR; }
";"								{ return _SEMI; }
":"								{ return _COLON; }
"="								{ return _ASSIGN; }
","								{ return _COMMA; }
"++"							{ return _POSTINC; }
"?"								{ return _QUESTION; }

"+"								{ yylval.i = ADD; return _OP; }
"-"								{ yylval.i = SUB; return _OP; }	

"<"								{ yylval.i = LT; return _RELOP; }
">"								{ yylval.i = GT; return _RELOP; }
">="							{ yylval.i = GE; return _RELOP; }
"<="							{ yylval.i = LE; return _RELOP; }
"=="							{ yylval.i = EQ; return _RELOP; }
"!="							{ yylval.i = NE; return _RELOP; }

[a-zA-Z][a-zA-Z0-9"-""_"]* 			{ yylval.s = strdup(yytext); return _ID; }
[+-]?[0-9]{1,10} 								{ yylval.s = strdup(yytext); return _INT_NUM; }
[0-9]{1,10}[uU]									{ yylval.s = strdup(yytext); 
																	yylval.s[yyleng-1] = 0; return _UINT_NUM; }



"//"(.)*	{ /*skip*/ }					
"/*"([^*]|"\n"|(\*+([^*/]|"\n")))*"*"+"/"

.                 		   { printf("line %d: LEXICAL ERROR on char %c\n", 
                           			   yylineno, *yytext);}
                             
%%


