
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 ".\\syntax.y"

    #include <stdio.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <math.h>
    #include <string.h>
    #include "hashtbl.h"


    HASHTBL *hashtbl; /* Define hashtable */
     int scope = 0;
    int error_count = 0;
    extern FILE *yyin;
    extern int yylex();
    extern void yyterminate();
    void yyerror(const char *s);

    


/* Line 189 of yacc.c  */
#line 94 "syntax.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     T_EOF = 0,
     T_TYPEDEF = 258,
     T_CHAR = 259,
     T_INT = 260,
     T_FLOAT = 261,
     T_STRING = 262,
     T_CLASS = 263,
     T_PRIVATE = 264,
     T_PROTECTED = 265,
     T_PUBLIC = 266,
     T_VOID = 267,
     T_STATIC = 268,
     T_UNION = 269,
     T_ENUM = 270,
     T_LIST = 271,
     T_CONTINUE = 272,
     T_BREAK = 273,
     T_IF = 274,
     T_ELSE = 275,
     T_WHILE = 276,
     T_FOR = 277,
     T_SWITCH = 278,
     T_CASE = 279,
     T_DEFAULT = 280,
     T_RETURN = 281,
     T_LENGTH = 282,
     T_NEW = 283,
     T_CIN = 284,
     T_COUT = 285,
     T_MAIN = 286,
     T_THIS = 287,
     T_ID = 288,
     T_ICONST = 289,
     T_FCONST = 290,
     T_CCONST = 291,
     T_SCONST = 292,
     T_OROP = 293,
     T_ANDOP = 294,
     T_EQUOP = 295,
     T_RELOP = 296,
     T_ADDOP = 297,
     T_MULOP = 298,
     T_NOTOP = 299,
     T_INCDEC = 300,
     T_SIZEOP = 301,
     T_LISTFUNC = 302,
     T_LPAREN = 303,
     T_RPAREN = 304,
     T_SEMI = 305,
     T_DOT = 306,
     T_COMMA = 307,
     T_ASSIGN = 308,
     T_COLON = 309,
     T_LBRACK = 310,
     T_RBRACK = 311,
     T_REFER = 312,
     T_LBRACE = 313,
     T_RBRACE = 314,
     T_METH = 315,
     T_INP = 316,
     T_OUT = 317
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 22 ".\\syntax.y"

    int ival;
    float fval;
    char cval;
    char* sval;



