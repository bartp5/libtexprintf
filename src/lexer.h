typedef enum {
	PD_RAISEBOX,
	PD_ENDLINE,
	PD_COMB_GRAVE,
	PD_COMB_ACUTE,
	PD_COMB_HAT,
	PD_COMB_TILDE,
	PD_COMB_BREVE,
	PD_COMB_DOT,
	PD_COMB_DIAERESIS,
	PD_COMB_MRING,
	PD_COMB_DACUTE,
	PD_COMB_CARON,
	PD_COMB_CEDILLA,
	PD_COMB_OGONEK,
	PD_COMB_UTILDE,
	PD_COMB_SSOLIDUS,
	PD_COMB_LSOLIDUS,
	PD_COMB_OVERLINE,
	PD_COMB_UNDERLINE,

	// auto generated
	PD_COMB_LVEC,
	PD_COMB_LLVEC,
	PD_COMB_VEC,
	PD_COMB_DDDOT,
	PD_COMB_DDDDOT,
	PD_COMB_OVERLEFTRIGHTARROW,
	PD_COMB_OCIRC,
	PD_COMB_OVHOOK,
	PD_COMB_OTURNEDCOMMA,
	PD_COMB_OCOMMATOPRIGHT,
	PD_COMB_DROANG,
	PD_COMB_LEFTHARPOONACCENT,
	PD_COMB_RIGHTHARPOONACCENT,
	PD_COMB_WIDEBRIDGEABOVE,
	PD_COMB_ASTERACCENT,
	PD_COMB_CANDRA,
	PD_COMB_WIDEUTILDE,
	PD_COMB_THREEUNDERDOT,
	PD_COMB_UNDERLEFTARROW,
	PD_COMB_UNDERRIGHTARROW,
	PD_COMB_UNDERBAR,
	PD_COMB_UNDERLEFTRIGHTARROW,
	PD_COMB_UNDERRIGHTHARPOONDOWN,
	PD_COMB_UNDERLEFTHARPOONDOWN,
	PD_COMB_PALH,
	PD_COMB_RH,
	PD_COMB_SBBRG,
	PD_COMB_SOUT,
	PD_COMB_STRIKE,
	PD_COMB_ANNUITY,
	PD_COMB_ENCLOSECIRCLE,
	PD_COMB_ENCLOSESQUARE,
	PD_COMB_ENCLOSEDIAMOND,
	PD_COMB_ENCLOSETRIANGLE,
	PD_COMB_VERTOVERLAY,
	
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
	PD_ROOTFONT, // switch to the root font for $...$ 
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
	PD_VVMATRIX,
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
int IsTexConstruct(char *string);
TOKEN Lexer(char *begin, FONT F);
void FreeToken(TOKEN T);
void PrintToken(TOKEN T);
char * Unicode2Utf8(int U);
char * PreProcessor(char *string2);
PRSDEF  LookupFont(char *begin);
SCALABLE_DELIMITER LookupDelimiter(char *begin, char **del);
void LookupCombining(PRSDEF P, unsigned int *comb, unsigned int *alt, unsigned int *altascii);
