%{
  #include <stdio.h>
  #include <stdlib.h>
  #include "defs.h"
  #include "symtab.h"
  #include "codegen.h"


  int yyparse(void);
  int yylex(void);
  int yyerror(char *s);
  void warning(char *s);

	extern int yylineno;
  int out_lin = 0;
  char char_buffer[CHAR_BUFFER_LENGTH];
  int error_count = 0;
  int warning_count = 0;
  int var_num = 0;
  int par_num = 0;
  int fun_idx = -1;
  int fcall_idx = -1;
  int lab_num = -1;
  FILE *output;
  
  int type_temp = 0;
  int has_return = 0;
  int sw_temp = -1;
  
  int arg_num = 0;
  int par_err = 0;
  
  int case_int = 0;	//Redni broj case-a
  int case_num = 0; //Trenutni broj case-a koji se posmatra
  
  int para_num = -1; //Broj para iskaza
  
  int declare_vars[10];
  int declare_vars_num = 0;
  int postinc_stm = -1;
  int args_for_stack[10];

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
%token _QUESTION

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

%type <i> num_exp exp literal function_call argument relation postinc_var if_part postinc_statement conditional_exp conditional_case

%nonassoc ONLY_IF
%nonassoc _ELSE
%nonassoc NO_FINISH
%nonassoc ONLY_EXP

%%

program
	: global_vars function_list
		{
			if (lookup_symbol("main", FUN) == NO_INDEX) 
				err("undefined reference to 'main'");
		}
	| //empty
	;

global_vars
	: //empty
	| global_vars global_var
	;

global_var
	: _TYPE _ID _SEMI 
		{
			if ($1 == VOID) err("invalid variable type '%s'", $2);
			 else if (lookup_symbol($2, GL) != -1) err("redefinition of '%s'", $2);
				else {
			
					insert_symbol($2, GL, $1, NO_ATR, NO_ATR);
					code("\n%s:\n\t\tWORD\t1", $2);
					
					}

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
			par_num = 0;
			has_return = 0;
			
			code("\n%s:", $2);
			code("\n\t\tPUSH\t%%14");
			code("\n\t\tMOV \t%%15,%%14");
						
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
									
			code("\n@%s_exit:", $2);
			code("\n\t\tMOV \t%%14, %%15");
			code("\n\t\tPOP \t%%14");
			code("\n\t\tRET");
		}
	;
	
parameters		//Jedan parametar po funkciji
	: //empty
		{ set_atr1(fun_idx, 0); }
	| parameter
	;

parameter
	: _TYPE _ID
		{
			if ($1 == VOID) err("invalid parameter type '%s'", $2);
    	insert_symbol($2, PAR, $1, ++par_num, NO_ATR);
    	set_param_type(fun_idx, par_num, $1);
    } 
     //Za vise parametara funkcije 
  | parameter _COMMA  _TYPE _ID
  {
  	if(lookup_symbol($4, PAR) != NO_INDEX) err("redefinition of '%s'", $4);
			insert_symbol($4, PAR, $3, ++par_num, NO_ATR);
			set_param_type(fun_idx, par_num, $3);
  } 
	;


body
	: _LBRACKET variable_list 
		{

			if(var_num)
				code("\n\t\tSUBS\t%%15,$%d,%%15", 4*var_num);
				
				code("\n@%s_body:", get_name(fun_idx));
			
		}
		
		statement_list _RBRACKET
		
		{
			//ZBOG TEST FAJLOVA MAIN BEZ RETUN-A PROLAZI BEZ WARNINGA!
			if (has_return == 0 && get_type(fun_idx)!=VOID) 
				if (lookup_symbol("main", FUN)!=fun_idx)
				warn("no return statement in %s", get_name(fun_idx));
			
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
      type_temp = $1; 
      declare_vars_num = 0;
      
      printf("%d",type_temp);
      } 
      declare_vars _SEMI
  ;	
	
var_ids	//korisceno iskljucivo za deklaraciju
	: _ID
		{
			if(lookup_symbol($1, VAR|PAR|GL) != NO_INDEX) err("redefinition of '%s'", $1);
			int idx = insert_symbol($1, VAR, type_temp, ++var_num, NO_ATR);
			
			declare_vars[declare_vars_num] = idx;
		}
	| var_ids _COMMA _ID
		{
			if(lookup_symbol($3, VAR|PAR|GL) != NO_INDEX) err("redefinition of '%s'", $3);
			int idx = insert_symbol($3, VAR, type_temp, ++var_num, NO_ATR);
			
			declare_vars_num++;
			declare_vars[declare_vars_num] = idx;
		}
	;
		
declare_vars
		//Individualni zadatak 1: int a, b = 100;
	: var_ids _ASSIGN num_exp
		{
			if(get_type($3) != type_temp) err("incompatible types in assignment");

			for (int i = 0; i<=declare_vars_num; i++)
				gen_mov($3, declare_vars[i]);
			
		}
	| var_ids	//Bez dodele vrednosti
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
			int idx = lookup_symbol($1, VAR|PAR|GL);
			if (idx == NO_INDEX) err("invalid value '%s' in assignment", $1);
			else if(get_type(idx) != get_type($3)) err("incompatible types in assignment");
			else {
			
			gen_mov($3, idx);
			
			}

		}
	;
	