/* Line 214 of yacc.c  */
#line 202 "syntax.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 214 "syntax.tab.c"

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
# if YYENABLE_NLS
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
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
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
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   882

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  63
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  82
/* YYNRULES -- Number of rules.  */
#define YYNRULES  179
/* YYNRULES -- Number of states.  */
#define YYNSTATES  349

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   317

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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     7,     8,    11,    12,    14,    16,    18,
      20,    22,    24,    31,    33,    35,    37,    39,    41,    43,
      45,    47,    48,    51,    52,    56,    59,    64,    68,    73,
      76,    79,    80,    82,    86,    90,    94,    98,   102,   106,
     110,   113,   116,   119,   122,   125,   127,   132,   137,   142,
     144,   148,   152,   154,   159,   163,   168,   171,   173,   177,
     179,   183,   185,   187,   188,   190,   192,   194,   196,   200,
     204,   206,   211,   216,   219,   220,   224,   227,   230,   233,
     236,   237,   239,   241,   243,   245,   249,   253,   257,   259,
     263,   267,   271,   274,   276,   278,   280,   283,   286,   291,
     295,   300,   303,   305,   308,   312,   317,   321,   325,   327,
     330,   332,   334,   339,   344,   349,   354,   359,   364,   367,
     372,   375,   377,   380,   384,   387,   389,   391,   392,   398,
     403,   405,   406,   409,   411,   413,   415,   417,   419,   421,
     423,   425,   427,   430,   433,   435,   438,   441,   448,   451,
     452,   458,   468,   470,   471,   477,   481,   483,   486,   488,
     490,   491,   494,   496,   501,   506,   510,   515,   520,   524,
     529,   534,   538,   540,   542,   546,   548,   550,   554,   559
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
      64,     0,    -1,    65,   143,     0,    -1,    -1,    65,    66,
      -1,    -1,    67,    -1,    73,    -1,    86,    -1,   107,    -1,
     108,    -1,   111,    -1,     3,    68,    70,    33,    71,    50,
      -1,    69,    -1,    33,    -1,     4,    -1,     5,    -1,     6,
      -1,     7,    -1,    12,    -1,    16,    -1,    -1,    71,    72,
      -1,    -1,    55,    34,    56,    -1,    55,    56,    -1,    15,
      33,    74,    50,    -1,    58,    75,    59,    -1,    75,    52,
      33,    76,    -1,    33,    76,    -1,    53,    77,    -1,    -1,
      78,    -1,    58,    85,    59,    -1,    78,    38,    78,    -1,
      78,    39,    78,    -1,    78,    40,    78,    -1,    78,    41,
      78,    -1,    78,    42,    78,    -1,    78,    43,    78,    -1,
      44,    78,    -1,    42,    78,    -1,    46,    78,    -1,    45,
      79,    -1,    79,    45,    -1,    79,    -1,    79,    48,    82,
      49,    -1,    27,    48,    80,    49,    -1,    28,    48,    80,
      49,    -1,    83,    -1,    48,    80,    49,    -1,    48,    69,
      49,    -1,    84,    -1,    79,    55,    80,    56,    -1,    79,
      51,    33,    -1,    47,    48,    80,    49,    -1,   121,    33,
      -1,    32,    -1,    80,    52,    80,    -1,    81,    -1,    79,
      53,    81,    -1,    78,    -1,    80,    -1,    -1,    36,    -1,
      34,    -1,    35,    -1,    37,    -1,    55,    82,    56,    -1,
      85,    52,    77,    -1,    77,    -1,     8,    33,    87,    50,
      -1,    88,    58,    89,    59,    -1,    54,    33,    -1,    -1,
      89,    90,    91,    -1,    90,    91,    -1,     9,    54,    -1,
      10,    54,    -1,    11,    54,    -1,    -1,    92,    -1,   100,
      -1,    93,    -1,    96,    -1,    68,    94,    50,    -1,    68,
      94,     1,    -1,    94,    52,    95,    -1,    95,    -1,    70,
      33,    71,    -1,    14,    97,    50,    -1,    58,    98,    59,
      -1,    98,    99,    -1,    99,    -1,    93,    -1,   101,    -1,
     102,    50,    -1,   106,    50,    -1,   103,    48,   104,    49,
      -1,    68,    70,    33,    -1,   104,    52,    68,   105,    -1,
      68,   105,    -1,    57,    -1,    70,    71,    -1,   103,    48,
      49,    -1,    14,    33,    97,    50,    -1,    68,   109,    50,
      -1,   109,    52,   110,    -1,   110,    -1,    95,    76,    -1,
     101,    -1,   112,    -1,   113,    58,   119,    59,    -1,   118,
      58,   119,    59,    -1,   106,    58,   119,    59,    -1,   114,
      48,   116,    49,    -1,   103,    48,   116,    49,    -1,    68,
      70,   115,    33,    -1,    33,    60,    -1,   116,    52,    68,
     117,    -1,    68,   117,    -1,    95,    -1,    57,    33,    -1,
     114,    48,    49,    -1,   120,   122,    -1,   120,    -1,   122,
      -1,    -1,   120,   121,    68,    94,    50,    -1,   121,    68,
      94,    50,    -1,    13,    -1,    -1,   122,   123,    -1,   123,
      -1,   124,    -1,   125,    -1,   127,    -1,   128,    -1,   130,
      -1,   136,    -1,   137,    -1,   142,    -1,    17,    50,    -1,
      18,    50,    -1,    50,    -1,    80,    50,    -1,     1,    50,
      -1,    19,    48,    80,    49,   123,   126,    -1,    20,   123,
      -1,    -1,    21,    48,    80,    49,   123,    -1,    22,    48,
     129,    50,   129,    50,   129,    49,   123,    -1,    80,    -1,
      -1,    23,    48,    80,    49,   131,    -1,    58,   132,    59,
      -1,   135,    -1,   120,   133,    -1,   120,    -1,   133,    -1,
      -1,   133,   134,    -1,   134,    -1,    24,    83,    54,   134,
      -1,    24,    83,    54,   122,    -1,    25,    54,   122,    -1,
      24,    83,    54,   135,    -1,    24,    83,    54,   123,    -1,
      26,   129,    50,    -1,    29,    61,   138,    50,    -1,    30,
      62,   140,    50,    -1,   138,    61,   139,    -1,   139,    -1,
      79,    -1,   140,    62,   141,    -1,   141,    -1,    80,    -1,
      58,   119,    59,    -1,   144,    58,   119,    59,    -1,     5,
      31,    48,    49,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   114,   114,   115,   118,   119,   122,   123,   124,   125,
     126,   127,   130,   133,   134,   137,   137,   137,   137,   137,
     140,   140,   143,   144,   147,   148,   151,   154,   157,   158,
     161,   162,   165,   166,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   190,   191,   192,   193,   194,   197,   198,
     201,   202,   205,   206,   209,   209,   209,   209,   212,   215,
     216,   219,   222,   225,   226,   229,   230,   233,   234,   235,
     236,   239,   240,   243,   244,   248,   249,   252,   253,   256,
     259,   262,   265,   266,   269,   272,   275,   276,   279,   282,
     285,   286,   289,   290,   293,   296,   299,   302,   303,   306,
     309,   310,   313,   314,   315,   318,   319,   322,   325,   328,
     329,   332,   333,   336,   339,   340,   341,   342,   345,   346,
     349,   350,   353,   354,   357,   358,   359,   360,   361,   362,
     363,   364,   365,   366,   367,   371,   372,   375,   378,   379,
     382,   385,   388,   389,   392,   395,   396,   399,   400,   401,
     402,   405,   406,   409,   410,   411,   414,   415,   418,   421,
     422,   425,   426,   429,   432,   433,   436,   439,   442,   445
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"EOF\"", "error", "$undefined", "\"typedef\"", "\"char\"", "\"int\"",
  "\"float\"", "\"string\"", "\"class\"", "\"private\"", "\"protected\"",
  "\"public\"", "\"void\"", "\"static\"", "\"union\"", "\"enum\"",
  "\"list\"", "\"continue\"", "\"break\"", "\"if\"", "\"else\"",
  "\"while\"", "\"for\"", "\"switch\"", "\"case\"", "\"default\"",
  "\"return\"", "\"length\"", "\"new\"", "\"cin\"", "\"cout\"", "\"main\"",
  "\"this\"", "\"id\"", "\"iconst\"", "\"fconst\"", "\"cconst\"",
  "\"sconst\"", "\"||\"", "\"&&\"", "\"==\"", "\">\"", "\"+\"", "\"*\"",
  "\"!\"", "\"++\"", "\"sizeop\"", "\"listfunc\"", "\"(\"", "\")\"",
  "\";\"", "\".\"", "\",\"", "\"=\"", "\":\"", "\"[\"", "\"]\"",
  "\"refer\"", "\"{\"", "\"}\"", "\"meth\"", "\"<<\"", "\">>\"", "$accept",
  "program", "global_declarations", "global_declaration",
  "typedef_declaration", "typename", "standard_type", "listspec", "dims",
  "dim", "enum_declaration", "enum_body", "id_list", "initializer",
  "init_value", "expression", "variable", "general_expression",
  "assignment", "expression_list", "constant", "listexpression",
  "init_values", "class_declaration", "class_body", "parent",
  "members_methods", "access", "member_or_method", "member",
  "var_declaration", "variabledefs", "variabledef", "anonymous_union",
  "union_body", "fields", "field", "method", "short_func_declaration",
  "short_par_func_header", "func_header_start", "parameter_types",
  "pass_list_dims", "nopar_func_header", "union_declaration",
  "global_var_declaration", "init_variabledefs", "init_variabledef",
  "func_declaration", "full_func_declaration", "full_par_func_header",
  "class_func_header_start", "func_class", "parameter_list",
  "pass_variabledef", "nopar_class_func_header", "decl_statements",
  "declarations", "decltype", "statements", "statement",
  "expression_statement", "if_statement", "if_tail", "while_statement",
  "for_statement", "optexpr", "switch_statement", "switch_tail",
  "decl_cases", "casestatements", "casestatement", "single_casestatement",
  "return_statement", "io_statement", "in_list", "in_item", "out_list",
  "out_item", "comp_statement", "main_function", "main_header", 0
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
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    63,    64,    64,    65,    65,    66,    66,    66,    66,
      66,    66,    67,    68,    68,    69,    69,    69,    69,    69,
      70,    70,    71,    71,    72,    72,    73,    74,    75,    75,
      76,    76,    77,    77,    78,    78,    78,    78,    78,    78,
      78,    78,    78,    78,    78,    78,    78,    78,    78,    78,
      78,    78,    78,    79,    79,    79,    79,    79,    80,    80,
      81,    81,    82,    82,    83,    83,    83,    83,    84,    85,
      85,    86,    87,    88,    88,    89,    89,    90,    90,    90,
      90,    91,    91,    92,    92,    93,    93,    94,    94,    95,
      96,    97,    98,    98,    99,   100,   101,   101,   102,   103,
     104,   104,   105,   105,   106,   107,   108,   109,   109,   110,
     111,   111,   112,   112,   112,   113,   113,   114,   115,   116,
     116,   117,   117,   118,   119,   119,   119,   119,   120,   120,
     121,   121,   122,   122,   123,   123,   123,   123,   123,   123,
     123,   123,   123,   123,   123,   124,   124,   125,   126,   126,
     127,   128,   129,   129,   130,   131,   131,   132,   132,   132,
     132,   133,   133,   134,   134,   134,   135,   135,   136,   137,
     137,   138,   138,   139,   140,   140,   141,   142,   143,   144
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     0,     2,     0,     1,     1,     1,     1,
       1,     1,     6,     1,     1,     1,     1,     1,     1,     1,
       1,     0,     2,     0,     3,     2,     4,     3,     4,     2,
       2,     0,     1,     3,     3,     3,     3,     3,     3,     3,
       2,     2,     2,     2,     2,     1,     4,     4,     4,     1,
       3,     3,     1,     4,     3,     4,     2,     1,     3,     1,
       3,     1,     1,     0,     1,     1,     1,     1,     3,     3,
       1,     4,     4,     2,     0,     3,     2,     2,     2,     2,
       0,     1,     1,     1,     1,     3,     3,     3,     1,     3,
       3,     3,     2,     1,     1,     1,     2,     2,     4,     3,
       4,     2,     1,     2,     3,     4,     3,     3,     1,     2,
       1,     1,     4,     4,     4,     4,     4,     4,     2,     4,
       2,     1,     2,     3,     2,     1,     1,     0,     5,     4,
       1,     0,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     2,     1,     2,     2,     6,     2,     0,
       5,     9,     1,     0,     5,     3,     1,     2,     1,     1,
       0,     2,     1,     4,     4,     3,     4,     4,     3,     4,
       4,     3,     1,     1,     3,     1,     1,     3,     4,     4
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       5,     0,     0,     1,     0,    15,    16,    17,    18,     0,
      19,     0,     0,    14,     4,     6,    21,    13,     7,     8,
     110,     0,     0,     0,     9,    10,    11,   111,     0,     0,
       0,     0,     0,    16,    21,     0,    74,     0,     0,    20,
       0,    31,     0,   108,    96,     0,    97,     0,     0,     0,
       0,     2,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    23,     0,   131,   109,   106,    21,   104,    21,
       0,     0,     0,   130,     0,     0,     0,     0,     0,     0,
     131,     0,     0,     0,     0,    57,    65,    66,    64,    67,
     131,   131,   131,   131,     0,   131,   144,    63,     0,    61,
      45,     0,    59,    49,    52,     0,     0,     0,     0,   133,
     134,   135,   136,   137,   138,   139,   140,   141,     0,   123,
      21,     0,     0,     0,    23,   179,    73,    71,    80,    21,
      94,     0,    93,   105,    31,     0,    26,   118,    89,   117,
     131,    30,    32,    45,     0,     0,   107,   102,    23,   121,
     101,   120,    98,     0,   116,     0,   146,   142,   143,   131,
     131,   131,   131,   152,     0,   131,   131,   131,   131,    41,
      40,    43,    42,   131,     0,     0,    62,     0,     0,   131,
     131,   131,   131,   131,   131,    44,    63,     0,   131,   131,
     145,   131,   114,     0,     0,    56,    21,   132,   112,     0,
     115,   113,   178,     0,     0,     0,     0,    80,     0,     0,
      88,    91,    92,    29,     0,    27,     0,    22,    70,     0,
      56,    23,   122,   103,    21,    21,     0,     0,     0,     0,
     168,     0,     0,   173,     0,   172,   176,     0,   175,     0,
      51,    50,    68,   177,    34,    35,    36,    37,    38,    39,
       0,    54,    60,     0,    58,    21,     0,    12,    77,    78,
      79,    72,     0,     0,    21,    76,    81,    83,    84,    82,
      95,     0,     0,    86,    85,    21,    31,     0,    25,   131,
      33,   102,    23,   100,   119,     0,     0,   131,     0,    47,
      48,   169,   131,   170,   131,    55,    46,    53,     0,   129,
      75,     0,     0,     0,    87,    28,    24,    69,   149,   150,
       0,     0,   131,   154,   156,   171,   174,   128,    90,    23,
      21,     0,   147,   131,     0,     0,     0,   131,     0,     0,
     159,   162,   148,     0,     0,     0,     0,     0,   157,   155,
     161,     0,   167,   166,     0,     0,   151,     0,   163
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    14,    15,   129,    17,   145,   138,   217,
      18,    61,   135,    65,   141,    99,   100,   101,   102,   177,
     103,   104,   219,    19,    56,    57,   207,   208,   265,   266,
     130,   209,   210,   268,    59,   131,   132,   269,   270,    21,
     271,    70,   150,   272,    24,    25,    42,    43,    26,    27,
      28,    29,    63,    71,   151,    30,   105,   106,   144,   108,
     109,   110,   111,   322,   112,   113,   164,   114,   313,   329,
     330,   331,   314,   115,   116,   234,   235,   237,   238,   117,
      31,    32
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -273
static const yytype_int16 yypact[] =
{
      35,    69,   169,  -273,   218,  -273,    44,  -273,  -273,    64,
    -273,   115,   125,  -273,  -273,  -273,   152,  -273,  -273,  -273,
    -273,   119,   134,    45,  -273,  -273,  -273,  -273,   136,   164,
     140,   213,   185,  -273,   152,   196,   173,   195,   201,  -273,
     228,   214,   128,  -273,  -273,   112,  -273,   310,   310,   159,
     310,  -273,   310,   229,   222,   244,   230,   224,   218,   239,
     257,   241,    -4,   259,   727,  -273,  -273,   152,  -273,     5,
      83,    95,   250,  -273,   253,   254,   246,   260,   261,   262,
     752,   264,   265,   258,   245,  -273,  -273,  -273,  -273,  -273,
     827,   827,    29,   827,   270,   251,  -273,   777,   310,   838,
     148,   202,  -273,  -273,  -273,   266,   366,   269,   510,  -273,
    -273,  -273,  -273,  -273,  -273,  -273,  -273,  -273,   271,  -273,
      11,   110,   275,   282,  -273,  -273,  -273,  -273,   209,   152,
    -273,    19,  -273,  -273,   214,    98,  -273,  -273,   293,  -273,
     727,  -273,   838,   101,   287,   288,  -273,   291,   288,  -273,
    -273,  -273,  -273,   218,  -273,   218,  -273,  -273,  -273,   827,
     827,   752,   827,   297,   300,   827,   827,    29,   827,   838,
     838,    53,   838,   827,   302,   155,   297,   303,   294,   827,
     827,   827,   827,   827,   827,  -273,   777,   328,   827,   827,
    -273,   827,  -273,   269,   558,    13,   152,  -273,  -273,   291,
    -273,  -273,  -273,   150,   308,   309,   312,    56,   183,    27,
    -273,  -273,  -273,  -273,   331,  -273,    30,  -273,  -273,   108,
    -273,  -273,  -273,   293,    17,    11,   162,   179,   324,   180,
    -273,   184,   186,    53,    50,  -273,   297,    31,  -273,   190,
    -273,  -273,  -273,  -273,   838,   838,   838,   838,   838,   838,
     326,  -273,  -273,   -11,   297,   152,   216,  -273,  -273,  -273,
    -273,  -273,   183,   195,   152,  -273,  -273,  -273,  -273,  -273,
    -273,   329,   330,  -273,  -273,   152,   214,   320,  -273,   727,
    -273,  -273,  -273,  -273,  -273,   702,   702,   752,    34,  -273,
    -273,  -273,    29,  -273,   827,  -273,  -273,  -273,   220,  -273,
    -273,   332,   348,   112,  -273,  -273,  -273,  -273,   370,  -273,
     336,    86,    47,  -273,  -273,  -273,  -273,  -273,  -273,   343,
      17,   702,  -273,   802,   350,    86,   351,    77,   218,   338,
     109,  -273,  -273,   357,   654,   353,   702,   218,   109,  -273,
    -273,   702,  -273,  -273,   606,   414,  -273,   462,  -273
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -273,  -273,  -273,  -273,  -273,    -2,   314,   -15,  -112,  -273,
    -273,  -273,  -273,  -121,  -125,   -53,   -42,   -77,   231,   232,
    -272,  -273,  -273,  -273,  -273,  -273,  -273,   210,   158,  -273,
    -192,  -182,   -10,  -273,   160,  -273,   295,  -273,   420,  -273,
     426,  -273,   205,   428,  -273,  -273,  -273,   367,  -273,  -273,
    -273,  -273,  -273,   396,   227,  -273,   -18,   141,   -43,   -96,
    -100,  -273,  -273,  -273,  -273,  -273,  -144,  -273,  -273,  -273,
     127,  -231,   121,  -273,  -273,  -273,   165,  -273,   171,  -273,
    -273,  -273
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -166
static const yytype_int16 yytable[] =
{
      16,    40,    34,   163,   107,   107,    41,   107,   197,   107,
     194,   142,   203,   213,   256,   218,   267,   228,   175,    53,
     176,    39,   143,     5,    33,     7,     8,    39,   273,   -14,
     118,    10,   122,    39,   123,    -3,   223,   169,   170,   324,
     172,   191,    73,    69,   -99,   297,   -14,   120,   143,   143,
     171,   143,    13,   335,   148,   107,   137,    41,   311,   149,
      73,    85,   147,   193,   277,   204,   205,   206,   199,     3,
     267,   325,   326,   298,   281,    35,    94,   274,   211,   275,
     178,   293,   226,   227,   163,   229,   278,   142,   231,   232,
      73,   236,   312,   294,   197,    46,   239,    36,   143,   340,
     291,   325,   326,    47,   187,   196,  -160,   340,   189,   176,
     149,   292,   253,   348,   254,   261,     5,    33,     7,     8,
      86,    87,    88,    89,    10,   233,   244,   245,   246,   247,
     248,   249,   152,   325,   326,   153,  -158,   143,   143,   143,
     143,   143,   143,   310,   154,    13,   185,   155,    37,   186,
     214,   224,   187,   225,   307,   305,   189,   215,    38,   200,
     279,    68,   155,     5,    33,     7,     8,   280,    39,    44,
     223,    10,     4,     5,     6,     7,     8,     9,    66,   333,
      67,    10,    45,    11,    12,   308,   309,     5,    33,     7,
       8,   255,    13,   185,    48,    10,   186,   263,    50,   187,
     257,   188,    13,   189,   241,   216,   264,   191,   119,   282,
     163,   285,    49,    51,   191,   149,    13,   236,   204,   205,
     206,   332,     5,    33,     7,     8,   142,    55,   286,   288,
      10,   191,   191,   289,   342,   290,   191,   143,   191,   295,
     345,   346,   191,    52,    54,   197,   163,   197,   347,   302,
     233,    13,   190,    58,   191,     5,    33,     7,     8,    60,
     264,    62,   124,    10,    73,   304,   299,    64,   275,   328,
     317,   125,   275,     5,    33,     7,     8,   126,    81,    82,
     127,    10,   128,    85,   337,    86,    87,    88,    89,   133,
     134,   136,   139,    90,   159,    91,    92,    93,    94,    95,
     156,   320,   195,   157,   158,   282,    97,   168,   160,   161,
     162,    72,   165,   166,  -131,  -131,  -131,  -131,   173,   167,
     220,   221,  -131,    73,   222,   192,   196,    74,    75,    76,
     198,    77,    78,    79,   201,   255,    80,    81,    82,    83,
      84,   202,    85,  -131,    86,    87,    88,    89,   216,   191,
     230,   240,    90,   243,    91,    92,    93,    94,    95,   242,
      96,   251,   258,   259,   276,    97,   260,    72,    98,  -127,
    -131,  -131,  -131,  -131,   287,   296,   306,   303,  -131,    73,
      46,   319,   318,    74,    75,    76,   323,    77,    78,    79,
     321,   -99,    80,    81,    82,    83,    84,   339,    85,  -131,
      86,    87,    88,    89,   334,   336,   341,   344,    90,   174,
      91,    92,    93,    94,    95,    72,    96,   262,   250,   252,
     300,    97,    20,   301,    98,  -125,   212,    73,    22,   283,
      23,    74,    75,    76,   146,    77,    78,    79,  -165,  -165,
      80,    81,    82,    83,    84,   121,    85,  -131,    86,    87,
      88,    89,   284,   327,   338,   343,    90,   315,    91,    92,
      93,    94,    95,    72,    96,   316,     0,     0,     0,    97,
       0,     0,    98,  -165,     0,    73,     0,     0,     0,    74,
      75,    76,     0,    77,    78,    79,  -164,  -164,    80,    81,
      82,    83,    84,     0,    85,  -131,    86,    87,    88,    89,
       0,     0,     0,     0,    90,     0,    91,    92,    93,    94,
      95,    72,    96,     0,     0,     0,     0,    97,     0,     0,
      98,  -164,     0,    73,     0,     0,     0,    74,    75,    76,
       0,    77,    78,    79,     0,     0,    80,    81,    82,    83,
      84,     0,    85,  -131,    86,    87,    88,    89,     0,     0,
       0,     0,    90,     0,    91,    92,    93,    94,    95,    72,
      96,     0,     0,     0,     0,    97,     0,     0,    98,  -126,
       0,    73,     0,     0,     0,    74,    75,    76,     0,    77,
      78,    79,     0,     0,    80,    81,    82,    83,    84,     0,
      85,  -131,    86,    87,    88,    89,     0,     0,     0,     0,
      90,     0,    91,    92,    93,    94,    95,    72,    96,     0,
       0,     0,     0,    97,     0,     0,    98,  -124,     0,    73,
       0,     0,     0,    74,    75,    76,     0,    77,    78,    79,
     325,   326,    80,    81,    82,    83,    84,     0,    85,  -131,
      86,    87,    88,    89,     0,     0,     0,     0,    90,     0,
      91,    92,    93,    94,    95,    72,    96,     0,     0,     0,
       0,    97,     0,     0,    98,     0,     0,    73,     0,     0,
       0,    74,    75,    76,     0,    77,    78,    79,   311,     0,
      80,    81,    82,    83,    84,     0,    85,  -131,    86,    87,
      88,    89,     0,     0,     0,     0,    90,     0,    91,    92,
      93,    94,    95,    72,    96,     0,     0,     0,     0,    97,
       0,     0,    98,     0,     0,    73,     0,     0,     0,    74,
      75,    76,     0,    77,    78,    79,     0,     0,    80,    81,
      82,    83,    84,     0,    85,  -131,    86,    87,    88,    89,
      73,     0,     0,     0,    90,     0,    91,    92,    93,    94,
      95,     0,    96,     0,    81,    82,     0,    97,     0,    85,
      98,    86,    87,    88,    89,    73,     0,     0,     0,    90,
       0,    91,    92,    93,    94,    95,     0,     0,     0,    81,
      82,     0,    97,     0,    85,   140,    86,    87,    88,    89,
      73,     0,     0,     0,    90,     0,    91,    92,    93,    94,
      95,     0,  -153,     0,    81,    82,     0,    97,     0,    85,
    -131,    86,    87,    88,    89,    73,     0,     0,     0,    90,
       0,    91,    92,    93,    94,    95,     0,     0,     0,    81,
      82,     0,    97,     0,    85,     0,    86,    87,    88,    89,
      73,     0,     0,     0,    90,     0,    91,    92,    93,    94,
      95,  -153,     0,     0,    81,    82,     0,    97,     0,    85,
       0,    86,    87,    88,    89,     0,     0,     0,     0,    90,
       0,    91,    92,    93,    94,    95,   179,   180,   181,   182,
     183,   184,    97
};

static const yytype_int16 yycheck[] =
{
       2,    16,     4,    80,    47,    48,    16,    50,   108,    52,
     106,    64,   124,   134,   196,   140,   208,   161,    95,    34,
      97,    16,    64,     4,     5,     6,     7,    16,     1,    16,
      48,    12,    50,    16,    52,     0,   148,    90,    91,   311,
      93,    52,    13,    45,    48,    56,    33,    49,    90,    91,
      92,    93,    33,   325,    69,    98,    60,    67,    24,    69,
      13,    32,    57,   106,    34,     9,    10,    11,    57,     0,
     262,    24,    25,   255,    57,    31,    47,    50,    59,    52,
      98,    50,   159,   160,   161,   162,    56,   140,   165,   166,
      13,   168,    58,    62,   194,    50,   173,    33,   140,   330,
      50,    24,    25,    58,    51,   107,    59,   338,    55,   186,
     120,    61,   189,   344,   191,    59,     4,     5,     6,     7,
      34,    35,    36,    37,    12,   167,   179,   180,   181,   182,
     183,   184,    49,    24,    25,    52,    59,   179,   180,   181,
     182,   183,   184,   287,    49,    33,    45,    52,    33,    48,
      52,   153,    51,   155,   279,   276,    55,    59,    33,    49,
      52,    49,    52,     4,     5,     6,     7,    59,    16,    50,
     282,    12,     3,     4,     5,     6,     7,     8,    50,   323,
      52,    12,    48,    14,    15,   285,   286,     4,     5,     6,
       7,   193,    33,    45,    58,    12,    48,    14,    58,    51,
      50,    53,    33,    55,    49,    55,   208,    52,    49,   224,
     287,    49,    48,     0,    52,   225,    33,   294,     9,    10,
      11,   321,     4,     5,     6,     7,   279,    54,    49,    49,
      12,    52,    52,    49,   334,    49,    52,   279,    52,    49,
     336,   341,    52,    58,    48,   345,   323,   347,   344,   264,
     292,    33,    50,    58,    52,     4,     5,     6,     7,    58,
     262,    33,    33,    12,    13,   275,    50,    53,    52,   312,
      50,    49,    52,     4,     5,     6,     7,    33,    27,    28,
      50,    12,    58,    32,   327,    34,    35,    36,    37,    50,
      33,    50,    33,    42,    48,    44,    45,    46,    47,    48,
      50,   303,    33,    50,    50,   320,    55,    62,    48,    48,
      48,     1,    48,    48,     4,     5,     6,     7,    48,    61,
      33,    33,    12,    13,    33,    59,   328,    17,    18,    19,
      59,    21,    22,    23,    59,   337,    26,    27,    28,    29,
      30,    59,    32,    33,    34,    35,    36,    37,    55,    52,
      50,    49,    42,    59,    44,    45,    46,    47,    48,    56,
      50,    33,    54,    54,    33,    55,    54,     1,    58,    59,
       4,     5,     6,     7,    50,    49,    56,    48,    12,    13,
      50,    33,    50,    17,    18,    19,    50,    21,    22,    23,
      20,    48,    26,    27,    28,    29,    30,    59,    32,    33,
      34,    35,    36,    37,    54,    54,    49,    54,    42,    95,
      44,    45,    46,    47,    48,     1,    50,   207,   186,   188,
     262,    55,     2,   263,    58,    59,   131,    13,     2,   224,
       2,    17,    18,    19,    67,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    49,    32,    33,    34,    35,
      36,    37,   225,   312,   327,   334,    42,   292,    44,    45,
      46,    47,    48,     1,    50,   294,    -1,    -1,    -1,    55,
      -1,    -1,    58,    59,    -1,    13,    -1,    -1,    -1,    17,
      18,    19,    -1,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    -1,    32,    33,    34,    35,    36,    37,
      -1,    -1,    -1,    -1,    42,    -1,    44,    45,    46,    47,
      48,     1,    50,    -1,    -1,    -1,    -1,    55,    -1,    -1,
      58,    59,    -1,    13,    -1,    -1,    -1,    17,    18,    19,
      -1,    21,    22,    23,    -1,    -1,    26,    27,    28,    29,
      30,    -1,    32,    33,    34,    35,    36,    37,    -1,    -1,
      -1,    -1,    42,    -1,    44,    45,    46,    47,    48,     1,
      50,    -1,    -1,    -1,    -1,    55,    -1,    -1,    58,    59,
      -1,    13,    -1,    -1,    -1,    17,    18,    19,    -1,    21,
      22,    23,    -1,    -1,    26,    27,    28,    29,    30,    -1,
      32,    33,    34,    35,    36,    37,    -1,    -1,    -1,    -1,
      42,    -1,    44,    45,    46,    47,    48,     1,    50,    -1,
      -1,    -1,    -1,    55,    -1,    -1,    58,    59,    -1,    13,
      -1,    -1,    -1,    17,    18,    19,    -1,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    -1,    32,    33,
      34,    35,    36,    37,    -1,    -1,    -1,    -1,    42,    -1,
      44,    45,    46,    47,    48,     1,    50,    -1,    -1,    -1,
      -1,    55,    -1,    -1,    58,    -1,    -1,    13,    -1,    -1,
      -1,    17,    18,    19,    -1,    21,    22,    23,    24,    -1,
      26,    27,    28,    29,    30,    -1,    32,    33,    34,    35,
      36,    37,    -1,    -1,    -1,    -1,    42,    -1,    44,    45,
      46,    47,    48,     1,    50,    -1,    -1,    -1,    -1,    55,
      -1,    -1,    58,    -1,    -1,    13,    -1,    -1,    -1,    17,
      18,    19,    -1,    21,    22,    23,    -1,    -1,    26,    27,
      28,    29,    30,    -1,    32,    33,    34,    35,    36,    37,
      13,    -1,    -1,    -1,    42,    -1,    44,    45,    46,    47,
      48,    -1,    50,    -1,    27,    28,    -1,    55,    -1,    32,
      58,    34,    35,    36,    37,    13,    -1,    -1,    -1,    42,
      -1,    44,    45,    46,    47,    48,    -1,    -1,    -1,    27,
      28,    -1,    55,    -1,    32,    58,    34,    35,    36,    37,
      13,    -1,    -1,    -1,    42,    -1,    44,    45,    46,    47,
      48,    -1,    50,    -1,    27,    28,    -1,    55,    -1,    32,
      33,    34,    35,    36,    37,    13,    -1,    -1,    -1,    42,
      -1,    44,    45,    46,    47,    48,    -1,    -1,    -1,    27,
      28,    -1,    55,    -1,    32,    -1,    34,    35,    36,    37,
      13,    -1,    -1,    -1,    42,    -1,    44,    45,    46,    47,
      48,    49,    -1,    -1,    27,    28,    -1,    55,    -1,    32,
      -1,    34,    35,    36,    37,    -1,    -1,    -1,    -1,    42,
      -1,    44,    45,    46,    47,    48,    38,    39,    40,    41,
      42,    43,    55
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    64,    65,     0,     3,     4,     5,     6,     7,     8,
      12,    14,    15,    33,    66,    67,    68,    69,    73,    86,
     101,   102,   103,   106,   107,   108,   111,   112,   113,   114,
     118,   143,   144,     5,    68,    31,    33,    33,    33,    16,
      70,    95,   109,   110,    50,    48,    50,    58,    58,    48,
      58,     0,    58,    70,    48,    54,    87,    88,    58,    97,
      58,    74,    33,   115,    53,    76,    50,    52,    49,    68,
     104,   116,     1,    13,    17,    18,    19,    21,    22,    23,
      26,    27,    28,    29,    30,    32,    34,    35,    36,    37,
      42,    44,    45,    46,    47,    48,    50,    55,    58,    78,
      79,    80,    81,    83,    84,   119,   120,   121,   122,   123,
     124,   125,   127,   128,   130,   136,   137,   142,   119,    49,
      68,   116,   119,   119,    33,    49,    33,    50,    58,    68,
      93,    98,    99,    50,    33,    75,    50,    60,    71,    33,
      58,    77,    78,    79,   121,    70,   110,    57,    70,    95,
     105,   117,    49,    52,    49,    52,    50,    50,    50,    48,
      48,    48,    48,    80,   129,    48,    48,    61,    62,    78,
      78,    79,    78,    48,    69,    80,    80,    82,   119,    38,
      39,    40,    41,    42,    43,    45,    48,    51,    53,    55,
      50,    52,    59,   121,   122,    33,    68,   123,    59,    57,
      49,    59,    59,    71,     9,    10,    11,    89,    90,    94,
      95,    59,    99,    76,    52,    59,    55,    72,    77,    85,
      33,    33,    33,    71,    68,    68,    80,    80,   129,    80,
      50,    80,    80,    79,   138,   139,    80,   140,   141,    80,
      49,    49,    56,    59,    78,    78,    78,    78,    78,    78,
      82,    33,    81,    80,    80,    68,    94,    50,    54,    54,
      54,    59,    90,    14,    68,    91,    92,    93,    96,   100,
     101,   103,   106,     1,    50,    52,    33,    34,    56,    52,
      59,    57,    70,   105,   117,    49,    49,    50,    49,    49,
      49,    50,    61,    50,    62,    49,    49,    56,    94,    50,
      91,    97,    70,    48,    95,    76,    56,    77,   123,   123,
     129,    24,    58,   131,   135,   139,   141,    50,    50,    33,
      68,    20,   126,    50,    83,    24,    25,   120,   121,   132,
     133,   134,   123,   129,    54,    83,    54,   121,   133,    59,
     134,    49,   123,   135,    54,   122,   123,   122,   134
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
# if YYLTYPE_IS_TRIVIAL
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
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
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
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
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


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

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
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

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
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
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
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
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

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
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
        case 3:

/* Line 1455 of yacc.c  */
#line 115 ".\\syntax.y"
    { ;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 119 ".\\syntax.y"
    { ;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 130 ".\\syntax.y"
    { hashtbl_insert(hashtbl, (yyvsp[(4) - (6)].sval), NULL, scope); ;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 134 ".\\syntax.y"
    { hashtbl_insert(hashtbl, (yyvsp[(1) - (1)].sval), NULL, scope); ;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 137 ".\\syntax.y"
    {scope++; ;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 140 ".\\syntax.y"
    { ;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 144 ".\\syntax.y"
    { ;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 151 ".\\syntax.y"
    { hashtbl_insert(hashtbl, (yyvsp[(2) - (4)].sval), NULL, scope); ;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 157 ".\\syntax.y"
    { hashtbl_insert(hashtbl, (yyvsp[(3) - (4)].sval), NULL, scope); ;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 158 ".\\syntax.y"
    { hashtbl_insert(hashtbl, (yyvsp[(1) - (2)].sval), NULL, scope); ;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 162 ".\\syntax.y"
    { ;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 191 ".\\syntax.y"
    { hashtbl_insert(hashtbl, (yyvsp[(3) - (3)].sval), NULL, scope); ;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 193 ".\\syntax.y"
    { hashtbl_insert(hashtbl, (yyvsp[(2) - (2)].sval), NULL, scope); ;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 206 ".\\syntax.y"
    { ;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 219 ".\\syntax.y"
    { hashtbl_insert(hashtbl, (yyvsp[(2) - (4)].sval), NULL, scope); ;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 225 ".\\syntax.y"
    { hashtbl_insert(hashtbl, (yyvsp[(2) - (2)].sval), NULL, scope); ;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 226 ".\\syntax.y"
    { ;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 233 ".\\syntax.y"
    { scope++; ;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 234 ".\\syntax.y"
    { scope++; ;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 235 ".\\syntax.y"
    { scope++; ;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 236 ".\\syntax.y"
    { ;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 249 ".\\syntax.y"
    { yyerror("Missing semicolon in variable declaration; recovering from error"); ;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 256 ".\\syntax.y"
    { hashtbl_insert(hashtbl, (yyvsp[(2) - (3)].sval), NULL, scope); ;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 259 ".\\syntax.y"
    {scope++; ;}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 262 ".\\syntax.y"
    {hashtbl_get(hashtbl, scope); scope--; ;}
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 282 ".\\syntax.y"
    { hashtbl_insert(hashtbl, (yyvsp[(3) - (3)].sval), NULL, scope); ;}
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 296 ".\\syntax.y"
    { hashtbl_insert(hashtbl, (yyvsp[(2) - (4)].sval), NULL, scope); ;}
    break;

  case 114:

/* Line 1455 of yacc.c  */
#line 315 ".\\syntax.y"
    {hashtbl_get(hashtbl, scope); scope--; ;}
    break;

  case 117:

/* Line 1455 of yacc.c  */
#line 322 ".\\syntax.y"
    { hashtbl_insert(hashtbl, (yyvsp[(4) - (4)].sval), NULL, scope); ;}
    break;

  case 118:

/* Line 1455 of yacc.c  */
#line 325 ".\\syntax.y"
    { hashtbl_insert(hashtbl, (yyvsp[(1) - (2)].sval), NULL, scope); ;}
    break;

  case 122:

/* Line 1455 of yacc.c  */
#line 333 ".\\syntax.y"
    { hashtbl_insert(hashtbl, (yyvsp[(2) - (2)].sval), NULL, scope); ;}
    break;

  case 127:

/* Line 1455 of yacc.c  */
#line 342 ".\\syntax.y"
    { /*empty*/;}
    break;

  case 128:

/* Line 1455 of yacc.c  */
#line 345 ".\\syntax.y"
    {scope++; ;}
    break;

  case 131:

/* Line 1455 of yacc.c  */
#line 350 ".\\syntax.y"
    { ;}
    break;

  case 146:

/* Line 1455 of yacc.c  */
#line 372 ".\\syntax.y"
    { yyerror("Invalid expression statement; recovering from error"); ;}
    break;

  case 147:

/* Line 1455 of yacc.c  */
#line 375 ".\\syntax.y"
    { scope++; ;}
    break;

  case 149:

/* Line 1455 of yacc.c  */
#line 379 ".\\syntax.y"
    { ;}
    break;

  case 150:

/* Line 1455 of yacc.c  */
#line 382 ".\\syntax.y"
    { scope++; ;}
    break;

  case 151:

/* Line 1455 of yacc.c  */
#line 385 ".\\syntax.y"
    { scope++; ;}
    break;

  case 153:

/* Line 1455 of yacc.c  */
#line 389 ".\\syntax.y"
    { ;}
    break;

  case 154:

/* Line 1455 of yacc.c  */
#line 392 ".\\syntax.y"
    { scope++; ;}
    break;

  case 155:

/* Line 1455 of yacc.c  */
#line 395 ".\\syntax.y"
    {hashtbl_get(hashtbl, scope); scope--; ;}
    break;

  case 160:

/* Line 1455 of yacc.c  */
#line 402 ".\\syntax.y"
    { ;}
    break;

  case 161:

/* Line 1455 of yacc.c  */
#line 405 ".\\syntax.y"
    {scope++; ;}
    break;

  case 177:

/* Line 1455 of yacc.c  */
#line 439 ".\\syntax.y"
    {hashtbl_get(hashtbl, scope); scope--; ;}
    break;

  case 178:

/* Line 1455 of yacc.c  */
#line 442 ".\\syntax.y"
    { hashtbl_get(hashtbl, scope); scope--; ;}
    break;

  case 179:

/* Line 1455 of yacc.c  */
#line 445 ".\\syntax.y"
    {scope++; ;}
    break;



/* Line 1455 of yacc.c  */
#line 2180 "syntax.tab.c"
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

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
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



/* Line 1675 of yacc.c  */
#line 449 ".\\syntax.y"


int main(int argc, char *argv[]) {
    int token;

    if (!(hashtbl = hashtbl_create(10, NULL))){
    puts("Error, failed to initialize hashtable");
    exit(EXIT_FAILURE);
  }

    if (argc > 1) {
        yyin = fopen(argv[1], "r");
        if (yyin == NULL) {
            perror("Error opening file");
            return -1;
        }
    } else {
        fprintf(stderr, "No input file provided.\n");
        return -1;
    }

    yyparse();  // Call the parser

    fclose(yyin);  // Close the file after parsing
    hashtbl_destroy(hashtbl);
    return 0;
}

void yyerror(const char *s) {
    extern int yylineno;  // Provided by your lexer
    extern char current_line[];  // Provided by your lexer
    error_count++;  // Increment the error counter

    fprintf(stderr, "Syntax error at line %d: %s\n", yylineno, s);
    fprintf(stderr, "Line: %s\n", current_line);

    if (error_count >= 5) {
        fprintf(stderr, "Too many syntax errors. Aborting parsing.\n");
        exit(1);  // Terminate the program after 5 errors
    }
}



