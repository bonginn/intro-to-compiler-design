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
#line 1 "parser.y"

#include "AST/BinaryOperator.hpp"
#include "AST/CompoundStatement.hpp"
#include "AST/ConstantValue.hpp"
#include "AST/FunctionInvocation.hpp"
#include "AST/UnaryOperator.hpp"
#include "AST/VariableReference.hpp"
#include "AST/assignment.hpp"
#include "AST/ast.hpp"
#include "AST/decl.hpp"
#include "AST/expression.hpp"
#include "AST/for.hpp"
#include "AST/function.hpp"
#include "AST/if.hpp"
#include "AST/print.hpp"
#include "AST/program.hpp"
#include "AST/read.hpp"
#include "AST/return.hpp"
#include "AST/variable.hpp"
#include "AST/while.hpp"
#include "AST/AstDumper.hpp"
#include "AST/PType.hpp"

#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>

#define YYLTYPE yyltype

typedef struct YYLTYPE {
    uint32_t first_line;
    uint32_t first_column;
    uint32_t last_line;
    uint32_t last_column;
} yyltype;

extern uint32_t line_num;   /* declared in scanner.l */
extern char current_line[]; /* declared in scanner.l */
extern FILE *yyin;          /* declared by lex */
extern char *yytext;        /* declared by lex */

static AstNode *root;

extern "C" int yylex(void);
static void yyerror(const char *msg);
extern int yylex_destroy(void);

#line 121 "parser.cpp"

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