num_exp	//Brojni izraz 4+5-8... ima konkretnu vrednost
	: exp
	| num_exp _OP exp
		{
    	if(get_type($1) != get_type($3)) err("invalid operands: arithmetic operation");
    		else {
    	
    	int t1 = get_type($1);
    	code("\n\t\t%s\t", ar_instructions[$2 + (t1-1) * AROP_NUMBER]);
    
   		 	gen_sym_name($1);
  	  	code(",");
  	  	gen_sym_name($3);
  	  	code(",");
   	  	free_if_reg($3);
  	  	free_if_reg($1);
 	  	 	$$ = take_reg();
  	  	gen_sym_name($$);
  	  	set_type($$, t1);
		
    	}
    }
	;

exp	//Sve sto moze biti clan aritmetickog izraza
	: literal
	| postinc_var
		{
			$$ = postinc_stm;
		}
	| function_call
		{
			//Ne sme biti void
			int idx = fcall_idx;
			if (get_type(idx) == VOID) err("using void function '%s' in expression", get_name(idx));
			$$ = take_reg();
			gen_mov(FUN_REG, $$);
		}
	| _ID
		{
      $$ = lookup_symbol($1, VAR|PAR|GL);
      if($$ == NO_INDEX) err("'%s' undeclared", $1);
    }
	| _LPAREN num_exp _RPAREN
		{ $$ = $2; }
	| conditional_case
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
    	
    	//Generisanje koda:	
    	
    		//Stack
    	for (int i = arg_num; i>0; i--) {
    		free_if_reg(args_for_stack[i]);
				code("\n\t\t\tPUSH\t");
				gen_sym_name(args_for_stack[i]);
			}
    	
    	code("\n\t\t\tCALL\t%s", get_name(fcall_idx));	
    						
			if (get_atr1(fcall_idx) > 0)
				code("\n\t\t\tADDS\t%%15,$%d,%%15", get_atr1(fcall_idx)*4);
    		
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
			
			//Gen
			args_for_stack[arg_num] = $1;
					
		}
	// Za vise argumenata
	| argument _COMMA num_exp
		{
			arg_num++;
			$$ = arg_num;
			if (get_type($3) != get_param_type(fcall_idx, arg_num))	par_err++;
			
			
			//Gen
			args_for_stack[arg_num] = $3;
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
	: if_part %prec ONLY_IF
		{
			code("\n@exit%d:", $1);
		}
	| if_part _ELSE statement	
		{
			code("\n@exit%d:", $1);
		}
	//Nije omoguceno vise od 1 elsa u ifu, ali moze if bez elsa
	;	
	
if_part
	: _IF _LPAREN
		{
			$<i>$ = ++lab_num;
			code("\n@if%d:", lab_num);
		}	
		relation
		{
			code("\n\t\t%s\t@false%d", opp_jumps[$4], $<i>3);
			code("\n@true%d:", $<i>3);
		}
		_RPAREN statement
		{
			code("\n\t\tJMP \t@exit%d", $<i>3);
      code("\n@false%d:", $<i>3);
      $$ = $<i>3;
		}
	;
	
relation
	: num_exp _RELOP num_exp
		{
			if (get_type($1) != get_type($3)) 
				err("invalid operands: relational operator");			

			else {
				$$ = $2 + ((get_type($1)-1)*RELOP_NUMBER);
				gen_cmp($1, $3);	
			}
		}
	;	
	
return_statement
	: _RETURN num_exp _SEMI
		{
			has_return++;
		
			if (get_type(fun_idx) == VOID) err("return statement found in void function");
			else if (get_type(fun_idx) != get_type($2)) err("incompatible types in return");
			
				else {
					gen_mov($2, FUN_REG);
					code("\n\t\tJMP \t@%s_exit", get_name(fun_idx));
					}
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
      int idx = lookup_symbol($1, VAR|PAR|GL);
      $$ = idx;
			if (idx == NO_INDEX) err("invalid value '%s'", $1);
			else {
	
				if (postinc_stm == -1)	free_if_reg(postinc_stm);
 		   	postinc_stm = take_reg();
 		   	gen_mov(idx, postinc_stm);
 		    set_type(postinc_stm, get_type(idx)); 		      
			
			int idx = lookup_symbol($1, GL);
			if (idx != NO_INDEX) {
					//Globalna prom
					if (get_type(idx)==INT)
						code("\n\t\tADDS\t");
					else code("\n\t\tADDU\t");
					code("%s,$1,%s", get_name(idx), get_name(idx));
				}	
			else {
			
				idx = lookup_symbol($1, VAR|PAR);
			
				if (get_type(idx)==INT)
					code("\n\t\tADDS\t");
				else code("\n\t\tADDU\t");
						
				gen_sym_name(idx);
				code(",$1,");
				gen_sym_name(idx);
				free_if_reg(idx);
			}
			}
    }
	;
	
para_statement	//Individualni 2: para
	: _PARA _LPAREN _TYPE _ID
		{
			code("\n@para_init%d:", ++para_num);
			$<i>$ = para_num;
			
			int para_idx = lookup_symbol($4, VAR|PAR|GL);
			if(para_idx != NO_INDEX) err("redefinition of '%s'", $4);
			else if ($3 == VOID) err("invalid variable type in para");
			else {
					insert_symbol($4, VAR, $3, ++var_num, NO_ATR);
					para_idx = take_reg();
					set_type($3, para_idx);
				}
		}
		 _ASSIGN num_exp _SEMI 
		{
			int para_idx = lookup_symbol($4, VAR|PAR|GL);
			gen_mov($7, para_idx);	//Inicijalizovanje vrednosti brojaca
			code("\n@para_it%d:", $<i>5);	//Pocetna provera para iteracije
		}
		relation 
		{
			code("\n\t\t%s\t@para_exit%d", opp_jumps[$10], $<i>5);	
		}
		_SEMI _ID _POSTINC _RPAREN 
		{
			if (lookup_symbol($4, VAR) != lookup_symbol($13, VAR)) err("para numerators not matching");
		}
		statement
		{
			//Kraj para: Povecati inc, proveriti condition
	
			int idx = lookup_symbol($4, GL);
			if (idx != NO_INDEX) {
					//Globalna prom
					if (get_type(idx)==INT)
						code("\n\t\tADDS\t");
					else code("\n\t\tADDU\t");
					code("%s,$1,%s", get_name(idx), get_name(idx));
				}	
			else {
			
				idx = lookup_symbol($4, VAR|PAR);
			
				if (get_type(idx)==INT)
					code("\n\t\tADDS\t");
				else code("\n\t\tADDU\t");
						
				gen_sym_name(idx);
				code(",$1,");
				gen_sym_name(idx);
				free_if_reg(idx);
			}
			
			code("\n\t\tJMP\t@para_it%d", $<i>5);	
			
			//Izlazak iz para-stm
			code("\n@para_exit%d:", $<i>5);
		}
	;
	
switch_statement	//Individualni 3: switch case
	: _SWITCH _LSQBR _ID _RSQBR
		{
			sw_temp = lookup_symbol($3, VAR|PAR|GL);
			if(sw_temp == NO_INDEX) err("variable '%s' in switch statement not found", $3);
			case_int++;		//Brojac trenutnog switch-a po redu
		}  
		switch_part
	;	
	
switch_part	//deo posle inicijalizacije switch-a	
	:	_LBRACKET cases _RBRACKET	//no default
		{
			code("\n@sw_exit%d:", case_int);
		}
	|	_LBRACKET cases _DEFAULT _COLON 
		{
			code("\n@sw_true%d:", ++case_num);
		}
		statement _RBRACKET	//default
		{
			//Ovde ce se generisati statement koji svakako ide posle poslednjeg case-a.
			code("\n@sw_exit%d:", case_int);
		}
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
					else { 
					
			set_atr1($2, case_int);
					
			$<i>$ = ++case_num;
			code("\n@sw%d:", $<i>$);
			gen_cmp(sw_temp, $2);
			code("\n\t\tJNE\t@sw_false%d", $<i>$);
			code("\n@sw_true%d:", $<i>$);
			
			}
		}
		case_part
		{
			//Nakon generisanja statementa
			code("\n@sw_false%d:", $<i>3);
		}
	;
	
