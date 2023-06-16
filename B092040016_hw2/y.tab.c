/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "B092040016.y"

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int yylex();
void yyerror(const char *s);

int error_flag = 0;
int error_charnum;
int error_linenum;
int operator_length=0;
int lack_commaid=0;
extern unsigned long long cpos,lc;
extern char full_line[1024];

int scopenum=0;
struct Node{
	char *identifier;
	int scope;
	int used;
	struct Node *next;
};
typedef struct Node Node;

int count=0;
Node *front;
Node *tail;
Node *temp;
Node *current;

void create();
int lookup(const char* search,int sco);
int insert(const char* id,int sco);
void beused(const char* used_id,int sco);
void usedornot();
void resetforclass();
void resettable();
void dump();

#line 112 "y.tab.c"

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

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    PTYPE = 258,                   /* PTYPE  */
    PP = 259,                      /* PP  */
    MM = 260,                      /* MM  */
    LE = 261,                      /* LE  */
    GE = 262,                      /* GE  */
    EQ = 263,                      /* EQ  */
    NE = 264,                      /* NE  */
    AND = 265,                     /* AND  */
    OR = 266,                      /* OR  */
    LB = 267,                      /* LB  */
    RB = 268,                      /* RB  */
    CLASS = 269,                   /* CLASS  */
    ELSE = 270,                    /* ELSE  */
    FINAL = 271,                   /* FINAL  */
    FOR = 272,                     /* FOR  */
    IF = 273,                      /* IF  */
    MAIN = 274,                    /* MAIN  */
    NEW = 275,                     /* NEW  */
    PRINT = 276,                   /* PRINT  */
    RETURN = 277,                  /* RETURN  */
    STATIC = 278,                  /* STATIC  */
    VOID = 279,                    /* VOID  */
    WHILE = 280,                   /* WHILE  */
    ID = 281,                      /* ID  */
    INT_N = 282,                   /* INT_N  */
    FLOAT_N = 283,                 /* FLOAT_N  */
    STR = 284                      /* STR  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define PTYPE 258
#define PP 259
#define MM 260
#define LE 261
#define GE 262
#define EQ 263
#define NE 264
#define AND 265
#define OR 266
#define LB 267
#define RB 268
#define CLASS 269
#define ELSE 270
#define FINAL 271
#define FOR 272
#define IF 273
#define MAIN 274
#define NEW 275
#define PRINT 276
#define RETURN 277
#define STATIC 278
#define VOID 279
#define WHILE 280
#define ID 281
#define INT_N 282
#define FLOAT_N 283
#define STR 284

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 42 "B092040016.y"

    char strVal[80];

#line 227 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_PTYPE = 3,                      /* PTYPE  */
  YYSYMBOL_PP = 4,                         /* PP  */
  YYSYMBOL_MM = 5,                         /* MM  */
  YYSYMBOL_LE = 6,                         /* LE  */
  YYSYMBOL_GE = 7,                         /* GE  */
  YYSYMBOL_EQ = 8,                         /* EQ  */
  YYSYMBOL_NE = 9,                         /* NE  */
  YYSYMBOL_AND = 10,                       /* AND  */
  YYSYMBOL_OR = 11,                        /* OR  */
  YYSYMBOL_LB = 12,                        /* LB  */
  YYSYMBOL_RB = 13,                        /* RB  */
  YYSYMBOL_CLASS = 14,                     /* CLASS  */
  YYSYMBOL_ELSE = 15,                      /* ELSE  */
  YYSYMBOL_FINAL = 16,                     /* FINAL  */
  YYSYMBOL_FOR = 17,                       /* FOR  */
  YYSYMBOL_IF = 18,                        /* IF  */
  YYSYMBOL_MAIN = 19,                      /* MAIN  */
  YYSYMBOL_NEW = 20,                       /* NEW  */
  YYSYMBOL_PRINT = 21,                     /* PRINT  */
  YYSYMBOL_RETURN = 22,                    /* RETURN  */
  YYSYMBOL_STATIC = 23,                    /* STATIC  */
  YYSYMBOL_VOID = 24,                      /* VOID  */
  YYSYMBOL_WHILE = 25,                     /* WHILE  */
  YYSYMBOL_ID = 26,                        /* ID  */
  YYSYMBOL_INT_N = 27,                     /* INT_N  */
  YYSYMBOL_FLOAT_N = 28,                   /* FLOAT_N  */
  YYSYMBOL_STR = 29,                       /* STR  */
  YYSYMBOL_30_ = 30,                       /* '='  */
  YYSYMBOL_31_ = 31,                       /* '('  */
  YYSYMBOL_32_ = 32,                       /* ')'  */
  YYSYMBOL_33_ = 33,                       /* ';'  */
  YYSYMBOL_34_ = 34,                       /* '['  */
  YYSYMBOL_35_ = 35,                       /* ']'  */
  YYSYMBOL_36_ = 36,                       /* ','  */
  YYSYMBOL_37_ = 37,                       /* '+'  */
  YYSYMBOL_38_ = 38,                       /* '-'  */
  YYSYMBOL_39_ = 39,                       /* '*'  */
  YYSYMBOL_40_ = 40,                       /* '/'  */
  YYSYMBOL_41_ = 41,                       /* '<'  */
  YYSYMBOL_42_ = 42,                       /* '>'  */
  YYSYMBOL_YYACCEPT = 43,                  /* $accept  */
  YYSYMBOL_classes = 44,                   /* classes  */
  YYSYMBOL_45_1 = 45,                      /* $@1  */
  YYSYMBOL_declare = 46,                   /* declare  */
  YYSYMBOL_47_2 = 47,                      /* $@2  */
  YYSYMBOL_48_3 = 48,                      /* $@3  */
  YYSYMBOL_49_4 = 49,                      /* $@4  */
  YYSYMBOL_nosemi = 50,                    /* nosemi  */
  YYSYMBOL_semiornot = 51,                 /* semiornot  */
  YYSYMBOL_func_orid = 52,                 /* func_orid  */
  YYSYMBOL_eachid = 53,                    /* eachid  */
  YYSYMBOL_54_5 = 54,                      /* $@5  */
  YYSYMBOL_compound = 55,                  /* compound  */
  YYSYMBOL_56_6 = 56,                      /* $@6  */
  YYSYMBOL_main_orid = 57,                 /* main_orid  */
  YYSYMBOL_para_list = 58,                 /* para_list  */
  YYSYMBOL_comma_para = 59,                /* comma_para  */
  YYSYMBOL_initialid = 60,                 /* initialid  */
  YYSYMBOL_const_exprandexpr = 61,         /* const_exprandexpr  */
  YYSYMBOL_comma_id = 62,                  /* comma_id  */
  YYSYMBOL_63_7 = 63,                      /* $@7  */
  YYSYMBOL_fin_id = 64,                    /* fin_id  */
  YYSYMBOL_65_8 = 65,                      /* $@8  */
  YYSYMBOL_fincomma_id = 66,               /* fincomma_id  */
  YYSYMBOL_const_expr = 67,                /* const_expr  */
  YYSYMBOL_statements = 68,                /* statements  */
  YYSYMBOL_69_9 = 69,                      /* $@9  */
  YYSYMBOL_simple = 70,                    /* simple  */
  YYSYMBOL_71_10 = 71,                     /* $@10  */
  YYSYMBOL_calculate = 72,                 /* calculate  */
  YYSYMBOL_expression = 73,                /* expression  */
  YYSYMBOL_term = 74,                      /* term  */
  YYSYMBOL_more_factor = 75,               /* more_factor  */
  YYSYMBOL_factor = 76,                    /* factor  */
  YYSYMBOL_77_11 = 77,                     /* $@11  */
  YYSYMBOL_postop_orinvoke = 78,           /* postop_orinvoke  */
  YYSYMBOL_preop = 79,                     /* preop  */
  YYSYMBOL_para_invoke = 80,               /* para_invoke  */
  YYSYMBOL_comma_invoke = 81,              /* comma_invoke  */
  YYSYMBOL_loop = 82,                      /* loop  */
  YYSYMBOL_forloop = 83,                   /* forloop  */
  YYSYMBOL_forinitopt = 84,                /* forinitopt  */
  YYSYMBOL_arr = 85,                       /* arr  */
  YYSYMBOL_forupdateopt = 86,              /* forupdateopt  */
  YYSYMBOL_postop = 87,                    /* postop  */
  YYSYMBOL_bool_expr = 88,                 /* bool_expr  */
  YYSYMBOL_errordetect = 89,               /* errordetect  */
  YYSYMBOL_90_12 = 90,                     /* $@12  */
  YYSYMBOL_operator = 91,                  /* operator  */
  YYSYMBOL_more_operator = 92,             /* more_operator  */
  YYSYMBOL_infixop = 93,                   /* infixop  */
  YYSYMBOL_simorcom = 94,                  /* simorcom  */
  YYSYMBOL_conditional = 95,               /* conditional  */
  YYSYMBOL_elseornot = 96                  /* elseornot  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




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

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
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
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
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

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

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
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   257

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  43
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  54
/* YYNRULES -- Number of rules.  */
#define YYNRULES  123
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  231

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   284


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      31,    32,    39,    37,    36,    38,     2,    40,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    33,
      41,    30,    42,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    34,     2,    35,     2,     2,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    55,    55,    56,    56,    59,    60,    61,    62,    63,
      67,    67,    63,    68,    69,    70,    73,    74,    77,    78,
      80,    81,    82,    84,    84,    91,    91,    93,    94,    96,
      97,    99,   100,   102,   103,   105,   105,   107,   108,   109,
     109,   114,   114,   121,   122,   124,   125,   126,   127,   128,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   144,
     145,   148,   149,   149,   150,   153,   154,   155,   158,   159,
     160,   163,   165,   166,   167,   169,   169,   170,   171,   172,
     173,   175,   176,   177,   178,   180,   180,   180,   180,   182,
     183,   185,   186,   190,   193,   195,   196,   198,   198,   200,
     201,   201,   204,   205,   207,   207,   208,   209,   210,   211,
     212,   214,   214,   217,   217,   217,   217,   217,   217,   219,
     220,   223,   225,   226
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "PTYPE", "PP", "MM",
  "LE", "GE", "EQ", "NE", "AND", "OR", "LB", "RB", "CLASS", "ELSE",
  "FINAL", "FOR", "IF", "MAIN", "NEW", "PRINT", "RETURN", "STATIC", "VOID",
  "WHILE", "ID", "INT_N", "FLOAT_N", "STR", "'='", "'('", "')'", "';'",
  "'['", "']'", "','", "'+'", "'-'", "'*'", "'/'", "'<'", "'>'", "$accept",
  "classes", "$@1", "declare", "$@2", "$@3", "$@4", "nosemi", "semiornot",
  "func_orid", "eachid", "$@5", "compound", "$@6", "main_orid",
  "para_list", "comma_para", "initialid", "const_exprandexpr", "comma_id",
  "$@7", "fin_id", "$@8", "fincomma_id", "const_expr", "statements", "$@9",
  "simple", "$@10", "calculate", "expression", "term", "more_factor",
  "factor", "$@11", "postop_orinvoke", "preop", "para_invoke",
  "comma_invoke", "loop", "forloop", "forinitopt", "arr", "forupdateopt",
  "postop", "bool_expr", "errordetect", "$@12", "operator",
  "more_operator", "infixop", "simorcom", "conditional", "elseornot", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-148)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-113)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -148,    24,  -148,    -7,    18,  -148,  -148,   118,    48,  -148,
    -148,  -148,  -148,  -148,    46,    26,    33,    38,    54,   199,
     104,     6,    86,    61,  -148,  -148,   199,  -148,  -148,  -148,
     105,  -148,  -148,    23,  -148,    60,  -148,    65,    98,  -148,
    -148,  -148,   107,   111,  -148,     0,  -148,    63,   122,    15,
       8,   134,   199,  -148,    73,   124,  -148,  -148,   137,     8,
    -148,    66,   135,    41,  -148,  -148,   144,   148,   149,   150,
     151,  -148,  -148,   199,   199,   199,   199,  -148,  -148,   168,
     159,   153,  -148,   124,  -148,   147,   169,    72,  -148,  -148,
    -148,  -148,   161,   173,   135,   172,   175,   182,  -148,  -148,
      14,   177,  -148,   113,    76,   198,    71,  -148,     0,   179,
     180,   183,  -148,  -148,   199,   181,   188,    11,  -148,   184,
     185,  -148,  -148,  -148,  -148,  -148,  -148,    65,    65,   190,
     186,   199,  -148,   189,     0,     0,  -148,  -148,  -148,   191,
     122,   147,   135,   192,     8,  -148,  -148,  -148,  -148,  -148,
    -148,   199,    63,   199,  -148,  -148,  -148,  -148,   194,   147,
     198,    63,   203,   120,  -148,   196,  -148,   206,  -148,  -148,
    -148,  -148,   193,   198,  -148,    23,   120,   204,  -148,  -148,
     207,   161,  -148,   205,   199,   200,   120,   223,  -148,  -148,
    -148,  -148,  -148,  -148,  -148,   184,   236,  -148,  -148,   237,
      89,  -148,   199,   120,   215,    63,  -148,   216,  -148,   217,
     135,   120,   135,   212,  -148,   214,   193,   213,   155,    63,
     218,  -148,  -148,  -148,  -148,  -148,  -148,  -148,   219,  -148,
    -148
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     1,     0,     0,     3,    50,     2,     0,    85,
      86,    25,     4,    58,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    75,    45,    80,     0,    60,    87,    88,
      15,    57,    51,    81,    52,     0,    68,    72,     0,    53,
      54,    55,    23,     0,     7,    37,    50,     0,     0,     0,
       0,     0,     0,    75,     0,     0,    27,    28,     0,     0,
       9,     0,    97,     0,    82,    83,    89,     0,     0,     0,
       0,    77,    64,     0,     0,     0,     0,    71,    79,    29,
      33,     0,    23,     0,    39,    18,     2,    75,   120,   119,
      59,    41,    43,     0,    97,     0,   107,   108,   109,   110,
       0,     0,   103,   104,     0,     0,     0,    56,    37,     0,
       0,     0,    65,    66,     0,     0,     0,    81,    78,    91,
       0,    46,    47,    48,    49,    69,    70,    72,    72,     0,
       0,     0,    24,     0,    37,    37,    19,    20,    26,     0,
       0,    18,    97,     0,     0,   117,   118,   113,   114,   115,
     116,     0,     0,     0,   107,   108,   106,    14,     0,    18,
       0,     0,     0,    67,    63,     0,    76,     0,    90,    84,
      73,    74,    31,     0,    34,    35,    36,     0,    38,    40,
       0,    43,     8,     0,     0,     0,   102,   122,   105,    61,
       6,    13,    93,    10,    98,    91,     0,    30,    21,     0,
      42,    44,     0,    95,     0,     0,   121,     0,    92,     0,
      97,    96,    97,     0,   123,     0,    31,     0,     0,     0,
       0,    32,    22,   100,   101,    99,    94,    11,    16,    17,
      12
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -148,   247,  -148,  -148,  -148,  -148,  -148,  -148,  -130,  -148,
      -2,  -148,    -6,  -148,  -148,  -148,    32,  -148,  -148,   -91,
    -148,   109,  -148,    70,  -121,   208,  -148,    -3,  -148,  -148,
     -19,    88,    36,   -67,  -148,   136,  -148,  -148,    62,  -148,
    -148,  -148,   -92,  -148,  -148,   -56,  -148,  -148,   152,  -148,
    -148,  -147,  -148,  -148
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    30,     6,    31,   111,   207,   228,   230,   137,    44,
      84,    80,    88,    46,    58,   130,   197,   132,   174,    85,
     135,    92,   139,   141,    33,     7,    47,    89,    61,   115,
      35,    36,    77,    37,    62,    71,    38,   120,   168,    39,
      40,    95,   117,   213,   225,   101,   102,   153,   103,   104,
     151,    90,    41,   206
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      54,    32,   143,   110,    34,   187,    45,    63,   127,   128,
     175,   182,     9,    10,   192,    64,    65,   159,    93,     4,
     145,   146,   147,   148,     2,    56,    82,    64,    65,   190,
       5,   100,    57,   106,    53,    24,    83,    25,     3,    26,
     100,    94,    66,   178,   179,    96,    97,    98,    99,    48,
     183,    73,    74,   108,    66,   149,   150,    49,   214,   200,
      67,    68,    69,    70,    50,   -62,   -62,     9,    10,    51,
     112,   113,   226,   118,    42,    11,   -62,   -62,    73,    74,
      32,   134,    43,    34,    18,    52,   188,    60,   185,    87,
      24,   -62,    25,    72,    26,   163,   114,    73,    74,   157,
      28,    29,   -62,   158,    75,    76,   107,    55,    73,    74,
      73,    74,   176,   154,   155,    98,    99,    59,   217,     3,
     218,     8,     9,    10,    78,   100,    67,    68,    69,    70,
      11,    12,   186,    13,    14,    15,    16,    17,    79,    18,
      19,    20,    21,    22,    23,    24,    81,    25,    91,    26,
      82,    27,  -112,  -112,   191,    28,    29,    73,    74,   223,
     224,   125,   126,   170,   171,   203,   105,   198,   109,   116,
     119,   129,     8,     9,    10,   121,   122,   123,   124,   133,
     136,    11,   138,   211,    13,    14,    15,    16,    17,   131,
      18,    19,    20,    21,    22,    23,    24,   140,    25,   142,
      26,   -87,    27,     9,    10,   144,    28,    29,   -88,   152,
      11,   160,   161,   162,   164,   165,   172,   169,   173,   177,
     167,   180,   184,   193,   199,    53,    24,   189,    25,   196,
      26,   194,   195,   204,    24,   202,    28,    29,   205,   209,
     210,   212,   215,   216,   219,   220,   222,     1,   221,   181,
     227,   201,   229,   166,    86,     0,   156,   208
};