#include "parser.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_COMMA = 3,                      /* COMMA  */
  YYSYMBOL_SEMICOLON = 4,                  /* SEMICOLON  */
  YYSYMBOL_COLON = 5,                      /* COLON  */
  YYSYMBOL_L_PARENTHESIS = 6,              /* L_PARENTHESIS  */
  YYSYMBOL_R_PARENTHESIS = 7,              /* R_PARENTHESIS  */
  YYSYMBOL_L_BRACKET = 8,                  /* L_BRACKET  */
  YYSYMBOL_R_BRACKET = 9,                  /* R_BRACKET  */
  YYSYMBOL_ASSIGN = 10,                    /* ASSIGN  */
  YYSYMBOL_MULTIPLY = 11,                  /* MULTIPLY  */
  YYSYMBOL_DIVIDE = 12,                    /* DIVIDE  */
  YYSYMBOL_MOD = 13,                       /* MOD  */
  YYSYMBOL_LESS = 14,                      /* LESS  */
  YYSYMBOL_LESS_OR_EQUAL = 15,             /* LESS_OR_EQUAL  */
  YYSYMBOL_EQUAL = 16,                     /* EQUAL  */
  YYSYMBOL_GREATER = 17,                   /* GREATER  */
  YYSYMBOL_GREATER_OR_EQUAL = 18,          /* GREATER_OR_EQUAL  */
  YYSYMBOL_NOT_EQUAL = 19,                 /* NOT_EQUAL  */
  YYSYMBOL_OR = 20,                        /* OR  */
  YYSYMBOL_AND = 21,                       /* AND  */
  YYSYMBOL_NOT = 22,                       /* NOT  */
  YYSYMBOL_PLUS = 23,                      /* PLUS  */
  YYSYMBOL_MINUS = 24,                     /* MINUS  */
  YYSYMBOL_ARRAY = 25,                     /* ARRAY  */
  YYSYMBOL_BOOLEAN = 26,                   /* BOOLEAN  */
  YYSYMBOL_INTEGER = 27,                   /* INTEGER  */
  YYSYMBOL_REAL = 28,                      /* REAL  */
  YYSYMBOL_STRING = 29,                    /* STRING  */
  YYSYMBOL_END = 30,                       /* END  */
  YYSYMBOL_BEGIN = 31,                     /* BEGIN  */
  YYSYMBOL_DO = 32,                        /* DO  */
  YYSYMBOL_ELSE = 33,                      /* ELSE  */
  YYSYMBOL_FOR = 34,                       /* FOR  */
  YYSYMBOL_IF = 35,                        /* IF  */
  YYSYMBOL_THEN = 36,                      /* THEN  */
  YYSYMBOL_WHILE = 37,                     /* WHILE  */
  YYSYMBOL_DEF = 38,                       /* DEF  */
  YYSYMBOL_OF = 39,                        /* OF  */
  YYSYMBOL_TO = 40,                        /* TO  */
  YYSYMBOL_RETURN = 41,                    /* RETURN  */
  YYSYMBOL_VAR = 42,                       /* VAR  */
  YYSYMBOL_FALSE = 43,                     /* FALSE  */
  YYSYMBOL_TRUE = 44,                      /* TRUE  */
  YYSYMBOL_PRINT = 45,                     /* PRINT  */
  YYSYMBOL_READ = 46,                      /* READ  */
  YYSYMBOL_ID = 47,                        /* ID  */
  YYSYMBOL_INT_LITERAL = 48,               /* INT_LITERAL  */
  YYSYMBOL_REAL_LITERAL = 49,              /* REAL_LITERAL  */
  YYSYMBOL_STRING_LITERAL = 50,            /* STRING_LITERAL  */
  YYSYMBOL_UMINUS = 51,                    /* UMINUS  */
  YYSYMBOL_YYACCEPT = 52,                  /* $accept  */
  YYSYMBOL_ProgramUnit = 53,               /* ProgramUnit  */
  YYSYMBOL_Program = 54,                   /* Program  */
  YYSYMBOL_ProgramName = 55,               /* ProgramName  */
  YYSYMBOL_DeclarationList = 56,           /* DeclarationList  */
  YYSYMBOL_Declarations = 57,              /* Declarations  */
  YYSYMBOL_FunctionList = 58,              /* FunctionList  */
  YYSYMBOL_Functions = 59,                 /* Functions  */
  YYSYMBOL_Function = 60,                  /* Function  */
  YYSYMBOL_FunctionDeclaration = 61,       /* FunctionDeclaration  */
  YYSYMBOL_FunctionDefinition = 62,        /* FunctionDefinition  */
  YYSYMBOL_FunctionName = 63,              /* FunctionName  */
  YYSYMBOL_FormalArgList = 64,             /* FormalArgList  */
  YYSYMBOL_FormalArgs = 65,                /* FormalArgs  */
  YYSYMBOL_FormalArg = 66,                 /* FormalArg  */
  YYSYMBOL_IdList = 67,                    /* IdList  */
  YYSYMBOL_ReturnType = 68,                /* ReturnType  */
  YYSYMBOL_Declaration = 69,               /* Declaration  */
  YYSYMBOL_Type = 70,                      /* Type  */
  YYSYMBOL_ScalarType = 71,                /* ScalarType  */
  YYSYMBOL_ArrType = 72,                   /* ArrType  */
  YYSYMBOL_ArrDecl = 73,                   /* ArrDecl  */
  YYSYMBOL_LiteralConstant = 74,           /* LiteralConstant  */
  YYSYMBOL_NegOrNot = 75,                  /* NegOrNot  */
  YYSYMBOL_StringAndBoolean = 76,          /* StringAndBoolean  */
  YYSYMBOL_IntegerAndReal = 77,            /* IntegerAndReal  */
  YYSYMBOL_Statement = 78,                 /* Statement  */
  YYSYMBOL_CompoundStatement = 79,         /* CompoundStatement  */
  YYSYMBOL_Simple = 80,                    /* Simple  */
  YYSYMBOL_VariableReference = 81,         /* VariableReference  */
  YYSYMBOL_ArrRefList = 82,                /* ArrRefList  */
  YYSYMBOL_ArrRefs = 83,                   /* ArrRefs  */
  YYSYMBOL_Condition = 84,                 /* Condition  */
  YYSYMBOL_ElseOrNot = 85,                 /* ElseOrNot  */
  YYSYMBOL_While = 86,                     /* While  */
  YYSYMBOL_For = 87,                       /* For  */
  YYSYMBOL_Return = 88,                    /* Return  */
  YYSYMBOL_FunctionCall = 89,              /* FunctionCall  */
  YYSYMBOL_FunctionInvocation = 90,        /* FunctionInvocation  */
  YYSYMBOL_ExpressionList = 91,            /* ExpressionList  */
  YYSYMBOL_Expressions = 92,               /* Expressions  */
  YYSYMBOL_StatementList = 93,             /* StatementList  */
  YYSYMBOL_Statements = 94,                /* Statements  */
  YYSYMBOL_Expression = 95,                /* Expression  */
  YYSYMBOL_Epsilon = 96                    /* Epsilon  */
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
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE) \
             + YYSIZEOF (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

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
#define YYFINAL  9
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   334

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  52
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  45
/* YYNRULES -- Number of rules.  */
#define YYNRULES  101
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  189

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   306


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
      45,    46,    47,    48,    49,    50,    51
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   178,   178,   180,   184,   197,   201,   203,   207,   209,
     216,   218,   222,   224,   231,   233,   237,   243,   251,   255,
     257,   263,   267,   274,   283,   288,   295,   297,   305,   312,
     321,   323,   327,   329,   331,   333,   337,   346,   350,   357,
     363,   369,   375,   377,   381,   385,   389,   395,   399,   409,
     411,   413,   415,   417,   419,   421,   425,   434,   438,   442,
     448,   454,   456,   462,   466,   473,   482,   485,   489,   497,
     525,   531,   537,   543,   545,   549,   551,   558,   560,   564,
     566,   573,   577,   581,   585,   589,   593,   597,   601,   605,
     609,   613,   617,   621,   625,   629,   633,   637,   639,   641,
     643,   651
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
  "\"end of file\"", "error", "\"invalid token\"", "COMMA", "SEMICOLON",
  "COLON", "L_PARENTHESIS", "R_PARENTHESIS", "L_BRACKET", "R_BRACKET",
  "ASSIGN", "MULTIPLY", "DIVIDE", "MOD", "LESS", "LESS_OR_EQUAL", "EQUAL",
  "GREATER", "GREATER_OR_EQUAL", "NOT_EQUAL", "OR", "AND", "NOT", "PLUS",
  "MINUS", "ARRAY", "BOOLEAN", "INTEGER", "REAL", "STRING", "END", "BEGIN",
  "DO", "ELSE", "FOR", "IF", "THEN", "WHILE", "DEF", "OF", "TO", "RETURN",
  "VAR", "FALSE", "TRUE", "PRINT", "READ", "ID", "INT_LITERAL",
  "REAL_LITERAL", "STRING_LITERAL", "UMINUS", "$accept", "ProgramUnit",
  "Program", "ProgramName", "DeclarationList", "Declarations",
  "FunctionList", "Functions", "Function", "FunctionDeclaration",
  "FunctionDefinition", "FunctionName", "FormalArgList", "FormalArgs",
  "FormalArg", "IdList", "ReturnType", "Declaration", "Type", "ScalarType",
  "ArrType", "ArrDecl", "LiteralConstant", "NegOrNot", "StringAndBoolean",
  "IntegerAndReal", "Statement", "CompoundStatement", "Simple",
  "VariableReference", "ArrRefList", "ArrRefs", "Condition", "ElseOrNot",
  "While", "For", "Return", "FunctionCall", "FunctionInvocation",
  "ExpressionList", "Expressions", "StatementList", "Statements",
  "Expression", "Epsilon", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-72)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-19)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -26,    19,    30,   -72,    29,   -72,   -72,   -72,    33,   -72,
       3,     1,     1,     2,     3,   -72,   -72,   -72,    43,    49,
     -72,    26,   -72,    31,   -72,    16,     2,   -72,   -72,   -72,
      67,     1,     7,    84,    79,     3,    50,   -72,   -11,     4,
     -72,   -72,   -72,    25,   -72,   -72,   -72,   -72,   -72,   -72,
     -72,    91,   -72,   -72,   -72,   -72,    72,    75,    -5,   -72,
     -72,    40,   -72,   -72,   -72,    52,    44,    36,   -72,   -72,
     -72,   -72,   -72,    41,    46,    46,    46,    46,    45,    32,
     -72,   -72,   -72,    81,   -72,   -72,   -72,   -72,   -72,    93,
      69,    40,   -72,   -72,   -72,    62,   111,    46,    46,    46,
     -72,   -72,   -72,   -72,   -72,   -72,   119,   149,   171,   189,
     116,   121,    46,    46,   -72,   118,   -72,    46,   -72,   -72,
     -72,   -72,    80,   222,   -72,   -72,    46,    46,    46,    46,
      46,    46,    46,    46,    46,    46,    46,    46,    46,    16,
      16,   -72,   -72,   -72,   120,   138,   268,   -72,   238,    46,
     207,   104,   -72,   -72,   -72,   -72,   296,   296,   296,   296,
     296,   296,   282,   310,     0,     0,   112,   117,   -72,    46,
     -72,   254,   -72,    98,    16,   122,   -72,   125,   268,   -72,
     126,   -72,   113,   -72,    16,   -72,   123,   139,   -72
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     5,     0,     2,     0,     3,    14,    15,     0,     1,
     101,   101,     0,   101,     7,     8,     6,    24,     0,    20,
      21,     0,    19,     0,    18,     0,    11,    12,    10,     9,
     101,     0,     0,     0,   101,   101,     0,    13,     0,     0,
      27,    22,    25,     0,    35,    32,    33,    34,    23,    30,
      31,     0,    43,    46,    45,    44,     0,     0,     0,    41,
      42,   101,     4,    26,    16,     0,     0,     0,    36,    28,
      29,    39,    40,     0,     0,     0,     0,     0,     0,   101,
      79,    49,    50,     0,    51,    52,    53,    54,    55,     0,
       0,    78,    77,    17,    37,     0,     0,     0,     0,     0,
      47,    48,    98,    97,    99,   100,     0,     0,     0,     0,
     101,     0,   101,     0,    60,    62,    61,     0,    71,    56,
      80,    38,     0,     0,    94,    82,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    70,    58,    59,     0,    74,    75,    73,     0,     0,
       0,     0,    81,    83,    84,    85,    88,    89,    92,    90,
      91,    93,    96,    95,    86,    87,   101,     0,    72,     0,
      63,     0,    57,     0,     0,     0,    67,     0,    76,    64,
       0,    66,     0,    68,     0,    65,     0,     0,    69
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -72,   -72,   -72,   -72,   115,   -72,   -72,   -72,    -4,   -72,
     -72,   -72,   -72,   -72,   143,   142,   -72,   137,   144,   -28,
     -72,   -72,   -72,   -72,   145,   -72,    85,   -25,   -72,   -59,
     -72,   -72,   -72,   -72,   -72,   -72,   -72,   -72,   -54,   -72,
     -72,   -72,   -72,   -71,   -10
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     3,     4,    13,    14,    25,    26,     5,     6,
       7,     8,    18,    19,    20,    21,    39,    15,    48,    49,
      50,    51,    57,    58,   102,   103,    80,    81,    82,   104,
     114,   115,    84,   175,    85,    86,    87,    88,   105,   144,
     145,    90,    91,   106,    16
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      36,    22,    83,    28,   107,   108,   109,    89,    64,    27,
      63,   126,   127,   128,    65,    44,    45,    46,    47,   111,
      40,     1,    37,    68,    60,   -18,   123,   124,   125,    32,
       9,    33,    83,    10,    32,    35,    34,    89,   112,    11,
     113,   146,   148,    71,    72,    12,   150,    35,    17,    24,
      30,    92,    97,    31,    42,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,    98,   116,
      99,    35,    38,    66,    73,    74,    69,    75,   171,    70,
      62,    76,    93,    94,    95,    77,    78,    79,    96,    53,
      54,   117,   110,    79,   100,   101,    55,   118,   178,   119,
     116,   121,   147,    52,    43,    44,    45,    46,    47,    43,
      44,    45,    46,    47,   166,   167,    67,    44,    45,    46,
      47,   122,    53,    54,   113,   143,   149,   168,   151,    55,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   169,   137,   138,   173,   174,   180,   177,   185,   181,
      61,    29,   182,   187,    23,   139,   176,   183,   184,   186,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   188,   137,   138,    41,   141,   120,     0,    56,    59,
       0,   140,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   142,   137,   138,     0,     0,     0,     0,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   172,   137,   138,     0,     0,     0,     0,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   152,
     137,   138,     0,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,     0,   137,   138,   170,     0,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
       0,   137,   138,   179,     0,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,     0,   137,   138,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
       0,   137,   138,   126,   127,   128,   129,   130,   131,   132,
     133,   134,     0,   136,     0,   137,   138,   126,   127,   128,
     -19,   -19,   -19,   -19,   -19,   -19,     0,     0,     0,   137,
     138,   126,   127,   128,   129,   130,   131,   132,   133,   134,
       0,     0,     0,   137,   138
};

