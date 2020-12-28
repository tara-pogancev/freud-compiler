/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "freud.y"

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
  
  int case_int = 0;
  
  int declare_vars[10];
  int declare_vars_num = 0;
  int is_postinc = 0;
  int postinc_stm = 0;
  int last_was_inc = 0;


#line 112 "freud.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_FREUD_TAB_H_INCLUDED
# define YY_YY_FREUD_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    _TYPE = 258,
    _FUNCTION = 259,
    _IF = 260,
    _ELSE = 261,
    _RETURN = 262,
    _PARA = 263,
    _LPAREN = 264,
    _RPAREN = 265,
    _LBRACKET = 266,
    _RBRACKET = 267,
    _SEMI = 268,
    _ASSIGN = 269,
    _COMMA = 270,
    _POSTINC = 271,
    _OP = 272,
    _RELOP = 273,
    _ID = 274,
    _INT_NUM = 275,
    _UINT_NUM = 276,
    _SWITCH = 277,
    _DEFAULT = 278,
    _LSQBR = 279,
    _RSQBR = 280,
    _COLON = 281,
    _CASE = 282,
    _FINISH = 283,
    ONLY_IF = 284,
    NO_FINISH = 285,
    ONLY_EXP = 286
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 43 "freud.y"

	int i;
	char *s;
	

#line 202 "freud.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_FREUD_TAB_H_INCLUDED  */



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   145

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  32
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  46
/* YYNRULES -- Number of rules.  */
#define YYNRULES  75
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  136

#define YYUNDEFTOK  2
#define YYMAXUTOK   286


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    90,    90,    95,    99,   100,   104,   115,   116,   121,
     134,   120,   154,   155,   159,   166,   177,   176,   198,   199,
     204,   203,   215,   222,   233,   241,   245,   246,   250,   251,
     252,   253,   254,   255,   256,   257,   261,   265,   277,   314,
     386,   387,   392,   400,   405,   410,   412,   418,   417,   444,
     446,   458,   468,   477,   481,   490,   495,   489,   508,   520,
     530,   539,   572,   584,   591,   583,   600,   599,   609,   610,
     614,   615,   620,   619,   629,   630
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "_TYPE", "_FUNCTION", "_IF", "_ELSE",
  "_RETURN", "_PARA", "_LPAREN", "_RPAREN", "_LBRACKET", "_RBRACKET",
  "_SEMI", "_ASSIGN", "_COMMA", "_POSTINC", "_OP", "_RELOP", "_ID",
  "_INT_NUM", "_UINT_NUM", "_SWITCH", "_DEFAULT", "_LSQBR", "_RSQBR",
  "_COLON", "_CASE", "_FINISH", "ONLY_IF", "NO_FINISH", "ONLY_EXP",
  "$accept", "program", "global_vars", "global_var", "function_list",
  "function", "$@1", "$@2", "parameters", "parameter", "body", "$@3",
  "variable_list", "variable", "$@4", "var_ids", "declare_vars",
  "statement_list", "statement", "compound_statement", "assign_statement",
  "num_exp", "exp", "literal", "function_call", "$@5", "argument",
  "void_function_call", "if_else_statement", "if_part", "@6", "$@7",
  "relation", "return_statement", "postinc_statement", "postinc_var",
  "para_statement", "$@8", "$@9", "switch_statement", "$@10",
  "switch_part", "cases", "case", "$@11", "case_part", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286
};
# endif