static const yytype_int16 yycheck[] =
{
      19,     7,    94,    59,     7,   152,     8,    26,    75,    76,
     131,   141,     4,     5,   161,     4,     5,   108,     3,    26,
       6,     7,     8,     9,     0,    19,    26,     4,     5,   159,
      12,    50,    26,    52,    26,    27,    36,    29,    14,    31,
      59,    26,    31,   134,   135,    37,    38,    39,    40,     3,
     142,    37,    38,    55,    31,    41,    42,    31,   205,   180,
      37,    38,    39,    40,    31,     4,     5,     4,     5,    31,
       4,     5,   219,    32,    26,    12,     4,     5,    37,    38,
      86,    83,    34,    86,    21,    31,   153,    26,   144,    26,
      27,    30,    29,    33,    31,   114,    30,    37,    38,   105,
      37,    38,    30,    32,    39,    40,    33,     3,    37,    38,
      37,    38,   131,    37,    38,    39,    40,    31,   210,    14,
     212,     3,     4,     5,    26,   144,    37,    38,    39,    40,
      12,    13,   151,    15,    16,    17,    18,    19,    31,    21,
      22,    23,    24,    25,    26,    27,    35,    29,    26,    31,
      26,    33,    39,    40,   160,    37,    38,    37,    38,     4,
       5,    73,    74,   127,   128,   184,    32,   173,    31,    34,
      26,     3,     3,     4,     5,    27,    27,    27,    27,    26,
      33,    12,    13,   202,    15,    16,    17,    18,    19,    30,
      21,    22,    23,    24,    25,    26,    27,    36,    29,    26,
      31,    26,    33,     4,     5,    33,    37,    38,    26,    32,
      12,    32,    32,    30,    33,    27,    26,    32,    32,    30,
      36,    30,    30,    20,    20,    26,    27,    33,    29,    36,
      31,    35,    26,    33,    27,    30,    37,    38,    15,     3,
       3,    26,    26,    26,    32,    31,    33,     0,   216,   140,
      32,   181,    33,   117,    46,    -1,   104,   195
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    44,     0,    14,    26,    12,    45,    68,     3,     4,
       5,    12,    13,    15,    16,    17,    18,    19,    21,    22,
      23,    24,    25,    26,    27,    29,    31,    33,    37,    38,
      44,    46,    55,    67,    70,    73,    74,    76,    79,    82,
      83,    95,    26,    34,    52,    53,    56,    69,     3,    31,
      31,    31,    31,    26,    73,     3,    19,    26,    57,    31,
      26,    71,    77,    73,     4,     5,    31,    37,    38,    39,
      40,    78,    33,    37,    38,    39,    40,    75,    26,    31,
      54,    35,    26,    36,    53,    62,    68,    26,    55,    70,
      94,    26,    64,     3,    26,    84,    37,    38,    39,    40,
      73,    88,    89,    91,    92,    32,    73,    33,    53,    31,
      88,    47,     4,     5,    30,    72,    34,    85,    32,    26,
      80,    27,    27,    27,    27,    74,    74,    76,    76,     3,
      58,    30,    60,    26,    53,    63,    33,    51,    13,    65,
      36,    66,    26,    85,    33,     6,     7,     8,     9,    41,
      42,    93,    32,    90,    37,    38,    91,    55,    32,    62,
      32,    32,    30,    73,    33,    27,    78,    36,    81,    32,
      75,    75,    26,    32,    61,    67,    73,    30,    62,    62,
      30,    64,    51,    85,    30,    88,    73,    94,    76,    33,
      51,    55,    94,    20,    35,    26,    36,    59,    55,    20,
      67,    66,    30,    73,    33,    15,    96,    48,    81,     3,
       3,    73,    26,    86,    94,    26,    26,    85,    85,    32,
      31,    59,    33,     4,     5,    87,    94,    32,    49,    33,
      50
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    43,    44,    45,    44,    46,    46,    46,    46,    47,
      48,    49,    46,    46,    46,    46,    50,    50,    51,    51,
      52,    52,    52,    54,    53,    56,    55,    57,    57,    58,
      58,    59,    59,    60,    60,    61,    61,    62,    62,    63,
      62,    65,    64,    66,    66,    67,    67,    67,    67,    67,
      68,    68,    68,    68,    68,    68,    68,    68,    69,    68,
      68,    70,    71,    70,    70,    72,    72,    72,    73,    73,
      73,    74,    75,    75,    75,    77,    76,    76,    76,    76,
      76,    78,    78,    78,    78,    79,    79,    79,    79,    80,
      80,    81,    81,    82,    83,    84,    84,    85,    85,    86,
      87,    87,    88,    88,    90,    89,    91,    91,    91,    91,
      91,    92,    92,    93,    93,    93,    93,    93,    93,    94,
      94,    95,    96,    96
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     0,     7,     0,     5,     2,     5,     0,
       0,     0,    11,     5,     4,     1,     0,     1,     0,     1,
       3,     5,     8,     0,     3,     0,     4,     1,     1,     0,
       3,     0,     4,     0,     2,     1,     1,     0,     3,     0,
       3,     0,     4,     0,     3,     1,     3,     3,     3,     3,
       0,     2,     2,     2,     2,     2,     4,     2,     0,     4,
       2,     5,     0,     4,     2,     1,     1,     2,     1,     3,
       3,     2,     0,     3,     3,     0,     4,     2,     3,     2,
       1,     0,     1,     1,     3,     1,     1,     1,     1,     0,
       2,     0,     3,     5,     9,     4,     5,     0,     3,     3,
       1,     1,     3,     1,     0,     3,     2,     1,     1,     1,
       1,     0,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     6,     0,     2
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
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
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

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
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
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
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  case 3: /* $@1: %empty  */
#line 56 "B092040016.y"
                                     {scopenum++;}
#line 1468 "y.tab.c"
    break;

  case 4: /* classes: classes CLASS ID LB $@1 statements RB  */
#line 56 "B092040016.y"
                                                                 {scopenum--;scopenum+=10;}
#line 1474 "y.tab.c"
    break;

  case 9: /* $@2: %empty  */
#line 63 "B092040016.y"
                        {if(lookup((yyvsp[0].strVal),scopenum)==-1)
					insert((yyvsp[0].strVal),scopenum); 
				else 
					printf("******\'%s\' is a duplicated identifier in the current scope.******\n",(yyvsp[0].strVal));
		}
#line 1484 "y.tab.c"
    break;

  case 10: /* $@3: %empty  */
#line 67 "B092040016.y"
                          {beused((yyvsp[-3].strVal),scopenum);}
#line 1490 "y.tab.c"
    break;

  case 11: /* $@4: %empty  */
#line 67 "B092040016.y"
                                                              {error_charnum=cpos;error_linenum=lc;}
#line 1496 "y.tab.c"
    break;

  case 16: /* nosemi: %empty  */
#line 73 "B092040016.y"
        {lack_commaid+=1;resetforclass();printf("Line %2d, char: %2d, statement without semicolon\n",error_linenum,error_charnum);}
#line 1502 "y.tab.c"
    break;

  case 18: /* semiornot: %empty  */
#line 77 "B092040016.y"
           {printf("Line %2d, char: %2d, statement without semicolon\n",error_linenum,error_charnum);}
#line 1508 "y.tab.c"
    break;

  case 20: /* func_orid: eachid comma_id semiornot  */
#line 80 "B092040016.y"
                                     {resettable();}
#line 1514 "y.tab.c"
    break;

  case 23: /* $@5: %empty  */
#line 84 "B092040016.y"
           {if(lookup((yyvsp[0].strVal),scopenum)==-1)
				insert((yyvsp[0].strVal),scopenum); 
			else
				printf("******\'%s\' is a duplicated identifier in the current scope.******\n",(yyvsp[0].strVal));
			error_charnum=cpos;error_linenum=lc;
		}
#line 1525 "y.tab.c"
    break;

  case 25: /* $@6: %empty  */
#line 91 "B092040016.y"
             {scopenum++;}
#line 1531 "y.tab.c"
    break;

  case 26: /* compound: LB $@6 statements RB  */
#line 91 "B092040016.y"
                                         {scopenum--;}
#line 1537 "y.tab.c"
    break;

  case 39: /* $@7: %empty  */
#line 109 "B092040016.y"
                         {
			lack_commaid+=1;
			printf("Line %2d, char: %2d, a syntax error at \"%s\"\n",error_linenum,error_charnum,(yyvsp[0].strVal));
		}
#line 1546 "y.tab.c"
    break;

  case 41: /* $@8: %empty  */
#line 114 "B092040016.y"
           {if(lookup((yyvsp[0].strVal),scopenum)==-1)
				insert((yyvsp[0].strVal),scopenum); 
			else
				printf("******\'%s\' is a duplicated identifier in the current scope.******\n",(yyvsp[0].strVal));
			error_charnum=cpos;error_linenum=lc;
		}
#line 1557 "y.tab.c"
    break;

  case 58: /* $@9: %empty  */
#line 144 "B092040016.y"
                                  {printf("******Else Without If at line %d, char %d******\n",lc,error_charnum-1);}
#line 1563 "y.tab.c"
    break;

  case 62: /* $@10: %empty  */
#line 149 "B092040016.y"
                    {beused((yyvsp[0].strVal),scopenum);}
#line 1569 "y.tab.c"
    break;

  case 75: /* $@11: %empty  */
#line 169 "B092040016.y"
           {beused((yyvsp[0].strVal),scopenum);}
#line 1575 "y.tab.c"
    break;

  case 104: /* $@12: %empty  */
#line 207 "B092040016.y"
                      {printf("******Invalid Boolean Expression at line %d,char %2d******\n",lc,cpos-operator_length-1);}
#line 1581 "y.tab.c"
    break;

  case 107: /* operator: '+'  */
#line 209 "B092040016.y"
                      {operator_length+=1;}
#line 1587 "y.tab.c"
    break;

  case 108: /* operator: '-'  */
#line 210 "B092040016.y"
                      {operator_length+=1;}
#line 1593 "y.tab.c"
    break;

  case 109: /* operator: '*'  */
#line 211 "B092040016.y"
                      {operator_length+=1;}
#line 1599 "y.tab.c"
    break;

  case 110: /* operator: '/'  */
#line 212 "B092040016.y"
                      {operator_length+=1;}
#line 1605 "y.tab.c"
    break;


#line 1609 "y.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

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
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 229 "B092040016.y"

void create(){
	count=0;
	front =(Node *)malloc(sizeof(Node));
	tail =(Node *)malloc(sizeof(Node));
}

int lookup(const char* search,int sco){

	if(count==0){return -1;}
	temp=front;
	for(int i=0;i<count;i++){
		if(strcmp(temp->identifier,search)==0 && temp->scope == sco){
			return temp->scope; //return scopenum of the id
		}
		temp = temp->next;
	}
	return -1;
}

int insert(const char* id,int sco){
	temp =(Node *)malloc(sizeof(Node));
	temp->identifier=(char *)malloc(sizeof(char)*(strlen(id)+1));
	strcpy(temp->identifier,id);
	temp->scope=scopenum;
	temp->used=0;
	temp->next=NULL;

	if(count==0){front=temp;tail=temp;}
	else{
		current=(Node *)malloc(sizeof(Node));
		current=front;
		for(int i=0;i<=count;i++){
			if(current->next!=NULL)
				current=current->next;
			else
				current->next=temp;
		}
	}
	count+=1;
	return count-1;
}

void beused(const char* used_id,int sco){//sco is the cuurent scope
	if(count==0){return;}
	temp=front;
	for(int i=0;i<count;i++){
		if(strcmp(temp->identifier,used_id)==0 && sco-temp->scope <= 5){
			 temp->used += 1;
			 break;
		}
		temp = temp->next;
	}
	
	return;
}

void usedornot(){
	if(count!=0){
		int flagnotuse=0;
		temp = front;
		for(int i=0;i<count;i++){
			if(temp->next!= NULL){
				if(temp->used==0){
					flagnotuse+=1;
				}
				temp = temp->next;
			}
			else {break;}
		}

		if(flagnotuse!=0){
			temp = front;
			printf("There are not used variable:\n");
			for(int i=0;i<count;i++){
				if(temp->used==0){
					printf("%s\n",temp->identifier);
				}
				if(temp->next!= NULL)
					temp = temp->next;
				else {break;}
			}	
		}
	}
}

void resetforclass(){
	if(count!=0 && lack_commaid!=0){
		temp = front;
		for(int i=0;i<count-lack_commaid;i++){
			if(i==count-lack_commaid-1){
				temp->next=NULL;
				tail=temp;
			}
			else{
				temp=temp->next;
			}
		}
		count=count-lack_commaid;
		lack_commaid=0;
	}
}

void resettable(){
	if(count!=0 && lack_commaid!=0){
		temp = front;
		for(int i=0;i<count-lack_commaid-1;i++){
			if(i==count-lack_commaid-2){
				temp->next=NULL;
				tail=temp;
			}
			else{
				temp=temp->next;
			}
		}
		count=count-lack_commaid-1;
		lack_commaid=0;
	}
}

void dump(){
	if(count!=0){
		printf("The symbol table contains:\n");
		temp = front;
		for(int i=0;i<count;i++){
			printf("%s %d\n",temp->identifier,temp->used);
			if(temp->next!= NULL)
				temp = temp->next;
			else {break;}
		}
	}
}

int main() {
    create();
    yyparse();
	usedornot();
	//dump();
    return 0;
}