static const yytype_int16 yycheck[] =
{
      25,    11,    61,    13,    75,    76,    77,    61,     4,    13,
      38,    11,    12,    13,    39,    26,    27,    28,    29,    78,
      30,    47,    26,    51,    34,     6,    97,    98,    99,     3,
       0,     5,    91,     4,     3,    31,     5,    91,     6,     6,
       8,   112,   113,    48,    49,    42,   117,    31,    47,    47,
       7,    61,     6,     4,    47,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,    22,    79,
      24,    31,     5,    48,    34,    35,     4,    37,   149,     4,
      30,    41,    30,    39,    48,    45,    46,    47,    47,    43,
      44,    10,    47,    47,    48,    49,    50,     4,   169,    30,
     110,    39,   112,    24,    25,    26,    27,    28,    29,    25,
      26,    27,    28,    29,   139,   140,    25,    26,    27,    28,
      29,    10,    43,    44,     8,     4,     8,     7,    48,    50,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,     3,    23,    24,    40,    33,    48,    30,    35,   174,
      35,    14,    30,    30,    12,    36,   166,    32,    32,   184,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    32,    23,    24,    31,     4,    91,    -1,    34,    34,
      -1,    32,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,     4,    23,    24,    -1,    -1,    -1,    -1,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,     4,    23,    24,    -1,    -1,    -1,    -1,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,     7,
      23,    24,    -1,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    -1,    23,    24,     9,    -1,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      -1,    23,    24,     9,    -1,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    -1,    23,    24,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      -1,    23,    24,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    -1,    21,    -1,    23,    24,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    -1,    -1,    -1,    23,
      24,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      -1,    -1,    -1,    23,    24
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    47,    53,    54,    55,    60,    61,    62,    63,     0,
       4,     6,    42,    56,    57,    69,    96,    47,    64,    65,
      66,    67,    96,    67,    47,    58,    59,    60,    96,    69,
       7,     4,     3,     5,     5,    31,    79,    60,     5,    68,
      96,    66,    47,    25,    26,    27,    28,    29,    70,    71,
      72,    73,    24,    43,    44,    50,    70,    74,    75,    76,
      96,    56,    30,    71,     4,    79,    48,    25,    71,     4,
       4,    48,    49,    34,    35,    37,    41,    45,    46,    47,
      78,    79,    80,    81,    84,    86,    87,    88,    89,    90,
      93,    94,    96,    30,    39,    48,    47,     6,    22,    24,
      48,    49,    76,    77,    81,    90,    95,    95,    95,    95,
      47,    81,     6,     8,    82,    83,    96,    10,     4,    30,
      78,    39,    10,    95,    95,    95,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    23,    24,    36,
      32,     4,     4,     4,    91,    92,    95,    96,    95,     8,
      95,    48,     7,    95,    95,    95,    95,    95,    95,    95,
      95,    95,    95,    95,    95,    95,    79,    79,     7,     3,
       9,    95,     4,    40,    33,    85,    96,    30,    95,     9,
      48,    79,    30,    32,    32,    35,    79,    30,    32
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    52,    53,    53,    54,    55,    56,    56,    57,    57,
      58,    58,    59,    59,    60,    60,    61,    62,    63,    64,
      64,    65,    65,    66,    67,    67,    68,    68,    69,    69,
      70,    70,    71,    71,    71,    71,    72,    73,    73,    74,
      74,    74,    75,    75,    76,    76,    76,    77,    77,    78,
      78,    78,    78,    78,    78,    78,    79,    80,    80,    80,
      81,    82,    82,    83,    83,    84,    85,    85,    86,    87,
      88,    89,    90,    91,    91,    92,    92,    93,    93,    94,
      94,    95,    95,    95,    95,    95,    95,    95,    95,    95,
      95,    95,    95,    95,    95,    95,    95,    95,    95,    95,
      95,    96
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     6,     1,     1,     1,     1,     2,
       1,     1,     1,     2,     1,     1,     6,     7,     1,     1,
       1,     1,     3,     3,     1,     3,     2,     1,     5,     5,
       1,     1,     1,     1,     1,     1,     2,     3,     4,     2,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     4,     4,     3,     3,
       2,     1,     1,     3,     4,     7,     2,     1,     6,    10,
       3,     2,     4,     1,     1,     1,     3,     1,     1,     1,
       2,     3,     2,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     2,     3,     3,     1,     1,     1,
       1,     0
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = TOK_YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == TOK_YYEMPTY)                                        \
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
   Use TOK_YYerror or TOK_YYUNDEF. */
