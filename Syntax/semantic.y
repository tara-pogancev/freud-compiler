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
  int sw_temp = -1;
  
  int arg_num = 0;
  int par_err = 0;
  
  int case_int = 0;

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
%token _PARA

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

%token _SWITCH
%token _DEFAULT
%token _LSQBR
%token _RSQBR
%token _COLON
%token _CASE
%token _FINISH

%type <i> num_exp exp literal function_call argument relation postinc_var

%nonassoc ONLY_IF
%nonassoc _ELSE
%nonassoc NO_FINISH

%%

program
	: function_list
		{
			if (lookup_symbol("main", FUN) == NO_INDEX) err("undefined reference to 'main'");
		}
	| //empty
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
			par_num = 0;
			has_return = 0;
		}
		_LPAREN parameters _RPAREN 
		{
			set_atr1(fun_idx, par_num);
			var_num = 0;
		}
		body
		{
			clear_symbols(fun_idx+1);
			var_num = 0;
		}
	;
	
parameters		//Jedan parametar po funkciji
	: //empty
		{ set_atr1(fun_idx, 0); }
	| _TYPE _ID
		{
			if ($1 == VOID) err("invalid parameter type '%s'", $2);
    	insert_symbol($2, PAR, $1, ++par_num, NO_ATR);
    	set_param_type(fun_idx, par_num, $1);
    }
    
   //Za vise parametara funkcije 
  | parameters _COMMA  _TYPE _ID
  {
  	if(lookup_symbol($4, PAR) != NO_INDEX) err("redefinition of '%s'", $4);
			insert_symbol($4, PAR, $3, ++par_num, NO_ATR);
			set_param_type(fun_idx, par_num, $3);
  }
    
	;

body
	: _LBRACKET variable_list statement_list _RBRACKET
		{
			if (has_return == 0 && get_type(fun_idx)!=VOID) warn("no return statement in %s", 															get_name(fun_idx));
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
		//Individualni zadatak 1: int a, b = 100;
	| var_ids	_COMMA _ID _ASSIGN num_exp
		{
			if(lookup_symbol($3, VAR|PAR) != NO_INDEX) err("redefinition of '%s'", $3);
			insert_symbol($3, VAR, type_temp, ++var_num, NO_ATR);
			if(get_type($5) != type_temp) err("incompatible types in assignment");
		}
	| _ID _ASSIGN num_exp
		{
			if(lookup_symbol($1, VAR|PAR) != NO_INDEX) err("redefinition of '%s'", $1);
			insert_symbol($1, VAR, type_temp, ++var_num, NO_ATR);
			if(get_type($3) != type_temp) err("incompatible types in assignment");
		}
	;
	
statement_list	//Lista naredbi koja moze biti u bloku {...}, moze biti i prazna {}
	: //empty
	| statement_list statement
	;

statement	//Jedan iskaz ili blok naredbi
	: compound_statement			//{...} blok naredbi
	| assign_statement				//dodela
	| if_else_statement				//if-else
	| return_statement				//return
	| postinc_statement				//a++;
	| para_statement					//para(...)		
	| switch_statement				//switch-case
	| void_function_call			//void functions
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
		{
			//Ne sme biti void
			int idx = fcall_idx;
			if (get_type(idx) == VOID) err("using void function '%s' in expression", get_name(idx));
		}
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
      par_err = 0;
    } 
     _LPAREN argument _RPAREN
    {
    
    //U slucaju pogresnog broja parametara ne ispisuju se greske u tipovima
    	if(get_atr1(fcall_idx) != $4) 
    		err("wrong number of arguments in function call '%s'", get_name(fcall_idx));
    	else if (par_err != 0) 
				err("incompatible type for argument in '%s'", get_name(fcall_idx));
    		
    	set_type(FUN_REG, get_type(fcall_idx));
      $$ = FUN_REG;
    }
	;	
	
argument
	: // empty
		{ $$ = 0; 
			arg_num = 0;}
	| num_exp
		{	
			arg_num = 1;
			$$ = 1;
			if (get_param_type(fcall_idx, arg_num) != get_type($1)) par_err++;
		}
	// Za vise argumenata
	| argument _COMMA num_exp
		{
			arg_num++;
			$$ = arg_num;
		//	warn("%d and %d", get_type($3), get_param_type(fcall_idx, arg_num));
			if (get_type($3) != get_param_type(fcall_idx, arg_num))	par_err++;
		}
	;	
	
void_function_call
	: function_call _SEMI
		{
			//Mora biti void
			int idx = fcall_idx;
			if (get_type(idx) != VOID) err("incorrect call of non-void function '%s'", get_name(idx));
		}
	;	
	
if_else_statement
	: _IF _LPAREN relation _RPAREN statement %prec ONLY_IF
	| _IF _LPAREN relation _RPAREN statement _ELSE statement	
		//Nije omoguceno vise od 1 elsa u ifu, ali moze if bez elsa
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
	
para_statement	//Individualni 2: para
	: _PARA _LPAREN _TYPE _ID
		{
			int para_idx = lookup_symbol($4, VAR|PAR);
			if(para_idx != NO_INDEX) err("redefinition of '%s'", $4);
			else if ($3 == VOID) err("invalid variable type in para");
			else insert_symbol($4, VAR, $3, ++var_num, NO_ATR);
		}
		 _ASSIGN num_exp _SEMI relation _SEMI _ID _POSTINC _RPAREN 
		{
			if (get_type($7) != $3) err("assignment types not matching");
			if (lookup_symbol($4, VAR) != lookup_symbol($11, VAR)) err("para numerators not matching");
		}
		statement
	;
	
switch_statement	//Individualni 3: switch case
	: _SWITCH _LSQBR _ID _RSQBR
		{
			sw_temp = lookup_symbol($3, VAR|PAR);
			if(sw_temp == NO_INDEX) err("variable '%s' in switch statement not found", $3);
			case_int++;		//Brojac trenutnog switch-a po redu
		}  
		switch_part
	;	
	
switch_part	//deo posle inicijalizacije switch-a	
	:	_LBRACKET cases _RBRACKET	//no default
	|	_LBRACKET cases _DEFAULT _COLON statement _RBRACKET	//default
	;
	
cases
	: case
	| cases case
	;
	
case
	:	_CASE literal 
		{
			if (get_type($2) != get_type(sw_temp)) err("invalid literal type in switch");
				else if (get_atr1($2) == case_int) err("literal values must be unique");
					else set_atr1($2, case_int);
		}
		case_part
	;
	
case_part
	:	_COLON statement %prec NO_FINISH
	| _COLON statement _FINISH _SEMI
	;
	
	
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


