%{
  #include <stdio.h>
  int yylex(void);
  int yyparse(void);
  int yyerror(char *);
  extern int yylineno;

%}

%token _TYPE_INT
%token _TYPE_UINT

%token _FUNCTION
%token _IF
%token _ELSE
%token _RETURN
%token _THEN

%token _LPAREN
%token _RPAREN
%token _LBRACKET
%token _RBRACKET
%token _SEMI
%token _ASSIGN
%token _COMMA
%token _POSTINC

%token _OP

%token _RELOP

%token _ID
%token _INT_NUM
%token _UINT_NUM

%nonassoc ONLY_IF
%nonassoc _ELSE

%%

program
	: function_list
	;

function_list
	: //empty
	| function_list function
	;

function 
	: type _ID _LPAREN parameter_list _RPAREN body
	| type _ID _LPAREN _RPAREN body									//Za funkcije bez parametara 😉️
	;
	
parameter_list		//Lista parametara koja sadrzi barem jedan parametas
	: type _ID
	| parameter_list _COMMA type _ID
	;
	

variable_list	//Lista imena varijabli koja sadrzi barem jednu varijablu
	: _ID
	| variable_list _COMMA _ID
	;
	
body
	: _LBRACKET statement_list _RBRACKET
	;
	
statement_list	//Lista naredbi koja moze biti u bloku {...}, moze biti i prazna {}
	: //empty
	| statement_list statement
	;
	
statement	//Jedan iskaz ili blok naredbi
	: body										//{...} blok naredbi
	| declare_statement 			//naredba deklaracije
	| assign_statement				//dodela
	| if_else_statement				//if-else (KOJI MORA DA SADRZI I ELSE DEO)
	| return_statement				//return
	| postinc_statement				//a++;
	| function_statement			//poziv funkcije kao void
	;

return_statement
	: _RETURN num_exp _SEMI
	;

postinc_statement
	: postinc_var _SEMI
	;

postinc_var
	: _ID _POSTINC
	;

if_else_statement
	: _IF _LPAREN relation _RPAREN _THEN statement %prec ONLY_IF
	| _IF _LPAREN relation _RPAREN _THEN statement _ELSE statement	//Nije omoguceno vise od 1 elsa u ifu
	;

declare_statement
	: type variable_list _SEMI
	| type assign_statement
	;
	
assign_statement
	: _ID _ASSIGN num_exp _SEMI
	;
		
relation
	: num_exp _RELOP num_exp
	;

function_statement
	: function_call _SEMI
	;

function_call
	: _ID _LPAREN num_exp_list _RPAREN
	| _ID _LPAREN _RPAREN
	;

num_exp_list
	: num_exp
	| num_exp_list _COMMA num_exp
	;

num_exp	//Brojni izraz 4+5-8... ima konkretnu vrednost
	: exp
	| num_exp _OP exp
	;
		
exp	//Sve sto moze biti clan aritmetickog izraza
	: literal
	| postinc_var
	| function_call
	| _ID
	| _LPAREN num_exp _RPAREN
	;

literal
	: _INT_NUM
	| _UINT_NUM
	;

type
	: _TYPE_INT
	| _TYPE_UINT
	;

%%

int yyerror(char *s) {
  fprintf(stderr, "line %d: SYNTAX ERROR %s\n", yylineno, s);
} 

int main() {
  yyparse();
	printf ("Parsing finished.\n");
}