#define YYPACT_NINF (-72)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-48)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
       7,    15,    25,   -72,    14,   -72,    57,   -72,    41,    28,
     -72,   -72,    71,   -72,    78,    63,    73,    69,   -72,   -72,
      82,    75,    68,   -72,   -72,   -72,    85,   -72,   -72,   -72,
      70,     0,   -72,    34,    77,    86,    22,    87,   -72,   -72,
      55,    74,   -72,   -72,   -72,    84,   -72,   -72,    93,   -72,
     -72,    88,   -72,   -72,    46,    81,   -72,   -72,    46,   -72,
      -3,   -72,   -72,     4,   -72,   -72,   -72,   -72,    99,    18,
      46,   -72,    96,    89,   -72,    51,   -72,    90,   -72,    46,
      -1,   -72,    46,    91,   -72,    33,    46,    92,   -72,    59,
     -72,   -72,   -72,   -72,   -72,    90,    17,   -72,    46,   101,
      95,   -72,    46,   102,    90,    51,    46,    90,    79,   -72,
     -72,    44,    58,    -9,   -72,    46,   -72,   -72,    94,   -72,
     103,    97,    51,   100,    51,   -72,   106,    98,   104,   -72,
     105,   108,   -72,   -72,    51,   -72
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       3,     0,     0,     1,     0,     5,     2,     7,     9,     0,
       8,     6,     0,     9,    12,     0,     0,    13,    14,    10,
       0,     0,     0,    18,    11,    15,    16,    20,    26,    19,
       0,     0,    22,    25,     0,     0,     0,     0,    26,    17,
      47,     0,    27,    28,    29,     0,    35,    30,    53,    31,
      32,     0,    33,    34,     0,     0,    21,    55,     0,    60,
      43,    45,    46,     0,    38,    40,    42,    41,     0,     0,
       0,    62,     0,     0,    52,     0,    61,    24,    23,     0,
       0,    59,     0,     0,    36,     0,    49,     0,    54,     0,
      56,    44,    39,    63,    37,    50,     0,    66,     0,     0,
       0,    48,     0,     0,    58,     0,     0,    51,     0,    67,
      57,     0,     0,     0,    70,     0,    72,    68,     0,    71,
       0,     0,     0,     0,     0,    73,     0,     0,    74,    69,
       0,     0,    64,    75,     0,    65
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -72,   -72,   -72,   -72,   -72,   116,   -72,   -72,   -72,   -72,
     -72,   -72,   -72,   -72,   -72,   -72,   -72,   107,   -71,   -72,
     -72,   -34,    30,    12,   -31,   -72,   -72,   -72,   -72,   -72,
     -72,   -72,    10,   -72,   -72,   -30,   -72,   -72,   -72,   -72,
     -72,   -72,   -72,    13,   -72,   -72
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,     5,     6,     7,    12,    21,    16,    17,
      24,    28,    26,    29,    30,    33,    34,    31,    42,    43,
      44,    89,    64,    65,    66,    72,    96,    46,    47,    48,
      79,    99,    90,    49,    50,    67,    52,   100,   134,    53,
     103,   109,   113,   114,   121,   125
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      45,    51,    63,   117,    88,    35,   -47,    36,    37,    91,
      -4,    38,    39,    71,   118,     3,    82,    81,   112,    40,
      77,    82,    41,    35,    80,    36,    37,   101,     4,    38,
      84,    58,   102,     8,   110,    59,    85,    40,    45,    51,
      41,    60,    61,    62,    45,    51,    94,    13,    54,    55,
      82,   126,    95,   128,    11,    58,    35,   115,    36,    37,
       9,    82,    38,   135,   104,    60,    61,    62,   107,    70,
      40,    71,   111,    41,    45,    51,    82,    98,    61,    62,
      14,    15,    18,    19,    20,    22,    23,    25,    27,    32,
      56,    45,    51,    45,    51,    57,    68,    74,    73,    75,
      78,    76,    83,    45,    51,    86,   112,    82,    87,   106,
      93,   105,    92,   108,   130,   132,   123,    97,   129,   127,
     122,   133,    10,   124,   116,   120,   119,     0,     0,     0,
       0,     0,   131,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    69
};

