typedef enum {
	PD_RAISEBOX,
	PD_ENDLINE,
	PD_OVERLINE,
	PD_UNDERLINE,
	PD_FUNCTION,
	PD_FRAC,
	PD_BINOM,
	PD_OVER,
	PD_CHOOSE,
	PD_SQRT,
	PD_INT,
	PD_IINT,
	PD_IIINT,
	PD_IIIINT,
	PD_IDOTSINT,
	PD_OINT,
	PD_OIINT,
	PD_OIIINT,
	PD_OIIIINT,
	PD_OIDOTSINT,
	PD_SUM,
	PD_PROD,
	PD_SUPER,
	PD_SUB,
	PD_LIMITS,
	PD_LIM,
	PD_LEFTRIGHT,
	PD_SYMBOL,
	PD_BACKSLASH,
	PD_TEXT,
	PD_MATHBF,
	PD_MATHBFIT,
	PD_MATHCAL,
	PD_MATHSCR,
	PD_MATHFRAK,
	PD_MATHBB,
	PD_MATHSF,
	PD_MATHSFBF,
	PD_MATHSFIT,
	PD_MATHSFBFIT,
	PD_MATHTT,
	PD_MATHNORMAL,
	PD_BEGIN,
	PD_END,
	PD_BOX, /* custom command to make a box of some size */
	PD_PHANTOM,
	PD_VPHANTOM,
	PD_HPHANTOM,
/*	subsection for \begin ... \end sections */
	PD_ALIGN,
	PD_ARRAY,
	PD_CASES,
	PD_PMATRIX,
	PD_BMATRIX,
	PD_BBMATRIX,
	PD_VMATRIX,
	PD_MATRIX,
	PD_HLINE,
	PD_BLOCK,
	PD_SETROMAN,
	PD_SETITALIC,
	PD_SETBOLD,
	PD_SPACE,
	PD_DSPACE,
	PD_TSPACE,
	PD_NSPACE,
	PD_PRIME,
	PD_NONE
} PRSDEF;
typedef enum {
	F_ROMAN,
	F_ITALIC,
	F_BOLD,
	F_NOFONT
} FONT;

typedef enum {
	DEL_L,
	DEL_R,
	DEL_LSQ,
	DEL_RSQ,
	DEL_LCURL,
	DEL_RCURL,
	DEL_LANGLE,
	DEL_RANGLE,
	DEL_LCEIL,
	DEL_RCEIL,
	DEL_LFLOOR,
	DEL_RFLOOR,	
	DEL_VBAR,
	DEL_DVBAR,
	DEL_DOT,
	DEL_UPARROW,
	DEL_DOWNARROW,
	DEL_UPDOWNARROW,
	DEL_DUPARROW,
	DEL_DDOWNARROW,
	DEL_DUPDOWNARROW,
	DEL_SLASH,
	DEL_BACKSLASH,
	DEL_NONE,
} SCALABLE_DELIMITER;
	
typedef struct {
	char	**args;
	int	Nargs;
	char 	**opt;
	int 	Nopt;
	char 	*sub;
	char 	*super;
	char 	*next; /* reference to the next thing to lex */
	char 	*self; /* a reference to the own lexed string */
	int 	limits;
	PRSDEF  P;
	FONT	F;
} TOKEN;

void ListSymbols();
char * Symbols_Str();
TOKEN Lexer(char *begin, FONT F);
void FreeToken(TOKEN T);
void PrintToken(TOKEN T);
char * Unicode2Utf8(int U);
char * PreProcessor(char *string);
PRSDEF  LookupFont(char *begin);
SCALABLE_DELIMITER LookupDelimiter(char *begin, char **del);
