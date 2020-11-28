%{
  #include <stdio.h>
  #include <stdlib.h>
  #include "defs.h"
  #include "symtab.h"

  int yyparse(void);
  int yylex(void);
  int yyerror(char *s);
  void warning(char *s);

  extern int yylineno;
  char char_buffer[CHAR_BUFFER_LENGTH];
  int error_count = 0;
  int warning_count = 0;
  int var_num = 0;
  int par_num = 0;
  int fun_idx = -1;
  int fcall_idx = -1;
  
  int type_temp = 0;
  int has_return = 0;

%}

%union {
	int i;
	char *s;
	}

%token <i> _TYPE

%token _FUNCTION
%token _IF
%token _ELSE
%token _RETURN

%token _LPAREN
%token _RPAREN
%token _LBRACKET
%token _RBRACKET
%token _SEMI
%token _ASSIGN
%token _COMMA
%token _POSTINC

%token <i> _OP
%token <i> _RELOP

%token <s> _ID
%token <s> _INT_NUM
%token <s> _UINT_NUM

%type <i> num_exp exp literal function_call argument relation postinc_var

%nonassoc ONLY_IF
%nonassoc _ELSE

%%

program
	: function_list
		{
			if (lookup_symbol("main", FUN) == NO_INDEX) err("undefined reference to 'main'");
		}
	;

function_list
	: function
	| function_list function
	;

function 
	: _TYPE _ID 
		{
			fun_idx = lookup_symbol($2, FUN);
			if (fun_idx == NO_INDEX) fun_idx = insert_symbol($2, FUN, $1, NO_ATR, NO_ATR);
			else err("redefinition of function '%s'", $2);
			
			has_return = 0;
		}
		_LPAREN parameter _RPAREN body
		{
			clear_symbols(fun_idx+1);
			var_num = 0;
			par_num = 0;
		}
	;
	
parameter		//Jedan parametar po funkciji
	: //empty
		{ set_atr1(fun_idx, 0); }
	| _TYPE _ID
		{
			if ($1 == VOID) err("invalid parameter type '%s'", $2);
    	insert_symbol($2, PAR, $1, 1, NO_ATR);
      set_atr1(fun_idx, 1);
      set_atr2(fun_idx, $1);
    }
    
   //Za vise parametara funkcije 
  | parameter _COMMA  _TYPE _ID
  {
  	if(lookup_symbol($4, PAR) != NO_INDEX) err("redefinition of '%s'", $4);
			insert_symbol($4, PAR, $3, ++par_num, NO_ATR);
  }
    
	;

body
	: _LBRACKET variable_list statement_list _RBRACKET
		{
			if (has_return == 0 && get_type(fun_idx)!=VOID) warn("no return statement in %s", get_name(fun_idx));
		}
	;
	
variable_list	//deo gde se definisu varijable
  : // empty
  | variable_list variable
  ;
  
variable	//definicija jedne varijable	int a; ili vise istog tipa int a, b, c;
  : _TYPE 
      { 
      if ($1 == VOID) err("invalid variable type");
      type_temp = $1; } 
      var_ids _SEMI
  ;	
	
var_ids	//korisceno iskljucivo za deklaraciju
	: _ID
		{
			if(lookup_symbol($1, VAR|PAR) != NO_INDEX) err("redefinition of '%s'", $1);
			insert_symbol($1, VAR, type_temp, ++var_num, NO_ATR);
		}
	| var_ids _COMMA _ID
		{
			if(lookup_symbol($3, VAR|PAR) != NO_INDEX) err("redefinition of '%s'", $3);
			insert_symbol($3, VAR, type_temp, ++var_num, NO_ATR);
		}
	;
	
statement_list	//Lista naredbi koja moze biti u bloku {...}, moze biti i prazna {}
	: //empty
	| statement_list statement
	;

statement	//Jedan iskaz ili blok naredbi
	: compound_statement										//{...} blok naredbi