static const yytype_int16 yycheck[] =
{
      31,    31,    36,    12,    75,     5,     9,     7,     8,    10,
       3,    11,    12,    16,    23,     0,    17,    13,    27,    19,
      54,    17,    22,     5,    58,     7,     8,    10,     3,    11,
      12,     9,    15,    19,   105,    13,    70,    19,    69,    69,
      22,    19,    20,    21,    75,    75,    13,    19,    14,    15,
      17,   122,    86,   124,    13,     9,     5,    13,     7,     8,
       3,    17,    11,   134,    98,    19,    20,    21,   102,    14,
      19,    16,   106,    22,   105,   105,    17,    18,    20,    21,
       9,     3,    19,    10,    15,     3,    11,    19,     3,    19,
      13,   122,   122,   124,   124,     9,     9,    13,    24,     6,
      19,    13,     3,   134,   134,     9,    27,    17,    19,    14,
      19,    10,    82,    11,    16,    10,    13,    25,    12,    19,
      26,    13,     6,    26,   112,   115,   113,    -1,    -1,    -1,
      -1,    -1,    28,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    38
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    33,    34,     0,     3,    35,    36,    37,    19,     3,
      37,    13,    38,    19,     9,     3,    40,    41,    19,    10,
      15,    39,     3,    11,    42,    19,    44,     3,    43,    45,
      46,    49,    19,    47,    48,     5,     7,     8,    11,    12,
      19,    22,    50,    51,    52,    56,    59,    60,    61,    65,
      66,    67,    68,    71,    14,    15,    13,     9,     9,    13,
      19,    20,    21,    53,    54,    55,    56,    67,     9,    49,
      14,    16,    57,    24,    13,     6,    13,    53,    19,    62,
      53,    13,    17,     3,    12,    53,     9,    19,    50,    53,
      64,    10,    54,    19,    13,    53,    58,    25,    18,    63,
      69,    10,    15,    72,    53,    10,    14,    53,    11,    73,
      50,    53,    27,    74,    75,    13,    55,    12,    23,    75,
      64,    76,    26,    13,    26,    77,    50,    19,    50,    12,
      16,    28,    10,    13,    70,    50
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    32,    33,    33,    34,    34,    35,    36,    36,    38,
      39,    37,    40,    40,    41,    41,    43,    42,    44,    44,
      46,    45,    47,    47,    48,    48,    49,    49,    50,    50,
      50,    50,    50,    50,    50,    50,    51,    52,    53,    53,
      54,    54,    54,    54,    54,    55,    55,    57,    56,    58,
      58,    58,    59,    60,    60,    62,    63,    61,    64,    65,
      65,    66,    67,    69,    70,    68,    72,    71,    73,    73,
      74,    74,    76,    75,    77,    77
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     0,     0,     2,     3,     1,     2,     0,
       0,     8,     0,     1,     2,     4,     0,     5,     0,     2,
       0,     4,     1,     3,     3,     1,     0,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     4,     1,     3,
       1,     1,     1,     1,     3,     1,     1,     0,     5,     0,
       1,     3,     2,     1,     3,     0,     0,     7,     3,     3,
       2,     2,     2,     0,     0,    15,     0,     6,     3,     6,
       1,     2,     0,     4,     2,     4
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2:
#line 91 "freud.y"
                {
			if (lookup_symbol("main", FUN) == NO_INDEX) 
				err("undefined reference to 'main'");
		}
#line 1481 "freud.tab.c"
    break;

  case 6:
#line 105 "freud.y"
                {
			if ((yyvsp[-2].i) == VOID) err("invalid variable type '%s'", (yyvsp[-1].s));
			if (lookup_symbol((yyvsp[-1].s), GL) != -1) err("redefinition of '%s'", (yyvsp[-1].s));
			insert_symbol((yyvsp[-1].s), GL, (yyvsp[-2].i), NO_ATR, NO_ATR);
			code("\n%s:\n\t\tWORD\t1", (yyvsp[-1].s));

		}
#line 1493 "freud.tab.c"
    break;

  case 9:
#line 121 "freud.y"
                {
			fun_idx = lookup_symbol((yyvsp[0].s), FUN);
			if (fun_idx == NO_INDEX) fun_idx = insert_symbol((yyvsp[0].s), FUN, (yyvsp[-1].i), NO_ATR, NO_ATR);
			else err("redefinition of function '%s'", (yyvsp[0].s));
			par_num = 0;
			has_return = 0;
			
			code("\n%s:", (yyvsp[0].s));
			code("\n\t\tPUSH\t%%14");
			code("\n\t\tMOV \t%%15,%%14");
						
		}
#line 1510 "freud.tab.c"
    break;

  case 10:
#line 134 "freud.y"
                {
			set_atr1(fun_idx, par_num);
			var_num = 0;
			
		}
#line 1520 "freud.tab.c"
    break;

  case 11:
#line 140 "freud.y"
                {
			clear_symbols(fun_idx+1);
			var_num = 0;
			
						
			code("\n@%s_exit:", (yyvsp[-6].s));
			code("\n\t\tMOV \t%%14, %%15");
			code("\n\t\tPOP \t%%14");
			code("\n\t\tRET");
		}
#line 1535 "freud.tab.c"
    break;

  case 12:
#line 154 "freud.y"
                { set_atr1(fun_idx, 0); }
#line 1541 "freud.tab.c"
    break;

  case 14:
#line 160 "freud.y"
                {
			if ((yyvsp[-1].i) == VOID) err("invalid parameter type '%s'", (yyvsp[0].s));
    	insert_symbol((yyvsp[0].s), PAR, (yyvsp[-1].i), ++par_num, NO_ATR);
    	set_param_type(fun_idx, par_num, (yyvsp[-1].i));
    }
#line 1551 "freud.tab.c"
    break;

  case 15:
#line 167 "freud.y"
  {
  	if(lookup_symbol((yyvsp[0].s), PAR) != NO_INDEX) err("redefinition of '%s'", (yyvsp[0].s));
			insert_symbol((yyvsp[0].s), PAR, (yyvsp[-1].i), ++par_num, NO_ATR);
			set_param_type(fun_idx, par_num, (yyvsp[-1].i));
  }
#line 1561 "freud.tab.c"
    break;

  case 16:
#line 177 "freud.y"
                {

			if(var_num)
				code("\n\t\tSUBS\t%%15,$%d,%%15", 4*var_num);
			code("\n@%s_body:", get_name(fun_idx));
			
		}
#line 1573 "freud.tab.c"
    break;

  case 17:
#line 187 "freud.y"
                {
			//ZBOG TEST FAJLOVA MAIN BEZ RETUN-A PROLAZI BEZ WARNINGA!
			if (has_return == 0 && get_type(fun_idx)!=VOID) 
				if (lookup_symbol("main", FUN)!=fun_idx)
				warn("no return statement in %s", get_name(fun_idx));
			
		}
#line 1585 "freud.tab.c"
    break;

  case 20:
#line 204 "freud.y"
      { 
      if ((yyvsp[0].i) == VOID) err("invalid variable type");
      type_temp = (yyvsp[0].i); 
      declare_vars_num = 0;
      
      printf("%d",type_temp);
      }
#line 1597 "freud.tab.c"
    break;

  case 22:
#line 216 "freud.y"
                {
			if(lookup_symbol((yyvsp[0].s), VAR|PAR|GL) != NO_INDEX) err("redefinition of '%s'", (yyvsp[0].s));
			int idx = insert_symbol((yyvsp[0].s), VAR, type_temp, ++var_num, NO_ATR);
			
			declare_vars[declare_vars_num] = idx;
		}
#line 1608 "freud.tab.c"
    break;

  case 23:
#line 223 "freud.y"
                {
			if(lookup_symbol((yyvsp[0].s), VAR|PAR|GL) != NO_INDEX) err("redefinition of '%s'", (yyvsp[0].s));
			int idx = insert_symbol((yyvsp[0].s), VAR, type_temp, ++var_num, NO_ATR);
			
			declare_vars_num++;
			declare_vars[declare_vars_num] = idx;
		}
#line 1620 "freud.tab.c"
    break;

  case 24:
#line 234 "freud.y"
                {
			if(get_type((yyvsp[0].i)) != type_temp) err("incompatible types in assignment");

			for (int i = 0; i<declare_vars_num; i++)
				gen_mov((yyvsp[0].i), declare_vars[i]);
			
		}
#line 1632 "freud.tab.c"
    break;

  case 37:
#line 266 "freud.y"
                {
			int idx = lookup_symbol((yyvsp[-3].s), VAR|PAR|GL);
			if (idx == NO_INDEX) err("invalid value '%s' in assignment", (yyvsp[-3].s));
			else if(get_type(idx) != get_type((yyvsp[-1].i))) err("incompatible types in assignment");
						
			gen_mov((yyvsp[-1].i), idx);

		}
#line 1645 "freud.tab.c"
    break;

  case 38:
#line 278 "freud.y"
                {
			if(is_postinc) {
				  	
				last_was_inc++;  	  	
 		   	postinc_stm = take_reg();
 		   	gen_mov((yyvsp[0].i), postinc_stm);
 		    set_type(postinc_stm, get_type((yyvsp[0].i))); 		    
 		    (yyval.i) = postinc_stm;
			
				int idx = lookup_symbol(get_name((yyvsp[0].i)), GL);
				if (idx != NO_INDEX) {
					//Globalna prom
					if (get_type(idx)==INT)
						code("\n\t\tADDS\t");
					else code("\n\t\tADDU\t");
					code("%s,$1,%s", get_name(idx), get_name(idx));
				}	
			else {
			
				idx = lookup_symbol(get_name((yyvsp[0].i)), VAR|PAR);
			
				if (get_type(idx)==INT)
					code("\n\t\tADDS\t");
				else code("\n\t\tADDU\t");
			
				free_if_reg((yyvsp[0].i));
				(yyvsp[0].i) = take_reg();
			
				gen_sym_name(idx);
				code(",$1,");
				gen_sym_name(idx);
				set_type((yyvsp[0].i), get_type(idx));
			}
  	  	is_postinc = 0;
    	} else last_was_inc = 0;
		}
#line 1686 "freud.tab.c"
    break;

  case 39:
#line 315 "freud.y"
                {
    	if(get_type((yyvsp[-2].i)) != get_type((yyvsp[0].i))) err("invalid operands: arithmetic operation");
    	int t1 = get_type((yyvsp[-2].i));
    	
    	code("\n\t\t%s\t", ar_instructions[(yyvsp[-1].i) + (t1-1) * AROP_NUMBER]);
    	
    	 if (last_was_inc) {
  	    	  
  	  	gen_sym_name(postinc_stm);
  	  	code(",");
  	  	gen_sym_name((yyvsp[0].i));
  	  	code(",");
  	  	free_if_reg((yyvsp[0].i));
  	  	free_if_reg(postinc_stm);
  	  	free_if_reg((yyval.i));
 	  	 	(yyval.i) = take_reg();
  	  	gen_sym_name((yyval.i));
  	  	set_type((yyval.i), t1);

		   	postinc_stm = 0;
  	  	last_was_inc = 0;
  	  } else {

   		 	gen_sym_name((yyvsp[-2].i));
  	  	code(",");
  	  	gen_sym_name((yyvsp[0].i));
  	  	code(",");
  	  	free_if_reg((yyvsp[0].i));
  	  	free_if_reg((yyvsp[-2].i));
 	  	 	(yyval.i) = take_reg();
  	  	gen_sym_name((yyval.i));
  	  	set_type((yyval.i), t1);
  	  	
  	  }
    	
 	  	if (is_postinc){
    		
			int idx = lookup_symbol(get_name((yyvsp[0].i)), GL);
				if (idx != NO_INDEX) {
					//Globalna prom
					if (get_type(idx)==INT)
						code("\n\t\tADDS\t");
					else code("\n\t\tADDU\t");
					code("%s,$1,%s", get_name(idx), get_name(idx));
				}	
			else {
			
				idx = lookup_symbol(get_name((yyvsp[0].i)), VAR|PAR);
			
				if (get_type(idx)==INT)
					code("\n\t\tADDS\t");
				else code("\n\t\tADDU\t");
			
				free_if_reg((yyvsp[0].i));
				(yyvsp[0].i) = take_reg();
			
				gen_sym_name(idx);
				code(",$1,");
				gen_sym_name(idx);
				set_type((yyvsp[0].i), get_type(idx));
			}
    		
    		is_postinc = 0;
    	}
    	
    	last_was_inc = 0;
    	
    }
#line 1759 "freud.tab.c"
    break;

  case 41:
#line 388 "freud.y"
                {
			is_postinc++;
			(yyval.i) = (yyvsp[0].i);
		}
#line 1768 "freud.tab.c"
    break;

  case 42:
#line 393 "freud.y"
                {
			//Ne sme biti void
			int idx = fcall_idx;
			if (get_type(idx) == VOID) err("using void function '%s' in expression", get_name(idx));
			(yyval.i) = take_reg();
			gen_mov(FUN_REG, (yyval.i));
		}
#line 1780 "freud.tab.c"
    break;

  case 43:
#line 401 "freud.y"
                {
      (yyval.i) = lookup_symbol((yyvsp[0].s), VAR|PAR|GL);
      if((yyval.i) == NO_INDEX) err("'%s' undeclared", (yyvsp[0].s));
    }
#line 1789 "freud.tab.c"
    break;

  case 44:
#line 406 "freud.y"
                { (yyval.i) = (yyvsp[-1].i); }
#line 1795 "freud.tab.c"
    break;

  case 45:
#line 411 "freud.y"
                { (yyval.i) = insert_literal((yyvsp[0].s), INT);	}
#line 1801 "freud.tab.c"
    break;

  case 46:
#line 413 "freud.y"
                {	(yyval.i) = insert_literal((yyvsp[0].s), UINT); }
#line 1807 "freud.tab.c"
    break;

  case 47:
#line 418 "freud.y"
                {
    	fcall_idx = lookup_symbol((yyvsp[0].s), FUN);
      if(fcall_idx == NO_INDEX) err("'%s' is not a function", (yyvsp[0].s));
      par_err = 0;
    }
#line 1817 "freud.tab.c"
    break;

  case 48:
#line 424 "freud.y"
    {
    
    //U slucaju pogresnog broja parametara ne ispisuju se greske u tipovima
    	if(get_atr1(fcall_idx) != (yyvsp[-1].i)) 
    		err("wrong number of arguments in function call '%s'", get_name(fcall_idx));
    	else if (par_err != 0) 
				err("incompatible type for argument in '%s'", get_name(fcall_idx));
    		
    	code("\n\t\t\tCALL\t%s", get_name(fcall_idx));	
    						
			if (get_atr1(fcall_idx) > 0)
				code("\n\t\t\tADDS\t%%15,$%d,%%15", get_atr1(fcall_idx)*4);
    		
    	set_type(FUN_REG, get_type(fcall_idx));
      (yyval.i) = FUN_REG;
    }
#line 1838 "freud.tab.c"
    break;

  case 49:
#line 444 "freud.y"
                { (yyval.i) = 0; 
			arg_num = 0;}
#line 1845 "freud.tab.c"
    break;

  case 50:
#line 447 "freud.y"
                {	
			arg_num = 1;
			(yyval.i) = 1;
			if (get_param_type(fcall_idx, arg_num) != get_type((yyvsp[0].i))) par_err++;
			
			free_if_reg((yyvsp[0].i));
			code("\n\t\t\tPUSH\t");
			gen_sym_name((yyvsp[0].i));
					
		}
#line 1860 "freud.tab.c"
    break;

  case 51:
#line 459 "freud.y"
                {
			arg_num++;
			(yyval.i) = arg_num;
		//	warn("%d and %d", get_type($3), get_param_type(fcall_idx, arg_num));
			if (get_type((yyvsp[0].i)) != get_param_type(fcall_idx, arg_num))	par_err++;
		}
#line 1871 "freud.tab.c"
    break;

  case 52:
#line 469 "freud.y"
                {
			//Mora biti void
			int idx = fcall_idx;
			if (get_type(idx) != VOID) err("incorrect call of non-void function '%s'", get_name(idx));
		}
#line 1881 "freud.tab.c"
    break;

  case 53:
#line 478 "freud.y"
                {
			code("\n@exit%d:", (yyvsp[0].i));
		}
#line 1889 "freud.tab.c"
    break;

  case 54:
#line 482 "freud.y"
                {
			code("\n@exit%d:", (yyvsp[-2].i));
		}
#line 1897 "freud.tab.c"
    break;

  case 55:
#line 490 "freud.y"
                {
			(yyval.i) = ++lab_num;
			code("\n@if%d:", lab_num);
		}
#line 1906 "freud.tab.c"
    break;

  case 56:
#line 495 "freud.y"
                {
			code("\n\t\t%s\t@false%d", opp_jumps[(yyvsp[0].i)], (yyvsp[-1].i));
			code("\n@true%d:", (yyvsp[-1].i));
		}
#line 1915 "freud.tab.c"
    break;

  case 57:
#line 500 "freud.y"
                {
			code("\n\t\tJMP \t@exit%d", (yyvsp[-4].i));
      code("\n@false%d:", (yyvsp[-4].i));
      (yyval.i) = (yyvsp[-4].i);
		}
#line 1925 "freud.tab.c"
    break;

  case 58:
#line 509 "freud.y"
                {
			if (get_type((yyvsp[-2].i)) != get_type((yyvsp[0].i))) 
				err("invalid operands: relational operator");			

			(yyval.i) = (yyvsp[-1].i) + ((get_type((yyvsp[-2].i))-1)*RELOP_NUMBER);
			gen_cmp((yyvsp[-2].i), (yyvsp[0].i));	
			
		}
#line 1938 "freud.tab.c"
    break;

  case 59:
#line 521 "freud.y"
                {
			has_return++;
		
			if (get_type(fun_idx) == VOID) err("return statement found in void function");
			else if (get_type(fun_idx) != get_type((yyvsp[-1].i))) err("incompatible types in return");
			
			gen_mov((yyvsp[-1].i), FUN_REG);
			code("\n\t\tJMP \t@%s_exit", get_name(fun_idx));
		}
#line 1952 "freud.tab.c"
    break;

  case 60:
#line 531 "freud.y"
                {
			has_return++;
		
			if (get_type(fun_idx) != VOID) warn("missing return statement");
		}
#line 1962 "freud.tab.c"
    break;

  case 61:
#line 540 "freud.y"
                {
			int idx = lookup_symbol(get_name((yyvsp[-1].i)), GL);
			if (idx != NO_INDEX) {
				//Globalna prom
				if (get_type(idx)==INT)
					code("\n\t\tADDS\t");
				else code("\n\t\tADDU\t");
				code("%s,$1,%s", get_name(idx), get_name(idx));
			}	
			else {
			
				idx = lookup_symbol(get_name((yyvsp[-1].i)), VAR|PAR);
			
				if (get_type(idx)==INT)
					code("\n\t\tADDS\t");
				else code("\n\t\tADDU\t");
			
				free_if_reg((yyvsp[-1].i));
				(yyval.i) = take_reg();
			
				gen_sym_name(idx);
				code(",$1,");
				gen_sym_name(idx);
				set_type((yyval.i), get_type(idx));
			}
			
			is_postinc = 0;
		
		}
#line 1996 "freud.tab.c"
    break;

  case 62:
#line 573 "freud.y"
                {
      int idx = lookup_symbol((yyvsp[-1].s), VAR|PAR|GL);
			if (idx == NO_INDEX) err("invalid lvalue '%s'", (yyvsp[-1].s));
			(yyval.i) = idx;
			idx = take_reg();

    }
#line 2008 "freud.tab.c"
    break;

  case 63:
#line 584 "freud.y"
                {
			int para_idx = lookup_symbol((yyvsp[0].s), VAR|PAR|GL);
			if(para_idx != NO_INDEX) err("redefinition of '%s'", (yyvsp[0].s));
			else if ((yyvsp[-1].i) == VOID) err("invalid variable type in para");
			else insert_symbol((yyvsp[0].s), VAR, (yyvsp[-1].i), ++var_num, NO_ATR);
		}
#line 2019 "freud.tab.c"
    break;

  case 64:
#line 591 "freud.y"
                {
			if (get_type((yyvsp[-6].i)) != (yyvsp[-10].i)) err("assignment types not matching");
			if (lookup_symbol((yyvsp[-9].s), VAR) != lookup_symbol((yyvsp[-2].s), VAR)) err("para numerators not matching");
		}
#line 2028 "freud.tab.c"
    break;

  case 66:
#line 600 "freud.y"
                {
			sw_temp = lookup_symbol((yyvsp[-1].s), VAR|PAR|GL);
			if(sw_temp == NO_INDEX) err("variable '%s' in switch statement not found", (yyvsp[-1].s));
			case_int++;		//Brojac trenutnog switch-a po redu
		}
#line 2038 "freud.tab.c"
    break;

  case 72:
#line 620 "freud.y"
                {
			if (get_type((yyvsp[0].i)) != get_type(sw_temp)) err("invalid literal type in switch");
				else if (get_atr1((yyvsp[0].i)) == case_int) err("literal values must be unique");
					else set_atr1((yyvsp[0].i), case_int);
		}
#line 2048 "freud.tab.c"
    break;


#line 2052 "freud.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 634 "freud.y"


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


