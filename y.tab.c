/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     SUBPROG_CLAVE = 258,
     CABECERA_PROGRAMA = 259,
     TIPO_PRIM = 260,
     TIPO_LISTA = 261,
     NOMB_IF = 262,
     NOMB_THEN = 263,
     NOMB_ELSE = 264,
     NOMB_WHILE = 265,
     NOMB_FOR = 266,
     NOMB_ENTRADA = 267,
     NOMB_SALIDA = 268,
     LISTA_UNARIO_PREFIJO = 269,
     LISTA_UNARIO_POSTFIJO = 270,
     OP_TERN_PRIM_UN = 271,
     OP_TERN_SEG = 272,
     OP_UN_BIN = 273,
     OP_UNARIO = 274,
     OP_BINARIO_OR_LOG = 275,
     OP_BINARIO_AND_LOG = 276,
     OP_BINARIO_XOR = 277,
     OP_BINARIO_IG = 278,
     OP_BINARIO_COMP = 279,
     OP_BINARIO_MULT = 280,
     IDENTIFICADOR = 281,
     CADENA = 282,
     CONSTANTE = 283,
     PARIZQ = 284,
     PARDER = 285,
     CORIZQ = 286,
     CORDER = 287,
     LLAVIZQ = 288,
     LLAVDER = 289,
     COMA = 290,
     PYC = 291,
     ASIGN = 292,
     MARCA_INI_DECLAR_VARIABLES = 293,
     MARCA_FIN_DECLAR_VARIABLES = 294,
     OP_BINARIO_ASTAST = 295,
     OP_BINARIO_MENMEN = 296
   };
#endif
/* Tokens.  */
#define SUBPROG_CLAVE 258
#define CABECERA_PROGRAMA 259
#define TIPO_PRIM 260
#define TIPO_LISTA 261
#define NOMB_IF 262
#define NOMB_THEN 263
#define NOMB_ELSE 264
#define NOMB_WHILE 265
#define NOMB_FOR 266
#define NOMB_ENTRADA 267
#define NOMB_SALIDA 268
#define LISTA_UNARIO_PREFIJO 269
#define LISTA_UNARIO_POSTFIJO 270
#define OP_TERN_PRIM_UN 271
#define OP_TERN_SEG 272
#define OP_UN_BIN 273
#define OP_UNARIO 274
#define OP_BINARIO_OR_LOG 275
#define OP_BINARIO_AND_LOG 276
#define OP_BINARIO_XOR 277
#define OP_BINARIO_IG 278
#define OP_BINARIO_COMP 279
#define OP_BINARIO_MULT 280
#define IDENTIFICADOR 281
#define CADENA 282
#define CONSTANTE 283
#define PARIZQ 284
#define PARDER 285
#define CORIZQ 286
#define CORDER 287
#define LLAVIZQ 288
#define LLAVDER 289
#define COMA 290
#define PYC 291
#define ASIGN 292
#define MARCA_INI_DECLAR_VARIABLES 293
#define MARCA_FIN_DECLAR_VARIABLES 294
#define OP_BINARIO_ASTAST 295
#define OP_BINARIO_MENMEN 296




/* Copy the first part of user declarations.  */
#line 1 "pract.y"

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include "tabla_simb.c"
#include "traduccion.c"
#include "codigos.h"
#define YYERROR_VERBOSE

#define YYSTYPE atributos

int yylineno;
int fd;
char* nombProced;
int err;

int yylex();

int yyparse();

void yyerror(const char *str)
{
    err = 1;
    printf("(Línea %d) Error sintáctico: %s", yylineno, str);
}

int yywrap()
{
    return 1;
}

int main()
{
    if ((fd = open("generado.c", O_WRONLY | O_CREAT | O_TRUNC), S_IRWXU) < 0) {
        perror("Error en abrir archivo\n");
        exit(-1);
    }
    yyparse();
    close(fd);
}



