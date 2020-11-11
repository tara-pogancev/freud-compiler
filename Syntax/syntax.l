%option noyywrap yylineno
%{
  #include "syntax.tab.h"
%}

%%

[ \t\n]+ 					    { /* skip */ }

"int"									{ return _TYPE_INT; }
"unsigned int"				{ return _TYPE_UINT; }

"function"				{ return _FUNCTION; }	
"if"							{ return _IF; }
"else"						{ return _ELSE; }
"return"					{ return _RETURN; }		
"then"						{ return _THEN; }

"("								{ return _LPAREN; }
")"								{ return _RPAREN; }
"{"								{ return _LBRACKET; }
"}"								{ return _RBRACKET; }
";"								{ return _SEMI; }
"="								{ return _ASSIGN; }
","								{ return _COMMA; }
"++"							{ return _POSTINC; }

("-"|"+")												{ return _OP; }

(">"|"<")												{ return _RELOP; }
(">="|"<="|"=="|"!=")						{ return _RELOP; }

[a-zA-Z][a-zA-Z0-9"-""_"]* 						{ return _ID; }
[+-]?[0-9]{1,10} 								{ return _INT_NUM; }
[0-9]{1,10}[uU]									{ return _UINT_NUM; }



"//"(.)*	{ /*skip*/ }					
"/*"([^*]|"\n"|(\*+([^*/]|"\n")))*"*"+"/"

.                 		   { printf("line %d: LEXICAL ERROR on char %c\n", 
                           			   yylineno, *yytext);}
                             
%%