//	| declare_statement 			//naredba deklaracije
	| assign_statement				//dodela
	| if_else_statement				//if-else
	| return_statement				//return
	| postinc_statement				//a++;
//	| function_statement			//poziv funkcije kao void
	;

compound_statement
	: _LBRACKET statement_list _RBRACKET
	;
	
assign_statement
	: _ID _ASSIGN num_exp _SEMI
		{
			int idx = lookup_symbol($1, VAR|PAR);
			if (idx == NO_INDEX) err("invalid lvalue '%s' in assignment", $1);
			else if(get_type(idx) != get_type($3)) err("incompatible types in assignment");
		}
	;
	
num_exp	//Brojni izraz 4+5-8... ima konkretnu vrednost
	: exp
	| num_exp _OP exp
		{
    	if(get_type($1) != get_type($3)) err("invalid operands: arithmetic operation");
    }
	;

exp	//Sve sto moze biti clan aritmetickog izraza
	: literal
	| postinc_var
	| function_call
	| _ID
		{
      $$ = lookup_symbol($1, VAR|PAR);
      if($$ == NO_INDEX) err("'%s' undeclared", $1);
    }
	| _LPAREN num_exp _RPAREN
		{ $$ = $2; }
	;
	
literal
	: _INT_NUM
		{ $$ = insert_literal($1, INT);	}
	| _UINT_NUM
		{	$$ = insert_literal($1, UINT); }
	;
	
function_call
	: _ID
		{
    	fcall_idx = lookup_symbol($1, FUN);
      if(fcall_idx == NO_INDEX) err("'%s' is not a function", $1);
    } 
     _LPAREN argument _RPAREN
    {
    	if(get_atr1(fcall_idx) != $4) 
    		err("wrong number of args to function '%s'", get_name(fcall_idx));
    	set_type(FUN_REG, get_type(fcall_idx));
      $$ = FUN_REG;
    }
	;	
	
argument
	: // empty
		{ $$ = 0; }
	| num_exp
		{
			if (get_atr2(fcall_idx) != get_type($1))
				err("incompatible type for argument in '%s'", get_name(fcall_idx));
			$$ = 1;
		}
	;	
	
if_else_statement
	: _IF _LPAREN relation _RPAREN statement %prec ONLY_IF
	| _IF _LPAREN relation _RPAREN statement _ELSE statement	
		//Nije omoguceno vise od 1 elsa u ifu, ali moze if bez elsa
		//Jedna akcija po ifu
	;	
	
relation
	: num_exp _RELOP num_exp
		{
			if (get_type($1) != get_type($3)) 
				err("invalid operands: relational operator");			
					
		}
	;	
	
return_statement
	: _RETURN num_exp _SEMI
		{
			has_return++;
		
			if (get_type(fun_idx) == VOID) err("return statement found in void function");
			else if (get_type(fun_idx) != get_type($2)) err("incompatible types in return");
		}
	| _RETURN _SEMI
		{
			has_return++;
		
			if (get_type(fun_idx) != VOID) warn("missing return statement");
		}
	;

postinc_statement
	: postinc_var _SEMI
	;

postinc_var
	: _ID _POSTINC
		{
      int idx = lookup_symbol($1, VAR|PAR);
			if (idx == NO_INDEX) err("invalid lvalue '%s'", $1);
			$$ = idx;
    }
	;
	

/*
function_statement
	: function_call _SEMI
	;
*/

%%

int yyerror(char *s) {
  fprintf(stderr, "\nline %d: ERROR: %s\n", yylineno, s);
  error_count++;
  return 0;
}

void warning(char *s) {
  fprintf(stderr, "\nline %d: WARNING: %s\n", yylineno, s);
  warning_count++;
}

int main() {
  int synerr;
  init_symtab();

  synerr = yyparse();

  clear_symtab();
  
  if(warning_count)
    printf("\n%d warning(s).\n", warning_count);

  if(error_count)
    printf("\n%d error(s).\n", error_count);

  if(synerr)
    return -1; //syntax error
  else
    return error_count; //semantic errors
}