/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 233 "y.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   350

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  34
/* YYNRULES -- Number of rules.  */
#define YYNRULES  79
/* YYNRULES -- Number of states.  */
#define YYNSTATES  148

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   296

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     6,     7,    14,    17,    18,    19,    23,
      27,    28,    29,    36,    38,    40,    43,    44,    49,    52,
      53,    55,    59,    61,    63,    67,    69,    70,    71,    76,
      78,    82,    84,    86,    89,    92,    93,    95,    97,    99,
     101,   103,   105,   107,   109,   111,   115,   119,   120,   127,
     132,   139,   148,   154,   163,   167,   171,   175,   179,   181,
     183,   184,   188,   191,   195,   199,   203,   207,   211,   215,
     219,   222,   226,   230,   234,   240,   242,   244,   246,   248
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      43,     0,    -1,     4,    44,    -1,    -1,    52,    45,    49,
      46,    62,    53,    -1,    46,    47,    -1,    -1,    -1,    50,
      48,    44,    -1,    38,    54,    39,    -1,    -1,    -1,     3,
      26,    51,    29,    55,    30,    -1,    33,    -1,    34,    -1,
      54,    58,    -1,    -1,    55,    35,    61,    26,    -1,    61,
      26,    -1,    -1,     1,    -1,    26,    35,    56,    -1,    26,
      -1,     1,    -1,    57,    35,    26,    -1,    26,    -1,    -1,
      -1,    61,    59,    60,    36,    -1,     1,    -1,    60,    35,
      26,    -1,    26,    -1,     5,    -1,     6,     5,    -1,    63,
      62,    -1,    -1,    44,    -1,    67,    -1,    68,    -1,    69,
      -1,    70,    -1,    71,    -1,    72,    -1,    65,    -1,    64,
      -1,    26,    15,    36,    -1,    14,    26,    36,    -1,    -1,
      26,    29,    66,    57,    30,    36,    -1,    26,    37,    74,
      36,    -1,     7,    29,    74,    30,     8,    63,    -1,     7,
      29,    74,    30,     8,    63,     9,    63,    -1,    10,    29,
      74,    30,    63,    -1,    11,    29,    67,    74,    36,    63,
      30,    63,    -1,    12,    56,    36,    -1,    13,    73,    36,
      -1,    74,    35,    73,    -1,    27,    35,    73,    -1,    74,
      -1,    27,    -1,    -1,    29,    74,    30,    -1,    19,    74,
      -1,    74,    25,    74,    -1,    74,    23,    74,    -1,    74,
      24,    74,    -1,    74,    21,    74,    -1,    74,    20,    74,
      -1,    74,    22,    74,    -1,    74,    40,    74,    -1,    18,
      74,    -1,    74,    18,    74,    -1,    74,    41,    74,    -1,
      74,    17,    74,    -1,    74,    16,    74,    17,    74,    -1,
      26,    -1,    28,    -1,    75,    -1,     1,    -1,    31,    73,
      32,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    86,    86,    96,    96,   118,   126,   134,   134,   145,
     148,   157,   156,   175,   178,   181,   192,   200,   214,   227,
     228,   231,   247,   262,   265,   283,   299,   302,   302,   315,
     318,   341,   364,   370,   381,   391,   399,   402,   405,   408,
     411,   414,   417,   420,   423,   428,   445,   458,   458,   481,
     503,   519,   540,   560,   580,   585,   590,   608,   618,   635,
     644,   647,   656,   714,   847,   862,   883,   898,   913,   928,
     951,   972,  1017,  1039,  1063,  1092,  1113,  1123,  1127,  1130
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "SUBPROG_CLAVE", "CABECERA_PROGRAMA",
  "TIPO_PRIM", "TIPO_LISTA", "NOMB_IF", "NOMB_THEN", "NOMB_ELSE",
  "NOMB_WHILE", "NOMB_FOR", "NOMB_ENTRADA", "NOMB_SALIDA",
  "LISTA_UNARIO_PREFIJO", "LISTA_UNARIO_POSTFIJO", "OP_TERN_PRIM_UN",
  "OP_TERN_SEG", "OP_UN_BIN", "OP_UNARIO", "OP_BINARIO_OR_LOG",
  "OP_BINARIO_AND_LOG", "OP_BINARIO_XOR", "OP_BINARIO_IG",
  "OP_BINARIO_COMP", "OP_BINARIO_MULT", "IDENTIFICADOR", "CADENA",
  "CONSTANTE", "PARIZQ", "PARDER", "CORIZQ", "CORDER", "LLAVIZQ",
  "LLAVDER", "COMA", "PYC", "ASIGN", "MARCA_INI_DECLAR_VARIABLES",
  "MARCA_FIN_DECLAR_VARIABLES", "OP_BINARIO_ASTAST", "OP_BINARIO_MENMEN",
  "$accept", "Programa", "bloque", "@1", "Declar_de_subprogs",
  "Declar_subprog", "@2", "Declar_de_variables_locales",
  "Cabecera_subprograma", "@3", "Inicio_de_bloque", "Fin_de_bloque",
  "Variables_locales", "lista_parametros", "lista_identificadores",
  "lista_argumentos", "Cuerpo_declar_variables", "@4",
  "declar_identificadores", "tipo", "Sentencias", "Sentencia",
  "lista_sent", "llamada_proced", "@5", "sentencia_asignacion",
  "sentencia_if", "sentencia_while", "sentencia_for", "sentencia_entrada",
  "sentencia_salida", "lista_expresiones_o_cadena", "expresion",
  "constante_lista", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    42,    43,    45,    44,    46,    46,    48,    47,    49,
      49,    51,    50,    52,    53,    54,    54,    55,    55,    55,
      55,    56,    56,    56,    57,    57,    57,    59,    58,    58,
      60,    60,    61,    61,    62,    62,    63,    63,    63,    63,
      63,    63,    63,    63,    63,    64,    64,    66,    65,    67,
      68,    68,    69,    70,    71,    72,    73,    73,    73,    73,
      73,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    75
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     0,     6,     2,     0,     0,     3,     3,
       0,     0,     6,     1,     1,     2,     0,     4,     2,     0,
       1,     3,     1,     1,     3,     1,     0,     0,     4,     1,
       3,     1,     1,     2,     2,     0,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     3,     0,     6,     4,
       6,     8,     5,     8,     3,     3,     3,     3,     1,     1,
       0,     3,     2,     3,     3,     3,     3,     3,     3,     3,
       2,     3,     3,     3,     5,     1,     1,     1,     1,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,    13,     2,     3,     1,    10,    16,     6,
       0,    35,    29,    32,     0,     9,    15,    27,     0,     0,
       0,     0,     0,     0,     0,     0,    36,     5,     7,     0,
      35,    44,    43,    37,    38,    39,    40,    41,    42,    33,
       0,    11,     0,     0,     0,    23,    22,     0,    78,     0,
       0,    75,    59,    76,     0,     0,     0,    58,    77,     0,
       0,    47,     0,     0,    14,     4,    34,    31,     0,     0,
       0,     0,     0,     0,     0,    54,    70,    62,     0,     0,
       0,    55,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    46,    45,    26,     0,     8,     0,
      28,     0,     0,     0,     0,    21,    57,    61,    79,     0,
      73,    71,    67,    66,    68,    64,    65,    63,    56,    69,
      72,    25,     0,    49,    30,    20,     0,     0,     0,    52,
       0,     0,     0,     0,    12,     0,    18,    50,     0,    74,
      48,    24,     0,     0,     0,    17,    51,    53
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,    26,     7,    11,    27,    63,     9,    28,    69,
       5,    65,    10,   126,    47,   122,    16,    40,    68,    17,
      29,    30,    31,    32,    96,    33,    34,    35,    36,    37,
      38,    56,    57,    58
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -98
static const yytype_int16 yypact[] =
{
       2,   -23,    13,   -98,   -98,   -98,   -98,   -17,   -98,   -98,
      10,   104,   -98,   -98,    20,   -98,   -98,   -98,     3,     7,
       8,    26,     4,    68,    33,    45,   -98,   -98,   -98,    32,
     132,   -98,   -98,   -98,   -98,   -98,   -98,   -98,   -98,   -98,
      35,   -98,   107,   107,    37,   -98,    38,    36,   -98,   107,
     107,   -98,    41,   -98,   107,    74,    49,   131,   -98,    54,
      55,   -98,   107,   -23,   -98,   -98,   -98,   -98,   -12,    48,
     157,   183,    61,   107,     4,   -98,    93,    93,    52,   209,
      78,   -98,   107,   107,   107,   107,   107,   107,   107,   107,
     107,    52,   107,   107,   -98,   -98,    86,   220,   -98,    87,
     -98,    27,   111,   132,   246,   -98,   -98,   -98,   -98,   256,
     282,    -7,   170,   292,   144,   295,   309,    93,   -98,   116,
      40,   -98,   -16,   -98,   -98,   -98,   -13,    94,   132,   -98,
     132,   107,    85,    96,   -98,    29,   -98,   114,    97,   282,
     -98,   -98,    98,   132,   132,   -98,   -98,   -98
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -98,   -98,     1,   -98,   -98,   -98,   -98,   -98,   -98,   -98,
     -98,   -98,   -98,   -98,    57,   -98,   -98,   -98,   -98,   -97,
      99,   -76,   -98,   -98,   -98,    84,   -98,   -98,   -98,   -98,
     -98,   -52,   -42,   -98
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -61
static const yytype_int16 yytable[] =
{
      70,    71,     4,    80,   127,    45,     1,    76,    77,    82,
       3,    12,    79,     6,   132,    13,    14,   134,    90,   133,
      97,     8,   135,    99,   100,    39,   106,   129,   125,    41,
      46,   104,    13,    14,    13,    14,    42,    43,   142,   118,
     109,   110,   111,   112,   113,   114,   115,   116,   117,    15,
     119,   120,   137,    48,   138,    44,    82,   -19,    84,    59,
      60,    67,   -19,    72,    98,    90,    64,   146,   147,    48,
      49,    50,    75,    74,    61,    48,    78,   101,    51,    52,
      53,    54,    62,    55,   -60,    81,    49,    50,   -60,   139,
      94,    95,    49,    50,    51,    52,    53,    54,    62,    55,
      51,    52,    53,    54,   -60,    55,   -60,    18,    48,    82,
     108,    19,   121,   124,    20,    21,    22,    23,    24,   128,
     136,   140,   141,   143,   145,    49,    50,   144,    73,    66,
      25,   105,    82,    51,    84,    53,    54,     3,    55,    19,
       0,    90,    20,    21,    22,    23,    24,    82,    83,    84,
       0,    85,    86,    87,    88,    89,    90,    93,    25,     0,
      82,     0,    84,     0,     0,     3,    91,    88,    89,    90,
       0,    92,    93,    82,    83,    84,     0,    85,    86,    87,
      88,    89,    90,     0,    92,    93,    82,   102,    84,     0,
       0,    86,    87,    88,    89,    90,     0,    92,    93,    82,
      83,    84,     0,    85,    86,    87,    88,    89,    90,     0,
      92,    93,     0,   103,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    92,    93,    82,    83,    84,     0,    85,
      86,    87,    88,    89,    90,     0,    82,    83,    84,   107,
      85,    86,    87,    88,    89,    90,     0,     0,     0,    92,
      93,     0,     0,     0,     0,     0,   123,     0,     0,     0,
      92,    93,    82,    83,    84,     0,    85,    86,    87,    88,
      89,    90,    82,   131,    84,     0,    85,    86,    87,    88,
      89,    90,   130,     0,     0,     0,    92,    93,     0,     0,
       0,     0,     0,     0,     0,     0,    92,    93,    82,    83,
      84,     0,    85,    86,    87,    88,    89,    90,    82,     0,
      84,    82,     0,    84,    87,    88,    89,    90,     0,    89,
      90,     0,    92,    93,     0,    82,     0,    84,     0,     0,
       0,     0,    92,    93,    90,    92,    93,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    92,
      93
};

static const yytype_int16 yycheck[] =
{
      42,    43,     1,    55,   101,     1,     4,    49,    50,    16,
      33,     1,    54,     0,    30,     5,     6,    30,    25,    35,
      62,    38,    35,    35,    36,     5,    78,   103,     1,    26,
      26,    73,     5,     6,     5,     6,    29,    29,   135,    91,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    39,
      92,    93,   128,     1,   130,    29,    16,    30,    18,    26,
      15,    26,    35,    26,    63,    25,    34,   143,   144,     1,
      18,    19,    36,    35,    29,     1,    35,    29,    26,    27,
      28,    29,    37,    31,    32,    36,    18,    19,    36,   131,
      36,    36,    18,    19,    26,    27,    28,    29,    37,    31,
      26,    27,    28,    29,    36,    31,    32,     3,     1,    16,
      32,     7,    26,    26,    10,    11,    12,    13,    14,     8,
      26,    36,    26,     9,    26,    18,    19,    30,    44,    30,
      26,    74,    16,    26,    18,    28,    29,    33,    31,     7,
      -1,    25,    10,    11,    12,    13,    14,    16,    17,    18,
      -1,    20,    21,    22,    23,    24,    25,    41,    26,    -1,
      16,    -1,    18,    -1,    -1,    33,    35,    23,    24,    25,
      -1,    40,    41,    16,    17,    18,    -1,    20,    21,    22,
      23,    24,    25,    -1,    40,    41,    16,    30,    18,    -1,
      -1,    21,    22,    23,    24,    25,    -1,    40,    41,    16,
      17,    18,    -1,    20,    21,    22,    23,    24,    25,    -1,
      40,    41,    -1,    30,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    40,    41,    16,    17,    18,    -1,    20,
      21,    22,    23,    24,    25,    -1,    16,    17,    18,    30,
      20,    21,    22,    23,    24,    25,    -1,    -1,    -1,    40,
      41,    -1,    -1,    -1,    -1,    -1,    36,    -1,    -1,    -1,
      40,    41,    16,    17,    18,    -1,    20,    21,    22,    23,
      24,    25,    16,    17,    18,    -1,    20,    21,    22,    23,
      24,    25,    36,    -1,    -1,    -1,    40,    41,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    40,    41,    16,    17,
      18,    -1,    20,    21,    22,    23,    24,    25,    16,    -1,
      18,    16,    -1,    18,    22,    23,    24,    25,    -1,    24,
      25,    -1,    40,    41,    -1,    16,    -1,    18,    -1,    -1,
      -1,    -1,    40,    41,    25,    40,    41,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    40,
      41
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     4,    43,    33,    44,    52,     0,    45,    38,    49,
      54,    46,     1,     5,     6,    39,    58,    61,     3,     7,
      10,    11,    12,    13,    14,    26,    44,    47,    50,    62,
      63,    64,    65,    67,    68,    69,    70,    71,    72,     5,
      59,    26,    29,    29,    29,     1,    26,    56,     1,    18,
      19,    26,    27,    28,    29,    31,    73,    74,    75,    26,
      15,    29,    37,    48,    34,    53,    62,    26,    60,    51,
      74,    74,    26,    67,    35,    36,    74,    74,    35,    74,
      73,    36,    16,    17,    18,    20,    21,    22,    23,    24,
      25,    35,    40,    41,    36,    36,    66,    74,    44,    35,
      36,    29,    30,    30,    74,    56,    73,    30,    32,    74,
      74,    74,    74,    74,    74,    74,    74,    74,    73,    74,
      74,    26,    57,    36,    26,     1,    55,    61,     8,    63,
      36,    17,    30,    35,    30,    35,    26,    63,    63,    74,
      36,    26,    61,     9,    30,    26,    63,    63
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
	    /* Fall through.  */
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

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

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
#line 86 "pract.y"
    {
                if (err == 0) {
                (yyval).codigo = malloc(sizeof(char) * (strlen((yyvsp[(2) - (2)]).codigo) + 50));
                sprintf((yyval).codigo, PROGRAMA_ESQ, (yyvsp[(2) - (2)]).codigo);
                escribir(fd, (yyval).codigo);
                }
                if (close(fd) < 0)
                    perror("Error en cerrar\n");
            }
    break;

  case 3:
#line 96 "pract.y"
    { 
                TS_InsertaMARCA(); 
                if (Subprog == 1) {
                    TS_CopiarParams();
                }
            }
    break;

  case 4:
#line 105 "pract.y"
    { 
                TS_QuitarHastaMarca();

                if (!err) {
                (yyval).codigo = malloc(sizeof(char) * (strlen((yyvsp[(3) - (6)]).codigo) + strlen((yyvsp[(4) - (6)]).codigo) + strlen((yyvsp[(5) - (6)]).codigo) + 10));
                sprintf((yyval).codigo, BLOQUE_ESQ, (yyvsp[(3) - (6)]).codigo, (yyvsp[(4) - (6)]).codigo, (yyvsp[(5) - (6)]).codigo);
                free((yyvsp[(3) - (6)]).codigo);
                free((yyvsp[(4) - (6)]).codigo);
                free((yyvsp[(5) - (6)]).codigo);
                }
            }
    break;

  case 5:
#line 118 "pract.y"
    {
                        if (!err) {
                        (yyval).codigo = malloc(sizeof(char) * (strlen((yyvsp[(1) - (2)]).codigo) + strlen((yyvsp[(2) - (2)]).codigo) + 3));
                        sprintf((yyval).codigo, "%s\n\n%s", (yyvsp[(1) - (2)]).codigo, (yyvsp[(2) - (2)]).codigo);
                        free((yyvsp[(1) - (2)]).codigo);
                        free((yyvsp[(2) - (2)]).codigo);
                        }
                    }
    break;

  case 6:
#line 126 "pract.y"
    {
                        if (!err) {
                        (yyval).codigo = malloc(sizeof(char));
                        *(yyval).codigo = 0;
                        }
                    }
    break;

  case 7:
#line 134 "pract.y"
    { Subprog = 1; }
    break;

  case 8:
#line 135 "pract.y"
    { Subprog = 0; 
                        if (!err) {
                        (yyval).codigo = malloc(sizeof(char) * (strlen((yyvsp[(1) - (3)]).codigo) + strlen((yyvsp[(3) - (3)]).codigo) + 2));
                        sprintf((yyval).codigo, "%s\n%s", (yyvsp[(1) - (3)]).codigo, (yyvsp[(3) - (3)]).codigo);
                        free((yyvsp[(1) - (3)]).codigo);
                        free((yyvsp[(3) - (3)]).codigo);
                        }
                    }
    break;

  case 9:
#line 145 "pract.y"
    {
                                    if (!err) (yyval).codigo = (yyvsp[(2) - (3)]).codigo;
                                }
    break;

  case 10:
#line 148 "pract.y"
    {
                                    if (!err) {
                                    (yyval).codigo = malloc(2 * sizeof(char));
                                    *(yyval).codigo = 0;
                                    }
                                }
    break;

  case 11:
#line 157 "pract.y"
    {
                            (yyvsp[(2) - (2)]).codigo = procnuevo();
                            TS_InsertaSUBPROG((yyvsp[(2) - (2)]));
                        }
    break;

  case 12:
#line 163 "pract.y"
    {
                            TS_AsignarParams((yyvsp[(2) - (6)]).lexema, (yyvsp[(5) - (6)]).parametros);

                            if (!err) {
                            (yyval).codigo = malloc(sizeof(char) * (strlen((yyvsp[(2) - (6)]).codigo) + strlen((yyvsp[(5) - (6)]).codigo) + 10));
                            sprintf((yyval).codigo, PROCED_ESQ, (yyvsp[(2) - (6)]).codigo, (yyvsp[(5) - (6)]).codigo);
                            free((yyvsp[(2) - (6)]).codigo);
                            free((yyvsp[(5) - (6)]).codigo);
                            }
                        }
    break;

  case 15:
#line 181 "pract.y"
    {
                            if (!err) {
                            if (*(yyvsp[(1) - (2)]).codigo == '\0') (yyval).codigo = (yyvsp[(2) - (2)]).codigo;
                            else {
                                (yyval).codigo = malloc(sizeof(char) * (2 + strlen((yyvsp[(1) - (2)]).codigo) + strlen((yyvsp[(2) - (2)]).codigo)));
                                sprintf((yyval).codigo, "%s\n%s", (yyvsp[(1) - (2)]).codigo, (yyvsp[(2) - (2)]).codigo);
                                free((yyvsp[(2) - (2)]).codigo);
                            }
                            free((yyvsp[(1) - (2)]).codigo);
                            }
                        }
    break;

  case 16:
#line 192 "pract.y"
    {
                        if (!err) {
                        (yyval).codigo = malloc(2 * sizeof(char));
                        *(yyval).codigo = '\0';
                        }
                    }
    break;

  case 17:
#line 200 "pract.y"
    {
                        (yyval).parametros = (yyvsp[(1) - (4)]).parametros + 1;
                        (yyvsp[(4) - (4)]).tipo = (yyvsp[(3) - (4)]).tipo;
                        (yyvsp[(4) - (4)]).codigo = paramnuevo();
                        TS_InsertaPARAMF((yyvsp[(4) - (4)]));

                        if (!err) {
                        (yyval).codigo = malloc(sizeof(char) * (strlen((yyvsp[(1) - (4)]).codigo) + strlen((yyvsp[(3) - (4)]).codigo) + strlen((yyvsp[(4) - (4)]).codigo) + 4));
                        sprintf((yyval).codigo, "%s, %s %s", (yyvsp[(1) - (4)]).codigo, (yyvsp[(3) - (4)]).codigo, (yyvsp[(4) - (4)]).codigo);
                        free((yyvsp[(1) - (4)]).codigo);
                        free((yyvsp[(3) - (4)]).codigo);
                        free((yyvsp[(4) - (4)]).codigo);
                        }
                    }
    break;

  case 18:
#line 214 "pract.y"
    {
                        (yyval).parametros = 1;
                        (yyvsp[(2) - (2)]).tipo = (yyvsp[(1) - (2)]).tipo;
                        (yyvsp[(2) - (2)]).codigo = paramnuevo();
                        TS_InsertaPARAMF((yyvsp[(2) - (2)]));

                        if (!err) {
                        (yyval).codigo = malloc(sizeof(char) * (strlen((yyvsp[(1) - (2)]).codigo) + strlen((yyvsp[(2) - (2)]).codigo) + 2));
                        sprintf((yyval).codigo, "%s %s", (yyvsp[(1) - (2)]).codigo, (yyvsp[(2) - (2)]).codigo);
                        free((yyvsp[(1) - (2)]).codigo);
                        free((yyvsp[(2) - (2)]).codigo);
                        }
                    }
    break;

  case 21:
#line 231 "pract.y"
    {
                            int n = TS_RecogerEntrada((yyvsp[(1) - (3)]).lexema);
                            if (n == -1) {
                                printf("(Línea %d) Error semántico: identificador %s no declarado\n", yylineno, (yyvsp[(1) - (3)]).lexema);                           
                                err = 1;
                            }

                            if (!err) {
                            char* id = TS[n].alias;
                            char* formato = getCadenaFormato(TS[n].tipoDato);
                            (yyval).codigo = malloc(sizeof(char) * (strlen((yyvsp[(3) - (3)]).codigo) + strlen(formato) + strlen(id) + 20));
                            sprintf((yyval).codigo, ENTRADAS_ESQ, formato, id, (yyvsp[(3) - (3)]).codigo);
                            free((yyvsp[(3) - (3)]).codigo);
                            free(formato); 
                            }
                        }
    break;

  case 22:
#line 247 "pract.y"
    {
                            int n = TS_RecogerEntrada((yyvsp[(1) - (1)]).lexema);
                            if (n == -1) {
                                printf("(Línea %d) Error semántico: identificador %s no declarado\n", yylineno, (yyvsp[(1) - (1)]).lexema);                           
                                err = 1;
                            }

                            if (!err) {
                            char* id = TS[n].alias;
                            char* formato = getCadenaFormato(TS[n].tipoDato);
                            (yyval).codigo = malloc(sizeof(char) * (strlen(formato) + strlen(id) + 20));
                            sprintf((yyval).codigo, ENTRADA_ESQ, formato, id);
                            free(formato);
                            }
                        }
    break;

  case 24:
#line 265 "pract.y"
    {
                            (yyval).parametros = (yyvsp[(1) - (3)]).parametros + 1;
                            (yyvsp[(3) - (3)]).parametros = (yyvsp[(1) - (3)]).parametros + 1;
                            int n = TS_RecogerEntrada((yyvsp[(3) - (3)]).lexema);
                            if (TS_ComprobarTipoParamf(nombProced, (yyvsp[(3) - (3)]).parametros, TS[n].tipoDato) == 0) {
                                printf("(Línea %d) Error semántico: argumento %d a procedimiento %s tiene tipo incorrecto\n", yylineno, (yyvsp[(3) - (3)]).parametros, (yyvsp[(3) - (3)]).lexema);
                                err = 1;
                            }

                            if (!err) {
                            char* id = TS[n].alias;
                            (yyvsp[(3) - (3)]).codigo = id;
                            (yyval).codigo = malloc(sizeof(char) * (strlen((yyvsp[(1) - (3)]).codigo) + strlen((yyvsp[(3) - (3)]).codigo) + 4));
                            sprintf((yyval).codigo, "%s, &%s", (yyvsp[(1) - (3)]).codigo, (yyvsp[(3) - (3)]).codigo);
                            free((yyvsp[(1) - (3)]).codigo);
                            // free($3.codigo);
                            }
                        }
    break;

  case 25:
#line 283 "pract.y"
    {
                            (yyval).parametros = 1;
                            (yyvsp[(1) - (1)]).parametros = 1;
                            int n = TS_RecogerEntrada((yyvsp[(1) - (1)]).lexema);
                            if (TS_ComprobarTipoParamf(nombProced, (yyvsp[(1) - (1)]).parametros, TS[n].tipoDato) == 0) {
                                printf("(Línea %d) Error semántico: argumento %d a procedimiento %s tiene tipo incorrecto\n", yylineno, (yyvsp[(1) - (1)]).parametros, (yyvsp[(1) - (1)]).lexema);
                                err = 1;
                            }
                            
                            if (!err) {
                            char* id = TS[n].alias;
                            (yyvsp[(1) - (1)]).codigo = id;
                            (yyval).codigo = malloc(sizeof(char) * (strlen((yyvsp[(1) - (1)]).codigo) + 2));
                            sprintf((yyval).codigo, "&%s", (yyvsp[(1) - (1)]).codigo);
                            }
                        }
    break;

  case 27:
#line 302 "pract.y"
    {
                                tipoTmp = (yyvsp[(1) - (1)]).tipo;
                                esListaTmp = (yyvsp[(1) - (1)]).esLista;
                            }
    break;

  case 28:
#line 307 "pract.y"
    {
                                if (!err) {
                                (yyval).codigo = malloc(sizeof(char) * (strlen((yyvsp[(1) - (4)]).codigo) + strlen((yyvsp[(3) - (4)]).codigo) + 3));
                                sprintf((yyval).codigo, "%s %s;", (yyvsp[(1) - (4)]).codigo, (yyvsp[(3) - (4)]).codigo);
                                free((yyvsp[(1) - (4)]).codigo);
                                free((yyvsp[(3) - (4)]).codigo);
                                }
                            }
    break;

  case 30:
#line 318 "pract.y"
    {
                                (yyvsp[(3) - (3)]).tipo = tipoTmp;
                                (yyvsp[(3) - (3)]).esLista = esListaTmp;
                                (yyvsp[(3) - (3)]).codigo = strdup(varnuevo());
                                if (TS_InsertaIDENT((yyvsp[(3) - (3)])) == 1) {
                                    printf("(Línea %d) Error semántico: variable local %s duplicado\n", yylineno, (yyvsp[(3) - (3)]).lexema);
                                    err = 1;
                                }
                                
                                if (!err) {
                                if (esListaTmp) {
                                    char* tipo = getTipoNombre((yyvsp[(3) - (3)]).tipo);
                                    (yyval).codigo = malloc(sizeof(char) * (strlen((yyvsp[(1) - (3)]).codigo) + strlen((yyvsp[(3) - (3)]).codigo) + strlen(tipo) + 20));
                                    sprintf((yyval).codigo, DECLARLISTAS_ESQ, (yyvsp[(1) - (3)]).codigo, (yyvsp[(3) - (3)]).codigo, tipo);
                                    free(tipo);
                                } else { 
                                    (yyval).codigo = malloc(sizeof(char) * (strlen((yyvsp[(1) - (3)]).codigo) + 2 + strlen((yyvsp[(3) - (3)]).codigo)));
                                    sprintf((yyval).codigo, "%s,%s", (yyvsp[(1) - (3)]).codigo, (yyvsp[(3) - (3)]).codigo);
                                }
                                free((yyvsp[(1) - (3)]).codigo);
                                free((yyvsp[(3) - (3)]).codigo);
                                }
                            }
    break;

  case 31:
#line 341 "pract.y"
    {
                                (yyvsp[(1) - (1)]).tipo = tipoTmp;
                                (yyvsp[(1) - (1)]).esLista = esListaTmp;
                                (yyvsp[(1) - (1)]).codigo = strdup(varnuevo());
                                if (TS_InsertaIDENT((yyvsp[(1) - (1)])) == 1) {
                                    printf("(Línea %d) Error semántico: variable local %s duplicado\n", yylineno, (yyvsp[(1) - (1)]).lexema);
                                    err = 1;
                                }
                                
                                if (!err) { 
                                if (esListaTmp) {
                                    char* tipo = getTipoNombre((yyvsp[(1) - (1)]).tipo);
                                    (yyval).codigo = malloc(sizeof(char) * (strlen((yyvsp[(1) - (1)]).codigo) + strlen(tipo) + 20));
                                    sprintf((yyval).codigo, DECLARLISTA_ESQ, (yyvsp[(1) - (1)]).codigo, tipo);
                                    free(tipo);
                                    free((yyvsp[(1) - (1)]).codigo);
                                } else { 
                                   (yyval).codigo = (yyvsp[(1) - (1)]).codigo;
                                }
                                }
                            }
    break;

  case 32:
#line 364 "pract.y"
    { 
            (yyval).tipo = (yyvsp[(1) - (1)]).tipo; 
            (yyval).esLista = 0;

            if (!err) (yyval).codigo = (yyvsp[(1) - (1)]).codigo;
        }
    break;

  case 33:
#line 370 "pract.y"
    { 
            (yyval).tipo = (yyvsp[(2) - (2)]).tipo; 
            (yyval).esLista = 1;

            if (!err) {
            (yyval).codigo = malloc(sizeof(char) * 9);
            sprintf((yyval).codigo, "lgestor");
            }
        }
    break;

  case 34:
#line 381 "pract.y"
    {
                    if (!err) {
                    if (*(yyvsp[(2) - (2)]).codigo == 0) {
                        (yyval).codigo = (yyvsp[(1) - (2)]).codigo;
                    } else {
                        (yyval).codigo = malloc(sizeof(char) * (strlen((yyvsp[(1) - (2)]).codigo) + strlen((yyvsp[(2) - (2)]).codigo) + 3));
                        sprintf((yyval).codigo, "%s\n%s", (yyvsp[(1) - (2)]).codigo, (yyvsp[(2) - (2)]).codigo);
                    }
                    }
                }
    break;

  case 35:
#line 391 "pract.y"
    {
                if (!err) {
                (yyval).codigo = malloc(sizeof(char));
                *(yyval).codigo = '\0';
                }
            }
    break;

  case 36:
#line 399 "pract.y"
    {
                if (!err) (yyval).codigo = (yyvsp[(1) - (1)]).codigo;
            }
    break;

  case 37:
#line 402 "pract.y"
    {
                if (!err) (yyval).codigo = (yyvsp[(1) - (1)]).codigo;
            }
    break;

  case 38:
#line 405 "pract.y"
    {
                if (!err) (yyval).codigo = (yyvsp[(1) - (1)]).codigo;
            }
    break;

  case 39:
#line 408 "pract.y"
    {
                if (!err) (yyval).codigo = (yyvsp[(1) - (1)]).codigo;
            }
    break;

  case 40:
#line 411 "pract.y"
    {
                if (!err) (yyval).codigo = (yyvsp[(1) - (1)]).codigo;
            }
    break;

  case 41:
#line 414 "pract.y"
    {
                if (!err) (yyval).codigo = (yyvsp[(1) - (1)]).codigo;
            }
    break;

  case 42:
#line 417 "pract.y"
    {
                if (!err) (yyval).codigo = (yyvsp[(1) - (1)]).codigo;
            }
    break;

  case 43:
#line 420 "pract.y"
    {
                if (!err) (yyval).codigo = (yyvsp[(1) - (1)]).codigo;
            }
    break;

  case 44:
#line 423 "pract.y"
    {
                if (!err) (yyval).codigo = (yyvsp[(1) - (1)]).codigo;
            }
    break;

  case 45:
#line 428 "pract.y"
    {
                    if ((yyvsp[(1) - (3)]).esLista != 1) {
                        printf("(Línea %d) Error semántico: intento de realizar operación de listas en algo que no sea lista\n", yylineno);
                        err = 1;
                    }

                    if (!err) {
                    int n = TS_RecogerEntrada((yyvsp[(1) - (3)]).lexema);
                    char* nomb = TS[n].alias;
                    (yyval).codigo = malloc(sizeof(char) * (strlen(nomb) + 25));
                    if ((yyvsp[(2) - (3)]).atrib == OPLISTA_IZQ)
                        sprintf((yyval).codigo, "retroceder_puntero(%s);", nomb);
                    if ((yyvsp[(2) - (3)]).atrib == OPLISTA_DER) {
                        sprintf((yyval).codigo, "avanzar_puntero(%s);", nomb);
                    }
                    }
                }
    break;

  case 46:
#line 445 "pract.y"
    {
                    if ((yyvsp[(2) - (3)]).esLista != 1) {
                        printf("(Línea %d) Error semántico: intento de realizar operación de listas en algo que no sea lista\n", yylineno);
                        err = 1;
                    }

                    if (!err) {
                    (yyval).codigo = malloc(sizeof(char) * (strlen((yyvsp[(2) - (3)]).tmp) + 25));
                    sprintf((yyval).codigo, "comienzo_puntero(%s);", (yyvsp[(2) - (3)]).tmp);
                    }
                }
    break;

  case 47:
#line 458 "pract.y"
    {nombProced = (yyvsp[(1) - (2)]).lexema;}
    break;

  case 48:
#line 458 "pract.y"
    {
                        int n = TS_RecogerProced((yyvsp[(1) - (6)]).lexema);
                        if (n == -1) {
                            printf("(Línea %d) Error semántico: llamada a procedimiento que no existe\n", yylineno);
                            err = 1;
                        } else {
                            unsigned int params = TS[n].parametros;
                            if (params != (yyvsp[(4) - (6)]).parametros) {
                                printf("(Línea %d) Error semántico: procedimiento espera %d argumentos\n", yylineno, params);
                                err = 1;
                            }
                        }
                        (yyvsp[(4) - (6)]).lexema = (yyvsp[(1) - (6)]).lexema;

                        if (!err) {
                        char* handle = TS[n].alias;
                        (yyval).codigo = malloc(sizeof(char) * (4 + strlen(handle) + strlen((yyvsp[(4) - (6)]).codigo)));
                        sprintf((yyval).codigo, "%s(%s);", handle, (yyvsp[(4) - (6)]).codigo);
                        free((yyvsp[(4) - (6)]).codigo); 
                        }
                    }
    break;

  case 49:
#line 481 "pract.y"
    {
                                int indice = TS_RecogerEntrada((yyvsp[(1) - (4)]).lexema);
                                if (indice == -1) {
                                    printf("(Línea %d) Error semántico: variable %s no ha sido declarado\n", yylineno, (yyvsp[(1) - (4)]).lexema);
                                    err = 1;
                                }
                                if (TS[indice].tipoDato != (yyvsp[(3) - (4)]).tipo) {
                                    printf("(Línea %d) Error semántico: intento de asignar un variable a un valor de tipo distinto\n", yylineno);
                                    err = 1;
                                }

                                if (!err) {
                                int n = TS_RecogerEntrada((yyvsp[(1) - (4)]).lexema);
                                char* id = TS[n].alias;
                                (yyval).codigo = malloc(sizeof(char) * (strlen((yyvsp[(3) - (4)]).codigo) + strlen(id) + strlen((yyvsp[(3) - (4)]).tmp) + 6));
                                sprintf((yyval).codigo, ASIGN_ESQ, (yyvsp[(3) - (4)]).codigo, id, (yyvsp[(3) - (4)]).tmp);
                                free((yyvsp[(3) - (4)]).tmp);
                                free((yyvsp[(3) - (4)]).codigo);
                                }
                            }
    break;

  case 50:
#line 503 "pract.y"
    {
                    if ((yyvsp[(3) - (6)]).tipo != booleano) {
                            printf("(Línea %d) Error semántico: intento de usar condición no booleano en condicional\n", yylineno);
                            err = 1;
                    }

                    if (!err) {
                    char* etiq = etiqnuevo();
                    (yyval).codigo = malloc(sizeof(char) * (strlen((yyvsp[(3) - (6)]).codigo) + strlen((yyvsp[(3) - (6)]).tmp) + 2*strlen(etiq) + strlen((yyvsp[(6) - (6)]).codigo) + 20));
                    sprintf((yyval).codigo, IF_ESQ, (yyvsp[(3) - (6)]).codigo, (yyvsp[(3) - (6)]).tmp, etiq, (yyvsp[(6) - (6)]).codigo, etiq);
                    free(etiq);
                    free((yyvsp[(3) - (6)]).codigo);
                    free((yyvsp[(3) - (6)]).tmp);
                    free((yyvsp[(6) - (6)]).codigo);
                    }
                }
    break;

  case 51:
#line 519 "pract.y"
    {
                    if ((yyvsp[(3) - (8)]).tipo != booleano) {
                            printf("(Línea %d) Error semántico: intento de usar condición no booleano en condicional\n", yylineno);
                            err = 1;
                    }

                    if (!err) {
                    char* etiq1 = etiqnuevo();
                    char* etiq2 = etiqnuevo();
                    (yyval).codigo = malloc(sizeof(char) * (strlen((yyvsp[(3) - (8)]).codigo) + strlen((yyvsp[(3) - (8)]).tmp) + 2*strlen(etiq1) + 2*strlen(etiq1) + strlen((yyvsp[(6) - (8)]).codigo) + strlen((yyvsp[(8) - (8)]).codigo) + 50));
                    sprintf((yyval).codigo, IFELSE_ESQ, (yyvsp[(3) - (8)]).codigo, (yyvsp[(3) - (8)]).tmp, etiq1, (yyvsp[(6) - (8)]).codigo, etiq2, etiq1, (yyvsp[(8) - (8)]).codigo, etiq2);
                    free(etiq1);
                    free(etiq2);
                    free((yyvsp[(3) - (8)]).codigo);
                    free((yyvsp[(3) - (8)]).tmp);
                    free((yyvsp[(6) - (8)]).codigo);
                    free((yyvsp[(8) - (8)]).codigo);
                    }
                }
    break;

  case 52:
#line 540 "pract.y"
    {
                        if ((yyvsp[(3) - (5)]).tipo != booleano) {
                            printf("(Línea %d) Error semántico: intento de usar condición de fin de bucle no booleano\n", yylineno);
                            err = 1;
                        }

                        if (!err) {
                        char* etiq1 = etiqnuevo();
                        char* etiq2 = etiqnuevo();
                        (yyval).codigo = malloc(sizeof(char) * (strlen(etiq1) + 2*strlen(etiq2) + strlen((yyvsp[(3) - (5)]).codigo) + strlen((yyvsp[(3) - (5)]).tmp) + strlen((yyvsp[(5) - (5)]).codigo) + 35));
                        sprintf((yyval).codigo, WHILE_ESQ, etiq1, (yyvsp[(3) - (5)]).codigo, (yyvsp[(3) - (5)]).tmp, etiq2, (yyvsp[(5) - (5)]).codigo, etiq1, etiq2);
                        free(etiq1);
                        free(etiq2);
                        free((yyvsp[(3) - (5)]).codigo);
                        free((yyvsp[(3) - (5)]).tmp);
                        free((yyvsp[(5) - (5)]).codigo);
                        }
                    }
    break;

  case 53:
#line 560 "pract.y"
    {
                        if ((yyvsp[(4) - (8)]).tipo != booleano) {
                            printf("(Línea %d) Error semántico: intento de usar condición de fin de bucle no booleano\n", yylineno);
                            err = 1;
                        }

                        if (!err) {
                        char* etiq1 = etiqnuevo();
                        char* etiq2 = etiqnuevo();
                        (yyval).codigo = malloc(sizeof(char) * (strlen((yyvsp[(3) - (8)]).codigo) + 2*strlen(etiq1) + 2*strlen(etiq2) + strlen((yyvsp[(4) - (8)]).codigo) + strlen((yyvsp[(4) - (8)]).tmp) + strlen((yyvsp[(8) - (8)]).codigo) + strlen((yyvsp[(6) - (8)]).codigo) + 40));
                        sprintf((yyval).codigo, FOR_ESQ, (yyvsp[(3) - (8)]).codigo, etiq1, (yyvsp[(4) - (8)]).codigo, (yyvsp[(4) - (8)]).tmp, etiq2, (yyvsp[(8) - (8)]).codigo, (yyvsp[(6) - (8)]).codigo, etiq1, etiq2);
                        free((yyvsp[(3) - (8)]).codigo);
                        free((yyvsp[(4) - (8)]).codigo);
                        free((yyvsp[(4) - (8)]).tmp);
                        free((yyvsp[(8) - (8)]).codigo);
                        free((yyvsp[(6) - (8)]).codigo);
                        }
                    }
    break;

  case 54:
#line 580 "pract.y"
    {
                        if (!err) (yyval).codigo = (yyvsp[(2) - (3)]).codigo;
                    }
    break;

  case 55:
#line 585 "pract.y"
    {
                        if (!err) (yyval).codigo = (yyvsp[(2) - (3)]).codigo;
                    }
    break;

  case 56:
#line 590 "pract.y"
    {
                                    (yyval).tipo = (yyvsp[(1) - (3)]).tipo;

                                    if (!err) {
                                    if ((yyvsp[(1) - (3)]).esLista) {
                                        (yyval).codigo = malloc(sizeof(char) * (strlen((yyvsp[(3) - (3)]).codigo) + strlen((yyvsp[(1) - (3)]).tmp) + strlen((yyvsp[(1) - (3)]).codigo) + 40));
                                        sprintf((yyval).codigo, SALIDASLISTA_ESQ, (yyvsp[(1) - (3)]).codigo, (yyvsp[(1) - (3)]).tmp, (yyvsp[(3) - (3)]).codigo);
                                    } else {
                                        char* formato = getCadenaFormato((yyvsp[(1) - (3)]).tipo);
                                        (yyval).codigo = malloc(sizeof(char) * (strlen((yyvsp[(1) - (3)]).codigo) + strlen(formato) + strlen((yyvsp[(1) - (3)]).tmp) + strlen((yyvsp[(3) - (3)]).codigo) + 21));
                                        sprintf((yyval).codigo, SALIDAS_ESQ, (yyvsp[(1) - (3)]).codigo, formato, (yyvsp[(1) - (3)]).tmp, (yyvsp[(3) - (3)]).codigo);
                                        free(formato);
                                        free((yyvsp[(1) - (3)]).codigo);
                                        free((yyvsp[(3) - (3)]).codigo);
                                        free((yyvsp[(1) - (3)]).tmp);
                                    }
                                    }
                                }
    break;

  case 57:
#line 608 "pract.y"
    {
                                    (yyval).tipo = cadena;

                                    if (!err) {
                                    (yyval).codigo = malloc(sizeof(char) * (strlen((yyvsp[(1) - (3)]).codigo) + strlen((yyvsp[(3) - (3)]).codigo) + 12));
                                    sprintf((yyval).codigo, "printf(%s);\n%s", (yyvsp[(1) - (3)]).codigo, (yyvsp[(3) - (3)]).codigo);
                                    free((yyvsp[(1) - (3)]).codigo);
                                    free((yyvsp[(3) - (3)]).codigo);
                                    }
                                }
    break;

  case 58:
#line 618 "pract.y"
    {
                                    (yyval).tipo = (yyvsp[(1) - (1)]).tipo;
                                   
                                    if (!err) {
                                    if ((yyvsp[(1) - (1)]).esLista) {
                                        (yyval).codigo = malloc(sizeof(char) * (strlen((yyvsp[(1) - (1)]).tmp) + strlen((yyvsp[(1) - (1)]).codigo) + 40));
                                        sprintf((yyval).codigo, SALIDALISTA_ESQ, (yyvsp[(1) - (1)]).codigo, (yyvsp[(1) - (1)]).tmp);
                                    } else {
                                        char* formato = getCadenaFormato((yyvsp[(1) - (1)]).tipo);
                                        (yyval).codigo = malloc(sizeof(char) * (strlen((yyvsp[(1) - (1)]).codigo) + strlen((yyvsp[(1) - (1)]).tmp) + 21));
                                        sprintf((yyval).codigo, SALIDA_ESQ, (yyvsp[(1) - (1)]).codigo, formato, (yyvsp[(1) - (1)]).tmp);
                                        free(formato);
                                    }
                                    free((yyvsp[(1) - (1)]).codigo);
                                    free((yyvsp[(1) - (1)]).tmp);
                                    }
                                }
    break;

  case 59:
#line 635 "pract.y"
    {
                                    (yyval).tipo = cadena;

                                    if (!err) {
                                    (yyval).codigo = malloc(sizeof(char) * (strlen((yyvsp[(1) - (1)]).codigo) + 30));
                                    sprintf((yyval).codigo, "printf(%s); printf(\"\\n\");", (yyvsp[(1) - (1)]).codigo);
                                    free((yyvsp[(1) - (1)]).codigo);
                                    }
                                }
    break;

  case 61:
#line 647 "pract.y"
    {
                (yyval).tipo = (yyvsp[(2) - (3)]).tipo;
                (yyval).esLista = (yyvsp[(2) - (3)]).esLista;

                if (!err) {
                (yyval).codigo = (yyvsp[(2) - (3)]).codigo;
                (yyval).tmp = (yyvsp[(2) - (3)]).tmp;
                }
            }
    break;

  case 62:
#line 656 "pract.y"
    {
                switch ((yyvsp[(2) - (2)]).atrib) {
                    case OPUN_NO :
                        if ((yyvsp[(2) - (2)]).tipo != booleano) {
                            printf("(Línea %d) Error semántico: intento de negar expresión no booleano\n", yylineno);
                            err = 1;
                        }
                        (yyval).tipo = booleano;
                        break;

                    case OPUN_HASH :
                        if ((yyvsp[(2) - (2)]).esLista == 0) {
                            printf("(Línea %d) Error semántico: sólo se puede calcular el número de elementos de una lista\n", yylineno);
                            err = 1;
                        }
                        (yyval).tipo = entero;
                        (yyval).esLista = 0;

                        if (!err) {
                        (yyval).tmp = tmpnuevo();
                        (yyval).codigo = malloc(sizeof(char) * (strlen((yyvsp[(2) - (2)]).codigo) + 2*strlen((yyval).tmp) + strlen((yyvsp[(2) - (2)]).tmp) + 25));
                        sprintf((yyval).codigo, "%s\nint %s;\n%s = %s->largo;", (yyvsp[(2) - (2)]).codigo, (yyval).tmp, (yyval).tmp, (yyvsp[(2) - (2)]).tmp);
                        free((yyvsp[(2) - (2)]).codigo);
                        free((yyvsp[(2) - (2)]).tmp);
                        }

                        break;

                    case OPUN_INTER :
                        if ((yyvsp[(2) - (2)]).esLista == 0) {
                            printf("(Línea %d) Error semántico: sólo se puede coger elementos de una lista\n", yylineno);
                            err = 1;
                        }
                        (yyval).tipo = (yyvsp[(2) - (2)]).tipo;
                        (yyval).esLista = 0;

                        if (!err) {
                        char* tipo = getTipoNombre((yyval).tipo);
                        (yyval).tmp = tmpnuevo();
                        (yyval).codigo = malloc(sizeof(char) * (strlen((yyvsp[(2) - (2)]).codigo) + 2*strlen(tipo) + 2*strlen((yyval).tmp) + strlen((yyvsp[(2) - (2)]).tmp) + 25));
                        sprintf((yyval).codigo, "%s\n%s %s;\n%s = recoger_%s(%s, -1);", (yyvsp[(2) - (2)]).codigo, tipo, (yyval).tmp, (yyval).tmp, tipo, (yyvsp[(2) - (2)]).tmp);
                        free(tipo);
                        free((yyvsp[(2) - (2)]).codigo);
                        free((yyvsp[(2) - (2)]).tmp);
                        }
                        break;

                    default :
                        if (!err) {
                        (yyval).tmp = tmpnuevo();
                        char* tipo = getTipoNombre((yyval).tipo);
                        (yyval).codigo = malloc(sizeof(char) * (strlen((yyvsp[(1) - (2)]).codigo) + strlen((yyvsp[(2) - (2)]).codigo) + strlen(tipo) + 2*strlen((yyval).tmp) + strlen((yyvsp[(2) - (2)]).tmp) + 9));
                        sprintf((yyval).codigo, OPUN_ESQ, (yyvsp[(2) - (2)]).codigo, tipo, (yyval).tmp, (yyval).tmp, (yyvsp[(1) - (2)]).codigo, (yyvsp[(2) - (2)]).tmp);
                }
                        break;
                }                

            }
    break;

  case 63:
#line 714 "pract.y"
    {
                if ((yyvsp[(1) - (3)]).tipo != (yyvsp[(3) - (3)]).tipo && (yyvsp[(1) - (3)]).esLista == 0) {
                    printf("(Línea %d) Error semántico: intento de operar en dos números de tipos distintos\n", yylineno);
                    err = 1;
                }

                switch ((yyvsp[(2) - (3)]).atrib) {
                    case OPBIN_MULT_PART :
                        (yyval).tipo = (yyvsp[(1) - (3)]).tipo;

                        if (!err) {
                        if ((yyval).esLista) { 
                            char* listanomb = (yyvsp[(1) - (3)]).tmp;
                            char* scalnomb = (yyvsp[(3) - (3)]).tmp;
                            if ((yyvsp[(3) - (3)]).esLista) {
                                listanomb = (yyvsp[(3) - (3)]).tmp;
                                scalnomb = (yyvsp[(1) - (3)]).tmp;
                            }
                            (yyval).tmp = tmpnuevo();
                            char* tipo = getTipoNombre((yyval).tipo);
                            (yyval).codigo = malloc(sizeof(char) * (strlen((yyvsp[(1) - (3)]).codigo) + strlen((yyvsp[(3) - (3)]).codigo) + strlen(tipo) + 2*strlen((yyval).tmp) + strlen(listanomb) + strlen(scalnomb) + 25));
                            sprintf((yyval).codigo, "%s\n%s\nlgestor* %s;\n%s = mapear_div_%s(%s, %s);", (yyvsp[(1) - (3)]).codigo, (yyvsp[(3) - (3)]).codigo, (yyval).tmp, (yyval).tmp, tipo, listanomb, scalnomb);
                            free((yyvsp[(1) - (3)]).codigo);
                            free((yyvsp[(3) - (3)]).codigo);
                            free((yyvsp[(1) - (3)]).tmp);
                            free((yyvsp[(3) - (3)]).tmp);
                            free(tipo);
                        } else {
                            char* tipo = getTipoNombre((yyval).tipo);
                            (yyval).tmp = tmpnuevo();
                            (yyval).codigo = malloc(sizeof(char) * (strlen((yyvsp[(1) - (3)]).codigo) + strlen((yyvsp[(3) - (3)]).codigo) + strlen(tipo) + strlen((yyval).tmp) + strlen((yyvsp[(1) - (3)]).tmp) + strlen((yyvsp[(3) - (3)]).tmp) + 15));
                            sprintf((yyval).codigo, "%s\n%s\n%s %s = %s / %s;", (yyvsp[(1) - (3)]).codigo, (yyvsp[(3) - (3)]).codigo, tipo, (yyval).tmp, (yyvsp[(1) - (3)]).tmp, (yyvsp[(3) - (3)]).tmp);
                            free((yyvsp[(1) - (3)]).codigo);
                            free((yyvsp[(3) - (3)]).codigo);
                            free((yyvsp[(1) - (3)]).tmp);
                            free((yyvsp[(3) - (3)]).tmp);
                            free(tipo);
                        }
                        }
                        break;

                    case OPBIN_MULT_MOD :
                        if ((yyvsp[(3) - (3)]).tipo != entero) {
                            printf("(Línea %d) Error semántico: sólo se puede calcular el módulo por un entero\n", yylineno);
                            err = 1;
                        }
                        if ((yyvsp[(1) - (3)]).tipo != entero && (yyvsp[(1) - (3)]).esLista == 0) {
                            printf("(Línea %d) Error semántico: sólo se puede calcular el módulo de un entero o una lista\n", yylineno);
                            err = 1;
                        }

                        (yyval).tipo = (yyvsp[(1) - (3)]).tipo;
                        (yyval).esLista = (yyvsp[(1) - (3)]).esLista;

                        if (!err) {
                        if ((yyval).esLista) {
                            (yyval).tmp = tmpnuevo();
                            (yyval).codigo = malloc(sizeof(char) * (strlen((yyvsp[(1) - (3)]).codigo) + strlen((yyvsp[(3) - (3)]).codigo) + 2*strlen((yyval).tmp) + strlen((yyvsp[(1) - (3)]).tmp) + strlen((yyvsp[(3) - (3)]).tmp) + 40));
                            sprintf((yyval).codigo, "%s\n%s\nlgestor* %s = copiar_lista(%s);\nborrar_despues(%s, %s);", (yyvsp[(1) - (3)]).codigo, (yyvsp[(3) - (3)]).codigo, (yyval).tmp, (yyvsp[(1) - (3)]).tmp, (yyval).tmp, (yyvsp[(3) - (3)]).tmp);
                            free((yyvsp[(1) - (3)]).codigo);
                            free((yyvsp[(3) - (3)]).codigo);
                            free((yyvsp[(1) - (3)]).tmp);
                            free((yyvsp[(3) - (3)]).tmp);
                        } else {
                            (yyval).tmp = tmpnuevo();
                            (yyval).codigo = malloc(sizeof(char) * (strlen((yyvsp[(1) - (3)]).codigo) + strlen((yyvsp[(3) - (3)]).codigo) + 2*strlen((yyval).tmp) + strlen((yyvsp[(1) - (3)]).tmp) + strlen((yyvsp[(3) - (3)]).tmp) + 15));
                            sprintf((yyval).codigo, "%s\n%s\nint %s;\n%s = %s %c %s;", (yyvsp[(1) - (3)]).codigo, (yyvsp[(3) - (3)]).codigo, (yyval).tmp, (yyval).tmp, (yyvsp[(1) - (3)]).tmp, '%', (yyvsp[(3) - (3)]).tmp);
                            free((yyvsp[(1) - (3)]).codigo);
                            free((yyvsp[(3) - (3)]).codigo);
                            free((yyvsp[(1) - (3)]).tmp);
                            free((yyvsp[(3) - (3)]).tmp);
                        }
                        }
                        break;

                    case OPBIN_MULT_POR :
                        if (((yyvsp[(1) - (3)]).tipo != entero && (yyvsp[(1) - (3)]).tipo != real) || ((yyvsp[(3) - (3)]).tipo != entero && (yyvsp[(3) - (3)]).tipo != real)) {
                            printf("(Línea %d) Error semántico: intento de multiplicar expresiones no numéricas\n", yylineno);
                            err = 1;
                        }
                        if ((yyvsp[(1) - (3)]).esLista && (yyvsp[(3) - (3)]).esLista) {
                            printf("(Línea %d) Error semántico: intento de multiplicar dos listas\n", yylineno);
                            err = 1;
                        }
                        if ((yyvsp[(1) - (3)]).tipo != (yyvsp[(3) - (3)]).tipo) {
                            printf("(Línea %d) Error semántico: intento de multiplicar datos de tipos distintos\n", yylineno);
                            err = 1;
                        }
                        (yyval).tipo = (yyvsp[(1) - (3)]).tipo;
                        (yyval).esLista = (yyvsp[(1) - (3)]).esLista || (yyvsp[(3) - (3)]).esLista;
                        
                        if (!err) {
                        if ((yyval).esLista) {
                            char* listanomb = (yyvsp[(1) - (3)]).tmp;
                            char* scalnomb = (yyvsp[(3) - (3)]).tmp;
                            if ((yyvsp[(3) - (3)]).esLista) {
                                listanomb = (yyvsp[(3) - (3)]).tmp;
                                scalnomb = (yyvsp[(1) - (3)]).tmp;
                            }
                            (yyval).tmp = tmpnuevo();
                            char* tipo = getTipoNombre((yyval).tipo);
                            (yyval).codigo = malloc(sizeof(char) * (strlen((yyvsp[(1) - (3)]).codigo) + strlen((yyvsp[(3) - (3)]).codigo) + strlen(tipo) + 2*strlen((yyval).tmp) + strlen(listanomb) + strlen(scalnomb) + 25));
                            sprintf((yyval).codigo, "%s\n%s\nlgestor* %s;\n%s = mapear_mul_%s(%s, %s);", (yyvsp[(1) - (3)]).codigo, (yyvsp[(3) - (3)]).codigo, (yyval).tmp, (yyval).tmp, tipo, listanomb, scalnomb);
                            free((yyvsp[(1) - (3)]).codigo);
                            free((yyvsp[(3) - (3)]).codigo);
                            free((yyvsp[(1) - (3)]).tmp);
                            free((yyvsp[(3) - (3)]).tmp);
                            free(tipo);
                        } else {
                            char* tipo = getTipoNombre((yyval).tipo);
                            (yyval).tmp = tmpnuevo();
                            (yyval).codigo = malloc(sizeof(char) * (strlen((yyvsp[(1) - (3)]).codigo) + strlen((yyvsp[(3) - (3)]).codigo) + strlen(tipo) + strlen((yyval).tmp) + strlen((yyvsp[(1) - (3)]).tmp) + strlen((yyvsp[(3) - (3)]).tmp) + 15));
                            sprintf((yyval).codigo, "%s\n%s\n%s %s = %s * %s;", (yyvsp[(1) - (3)]).codigo, (yyvsp[(3) - (3)]).codigo, tipo, (yyval).tmp, (yyvsp[(1) - (3)]).tmp, (yyvsp[(3) - (3)]).tmp);
                            free((yyvsp[(1) - (3)]).codigo);
                            free((yyvsp[(3) - (3)]).codigo);
                            free((yyvsp[(1) - (3)]).tmp);
                            free((yyvsp[(3) - (3)]).tmp);
                            free(tipo);
                        }
                        }
                        break;

                    default:
                        (yyval).tipo = (yyvsp[(1) - (3)]).tipo;

                        if (!err) {
                        (yyval).tmp = tmpnuevo();
                        char* tipo = getTipoNombre((yyval).tipo);
                        (yyval).codigo = malloc(sizeof(char) * (strlen((yyvsp[(1) - (3)]).codigo) + strlen((yyvsp[(3) - (3)]).codigo) + strlen(tipo) + 2*strlen((yyval).tmp) + strlen((yyvsp[(2) - (3)]).codigo) + strlen((yyvsp[(1) - (3)]).tmp) + strlen((yyvsp[(3) - (3)]).tmp) + 11));
                        sprintf((yyval).codigo, OPBIN_ESQ, (yyvsp[(1) - (3)]).codigo, (yyvsp[(3) - (3)]).codigo, tipo, (yyval).tmp, (yyval).tmp, (yyvsp[(1) - (3)]).tmp, (yyvsp[(2) - (3)]).codigo, (yyvsp[(3) - (3)]).tmp);
                        }
                }
            }
    break;

  case 64:
#line 847 "pract.y"
    {
                if ((yyvsp[(1) - (3)]).tipo != (yyvsp[(3) - (3)]).tipo || (yyvsp[(1) - (3)]).esLista != (yyvsp[(3) - (3)]).esLista) {
                    printf("(Línea %d) Error semántico: intento de comparar variables de tipos distintos\n", yylineno);
                    err = 1;
                }

                (yyval).tipo = booleano;

                if (!err) {
                (yyval).tmp = tmpnuevo();
                char* tipo = getTipoNombre((yyval).tipo);
                (yyval).codigo = malloc(sizeof(char) * (strlen((yyvsp[(1) - (3)]).codigo) + strlen((yyvsp[(3) - (3)]).codigo) + strlen(tipo) + 2*strlen((yyval).tmp) + strlen((yyvsp[(2) - (3)]).codigo) + strlen((yyvsp[(1) - (3)]).tmp) + strlen((yyvsp[(3) - (3)]).tmp) + 11));
                sprintf((yyval).codigo, OPBIN_ESQ, (yyvsp[(1) - (3)]).codigo, (yyvsp[(3) - (3)]).codigo, tipo, (yyval).tmp, (yyval).tmp, (yyvsp[(1) - (3)]).tmp, (yyvsp[(2) - (3)]).codigo, (yyvsp[(3) - (3)]).tmp);
                }
            }
    break;

  case 65:
#line 862 "pract.y"
    {
                if ((yyvsp[(1) - (3)]).tipo != entero && (yyvsp[(1) - (3)]).tipo != real) {
                    printf("(Línea %d) Error semántico: intento de comparar variables no numéricos\n", yylineno);
                    err = 1;
                } else if ((yyvsp[(3) - (3)]).tipo != entero && (yyvsp[(3) - (3)]).tipo != real) {
                    printf("(Línea %d) Error semántico: intento de comparar variables no numéricos\n", yylineno);
                    err = 1;
                } else if ((yyvsp[(1) - (3)]).tipo != (yyvsp[(3) - (3)]).tipo) {
                    printf("(Línea %d) Error semántico: intento de operar en dos números de tipos distintos\n", yylineno);
                    err = 1;
                }

                (yyval).tipo = booleano;

                if (!err) {
                (yyval).tmp = tmpnuevo();
                char* tipo = getTipoNombre((yyval).tipo);
                (yyval).codigo = malloc(sizeof(char) * (strlen((yyvsp[(1) - (3)]).codigo) + strlen((yyvsp[(3) - (3)]).codigo) + strlen(tipo) + 2*strlen((yyval).tmp) + strlen((yyvsp[(2) - (3)]).codigo) + strlen((yyvsp[(1) - (3)]).tmp) + strlen((yyvsp[(3) - (3)]).tmp) + 11));
                sprintf((yyval).codigo, OPBIN_ESQ, (yyvsp[(1) - (3)]).codigo, (yyvsp[(3) - (3)]).codigo, tipo, (yyval).tmp, (yyval).tmp, (yyvsp[(1) - (3)]).tmp, (yyvsp[(2) - (3)]).codigo, (yyvsp[(3) - (3)]).tmp);
                }
            }
    break;

  case 66:
#line 883 "pract.y"
    {
                if ((yyvsp[(1) - (3)]).tipo != booleano || (yyvsp[(3) - (3)]).tipo != booleano) {
                    printf("(Línea %d) Error semántico: intento de realizar AND con variables no booleanos\n", yylineno);
                    err = 1;
                }

                (yyval).tipo = booleano;

                if (!err) {
                (yyval).tmp = tmpnuevo();
                char* tipo = getTipoNombre((yyval).tipo);
                (yyval).codigo = malloc(sizeof(char) * (strlen((yyvsp[(1) - (3)]).codigo) + strlen((yyvsp[(3) - (3)]).codigo) + strlen(tipo) + 2*strlen((yyval).tmp) + strlen((yyvsp[(2) - (3)]).codigo) + strlen((yyvsp[(1) - (3)]).tmp) + strlen((yyvsp[(3) - (3)]).tmp) + 11));
                sprintf((yyval).codigo, OPBIN_ESQ, (yyvsp[(1) - (3)]).codigo, (yyvsp[(3) - (3)]).codigo, tipo, (yyval).tmp, (yyval).tmp, (yyvsp[(1) - (3)]).tmp, (yyvsp[(2) - (3)]).codigo, (yyvsp[(3) - (3)]).tmp);
                }
            }
    break;

  case 67:
#line 898 "pract.y"
    {
                if ((yyvsp[(1) - (3)]).tipo != booleano || (yyvsp[(3) - (3)]).tipo != booleano) {
                    printf("(Línea %d) Error semántico: intento de realizar OR con variables no booleanos\n", yylineno);
                    err = 1;
                }

                (yyval).tipo = booleano;

                if (!err) {
                (yyval).tmp = tmpnuevo();
                char* tipo = getTipoNombre((yyval).tipo);
                (yyval).codigo = malloc(sizeof(char) * (strlen((yyvsp[(1) - (3)]).codigo) + strlen((yyvsp[(3) - (3)]).codigo) + strlen(tipo) + 2*strlen((yyval).tmp) + strlen((yyvsp[(2) - (3)]).codigo) + strlen((yyvsp[(1) - (3)]).tmp) + strlen((yyvsp[(3) - (3)]).tmp) + 12));
                sprintf((yyval).codigo, OPBIN_ESQ, (yyvsp[(1) - (3)]).codigo, (yyvsp[(3) - (3)]).codigo, tipo, (yyval).tmp, (yyval).tmp, (yyvsp[(1) - (3)]).tmp, (yyvsp[(2) - (3)]).codigo, (yyvsp[(3) - (3)]).tmp);
                }
            }
    break;

  case 68:
#line 913 "pract.y"
    {
                if ((yyvsp[(1) - (3)]).tipo != booleano || (yyvsp[(3) - (3)]).tipo != booleano) {
                    printf("(Línea %d) Error semántico: intento de realizar XOR con variables no booleanos\n", yylineno);
                    err = 1;
                }

                (yyval).tipo = booleano;

                if (!err) {
                (yyval).tmp = tmpnuevo();
                char* tipo = getTipoNombre((yyval).tipo);
                (yyval).codigo = malloc(sizeof(char) * (strlen((yyvsp[(1) - (3)]).codigo) + strlen((yyvsp[(3) - (3)]).codigo) + strlen(tipo) + 2*strlen((yyval).tmp) + strlen((yyvsp[(2) - (3)]).codigo) + strlen((yyvsp[(1) - (3)]).tmp) + strlen((yyvsp[(3) - (3)]).tmp) + 12));
                sprintf((yyval).codigo, OPBIN_ESQ, (yyvsp[(1) - (3)]).codigo, (yyvsp[(3) - (3)]).codigo, tipo, (yyval).tmp, (yyval).tmp, (yyvsp[(1) - (3)]).tmp, (yyvsp[(2) - (3)]).codigo, (yyvsp[(3) - (3)]).tmp);
                }
            }
    break;

  case 69:
#line 928 "pract.y"
    {
                if ((yyvsp[(1) - (3)]).esLista != 1 || (yyvsp[(3) - (3)]).esLista != 1) {
                    printf("(Línea %d) Error semántico: intento de concatenar variables que no son listas\n", yylineno);
                    err = 1;
                }
                if ((yyvsp[(1) - (3)]).tipo != (yyvsp[(3) - (3)]).tipo) {
                    printf("(Línea %d) Error semántico: intento de concatenar listas de tipos distintos\n", yylineno);
                    err = 1;
                }

                (yyval).tipo = (yyvsp[(3) - (3)]).tipo;
                (yyval).esLista = 1;

                if (!err) {
                (yyval).tmp = tmpnuevo();
                (yyval).codigo = malloc(sizeof(char) * (strlen((yyvsp[(1) - (3)]).codigo) + strlen((yyvsp[(3) - (3)]).codigo) + strlen((yyvsp[(1) - (3)]).tmp) + strlen((yyvsp[(3) - (3)]).tmp) + 2*strlen((yyval).tmp)));
                sprintf((yyval).codigo, "%s\n%s\nlgestor* %s;\n%s = concatenar(%s, %s);", (yyvsp[(1) - (3)]).codigo, (yyvsp[(3) - (3)]).codigo, (yyval).tmp, (yyval).tmp, (yyvsp[(1) - (3)]).tmp, (yyvsp[(3) - (3)]).tmp);
                free((yyvsp[(1) - (3)]).codigo);
                free((yyvsp[(3) - (3)]).codigo);
                free((yyvsp[(1) - (3)]).tmp);
                free((yyvsp[(3) - (3)]).tmp);
                }
            }
    break;

  case 70:
#line 951 "pract.y"
    {
               switch ((yyvsp[(1) - (2)]).atrib) {
                    case OPUNBIN_MAS :
                        /* ????? */
                        break;

                    case OPUNBIN_MENOS :
                        if ((yyvsp[(2) - (2)]).tipo != real && (yyvsp[(2) - (2)]).tipo != entero) {
                            printf("(Línea %d) Error semántico: intento de negar un variable no numérico\n", yylineno);
                            err = 1;
                        }
                }
                (yyval).tipo = (yyvsp[(2) - (2)]).tipo; 

                if (!err) {
                (yyval).tmp = tmpnuevo();
                char* tipo = getTipoNombre((yyval).tipo);
                (yyval).codigo = malloc(sizeof(char) * (strlen((yyvsp[(1) - (2)]).codigo) + strlen((yyvsp[(2) - (2)]).codigo) + strlen(tipo) + 2*strlen((yyval).tmp) + strlen((yyvsp[(2) - (2)]).tmp) + 10));
                sprintf((yyval).codigo, OPUN_ESQ, (yyvsp[(2) - (2)]).codigo, tipo, (yyval).tmp, (yyval).tmp, (yyvsp[(1) - (2)]).codigo, (yyvsp[(2) - (2)]).tmp);
                }
            }
    break;

  case 71:
#line 972 "pract.y"
    {
                if ((yyvsp[(1) - (3)]).tipo != (yyvsp[(3) - (3)]).tipo) {
                    printf("(Línea %d) Error semántico: intento de operar en dos valores de tipos distintos\n", yylineno);
                    err = 1;
                }
                if ((yyvsp[(1) - (3)]).tipo != real && (yyvsp[(1) - (3)]).tipo != entero) {
                    printf("(Línea %d) Error semántico: intento de operar en valores no numéricos\n", yylineno);
                    err = 1;
                }
                if ((yyvsp[(3) - (3)]).tipo != real && (yyvsp[(3) - (3)]).tipo != entero) {
                    printf("(Línea %d) Error semántico: intento de operar en valores no numéricos\n", yylineno);
                    err = 1;
                }
                (yyval).tipo = (yyvsp[(1) - (3)]).tipo;
                (yyval).esLista = (yyvsp[(1) - (3)]).esLista;

                if (!err) {
                if ((yyval).esLista) {
                    (yyval).tmp = tmpnuevo();
                    char* tipo = getTipoNombre((yyval).tipo);
                    char* listnomb = (yyvsp[(1) - (3)]).tmp;
                    char* scalnomb = (yyvsp[(3) - (3)]).tmp;
                    (yyval).codigo = malloc(sizeof(char) * (strlen((yyvsp[(1) - (3)]).codigo) + strlen((yyvsp[(3) - (3)]).codigo) + strlen((yyval).tmp) + strlen(tipo) + strlen(listnomb) + strlen(scalnomb) + 25));
                    if ((yyvsp[(3) - (3)]).esLista) {
                        listnomb = (yyvsp[(3) - (3)]).tmp;
                        scalnomb = (yyvsp[(1) - (3)]).tmp;
                    }
                    if ((yyvsp[(2) - (3)]).atrib == OPUNBIN_MAS) {
                        sprintf((yyval).codigo, "%s\n%s\nlgestor* %s = mapear_add_%s(%s, %s);", (yyvsp[(1) - (3)]).codigo, (yyvsp[(3) - (3)]).codigo, (yyval).tmp, tipo, listnomb, scalnomb);
                    } else if ((yyvsp[(2) - (3)]).atrib == OPUNBIN_MENOS) {
                        sprintf((yyval).codigo, "%s\n%s\nlgestor* %s = mapear_sub_%s(%s, %s);", (yyvsp[(1) - (3)]).codigo, (yyvsp[(3) - (3)]).codigo, (yyval).tmp, tipo, listnomb, scalnomb);
                    }
                    free(tipo);
                } else {
                    (yyval).tmp = tmpnuevo();
                    char* tipo = getTipoNombre((yyval).tipo);
                    (yyval).codigo = malloc(sizeof(char) * (strlen((yyvsp[(1) - (3)]).codigo) + strlen((yyvsp[(3) - (3)]).codigo) + strlen(tipo) + 2*strlen((yyval).tmp) + strlen((yyvsp[(2) - (3)]).codigo) + strlen((yyvsp[(1) - (3)]).tmp) + strlen((yyvsp[(3) - (3)]).tmp) + 12));
                    sprintf((yyval).codigo, OPBIN_ESQ, (yyvsp[(1) - (3)]).codigo, (yyvsp[(3) - (3)]).codigo, tipo, (yyval).tmp, (yyval).tmp, (yyvsp[(1) - (3)]).tmp, (yyvsp[(2) - (3)]).codigo, (yyvsp[(3) - (3)]).tmp);
                }
                free((yyvsp[(1) - (3)]).codigo);
                free((yyvsp[(3) - (3)]).codigo);
                free((yyvsp[(1) - (3)]).tmp);
                free((yyvsp[(3) - (3)]).tmp);
                }
            }
    break;

  case 72:
#line 1017 "pract.y"
    {
                if ((yyvsp[(1) - (3)]).esLista != 1) {
                    printf("(Línea %d) Error semántico: intento de borrar elemento de algo que no sea lista\n", yylineno);
                    err = 1;
                }
                if ((yyvsp[(3) - (3)]).tipo != entero) {
                    printf("(Línea %d) Error semántico: índice de una lista debe ser un número entero\n", yylineno);
                    err = 1;
                }
                (yyval).tipo = (yyvsp[(1) - (3)]).tipo;
                (yyval).esLista = 1;

                if (!err) {
                (yyval).tmp = tmpnuevo();
                (yyval).codigo = malloc(sizeof(char) * (strlen((yyvsp[(1) - (3)]).codigo) + strlen((yyvsp[(3) - (3)]).codigo) + 2*strlen((yyval).tmp) + strlen((yyvsp[(1) - (3)]).tmp) + strlen((yyvsp[(3) - (3)]).tmp) + 40));
                sprintf((yyval).codigo, "%s\n%s\nlgestor* %s = copiar_lista(%s);\nborrar_posicion(%s, %s);", (yyvsp[(1) - (3)]).codigo, (yyvsp[(3) - (3)]).codigo, (yyval).tmp, (yyvsp[(1) - (3)]).tmp, (yyval).tmp, (yyvsp[(3) - (3)]).tmp);
                free((yyvsp[(1) - (3)]).codigo);
                free((yyvsp[(3) - (3)]).codigo);
                free((yyvsp[(1) - (3)]).tmp);
                free((yyvsp[(3) - (3)]).tmp); 
                }
            }
    break;

  case 73:
#line 1039 "pract.y"
    {
                if ((yyvsp[(1) - (3)]).esLista == 0) {
                    printf("(Línea %d) Error semántico: intento de recoger elemento de expresión que no sea lista\n", yylineno);
                    err = 1;
                }
                if ((yyvsp[(3) - (3)]).tipo != entero) {
                    printf("(Línea %d) Error semántico: índice de lista debe ser un número entero\n", yylineno);
                    err = 1;
                }
                (yyval).tipo = (yyvsp[(1) - (3)]).tipo;
                (yyval).esLista = 0;

                if (!err) {
                char* tipo = getTipoNombre((yyval).tipo);
                (yyval).tmp = tmpnuevo();
                (yyval).codigo = malloc(sizeof(char) * (strlen((yyvsp[(1) - (3)]).codigo) + strlen((yyvsp[(3) - (3)]).codigo) + 2*strlen(tipo) + 2*strlen((yyval).tmp) + strlen((yyvsp[(1) - (3)]).tmp) + strlen((yyvsp[(3) - (3)]).tmp) + 20));
                sprintf((yyval).codigo, "%s\n%s\n%s %s;\n%s = recoger_%s(%s, %s);", (yyvsp[(1) - (3)]).codigo, (yyvsp[(3) - (3)]).codigo, tipo, (yyval).tmp, (yyval).tmp, tipo, (yyvsp[(1) - (3)]).tmp, (yyvsp[(3) - (3)]).tmp);
                free((yyvsp[(1) - (3)]).codigo);
                free((yyvsp[(3) - (3)]).codigo);
                free((yyvsp[(1) - (3)]).tmp);
                free((yyvsp[(3) - (3)]).tmp);
                free(tipo);
                }
            }
    break;

  case 74:
#line 1063 "pract.y"
    {
                if ((yyvsp[(1) - (5)]).esLista == 0) {
                    printf("(Línea %d) Error semántico: intento de realizar operación de listas con algo que no sea lista\n", yylineno);
                    err = 1;
                }
                if ((yyvsp[(1) - (5)]).tipo != (yyvsp[(3) - (5)]).tipo) {
                    printf("(Línea %d) Error semántico: intento de meter valor en una lista de tipo distinto\n", yylineno);
                    err = 1;
                }
                if ((yyvsp[(5) - (5)]).tipo != entero) {
                    printf("(Línea %d) Error semántico: los índices de una lista deben ser números enteros\n", yylineno);
                    err = 1;
                }
                (yyval).tipo = (yyvsp[(1) - (5)]).tipo;
                (yyval).esLista = 1;

                if (!err) {
                char* tipo = getTipoNombre((yyval).tipo);
                (yyval).tmp = tmpnuevo();
                char* dato = tmpnuevo();
                (yyval).codigo = malloc(sizeof(char) * (strlen((yyvsp[(1) - (5)]).codigo) + strlen((yyvsp[(3) - (5)]).codigo) + strlen((yyvsp[(5) - (5)]).codigo) + 2*strlen((yyval).tmp) + 2*strlen((yyvsp[(1) - (5)]).tmp) + strlen((yyvsp[(3) - (5)]).tmp) + strlen((yyvsp[(5) - (5)]).tmp) + 2*strlen(dato) + strlen(tipo) + 50));
                sprintf((yyval).codigo, OPTERN_ESQ, (yyvsp[(1) - (5)]).codigo, (yyvsp[(3) - (5)]).codigo, (yyvsp[(5) - (5)]).codigo, (yyval).tmp, (yyvsp[(1) - (5)]).tmp, dato, tipo, (yyvsp[(3) - (5)]).tmp, (yyval).tmp, dato, (yyvsp[(5) - (5)]).tmp);
                free((yyvsp[(1) - (5)]).codigo);
                free((yyvsp[(3) - (5)]).codigo);
                free((yyvsp[(5) - (5)]).codigo);
                free(tipo);
                free(dato);
                }
            }
    break;

  case 75:
#line 1092 "pract.y"
    {
                int indice = TS_RecogerEntrada((yyvsp[(1) - (1)]).lexema);
                if (indice == -1) {
                    printf("(Línea %d) Error semántico: variable %s no ha sido declarado\n", yylineno, (yyvsp[(1) - (1)]).lexema);
                    (yyval).tipo = no_asignado;
                    err = 1;
                } else {
                    entradaTS entrada = TS[indice];
                    (yyval).tipo = entrada.tipoDato;
                    (yyval).esLista = entrada.esLista;
                }

                if (!err) {
                (yyval).codigo = malloc(sizeof(char));
                *(yyval).codigo = '\0';
                int n = TS_RecogerEntrada((yyvsp[(1) - (1)]).lexema);
                char* id = TS[n].alias;
                (yyval).tmp = malloc(sizeof(char) * (strlen(id) + 1));
                (yyval).tmp = strdup(id);
                }
            }
    break;

  case 76:
#line 1113 "pract.y"
    {
                (yyval).tipo = (yyvsp[(1) - (1)]).tipo;
                (yyval).esLista = 0;

                if (!err) {
                (yyval).codigo = malloc(2 * sizeof(char));
                *(yyval).codigo = 0;
                (yyval).tmp = (yyvsp[(1) - (1)]).codigo;
                }
            }
    break;

  case 77:
#line 1123 "pract.y"
    {
                (yyval).tipo = (yyvsp[(1) - (1)]).tipo;
                (yyval).esLista = 1;
            }
    break;

  case 79:
#line 1130 "pract.y"
    {
                        (yyval).tipo = (yyvsp[(2) - (3)]).tipo;
                        (yyval).esLista = 1;
                    }
    break;


/* Line 1267 of yacc.c.  */
#line 2865 "y.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
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

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