case_part
	:	_COLON statement %prec NO_FINISH
		{
			code("\n\t\tJMP\t@sw_true%d", case_num+1);
		}
	| _COLON statement _FINISH _SEMI
		{
			code("\n\t\tJMP\t@sw_exit%d", case_int);
		}
	;
	
conditional_case	
	: _LPAREN relation
		{
			$<i>$ = ++lab_num;
			code("\n@if%d:", $<i>$);
			code("\n\t\t%s\t@false%d", opp_jumps[$2], $<i>$);
			code("\n@true%d:", $<i>$);
		}
		_RPAREN _QUESTION conditional_exp _COLON conditional_exp
		{
			if (get_type($6)!=get_type($8)) err("One or more invalid variable types in conditional case!");
				else {
			$$ = take_reg();
			set_type($$, get_type($6));
			gen_mov($6, $$);
			code("\n\t\tJMP\t@exit%d", $<i>3);
			code("\n@false%d:", $<i>3);
			gen_mov($8, $$);
			code("\n@exit%d:", $<i>3);
			}
		}
	;
	
conditional_exp	
	:	_ID
		{
      $$ = lookup_symbol($1, VAR|PAR|GL);
      if($$ == NO_INDEX) err("'%s' undeclared", $1);
		}
	| literal
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
  output = fopen("output.asm", "w+");

  synerr = yyparse();

  clear_symtab();
  fclose(output);
  
  if(warning_count)
    printf("\n%d warning(s).\n", warning_count);

  if(error_count) {
    remove("output.asm");
    printf("\n%d error(s).\n", error_count);
  }

  if(synerr)
    return -1;  //syntax error
  else if(error_count)
    return error_count & 127; //semantic errors
  else if(warning_count)
    return (warning_count & 127) + 127; //warnings
  else
    return 0; //OK
}