#define YYERRCODE TOK_YYUNDEF

/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


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


/* YYLOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

# ifndef YYLOCATION_PRINT

#  if defined YY_LOCATION_PRINT

   /* Temporary convenience wrapper in case some people defined the
      undocumented and private YY_LOCATION_PRINT macros.  */
#   define YYLOCATION_PRINT(File, Loc)  YY_LOCATION_PRINT(File, *(Loc))

#  elif defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
}

#   define YYLOCATION_PRINT  yy_location_print_

    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT(File, Loc)  YYLOCATION_PRINT(File, &(Loc))

#  else

#   define YYLOCATION_PRINT(File, Loc) ((void) 0)
    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT  YYLOCATION_PRINT

#  endif
# endif /* !defined YYLOCATION_PRINT */


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (yylocationp);
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
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  YYLOCATION_PRINT (yyo, yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yykind, yyvaluep, yylocationp);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp,
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
                       &yyvsp[(yyi + 1) - (yynrhs)],
                       &(yylsp[(yyi + 1) - (yynrhs)]));
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
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
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YY_USE (yyvaluep);
  YY_USE (yylocationp);
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
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
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

    /* The location stack: array, bottom, top.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls = yylsa;
    YYLTYPE *yylsp = yyls;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

  /* The locations where the error started and ended.  */
  YYLTYPE yyerror_range[3];



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = TOK_YYEMPTY; /* Cause a token to be read.  */

  yylsp[0] = yylloc;
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
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yyls1, yysize * YYSIZEOF (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
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
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

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
  if (yychar == TOK_YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= TOK_YYEOF)
    {
      yychar = TOK_YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == TOK_YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = TOK_YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      yyerror_range[1] = yylloc;
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
  *++yylsp = yylloc;

  /* Discard the shifted token.  */
  yychar = TOK_YYEMPTY;
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

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 4: /* Program: ProgramName SEMICOLON DeclarationList FunctionList CompoundStatement END  */
#line 188 "parser.y"
        {
        root = new ProgramNode((yylsp[-5]).first_line, (yylsp[-5]).first_column,
                               (yyvsp[-5].identifier), (yyvsp[-3].declaration_list_ptr), (yyvsp[-2].function_list_ptr), (yyvsp[-1].compound_stmt_ptr));

        free((yyvsp[-5].identifier));
    }
#line 1490 "parser.cpp"
    break;

  case 6: /* DeclarationList: Epsilon  */
#line 201 "parser.y"
            { (yyval.declaration_list_ptr) = new std::vector <DeclNode *>(); }
#line 1496 "parser.cpp"
    break;

  case 7: /* DeclarationList: Declarations  */
#line 203 "parser.y"
                 { (yyval.declaration_list_ptr) = (yyvsp[0].declaration_list_ptr); }
#line 1502 "parser.cpp"
    break;

  case 8: /* Declarations: Declaration  */
#line 207 "parser.y"
                { (yyval.declaration_list_ptr) = new std::vector <DeclNode *>(1, (yyvsp[0].declaration_ptr)); }
#line 1508 "parser.cpp"
    break;

  case 9: /* Declarations: Declarations Declaration  */
#line 209 "parser.y"
                             {
        (yyval.declaration_list_ptr) = (yyvsp[-1].declaration_list_ptr);
        (yyval.declaration_list_ptr)->push_back((yyvsp[0].declaration_ptr));
    }
#line 1517 "parser.cpp"
    break;

  case 10: /* FunctionList: Epsilon  */
#line 216 "parser.y"
            { (yyval.function_list_ptr) = new std::vector <FunctionNode *>(); }
#line 1523 "parser.cpp"
    break;

  case 11: /* FunctionList: Functions  */
#line 218 "parser.y"
              { (yyval.function_list_ptr) = (yyvsp[0].function_list_ptr); }
#line 1529 "parser.cpp"
    break;

  case 12: /* Functions: Function  */
#line 222 "parser.y"
             { (yyval.function_list_ptr) = new std::vector <FunctionNode *>(1, (yyvsp[0].function_ptr)); }
#line 1535 "parser.cpp"
    break;

  case 13: /* Functions: Functions Function  */
#line 224 "parser.y"
                       {
        (yyval.function_list_ptr) = (yyvsp[-1].function_list_ptr);
        (yyval.function_list_ptr)->push_back((yyvsp[0].function_ptr));
    }
#line 1544 "parser.cpp"
    break;

  case 14: /* Function: FunctionDeclaration  */
#line 231 "parser.y"
                        { (yyval.function_ptr) = (yyvsp[0].function_ptr); }
#line 1550 "parser.cpp"
    break;

  case 15: /* Function: FunctionDefinition  */
#line 233 "parser.y"
                       { (yyval.function_ptr) = (yyvsp[0].function_ptr); }
#line 1556 "parser.cpp"
    break;

  case 16: /* FunctionDeclaration: FunctionName L_PARENTHESIS FormalArgList R_PARENTHESIS ReturnType SEMICOLON  */
#line 237 "parser.y"
                                                                                {
        (yyval.function_ptr) = new FunctionNode((yylsp[-5]).first_line, (yylsp[-5]).first_column, (yyvsp[-5].identifier), (yyvsp[-3].declaration_list_ptr), (yyvsp[-1].type_ptr), nullptr);
    }
#line 1564 "parser.cpp"
    break;

  case 17: /* FunctionDefinition: FunctionName L_PARENTHESIS FormalArgList R_PARENTHESIS ReturnType CompoundStatement END  */
#line 245 "parser.y"
        {
        (yyval.function_ptr) = new FunctionNode((yylsp[-6]).first_line, (yylsp[-6]).first_column, (yyvsp[-6].identifier), (yyvsp[-4].declaration_list_ptr), (yyvsp[-2].type_ptr), (yyvsp[-1].compound_stmt_ptr));
    }
#line 1572 "parser.cpp"
    break;

  case 18: /* FunctionName: ID  */
#line 251 "parser.y"
       { (yyval.identifier) = (yyvsp[0].identifier); }
#line 1578 "parser.cpp"
    break;

  case 19: /* FormalArgList: Epsilon  */
#line 255 "parser.y"
            { (yyval.declaration_list_ptr) = new std::vector <DeclNode *>(); }
#line 1584 "parser.cpp"
    break;

  case 20: /* FormalArgList: FormalArgs  */
#line 257 "parser.y"
               {
        (yyval.declaration_list_ptr) = (yyvsp[0].declaration_list_ptr);
    }
#line 1592 "parser.cpp"
    break;

  case 21: /* FormalArgs: FormalArg  */
#line 263 "parser.y"
              {
        (yyval.declaration_list_ptr) = new std::vector <DeclNode *>(1, (yyvsp[0].declaration_ptr));
    }
#line 1600 "parser.cpp"
    break;

  case 22: /* FormalArgs: FormalArgs SEMICOLON FormalArg  */
#line 267 "parser.y"
                                   {
        (yyval.declaration_list_ptr) = (yyvsp[-2].declaration_list_ptr);
        (yyval.declaration_list_ptr)->push_back((yyvsp[0].declaration_ptr));
    }
#line 1609 "parser.cpp"
    break;

  case 23: /* FormalArg: IdList COLON Type  */
#line 274 "parser.y"
                      {
        for (auto &v : *(yyvsp[-2].variable_list_ptr)) {
            v->setType((yyvsp[0].type_ptr));
        }
        (yyval.declaration_ptr) = new DeclNode((yylsp[-2]).first_line, (yylsp[-2]).first_column, (yyvsp[-2].variable_list_ptr));
    }
#line 1620 "parser.cpp"
    break;

  case 24: /* IdList: ID  */
#line 283 "parser.y"
       {
        (yyval.variable_list_ptr) = new std::vector<VariableNode*>();
        (yyval.variable_list_ptr)->push_back(new VariableNode((yylsp[0]).first_line, (yylsp[0]).first_column, (yyvsp[0].identifier)));
    }
#line 1629 "parser.cpp"
    break;

  case 25: /* IdList: IdList COMMA ID  */
#line 288 "parser.y"
                    {
        (yyval.variable_list_ptr) = (yyvsp[-2].variable_list_ptr);
        (yyval.variable_list_ptr)->push_back(new VariableNode((yylsp[0]).first_line, (yylsp[0]).first_column, (yyvsp[0].identifier)));
    }
#line 1638 "parser.cpp"
    break;

  case 26: /* ReturnType: COLON ScalarType  */
#line 295 "parser.y"
                     { (yyval.type_ptr) = (yyvsp[0].type_ptr); }
#line 1644 "parser.cpp"
    break;

  case 27: /* ReturnType: Epsilon  */
#line 297 "parser.y"
            { (yyval.type_ptr) = nullptr; }
#line 1650 "parser.cpp"
    break;

  case 28: /* Declaration: VAR IdList COLON Type SEMICOLON  */
#line 305 "parser.y"
                                    {
        for (auto &v : *(yyvsp[-3].variable_list_ptr)) {
            v->setType((yyvsp[-1].type_ptr));
        }
        (yyval.declaration_ptr) = new DeclNode((yylsp[-4]).first_line, (yylsp[-4]).first_column, (yyvsp[-3].variable_list_ptr));
    }
#line 1661 "parser.cpp"
    break;

  case 29: /* Declaration: VAR IdList COLON LiteralConstant SEMICOLON  */
#line 312 "parser.y"
                                               {
        for (auto &v : *(yyvsp[-3].variable_list_ptr)){
            v->setConstant((yyvsp[-1].constant_value_ptr));
        }
        (yyval.declaration_ptr) = new DeclNode((yylsp[-4]).first_line, (yylsp[-4]).first_column, (yyvsp[-3].variable_list_ptr));
    }
#line 1672 "parser.cpp"
    break;

  case 30: /* Type: ScalarType  */
#line 321 "parser.y"
               { (yyval.type_ptr) = (yyvsp[0].type_ptr); }
#line 1678 "parser.cpp"
    break;

  case 31: /* Type: ArrType  */
#line 323 "parser.y"
            { (yyval.type_ptr) = (yyvsp[0].type_ptr); }
#line 1684 "parser.cpp"
    break;

  case 32: /* ScalarType: INTEGER  */
#line 327 "parser.y"
            { (yyval.type_ptr) = new PType(PType::kInteger); }
#line 1690 "parser.cpp"
    break;

  case 33: /* ScalarType: REAL  */
#line 329 "parser.y"
         { (yyval.type_ptr) = new PType(PType::kReal); }
#line 1696 "parser.cpp"
    break;

  case 34: /* ScalarType: STRING  */
#line 331 "parser.y"
           { (yyval.type_ptr) = new PType(PType::kString); }
#line 1702 "parser.cpp"
    break;

  case 35: /* ScalarType: BOOLEAN  */
#line 333 "parser.y"
            { (yyval.type_ptr) = new PType(PType::kBoolean); }
#line 1708 "parser.cpp"
    break;

  case 36: /* ArrType: ArrDecl ScalarType  */
#line 337 "parser.y"
                       {
        (yyval.type_ptr) = (yyvsp[0].type_ptr);
        for (auto &dim : *(yyvsp[-1].dimension_list_ptr)) {
            (yyval.type_ptr)->addDimension(dim);
        }
    }
#line 1719 "parser.cpp"
    break;

  case 37: /* ArrDecl: ARRAY INT_LITERAL OF  */
#line 346 "parser.y"
                         {
        (yyval.dimension_list_ptr) = new std::vector <int>(1, (yyvsp[-1].int_literal));
    }
#line 1727 "parser.cpp"
    break;

  case 38: /* ArrDecl: ArrDecl ARRAY INT_LITERAL OF  */
#line 350 "parser.y"
                                {
        (yyval.dimension_list_ptr) = (yyvsp[-3].dimension_list_ptr);
        (yyval.dimension_list_ptr)->push_back((yyvsp[-1].int_literal));
    }
#line 1736 "parser.cpp"
    break;

  case 39: /* LiteralConstant: NegOrNot INT_LITERAL  */
#line 357 "parser.y"
                         {
        (yyval.constant_value_ptr) = ((yyvsp[-1].neg_or_not)) ? 
            new ConstantValueNode((yylsp[-1]).first_line, (yylsp[-1]).first_column, new PType(PType::kInteger), -(yyvsp[0].int_literal)) :
            new ConstantValueNode((yylsp[0]).first_line, (yylsp[0]).first_column, new PType(PType::kInteger), (yyvsp[0].int_literal));
    }
#line 1746 "parser.cpp"
    break;

  case 40: /* LiteralConstant: NegOrNot REAL_LITERAL  */
#line 363 "parser.y"
                          {
        (yyval.constant_value_ptr) = ((yyvsp[-1].neg_or_not)) ? 
            new ConstantValueNode((yylsp[-1]).first_line, (yylsp[-1]).first_column, new PType(PType::kReal), -(yyvsp[0].real_literal)) :
            new ConstantValueNode((yylsp[0]).first_line, (yylsp[0]).first_column, new PType(PType::kReal), (yyvsp[0].real_literal));
    }
#line 1756 "parser.cpp"
    break;

  case 41: /* LiteralConstant: StringAndBoolean  */
#line 369 "parser.y"
                     {
        (yyval.constant_value_ptr) = (yyvsp[0].constant_value_ptr);
    }
#line 1764 "parser.cpp"
    break;

  case 42: /* NegOrNot: Epsilon  */
#line 375 "parser.y"
            { (yyval.neg_or_not) = false;}
#line 1770 "parser.cpp"
    break;

  case 43: /* NegOrNot: MINUS  */
#line 377 "parser.y"
          { (yyval.neg_or_not) = true;}
#line 1776 "parser.cpp"
    break;

  case 44: /* StringAndBoolean: STRING_LITERAL  */
#line 381 "parser.y"
                   {
        (yyval.constant_value_ptr) = new ConstantValueNode((yylsp[0]).first_line, (yylsp[0]).first_column, new PType(PType::kString), (yyvsp[0].string_literal));
    }
#line 1784 "parser.cpp"
    break;

  case 45: /* StringAndBoolean: TRUE  */
#line 385 "parser.y"
         {
        (yyval.constant_value_ptr) = new ConstantValueNode((yylsp[0]).first_line, (yylsp[0]).first_column, new PType(PType::kBoolean), true);
    }
#line 1792 "parser.cpp"
    break;

  case 46: /* StringAndBoolean: FALSE  */
#line 389 "parser.y"
          {
        (yyval.constant_value_ptr) = new ConstantValueNode((yylsp[0]).first_line, (yylsp[0]).first_column, new PType(PType::kBoolean), false);
    }
#line 1800 "parser.cpp"
    break;

  case 47: /* IntegerAndReal: INT_LITERAL  */
#line 395 "parser.y"
                {
        (yyval.constant_value_ptr) = new ConstantValueNode((yylsp[0]).first_line, (yylsp[0]).first_column, new PType(PType::kInteger), (yyvsp[0].int_literal));
    }
#line 1808 "parser.cpp"
    break;

  case 48: /* IntegerAndReal: REAL_LITERAL  */
#line 399 "parser.y"
                 {
        (yyval.constant_value_ptr) = new ConstantValueNode((yylsp[0]).first_line, (yylsp[0]).first_column, new PType(PType::kReal), (yyvsp[0].real_literal));
    }
#line 1816 "parser.cpp"
    break;

  case 49: /* Statement: CompoundStatement  */
#line 409 "parser.y"
                      { (yyval.node) = (yyvsp[0].compound_stmt_ptr); }
#line 1822 "parser.cpp"
    break;

  case 50: /* Statement: Simple  */
#line 411 "parser.y"
           { (yyval.node) = (yyvsp[0].node); }
#line 1828 "parser.cpp"
    break;

  case 51: /* Statement: Condition  */
#line 413 "parser.y"
              { (yyval.node) = (yyvsp[0].if_ptr); }
#line 1834 "parser.cpp"
    break;

  case 52: /* Statement: While  */
#line 415 "parser.y"
          { (yyval.node) = (yyvsp[0].while_ptr); }
#line 1840 "parser.cpp"
    break;

  case 53: /* Statement: For  */
#line 417 "parser.y"
        { (yyval.node) = (yyvsp[0].for_ptr); }
#line 1846 "parser.cpp"
    break;

  case 54: /* Statement: Return  */
#line 419 "parser.y"
           { (yyval.node) = (yyvsp[0].return_ptr); }
#line 1852 "parser.cpp"
    break;

  case 55: /* Statement: FunctionCall  */
#line 421 "parser.y"
                 { (yyval.node) = (yyvsp[0].node); }
#line 1858 "parser.cpp"
    break;

  case 56: /* CompoundStatement: BEGIN DeclarationList StatementList END  */
#line 428 "parser.y"
        {
        (yyval.compound_stmt_ptr) = new CompoundStatementNode((yylsp[-3]).first_line, (yylsp[-3]).first_column, (yyvsp[-2].declaration_list_ptr), (yyvsp[-1].node_list_ptr));
    }
#line 1866 "parser.cpp"
    break;

  case 57: /* Simple: VariableReference ASSIGN Expression SEMICOLON  */
#line 434 "parser.y"
                                                  {
        (yyval.node) = new AssignmentNode((yylsp[-2]).first_line, (yylsp[-2]).first_column, (yyvsp[-3].variable_reference_ptr), (yyvsp[-1].expression_ptr));
    }
#line 1874 "parser.cpp"
    break;

  case 58: /* Simple: PRINT Expression SEMICOLON  */
#line 438 "parser.y"
                               {
        (yyval.node) = new PrintNode((yylsp[-2]).first_line, (yylsp[-2]).first_column, (yyvsp[-1].expression_ptr));
    }
#line 1882 "parser.cpp"
    break;

  case 59: /* Simple: READ VariableReference SEMICOLON  */
#line 442 "parser.y"
                                     {
        (yyval.node) = new ReadNode((yylsp[-2]).first_line, (yylsp[-2]).first_column, (yyvsp[-1].variable_reference_ptr));
    }
#line 1890 "parser.cpp"
    break;

  case 60: /* VariableReference: ID ArrRefList  */
#line 448 "parser.y"
                  {
        (yyval.variable_reference_ptr) = new VariableReferenceNode((yylsp[-1]).first_line, (yylsp[-1]).first_column, (yyvsp[-1].identifier), (yyvsp[0].expression_list_ptr));
    }
#line 1898 "parser.cpp"
    break;

  case 61: /* ArrRefList: Epsilon  */
#line 454 "parser.y"
            { (yyval.expression_list_ptr) = new std::vector <ExpressionNode*>(); }
#line 1904 "parser.cpp"
    break;

  case 62: /* ArrRefList: ArrRefs  */
#line 456 "parser.y"
            {
        (yyval.expression_list_ptr) = (yyvsp[0].expression_list_ptr);
    }
#line 1912 "parser.cpp"
    break;

  case 63: /* ArrRefs: L_BRACKET Expression R_BRACKET  */
#line 462 "parser.y"
                                   {
        (yyval.expression_list_ptr) = new std::vector <ExpressionNode*>(1, (yyvsp[-1].expression_ptr));
    }
#line 1920 "parser.cpp"
    break;

  case 64: /* ArrRefs: ArrRefs L_BRACKET Expression R_BRACKET  */
#line 466 "parser.y"
                                           {
        (yyval.expression_list_ptr) = (yyvsp[-3].expression_list_ptr);
        (yyval.expression_list_ptr)->push_back((yyvsp[-1].expression_ptr));
    }
#line 1929 "parser.cpp"
    break;

  case 65: /* Condition: IF Expression THEN CompoundStatement ElseOrNot END IF  */
#line 476 "parser.y"
           {
        (yyval.if_ptr) = new IfNode((yylsp[-6]).first_line, (yylsp[-6]).first_column, (yyvsp[-5].expression_ptr), (yyvsp[-3].compound_stmt_ptr), (yyvsp[-2].compound_stmt_ptr));
    }
#line 1937 "parser.cpp"
    break;

  case 66: /* ElseOrNot: ELSE CompoundStatement  */
#line 483 "parser.y"
                      { (yyval.compound_stmt_ptr) = (yyvsp[0].compound_stmt_ptr); }
#line 1943 "parser.cpp"
    break;

  case 67: /* ElseOrNot: Epsilon  */
#line 485 "parser.y"
            { (yyval.compound_stmt_ptr) = nullptr;}
#line 1949 "parser.cpp"
    break;

  case 68: /* While: WHILE Expression DO CompoundStatement END DO  */
#line 491 "parser.y"
           {
        (yyval.while_ptr) = new WhileNode((yylsp[-5]).first_line, (yylsp[-5]).first_column, (yyvsp[-4].expression_ptr), (yyvsp[-2].compound_stmt_ptr));
    }
#line 1957 "parser.cpp"
    break;

  case 69: /* For: FOR ID ASSIGN INT_LITERAL TO INT_LITERAL DO CompoundStatement END DO  */
#line 499 "parser.y"
           {
        // Variable Node
        VariableNode *var = new VariableNode((yylsp[-8]).first_line, (yylsp[-8]).first_column, (yyvsp[-8].identifier));
        var->setType(new PType(PType::kInteger));

        // Declaration Node
        DeclNode *decl = new DeclNode((yylsp[-8]).first_line, (yylsp[-8]).first_column, new std::vector<VariableNode*>(1, var));

        // Variable Reference Node
        VariableReferenceNode *var_ref = new VariableReferenceNode((yylsp[-8]).first_line, (yylsp[-8]).first_column, (yyvsp[-8].identifier), new std::vector<ExpressionNode*>());

        // Initial value
        ConstantValueNode *init_value = new ConstantValueNode((yylsp[-6]).first_line, (yylsp[-6]).first_column, new PType(PType::kInteger), (yyvsp[-6].int_literal));

        // Assignment Node
        AssignmentNode *assign = new AssignmentNode((yylsp[-7]).first_line, (yylsp[-7]).first_column, var_ref, init_value);

        // Upper Bound Node
        ConstantValueNode *upper_bound = new ConstantValueNode((yylsp[-4]).first_line, (yylsp[-4]).first_column, new PType(PType::kInteger), (yyvsp[-4].int_literal));

        // For Node
        (yyval.for_ptr) = new ForNode((yylsp[-9]).first_line, (yylsp[-9]).first_column, decl, assign, upper_bound, (yyvsp[-2].compound_stmt_ptr));
    }
#line 1985 "parser.cpp"
    break;

  case 70: /* Return: RETURN Expression SEMICOLON  */
#line 525 "parser.y"
                                {
        (yyval.return_ptr) = new ReturnNode((yylsp[-2]).first_line, (yylsp[-2]).first_column, (yyvsp[-1].expression_ptr));
    }
#line 1993 "parser.cpp"
    break;

  case 71: /* FunctionCall: FunctionInvocation SEMICOLON  */
#line 531 "parser.y"
                                 {
        (yyval.node) = (yyvsp[-1].function_invocation_ptr);
    }
#line 2001 "parser.cpp"
    break;

  case 72: /* FunctionInvocation: ID L_PARENTHESIS ExpressionList R_PARENTHESIS  */
#line 537 "parser.y"
                                                  {
        (yyval.function_invocation_ptr) = new FunctionInvocationNode((yylsp[-3]).first_line, (yylsp[-3]).first_column, (yyvsp[-3].identifier), (yyvsp[-1].expression_list_ptr));
    }
#line 2009 "parser.cpp"
    break;

  case 73: /* ExpressionList: Epsilon  */
#line 543 "parser.y"
            { (yyval.expression_list_ptr) = new std::vector <ExpressionNode*>(); }
#line 2015 "parser.cpp"
    break;

  case 74: /* ExpressionList: Expressions  */
#line 545 "parser.y"
                { (yyval.expression_list_ptr) = (yyvsp[0].expression_list_ptr); }
#line 2021 "parser.cpp"
    break;

  case 75: /* Expressions: Expression  */
#line 549 "parser.y"
               { (yyval.expression_list_ptr) = new std::vector <ExpressionNode*>(1, (yyvsp[0].expression_ptr)); }
#line 2027 "parser.cpp"
    break;

  case 76: /* Expressions: Expressions COMMA Expression  */
#line 551 "parser.y"
                                 {
        (yyval.expression_list_ptr) = (yyvsp[-2].expression_list_ptr);
        (yyval.expression_list_ptr)->push_back((yyvsp[0].expression_ptr));
    }
#line 2036 "parser.cpp"
    break;

  case 77: /* StatementList: Epsilon  */
#line 558 "parser.y"
            { (yyval.node_list_ptr) = new std::vector <AstNode*>(); }
#line 2042 "parser.cpp"
    break;

  case 78: /* StatementList: Statements  */
#line 560 "parser.y"
               { (yyval.node_list_ptr) = (yyvsp[0].node_list_ptr); }
#line 2048 "parser.cpp"
    break;

  case 79: /* Statements: Statement  */
#line 564 "parser.y"
              { (yyval.node_list_ptr) = new std::vector <AstNode*>(1, (yyvsp[0].node)); }
#line 2054 "parser.cpp"
    break;

  case 80: /* Statements: Statements Statement  */
#line 566 "parser.y"
                         {
        (yyval.node_list_ptr) = (yyvsp[-1].node_list_ptr);
        (yyval.node_list_ptr)->push_back((yyvsp[0].node));
    }
#line 2063 "parser.cpp"
    break;

  case 81: /* Expression: L_PARENTHESIS Expression R_PARENTHESIS  */
#line 573 "parser.y"
                                           {
        (yyval.expression_ptr) = (yyvsp[-1].expression_ptr);
    }
#line 2071 "parser.cpp"
    break;

  case 82: /* Expression: MINUS Expression  */
#line 577 "parser.y"
                                  {
        (yyval.expression_ptr) = new UnaryOperatorNode((yylsp[-1]).first_line, (yylsp[-1]).first_column, new OperatorNode(OperatorNode::UNARY_MINUS), (yyvsp[0].expression_ptr));
    }
#line 2079 "parser.cpp"
    break;

  case 83: /* Expression: Expression MULTIPLY Expression  */
#line 581 "parser.y"
                                   {
        (yyval.expression_ptr) = new BinaryOperatorNode((yylsp[-1]).first_line, (yylsp[-1]).first_column, new OperatorNode(OperatorNode::MULTIPLY), (yyvsp[-2].expression_ptr), (yyvsp[0].expression_ptr));
    }
#line 2087 "parser.cpp"
    break;

  case 84: /* Expression: Expression DIVIDE Expression  */
#line 585 "parser.y"
                                 {
        (yyval.expression_ptr) = new BinaryOperatorNode((yylsp[-1]).first_line, (yylsp[-1]).first_column, new OperatorNode(OperatorNode::DIVIDE), (yyvsp[-2].expression_ptr), (yyvsp[0].expression_ptr));
    }
#line 2095 "parser.cpp"
    break;

  case 85: /* Expression: Expression MOD Expression  */
#line 589 "parser.y"
                              {
        (yyval.expression_ptr) = new BinaryOperatorNode((yylsp[-1]).first_line, (yylsp[-1]).first_column, new OperatorNode(OperatorNode::MOD), (yyvsp[-2].expression_ptr), (yyvsp[0].expression_ptr));
    }
#line 2103 "parser.cpp"
    break;

  case 86: /* Expression: Expression PLUS Expression  */
#line 593 "parser.y"
                               {
        (yyval.expression_ptr) = new BinaryOperatorNode((yylsp[-1]).first_line, (yylsp[-1]).first_column, new OperatorNode(OperatorNode::PLUS), (yyvsp[-2].expression_ptr), (yyvsp[0].expression_ptr));
    }
#line 2111 "parser.cpp"
    break;

  case 87: /* Expression: Expression MINUS Expression  */
#line 597 "parser.y"
                                {
        (yyval.expression_ptr) = new BinaryOperatorNode((yylsp[-1]).first_line, (yylsp[-1]).first_column, new OperatorNode(OperatorNode::MINUS), (yyvsp[-2].expression_ptr), (yyvsp[0].expression_ptr));
    }
#line 2119 "parser.cpp"
    break;

  case 88: /* Expression: Expression LESS Expression  */
#line 601 "parser.y"
                               {
        (yyval.expression_ptr) = new BinaryOperatorNode((yylsp[-1]).first_line, (yylsp[-1]).first_column, new OperatorNode(OperatorNode::LESS), (yyvsp[-2].expression_ptr), (yyvsp[0].expression_ptr));
    }
#line 2127 "parser.cpp"
    break;

  case 89: /* Expression: Expression LESS_OR_EQUAL Expression  */
#line 605 "parser.y"
                                        {
        (yyval.expression_ptr) = new BinaryOperatorNode((yylsp[-1]).first_line, (yylsp[-1]).first_column, new OperatorNode(OperatorNode::LESS_OR_EQUAL), (yyvsp[-2].expression_ptr), (yyvsp[0].expression_ptr));
    }
#line 2135 "parser.cpp"
    break;

  case 90: /* Expression: Expression GREATER Expression  */
#line 609 "parser.y"
                                  {
        (yyval.expression_ptr) = new BinaryOperatorNode((yylsp[-1]).first_line, (yylsp[-1]).first_column, new OperatorNode(OperatorNode::GREATER), (yyvsp[-2].expression_ptr), (yyvsp[0].expression_ptr));
    }
#line 2143 "parser.cpp"
    break;

  case 91: /* Expression: Expression GREATER_OR_EQUAL Expression  */
#line 613 "parser.y"
                                           {
        (yyval.expression_ptr) = new BinaryOperatorNode((yylsp[-1]).first_line, (yylsp[-1]).first_column, new OperatorNode(OperatorNode::GREATER_OR_EQUAL), (yyvsp[-2].expression_ptr), (yyvsp[0].expression_ptr));
    }
#line 2151 "parser.cpp"
    break;

  case 92: /* Expression: Expression EQUAL Expression  */
#line 617 "parser.y"
                                {
        (yyval.expression_ptr) = new BinaryOperatorNode((yylsp[-1]).first_line, (yylsp[-1]).first_column, new OperatorNode(OperatorNode::EQUAL), (yyvsp[-2].expression_ptr), (yyvsp[0].expression_ptr));
    }
#line 2159 "parser.cpp"
    break;

  case 93: /* Expression: Expression NOT_EQUAL Expression  */
#line 621 "parser.y"
                                    {
        (yyval.expression_ptr) = new BinaryOperatorNode((yylsp[-1]).first_line, (yylsp[-1]).first_column, new OperatorNode(OperatorNode::NOT_EQUAL), (yyvsp[-2].expression_ptr), (yyvsp[0].expression_ptr));
    }
#line 2167 "parser.cpp"
    break;

  case 94: /* Expression: NOT Expression  */
#line 625 "parser.y"
                   {
        (yyval.expression_ptr) = new UnaryOperatorNode((yylsp[-1]).first_line, (yylsp[-1]).first_column, new OperatorNode(OperatorNode::NOT), (yyvsp[0].expression_ptr));
    }
#line 2175 "parser.cpp"
    break;

  case 95: /* Expression: Expression AND Expression  */
#line 629 "parser.y"
                              {
        (yyval.expression_ptr) = new BinaryOperatorNode((yylsp[-1]).first_line, (yylsp[-1]).first_column, new OperatorNode(OperatorNode::AND), (yyvsp[-2].expression_ptr), (yyvsp[0].expression_ptr));
    }
#line 2183 "parser.cpp"
    break;

  case 96: /* Expression: Expression OR Expression  */
#line 633 "parser.y"
                             {
        (yyval.expression_ptr) = new BinaryOperatorNode((yylsp[-1]).first_line, (yylsp[-1]).first_column, new OperatorNode(OperatorNode::OR), (yyvsp[-2].expression_ptr), (yyvsp[0].expression_ptr));
    }
#line 2191 "parser.cpp"
    break;

  case 97: /* Expression: IntegerAndReal  */
#line 637 "parser.y"
                   { (yyval.expression_ptr) = (yyvsp[0].constant_value_ptr); }
#line 2197 "parser.cpp"
    break;

  case 98: /* Expression: StringAndBoolean  */
#line 639 "parser.y"
                     { (yyval.expression_ptr) = (yyvsp[0].constant_value_ptr); }
#line 2203 "parser.cpp"
    break;

  case 99: /* Expression: VariableReference  */
#line 641 "parser.y"
                      { (yyval.expression_ptr) = (yyvsp[0].variable_reference_ptr); }
#line 2209 "parser.cpp"
    break;

  case 100: /* Expression: FunctionInvocation  */
#line 643 "parser.y"
                       {
        (yyval.expression_ptr) = (yyvsp[0].function_invocation_ptr);
    }
#line 2217 "parser.cpp"
    break;


#line 2221 "parser.cpp"

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
  *++yylsp = yyloc;

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
  yytoken = yychar == TOK_YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  yyerror_range[1] = yylloc;
  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= TOK_YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == TOK_YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval, &yylloc);
          yychar = TOK_YYEMPTY;
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

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  ++yylsp;
  YYLLOC_DEFAULT (*yylsp, yyerror_range, 2);

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
  if (yychar != TOK_YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 654 "parser.y"


void yyerror(const char *msg) {
    fprintf(stderr,
            "\n"
            "|-----------------------------------------------------------------"
            "---------\n"
            "| Error found in Line #%d: %s\n"
            "|\n"
            "| Unmatched token: %s\n"
            "|-----------------------------------------------------------------"
            "---------\n",
            line_num, current_line, yytext);
    exit(-1);
}

int main(int argc, const char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename> [--dump-ast]\n", argv[0]);
        exit(-1);
    }

    yyin = fopen(argv[1], "r");
    if (yyin == NULL) {
        perror("fopen() failed");
        exit(-1);
    }

    yyparse();

    if (argc >= 3 && strcmp(argv[2], "--dump-ast") == 0) {
        AstDumper ast_dumper;
        root->accept(ast_dumper);
    }

    printf("\n"
           "|--------------------------------|\n"
           "|  There is no syntactic error!  |\n"
           "|--------------------------------|\n");

    delete root;
    fclose(yyin);
    yylex_destroy();
    return 0;
}
