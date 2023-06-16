
typedef struct {
	char           *name;
	PRSDEF          P; /* the PRSDEF enummerator type is declared in lexer.h */
	int 			Nargs;
	int 			Nopt;
} KEYWORD;
/* base context keywords */
const KEYWORD   Keys[] = {
	{"\\raisebox",  PD_RAISEBOX   	, 2, 0},
	{"\\int",  		PD_INT     	, 0, 1},
	{"\\iint",  	PD_IINT     	, 0, 1},
	{"\\iiint",  	PD_IIINT     	, 0, 1},
	{"\\iiiint",  	PD_IIIINT     	, 0, 1},
	{"\\idotsint",  PD_IDOTSINT   	, 0, 1},
	{"\\oint",  	PD_OINT     	, 0, 1},
	{"\\oiint",  	PD_OIINT     	, 0, 1},
	{"\\oiiint",  	PD_OIIINT     	, 0, 1},
	{"\\oiiiint",  	PD_OIIIINT    	, 0, 1},
	{"\\oidotsint", PD_OIDOTSINT  	, 0, 1},
	{"\\overline",  PD_OVERLINE    , 1, 0},
	{"\\underline", PD_UNDERLINE   , 1, 0},
	{"\\mathsfbfit",PD_MATHSFBFIT	, 1, 0},
	{"\\mathsfbf",  PD_MATHSFBF	, 1, 0},
	{"\\mathfrak",  PD_MATHFRAK	, 1, 0},
	{"\\mathbfit",  PD_MATHBFIT	, 1, 0},
	{"\\mathsfit",  PD_MATHSFIT	, 1, 0},
	{"\\mathcal",  	PD_MATHCAL		, 1, 0},
	{"\\mathscr",  	PD_MATHSCR		, 1, 0},
	{"\\mathbf",  	PD_MATHBF		, 1, 0},
	{"\\mathbb",  	PD_MATHBB		, 1, 0},
	{"\\mathsf",  	PD_MATHSF		, 1, 0},
	{"\\mathtt",  	PD_MATHTT		, 1, 0},
	{"\\mathnormal",PD_MATHNORMAL	, 1, 0},
	{"\\text",		PD_TEXT		, 1, 0},
	{"\\backslash", PD_BACKSLASH	, 0, 0},
	{"\\begin", 	PD_BEGIN   	, 1, 0},
	{"\\frac", 		PD_FRAC    	, 2, 0},
	{"\\binom", 	PD_BINOM   	, 2, 0},
	{"\\sqrt", 		PD_SQRT    	, 1, 1},
	{"\\left", 		PD_LEFTRIGHT   , 0, 0},
	{"\\prod",  	PD_PROD    	, 0, 0},
	{"\\sum",  		PD_SUM     	, 0, 0},
	{"\\bar",  		PD_OVERLINE    , 1, 0},
	{"\\box",  		PD_BOX     	, 2, 0},
	{"\\phantom",  	PD_PHANTOM     	, 1, 0},
	{"\\vphantom",  PD_VPHANTOM   	, 1, 0},
	{"\\hphantom",  PD_HPHANTOM    	, 1, 0},
	{"\\limits",  	PD_LIMITS      , 1, 0},
	{"\\lim",  		PD_LIM   		, 0, 0},
	{"\\over", 		PD_OVER   		, 0, 0},
	{"\\choose", 	PD_CHOOSE  		, 0, 0},
	{"\\exp",  		PD_FUNCTION   	, 0, 0},
	{"\\ln",  		PD_FUNCTION   	, 0, 0},
	{"\\log",  		PD_FUNCTION   	, 0, 0},
	{"\\min",  		PD_FUNCTION   	, 0, 0},
	{"\\max",  		PD_FUNCTION   	, 0, 0},
	{"\\sin",  		PD_FUNCTION   	, 0, 0},
	{"\\cos",  		PD_FUNCTION   	, 0, 0},
	{"\\tan",  		PD_FUNCTION   	, 0, 0},
	{"\\cot",  		PD_FUNCTION   	, 0, 0},
	{"\\arcsin",	PD_FUNCTION   	, 0, 0},
	{"\\arccos",	PD_FUNCTION   	, 0, 0},
	{"\\arctan",	PD_FUNCTION   	, 0, 0},
	{"\\arccot",	PD_FUNCTION   	, 0, 0},
	{"\\sinh", 		PD_FUNCTION   	, 0, 0},
	{"\\cosh", 		PD_FUNCTION   	, 0, 0},
	{"\\tanh", 		PD_FUNCTION   	, 0, 0},
	{"\\coth", 		PD_FUNCTION   	, 0, 0},
	{"\\sec",  		PD_FUNCTION   	, 0, 0},
	{"\\csc",  		PD_FUNCTION   	, 0, 0},
	{"\\deg",  		PD_FUNCTION   	, 0, 0},
	{"\\det",  		PD_FUNCTION   	, 0, 0},
	{"\\arg",  		PD_FUNCTION   	, 0, 0},
	{"\\it",		PD_SETITALIC	, 0, 0},
	{"\\bf",  		PD_SETBOLD		, 0, 0},
	{"\\rm",  		PD_SETROMAN	, 0, 0},
	{"\\mathrm",	PD_TEXT		, 1, 0},
	{"^",      		PD_SUPER   	, 2, 0},
	{"_",      		PD_SUB     	, 2, 0},
	{"\\\\",      	PD_ENDLINE    	, 0, 0},
	{"\\ ",      	PD_SPACE    	, 0, 0}, /* in monospace fonts small spacing is a minimal one space wide */
	{"\\,",      	PD_NSPACE    	, 0, 0}, /* dummy for no space */
	{"\\-",      	PD_NSPACE    	, 0, 0}, /* what is \- in latex math mode. with me it does not through an arror and I see no change */
	{"\\;",      	PD_SPACE    	, 0, 0},
	{"\\:",      	PD_SPACE    	, 0, 0},
	{"\\quad",      PD_DSPACE    	, 0, 0},
	{"\\qquad",     PD_TSPACE    	, 0, 0},
	{NULL, 			PD_NONE 		, 0, 0},
};

/* context dependent keywords */
const KEYWORD   Envs[] = {
	{"aligned",  	PD_ALIGN     	, 0, 0},
	{"align*",  	PD_ALIGN     	, 0, 0},
	{"align",  		PD_ALIGN     	, 0, 0},
	{"array",  		PD_ARRAY     	, 1, 1},
	{"cases*",  	PD_CASES    	, 0, 1},
	{"cases",  		PD_CASES    	, 0, 1},
	{"pmatrix*",  	PD_PMATRIX    	, 0, 1},
	{"pmatrix",  	PD_PMATRIX    	, 0, 1},
	{"bmatrix*",  	PD_BMATRIX    	, 0, 1},
	{"bmatrix",  	PD_BMATRIX    	, 0, 1},
	{"Bmatrix*",  	PD_BBMATRIX    , 0, 1},
	{"Bmatrix",  	PD_BBMATRIX    , 0, 1},
	{"vmatrix*",  	PD_VMATRIX    	, 0, 1},
	{"vmatrix",  	PD_VMATRIX    	, 0, 1},
	{"Vmatrix*",  	PD_VVMATRIX    	, 0, 1},
	{"Vmatrix",  	PD_VVMATRIX    	, 0, 1},
	{"matrix*",  	PD_MATRIX    	, 0, 1},
	{"matrix",  	PD_MATRIX    	, 0, 1},
	{"\\begin", 	PD_BEGIN   	, 0, 0},
	{"\\end", 		PD_END   		, 0, 0},
	{"\\hline",  	PD_HLINE     	, 0, 0},
	{NULL, 			PD_NONE		, 0, 0},
};


typedef struct {
	char *name;
	SCALABLE_DELIMITER D;
} DELIMITER;


const DELIMITER   DelTable[] = {
	{"(", DEL_L},
	{")", DEL_R},
	{"[", DEL_LSQ},
	{"]", DEL_RSQ},
	{"{", DEL_LCURL},
	{"}", DEL_RCURL},
	{"<", DEL_LANGLE},
	{">", DEL_RANGLE},
	{"⌈", DEL_LCEIL}, /* note some strings in this table are UTF-8 encoded */
	{"⌉", DEL_RCEIL},
	{"⌊", DEL_LFLOOR},
	{"⌋", DEL_RFLOOR},	
	{"|", DEL_VBAR},
	{"‖", DEL_DVBAR},
	{".", DEL_DOT},
	{"↑", DEL_UPARROW},
	{"↓", DEL_DOWNARROW},
	{"↕", DEL_UPDOWNARROW},
	{"⇑", DEL_DUPARROW},
	{"⇓", DEL_DDOWNARROW},
	{"⇕", DEL_DUPDOWNARROW},
	{"/", DEL_SLASH},
	{"\\backslash", DEL_BACKSLASH}, /* backslash is not substituted by the preprocessor as would collide with the use as an escape character
									 * thus the whole string \backslash remains and needs to be matched */
	{NULL, DEL_NONE}
};

typedef struct {
	char *name;
	unsigned int unicode;
} Symbol;

/* note symbols take presedence over keywords */

const Symbol  Symbols[] = {
/* basic latin */
//	{"\\,",                    0x00020}, /* take spacing out of the preprocessor */
//	{"\\;",                    0x00020}, /* take spacing out of the preprocessor */
	{"\\_",                    0x0005F},
	{"\\{",                    0x0007B},
	{"\\}",                    0x0007D},
	{"\\lbrac",                0x0005B},
//	{"\\backslash",            0x0005C}, /* this cannot work as this table is for the pre-processor, it is defined as an argument-less command */
	{"\\rbrac",                0x0005D},
	{"\\sphat",                0x0005E},
	{"\\sptilde",              0x0007E},
/* latin supplement*/
	{"\\cent",                 0x000A2},
	{"\\pounds",               0x000A3},
	{"\\yen",                  0x000A5},
	{"\\neg",                  0x000AC},
	{"\\circledR",             0x000AE},
	{"\\pm",                   0x000B1},
	{"\\Micro",                0x000B5},
	{"\\times",                0x000D7},
	{"\\eth",                  0x000F0},
	{"\\div",                  0x000F7},
/* latin extended A & B*/
	{"\\imath",                0x00131},
	{"\\jmath",                0x00237},
/* combining diacritical marks*/
	{"\\grave",                0x00300},
	{"\\`",                    0x00300},
	{"\\acute",                0x00301},
	{"\\'",                    0x00301},
	{"\\hat",                  0x00302},
	{"\\^",                    0x00302},
	{"\\tilde",                0x00303},
	{"\\~",                    0x00303},
	{"\\utfbar",               0x00304}, 
	{"\\utfoverline",          0x00305},
	{"\\breve",                0x00306},
	{"\\dot",                  0x00307}, 
	{"\\ddot",                 0x00308}, 
	{"\\\"",                   0x00308}, 
	{"\\mathring",             0x0030A}, 
	{"\\H",                    0x0030B},
	{"\\check",                0x0030C},
	{"\\c", 				   0x00327}, 
	{"\\k", 				   0x00328}, 
	{"\\utilde",               0x00330},
	{"\\utfunderbar",          0x00331},
	{"\\utfunderline",         0x00332}, 
	{"\\l",                    0x00337}, 
	{"\\not",                  0x00338}, 
/* hat and bar are made scalable */
/* greek symbols */
	/* upper case */
	{"\\Gamma",                0x00393},
	{"\\Delta",                0x00394},
	{"\\Theta",                0x00398},
	{"\\Lambda",               0x0039B},	
	{"\\Xi",                   0x0039E},
	{"\\Pi",                   0x003A0},
	{"\\Sigma",                0x003A3},
	{"\\Upsilon",              0x003A5},
	{"\\Phi",                  0x003A6},
	{"\\Psi",                  0x003A8},
	{"\\Omega",                0x003A9},
	
	/* lower case */
	{"\\alpha",                0x003B1},
	{"\\beta",                 0x003B2},
	{"\\gamma",                0x003B3},
	{"\\delta",                0x003B4},
	{"\\varepsilon",           0x003B5},
	{"\\epsilon",              0x003F5},
	{"\\backepsilon",          0x003F6},
	{"\\zeta",                 0x003B6},
	{"\\eta",                  0x003B7},
	{"\\theta",                0x003B8},
	{"\\iota",                 0x003B9},
	{"\\kappa",                0x003BA},
	{"\\lambda",               0x003BB},
	{"\\mu",                   0x003BC},
	{"\\nu",                   0x003BD},
	{"\\Nu",                   0x0039D},
	{"\\xi",                   0x003BE},
	{"\\pi",                   0x003C0},
	{"\\rho",                  0x003C1},
	{"\\varrho",               0x003F1},
	{"\\sigma",                0x003C3},
	{"\\varsigma",             0x003C2},
	{"\\tau",                  0x003C4},
	{"\\upsilon",              0x003C5},
	{"\\varphi",               0x1D711},
	{"\\chi",                  0x003C7},
	{"\\psi",                  0x003C8},
	{"\\omega",                0x003C9},
	{"\\varbeta",              0x003D0},
	{"\\vartheta",             0x003D1},
	{"\\phi",                  0x003D5},
	{"\\varpi",                0x003D6},
	{"\\Qoppa",                0x003D8},
	{"\\qoppa",                0x003D9},
	{"\\Stigma",               0x003DA},
	{"\\stigma",               0x003DB},
	{"\\Digamma",              0x003DC},
	{"\\digamma",              0x003DD},
	{"\\Koppa",                0x003DE},
	{"\\koppa",                0x003DF},
	{"\\Sampi",                0x003E0},
	{"\\sampi",                0x003E1},
/* general punktuation */
//	{"\\quad",                 0x02001},
	{"\\|",                    0x02016},
	{"\\dagger",               0x02020},
	{"\\ddagger",              0x02021},
	{"\\ldots",                0x02026},
	{"\\prime",                0x02032},
	{"\\pprime",               0x02033},
	{"\\second",               0x02033},
	{"\\third",                0x02034},
	{"\\ppprime",               0x02034},
	{"\\backprime",            0x02035},
	{"\\backpprime",           0x02036},
	{"\\backppprime",          0x02037},
	{"\\cat",                  0x02040},
	{"\\fourth",               0x02057},
	{"\\pppprime",             0x02057}, 
//	{"\\:",                    0x02001}, /* this should be medspace U0x0205F, however, I need fixed spaced fonts so we make it a full space */
//	{"\\ ",                    0x02001}, 
/* combining diacritical marks for symbols, it seems with me these symbols are treated as full chacaters and not combining marks as should be */
	{"\\lvec",                 0x020D0},
	{"\\Lvec",                 0x020D6},
	{"\\vec",                  0x020D7},
	{"\\dddot",                0x020DB}, 
	{"\\ddddot",               0x020DC}, 
	{"\\overleftrightarrow",   0x020E1}, 
/* Letterlike Symbols */
/*some symbols require a latex command structure, those I leave out here */
	{"\\Euler",   			   0x02107}, 
	{"\\hslash",   			   0x0210F}, 
	{"\\Im",  	 			   0x02111}, 
	{"\\ell",  	 			   0x02113}, 
	{"\\wp",  	 			   0x02118}, 
	{"\\Re",  	 			   0x0211C}, 
	{"\\tcohm",  	 		   0x02126}, 
	{"\\mho",	  	 		   0x02127}, 
	{"\\Angstroem",	 		   0x0212B}, 
	{"\\Finv",	  	 		   0x02132},  
	{"\\aleph",  	 		   0x02135},  
	{"\\beth",  	 		   0x02136},  
	{"\\gimel",  	 		   0x02137},  
	{"\\daleth",  	 		   0x02138},  
	{"\\Yup",  	 			   0x02144},  
	{"\\CapitalDifferentialD", 0x02145}, 
	{"\\DifferentialD",		   0x02146},  
	{"\\ExponetialE",		   0x02147},  
	{"\\ComplexI",			   0x02148},  
	{"\\ComplexJ",			   0x02149}, 
	{"\\invamp",			   0x0214B}, 
	
/* arrows */
	{"\\leftarrow",            0x02190},
	{"\\uparrow",              0x02191},
	{"\\to",           		   0x02192}, 
	{"\\rightarrow",           0x02192},
	{"\\downarrow",            0x02193},
	{"\\leftrightarrow",       0x02194},
	{"\\updownarrow",          0x02195},
	{"\\nwarrow",              0x02196},
	{"\\nearrow",              0x02197},
	{"\\searrow",              0x02198},
	{"\\swarrow",              0x02199},
	{"\\nleftarrow",           0x0219A},
	{"\\nrightarrow",          0x0219B},
	{"\\twoheadleftarrow",     0x0219E},
	{"\\twoheadrightarrow",    0x021A0},
	{"\\leftarrowtail",        0x021A2},
	{"\\rightarrowtail",       0x021A3},
	{"\\mapsfrom",             0x021A4},
	{"\\MapsUp",               0x021A5},
	{"\\mapsto",               0x021A6},
	{"\\MapsDown",             0x021A7},
	{"\\hookleftarrow", 0x021A9},
	{"\\hookrightarrow", 0x021AA},
	{"\\looparrowleft", 0x021AB},
	{"\\looparrowright", 0x021AC},
	{"\\leftrightsquigarrow", 0x021AD},
	{"\\nleftrightarrow", 0x021AE},
	{"\\lightning", 0x021AF},
	{"\\Lsh", 0x021B0},
	{"\\Rsh", 0x021B1},
	{"\\dlsh", 0x021B2},
	{"\\drsh", 0x021B3},
	{"\\curvearrowleft", 0x021B6},
	{"\\curvearrowright", 0x021B7},
	{"\\circlearrowleft", 0x021BA},
	{"\\circlearrowright", 0x021BB},
	{"\\leftharpoonup", 0x021BC},
	{"\\leftharpoondown", 0x021BD},
	{"\\upharpoonright", 0x021BE},
	{"\\upharpoonleft", 0x021BF},
	{"\\rightharpoonup", 0x021C0},
	{"\\rightharpoondown", 0x021C1},
	{"\\downharpoonright", 0x021C2},
	{"\\downharpoonleft", 0x021C3},
	{"\\rightleftarrows", 0x021C4},
	{"\\updownarrows", 0x021C5},
	{"\\leftrightarrows", 0x021C6},
	{"\\leftleftarrows", 0x021C7},
	{"\\upuparrows", 0x021C8},
	{"\\rightrightarrows", 0x021C9},
	{"\\downdownarrows", 0x021CA},
	{"\\leftrightharpoons", 0x021CB},
	{"\\rightleftharpoons", 0x021CC},
	{"\\nLeftarrow", 0x021CD},
	{"\\nLeftrightarrow", 0x021CE},
	{"\\nRightarrow", 0x021CF},
	{"\\Leftarrow", 0x021D0},
	{"\\Uparrow", 0x021D1},
	{"\\Rightarrow", 0x021D2},
	{"\\Downarrow", 0x021D3},
	{"\\Leftrightarrow", 0x021D4},
	{"\\Updownarrow", 0x021D5},
	{"\\Nwarrow", 0x021D6},
	{"\\Nearrow", 0x021D7},
	{"\\Searrow", 0x021D8},
	{"\\Swarrow", 0x021D9},
	{"\\Lleftarrow", 0x021DA},
	{"\\Rrightarrow", 0x021DB},
	{"\\leftsquigarrow", 0x021DC},
	{"\\rightsquigarrow", 0x021DD},
	{"\\dashleftarrow", 0x021E0},
	{"\\dashrightarrow", 0x021E2},
	{"\\LeftArrowBar", 0x021E4},
	{"\\RightArrowBar", 0x021E5},
	{"\\downuparrows", 0x021F5},
	{"\\pfun", 0x021F8},
	{"\\ffun", 0x021FB},
	{"\\leftarrowtriangle", 0x021FD},
	{"\\rightarrowtriangle", 0x021FE},
	{"\\leftrightarrowtriangle", 0x021FF},	/* to be continued */
	
	/* mathematical operators */
	{"\\forall", 0x02200},
	{"\\complement", 0x02201},
	{"\\partialup", 0x02202},
	{"\\exists", 0x02203},
	{"\\nexists", 0x02204},
	{"\\varnothing", 0x02205},
	{"\\nabla", 0x02207},
	{"\\in", 0x02208},
	{"\\notin", 0x02209},
	{"\\ni", 0x0220B},
	{"\\nni", 0x0220C},
	{"\\utfprod", 0x0220F},
	{"\\coprod", 0x02210},
	{"\\utfsum", 0x02211},
	{"\\mp", 0x02213},
	{"\\dotplus", 0x02214},
	{"\\slash", 0x02215},
	{"\\smallsetminus", 0x02216},
	{"\\ast", 0x02217},
	{"\\circ", 0x02218},
	{"\\bullet", 0x02219},	
	{"\\utfsqrt", 0x0221A},
	{"\\utfsqrt[3]", 0x0221B},
	{"\\utfsqrt[4]", 0x0221C},
	{"\\propto", 0x0221D},
	{"\\infty", 0x0221E},
	{"\\rightangle", 0x0221F},
	{"\\angle", 0x02220},
	{"\\measuredangle", 0x02221},
	{"\\sphericalangle", 0x02222},
	{"\\mid", 0x02223},
	{"\\nmid", 0x02224},
	{"\\parallel", 0x02225},
	{"\\nparallel", 0x02226},
	{"\\wedge", 0x02227},
	{"\\vee", 0x02228},
	{"\\cap", 0x02229},
	{"\\cup", 0x0222A},
	{"\\utfint", 0x0222B},
	{"\\utfiint", 0x0222C},
	{"\\utfiiint", 0x0222D},
	{"\\utfoint", 0x0222E},
	{"\\utfoiint", 0x0222F},
	{"\\utfoiiint", 0x02230},
	{"\\varointclockwise", 0x02232},
	{"\\ointctrclockwise", 0x02233},
	{"\\therefore", 0x02234},
	{"\\because", 0x02235},
	{"\\Proportion", 0x02237},
	{"\\eqcolon", 0x02239},
	{"\\sim", 0x0223C},
	{"\\backsim", 0x0223D},
	{"\\AC", 0x0223F},
	{"\\wr", 0x02240},
	{"\\nsim", 0x02241},
	{"\\eqsim", 0x02242},
	{"\\simeq", 0x02243},
	{"\\nsimeq", 0x02244},
	{"\\cong", 0x02245},
	{"\\ncong", 0x02247},
	{"\\approx", 0x02248},
	{"\\napprox", 0x02249},
	{"\\approxeq", 0x0224A},
	{"\\asymp", 0x0224D},
	{"\\Bumpeq", 0x0224E},
	{"\\bumpeq", 0x0224F},
	{"\\doteq", 0x02250},
	{"\\Doteq", 0x02251},
	{"\\fallingdotseq", 0x02252},
	{"\\risingdotseq", 0x02253},
	{"\\coloneq", 0x02254},
	{"\\eqcolon", 0x02255},
	{"\\eqcirc", 0x02256},
	{"\\circeq", 0x02257},
	{"\\corresponds", 0x02259},
	{"\\triangleq", 0x0225C},
	{"\\neq", 0x02260},
	{"\\equiv", 0x02261},
	{"\\nequiv", 0x02262},
	{"\\leq", 0x02264},
	{"\\geq", 0x02265},
	{"\\leqq", 0x02266},
	{"\\geqq", 0x02267},
	{"\\lneqq", 0x02268},
	{"\\gneqq", 0x02269},
	{"\\ll", 0x0226A},
	{"\\gg", 0x0226B},
	{"\\between", 0x0226C},
	{"\\notasymp", 0x0226D},
	{"\\nless", 0x0226E},
	{"\\ngtr", 0x0226F},
	{"\\nleq", 0x02270},
	{"\\ngeq", 0x02271},
	{"\\lesssim", 0x02272},
	{"\\gtrsim", 0x02273},
	{"\\NotLessTilde", 0x02274},
	{"\\NotGreaterTilde", 0x02275},
	{"\\lessgtr", 0x02276},
	{"\\gtrless", 0x02277},
	{"\\NotGreaterLess", 0x02279},
	{"\\prec", 0x0227A},
	{"\\succ", 0x0227B},
	{"\\preccurlyeq", 0x0227C},
	{"\\succcurlyeq", 0x0227D},
	{"\\precsim", 0x0227E},
	{"\\succsim", 0x0227F},
	{"\\nprec", 0x02280},
	{"\\nsucc", 0x02281},
	{"\\subset", 0x02282},
	{"\\supset", 0x02283},
	{"\\nsubset", 0x02284},
	{"\\nsupset", 0x02285},
	{"\\subseteq", 0x02286},
	{"\\supseteq", 0x02287},
	{"\\nsubseteq", 0x02288},
	{"\\nsupseteq", 0x02289},
	{"\\subsetneq", 0x0228A},
	{"\\supsetneq", 0x0228B},
	{"\\uplus", 0x0228E},
	{"\\sqsubset", 0x0228F},
	{"\\sqsupset", 0x02290},
	{"\\sqsubseteq", 0x02291},
	{"\\sqsupseteq", 0x02292},
	{"\\sqcap", 0x02293},
	{"\\sqcup", 0x02294},
	{"\\oplus", 0x02295},
	{"\\ominus", 0x02296},
	{"\\otimes", 0x02297},
	{"\\oslash", 0x02298},
	{"\\odot", 0x02299},
	{"\\circledcirc", 0x0229A},
	{"\\circledast", 0x0229B},
	{"\\circleddash", 0x0229D},
	{"\\boxplus", 0x0229E},
	{"\\boxminus", 0x0229F},
	{"\\boxtimes", 0x022A0},
	{"\\boxdot", 0x022A1},
	{"\\vdash", 0x022A2},
	{"\\dashv", 0x022A3},
	{"\\top", 0x022A4},
	{"\\bot", 0x022A5},
	{"\\models", 0x022A7},
	{"\\vDash", 0x022A8},
	{"\\Vdash", 0x022A9},
	{"\\Vvdash", 0x022AA},
	{"\\VDash", 0x022AB},
	{"\\nvdash", 0x022AC},
	{"\\nvDash", 0x022AD},
	{"\\nVdash", 0x022AE},
	{"\\nVDash", 0x022AF},
	{"\\vartriangleleft", 0x022B2},
	{"\\vartriangleright", 0x022B3},
	{"\\trianglelefteq", 0x022B4},
	{"\\trianglerighteq", 0x022B5},
	{"\\multimapdotbothA", 0x022B6},
	{"\\multimapdotbothB", 0x022B7},
	{"\\multimap", 0x022B8},
	{"\\intercal", 0x022BA},
	{"\\veebar", 0x022BB},
	{"\\barwedge", 0x022BC},
	{"\\bigwedge", 0x022C0},
	{"\\bigvee", 0x022C1},
	{"\\bigcap", 0x022C2},
	{"\\bigcup", 0x022C3},
	{"\\diamond", 0x022C4},
	{"\\cdot", 0x022C5},
	{"\\star", 0x022C6},
	{"\\divideontimes", 0x022C7},
	{"\\bowtie", 0x022C8},
	{"\\ltimes", 0x022C9},
	{"\\rtimes", 0x022CA},
	{"\\leftthreetimes", 0x022CB},
	{"\\rightthreetimes", 0x022CC},
	{"\\backsimeq", 0x022CD},
	{"\\curlyvee", 0x022CE},
	{"\\curlywedge", 0x022CF},
	{"\\Subset", 0x022D0},
	{"\\Supset", 0x022D1},
	{"\\Cap", 0x022D2},
	{"\\Cup", 0x022D3},
	{"\\pitchfork", 0x022D4},
	{"\\hash", 0x022D5},
	{"\\lessdot", 0x022D6},
	{"\\gtrdot", 0x022D7},
	{"\\lll", 0x022D8},
	{"\\ggg", 0x022D9},
	{"\\lesseqgtr", 0x022DA},
	{"\\gtreqless", 0x022DB},
	{"\\curlyeqprec", 0x022DE},
	{"\\curlyeqsucc", 0x022DF},
	{"\\npreceq", 0x022E0},
	{"\\nsucceq", 0x022E1},
	{"\\nsqsubseteq", 0x022E2},
	{"\\nsqsupseteq", 0x022E3},
	{"\\lnsim", 0x022E6},
	{"\\gnsim", 0x022E7},
	{"\\precnsim", 0x022E8},
	{"\\succnsim", 0x022E9},
	{"\\ntriangleleft", 0x022EA},
	{"\\ntriangleright", 0x022EB},
	{"\\ntrianglelefteq", 0x022EC},
	{"\\ntrianglerighteq", 0x022ED},
	{"\\vdots", 0x022EE},
	{"\\cdots", 0x022EF},
	{"\\iddots", 0x022F0},
	{"\\ddots", 0x022F1},
	{"\\barin", 0x022F6},	
	/* misc technical */
	{"\\diameter", 0x02300},
	{"\\lceil", 0x02308},
	{"\\rceil", 0x02309},
	{"\\lfloor", 0x0230A},
	{"\\rfloor", 0x0230B},
	{"\\invneg", 0x02310},
	{"\\wasylozenge", 0x02311},
	{"\\ulcorner", 0x0231C},
	{"\\urcorner", 0x0231D},
	{"\\llcorner", 0x0231E},
	{"\\lrcorner", 0x0231F},
	{"\\frown", 0x02322},
	{"\\smile", 0x02323},
	{"\\APLinv", 0x02339},
	{"\\notslash", 0x0233F},
	{"\\notbackslash", 0x02340},
	{"\\APLleftarrowbox", 0x02347},
	{"\\APLrightarrowbox", 0x02348},
	{"\\APLuparrowbox", 0x02350},
	{"\\APLdownarrowbox", 0x02357},
	{"\\APLcomment", 0x0235D},
	{"\\APLinput", 0x0235E},
	{"\\APLlog", 0x0235F},
	{"\\overparen", 0x023DC},
	{"\\underparen", 0x023DD},
	{"\\overbrace", 0x023DE},
	{"\\underbrace", 0x023DF},	
	/* geometric shapes */
	{"\\bigtriangleup", 0x025B3},
	{"\\blacktriangleup", 0x025B4},
	{"\\smalltriangleup", 0x025B5},
	{"\\RHD", 0x025B6},
	{"\\rhd", 0x025B7},
	{"\\blacktriangleright", 0x025B8},
	{"\\smalltriangleright", 0x025B9},
	{"\\bigtriangledown", 0x025BD},
	{"\\blacktriangledown", 0x025BE},
	{"\\smalltriangledown", 0x025BF},
	{"\\LHD", 0x025C0},
	{"\\lhd", 0x025C1},
	{"\\blacktriangleleft", 0x025C2},
	{"\\smalltriangleleft", 0x025C3},
	{"\\Diamondblack", 0x025C6},
	{"\\Diamond", 0x025C7},
	{"\\lozenge", 0x025CA},
	{"\\Circle", 0x025CB},
	{"\\CIRCLE", 0x025CF},
	{"\\LEFTcircle", 0x025D0},
	{"\\RIGHTcircle", 0x025D1},
	{"\\LEFTCIRCLE", 0x025D6},
	{"\\RIGHTCIRCLE", 0x025D7},
	{"\\boxbar", 0x025EB},
	{"\\square", 0x025FB},
	{"\\blacksquare", 0x025FC},
	/* Misc. Symbols */
	{"\\bigstar", 0x02605},
	{"\\Sun", 0x02609},
	{"\\Square", 0x02610},
	{"\\CheckedBox", 0x02611},
	{"\\XBox", 0x02612},
	{"\\steaming", 0x02615},
	{"\\pointright", 0x0261E},
	{"\\skull", 0x02620},
	{"\\radiation", 0x02622},
	{"\\biohazard", 0x02623},
	{"\\yinyang", 0x0262F},
	{"\\frownie", 0x02639},
	{"\\smiley", 0x0263A},
	{"\\blacksmiley", 0x0263B},
	{"\\sun", 0x0263C},
	{"\\rightmoon", 0x0263D},
	{"\\leftmoon", 0x0263E},
	{"\\mercury", 0x0263F},
	{"\\female", 0x02640},
	{"\\earth", 0x02641},
	{"\\male", 0x02642},
	{"\\jupiter", 0x02643},
	{"\\saturn", 0x02644},
	{"\\uranus", 0x02645},
	{"\\neptune", 0x02646},
	{"\\pluto", 0x02647},
	{"\\aries", 0x02648},
	{"\\taurus", 0x02649},
	{"\\gemini", 0x0264A},
	{"\\cancer", 0x0264B},
	{"\\leo", 0x0264C},
	{"\\virgo", 0x0264D},
	{"\\libra", 0x0264E},
	{"\\scorpio", 0x0264F},
	{"\\sagittarius", 0x02650},
	{"\\capricornus", 0x02651},
	{"\\aquarius", 0x02652},
	{"\\pisces", 0x02653},
	{"\\spadesuit", 0x02660},
	{"\\heartsuit", 0x02661},
	{"\\diamondsuit", 0x02662},
	{"\\clubsuit", 0x02663},
	{"\\varspadesuit", 0x02664},
	{"\\varheartsuit", 0x02665},
	{"\\vardiamondsuit", 0x02666},
	{"\\varclubsuit", 0x02667},
	{"\\quarternote", 0x02669},
	{"\\eighthnote", 0x0266A},
	{"\\twonotes", 0x0266B},
	{"\\sixteenthnote", 0x0266C},
	{"\\flat", 0x0266D},
	{"\\natural", 0x0266E},
	{"\\sharp", 0x0266F},
	{"\\recycle", 0x0267B},
	{"\\anchor", 0x02693},
	{"\\swords", 0x02694},
	{"\\warning", 0x026A0},
	{"\\medcirc", 0x026AA},
	{"\\medbullet", 0x026AB},
	/* dingbats */
	{"\\pencil", 0x0270E},
	{"\\checkmark", 0x02713},
	{"\\ballotx", 0x02717},
	{"\\maltese", 0x02720},
	{"\\arrowbullet", 0x027A2},
	/* Misc. Mathematical symbols-A */
	{"\\perp", 0x027C2},
	{"\\Lbag", 0x027C5},
	{"\\Rbag", 0x027C6},
	{"\\Diamonddot", 0x027D0},
	{"\\multimapinv", 0x027DC},
	{"\\llbracket", 0x027E6},
	{"\\rrbracket", 0x027E7},
	{"\\langle", 0x027E8},
	{"\\rangle", 0x027E9},
	{"\\lang", 0x027EA},
	{"\\rang", 0x027EB},
	{"\\lgroup", 0x027EE},
	{"\\rgroup", 0x027EF},
	/* Suppl. Arrows-A*/
	{"\\longleftarrow", 0x027F5},
	{"\\longrightarrow", 0x027F6},
	{"\\longleftrightarrow", 0x027F7},
	{"\\Longleftarrow", 0x027F8},
	{"\\Longrightarrow", 0x027F9},
	{"\\Longleftrightarrow", 0x027FA},
	{"\\longmapsfrom", 0x027FB},
	{"\\longmapsto", 0x027FC},
	{"\\Longmapsfrom", 0x027FD},
	{"\\Longmapsto", 0x027FE},
	/* Suppl. Arrows-B*/
	{"\\psur", 0x02900},
	{"\\Mapsfrom", 0x02906},
	{"\\Mapsto", 0x02907},
	{"\\UpArrowBar", 0x02912},
	{"\\DownArrowBar", 0x02913},
	{"\\pinj", 0x02914},
	{"\\finj", 0x02915},
	{"\\bij", 0x02916},
	{"\\leadsto", 0x02933},
	{"\\leftrightharpoon", 0x0294A},
	{"\\rightleftharpoon", 0x0294B},
	{"\\leftrightharpoonup", 0x0294E},
	{"\\rightupdownharpoon", 0x0294F},
	{"\\leftrightharpoondown", 0x02950},
	{"\\leftupdownharpoon", 0x02951},
	{"\\LeftVectorBar", 0x02952},
	{"\\RightVectorBar", 0x02953},
	{"\\RightUpVectorBar", 0x02954},
	{"\\RightDownVectorBar", 0x02955},
	{"\\DownLeftVectorBar", 0x02956},
	{"\\DownRightVectorBar", 0x02957},
	{"\\LeftUpVectorBar", 0x02958},
	{"\\LeftDownVectorBar", 0x02959},
	{"\\LeftTeeVector", 0x0295A},
	{"\\RightTeeVector", 0x0295B},
	{"\\RightUpTeeVector", 0x0295C},
	{"\\RightDownTeeVector", 0x0295D},
	{"\\DownLeftTeeVector", 0x0295E},
	{"\\DownRightTeeVector", 0x0295F},
	{"\\LeftUpTeeVector", 0x02960},
	{"\\LeftDownTeeVector", 0x02961},
	{"\\leftleftharpoons", 0x02962},
	{"\\upupharpoons", 0x02963},
	{"\\rightrightharpoons", 0x02964},
	{"\\downdownharpoons", 0x02965},
	{"\\leftbarharpoon", 0x0296A},
	{"\\barleftharpoon", 0x0296B},
	{"\\rightbarharpoon", 0x0296C},
	{"\\barrightharpoon", 0x0296D},
	{"\\updownharpoons", 0x0296E},
	{"\\downupharpoons", 0x0296F},
	{"\\strictfi", 0x0297C},
	{"\\strictif", 0x0297D},
	/* Misc. Mathematical symbols-B */
	{"\\VERT", 0x02980},
	{"\\spot", 0x02981},
	{"\\Lparen", 0x02985},
	{"\\Rparen", 0x02986},
	{"\\limg", 0x02987},
	{"\\rimg", 0x02988},
	{"\\lblot", 0x02989},
	{"\\rblot", 0x0298A},
	{"\\circledbslash", 0x029B8},
	{"\\circledless", 0x029C0},
	{"\\circledgtr", 0x029C1},
	{"\\boxslash", 0x029C4},
	{"\\boxbslash", 0x029C5},
	{"\\boxast", 0x029C6},
	{"\\boxcircle", 0x029C7},
	{"\\boxbox", 0x029C8},
	{"\\LeftTriangleBar", 0x029CF},
	{"\\RightTriangleBar", 0x029D0},
	{"\\multimapboth", 0x029DF},
	{"\\blacklozenge", 0x029EB},
	{"\\setminus", 0x029F5},
	{"\\zhide", 0x029F9},
	/* Suppl. Mathematical operators */{"\\bigodot", 0x02A00},
	{"\\bigoplus", 0x02A01},
	{"\\bigotimes", 0x02A02},
	{"\\biguplus", 0x02A04},
	{"\\bigsqcap", 0x02A05},
	{"\\bigsqcup", 0x02A06},
	{"\\varprod", 0x02A09},
	{"\\utfiiiint", 0x02A0C},
	{"\\utffint", 0x02A0F},
	{"\\utfsqint", 0x02A16},
	{"\\Join", 0x02A1D},
	{"\\zcmp", 0x02A1F},
	{"\\zpipe", 0x02A20},
	{"\\zproject", 0x02A21},
	{"\\fcmp", 0x02A3E},
	{"\\amalg", 0x02A3F},
	{"\\doublebarwedge", 0x02A5E},
	{"\\dsub", 0x02A64},
	{"\\rsub", 0x02A65},
	{"\\Coloneqq", 0x02A74},
	{"\\Equal", 0x02A75},
	{"\\Same", 0x02A76},
	{"\\leqslant", 0x02A7D},
	{"\\geqslant", 0x02A7E},
	{"\\lessapprox", 0x02A85},
	{"\\gtrapprox", 0x02A86},
	{"\\lneq", 0x02A87},
	{"\\gneq", 0x02A88},
	{"\\lnapprox", 0x02A89},
	{"\\gnapprox", 0x02A8A},
	{"\\lesseqqgtr", 0x02A8B},
	{"\\gtreqqless", 0x02A8C},
	{"\\eqslantless", 0x02A95},
	{"\\eqslantgtr", 0x02A96},
	{"\\NestedLessLess", 0x02AA1},
	{"\\NestedGreaterGreater", 0x02AA2},
	{"\\leftslice", 0x02AA6},
	{"\\rightslice", 0x02AA7},
	{"\\preceq", 0x02AAF},
	{"\\succeq", 0x02AB0},
	{"\\preceqq", 0x02AB3},
	{"\\succeqq", 0x02AB4},
	{"\\precapprox", 0x02AB7},
	{"\\succapprox", 0x02AB8},
	{"\\precnapprox", 0x02AB9},
	{"\\succnapprox", 0x02ABA},
	{"\\llcurly", 0x02ABB},
	{"\\ggcurly", 0x02ABC},
	{"\\subseteqq", 0x02AC5},
	{"\\supseteqq", 0x02AC6},
	{"\\subsetneqq", 0x02ACB},
	{"\\supsetneqq", 0x02ACC},
	{"\\Top", 0x02AEA},
	{"\\Bot", 0x02AEB},
	{"\\interleave", 0x02AF4},
	{"\\biginterleave", 0x02AFC},
	{"\\sslash", 0x02AFD},
	{"\\talloblong", 0x02AFE},
	/* misc symbols & arrows */
	{"\\blacksquare", 0x02B1B},
	{"\\square", 0x02B1C},
	/* mathematical alphanumeric symbols */
	{"\\partial", 0x1D715},
	/* terminate the table */
	/* modify some emojic characters to full blown emojis , e.g. ☠ → ☠️ (\skull  \rightarrow  \emojify \skull)*/
	{"\\emojify", 0x0FE0F},	
	
	/* whatever symbols that were not there but were in https://github.com/JuliaLang/julia/blob/master/stdlib/REPL/src/latex_symbols.jl */
	{"\\cbrt",0x221B}, //  0x221B
	{"\\mars",0x02642}, //  ♂
	{"\\xor",0x022BB}, //  ⊻
	{"\\nand",0x022BC}, //  ⊼
	{"\\nor",0x022BD}, //  ⊽
	{"\\iff",0x027FA}, //  ⟺
	{"\\implies",0x027F9}, //  ⟹
	{"\\impliedby",0x027F8}, //  ⟸
	{"\\euler",0x0212F}, //  ℯ
	{"\\ohm",0x02126}, //  Ω
	{"\\hbar",0x00127}, //  ħ
	{"\\del",0x02207}, //  ∇
	{"\\sout",0x00336}, //  ̶ # ulem package same as Elzbar
	{"\\euro",0x020AC}, //  €
	{"\\exclamdown",0x000A1}, //  ¡
	{"\\sterling",0x000A3}, //  £
	{"\\brokenbar",0x000A6}, //  ¦
	{"\\S",0x000A7}, //  §
	{"\\copyright",0x000A9}, //  ©
	{"\\ordfeminine",0x000AA}, //  ª
	{"\\highminus",0x000AF}, //  ¯ # APL high minus or non-combining macron above
	{"\\P",0x000B6}, //  ¶
	{"\\cdotp",0x000B7}, //  ·
	{"\\ordmasculine",0x000BA}, //  º
	{"\\questiondown",0x000BF}, //  ¿
	{"\\AA",0x000C5}, //  Å
	{"\\AE",0x000C6}, //  Æ
	{"\\DH",0x000D0}, //  Ð
	{"\\O",0x000D8}, //  Ø
	{"\\TH",0x000DE}, //  Þ
	{"\\ss",0x000DF}, //  ß
	{"\\aa",0x000E5}, //  å
	{"\\ae",0x000E6}, //  æ
	{"\\dh",0x000F0}, //  ð
	{"\\o",0x000F8}, //  ø
	{"\\th",0x000FE}, //  þ
	{"\\DJ",0x00110}, //  Đ
	{"\\dj",0x00111}, //  đ
	{"\\L",0x00141}, //  Ł
	{"\\NG",0x0014A}, //  Ŋ
	{"\\ng",0x0014B}, //  ŋ
	{"\\OE",0x00152}, //  Œ
	{"\\oe",0x00153}, //  œ
	{"\\hvlig",0x00195}, //  ƕ
	{"\\nrleg",0x0019E}, //  ƞ
	{"\\doublepipe",0x001C2}, //  ǂ
	{"\\trna",0x00250}, //  ɐ
	{"\\trnsa",0x00252}, //  ɒ
	{"\\openo",0x00254}, //  ɔ
	{"\\rtld",0x00256}, //  ɖ
	{"\\schwa",0x00259}, //  ə
	{"\\pgamma",0x00263}, //  ɣ
	{"\\pbgam",0x00264}, //  ɤ
	{"\\trnh",0x00265}, //  ɥ
	{"\\btdl",0x0026C}, //  ɬ
	{"\\rtll",0x0026D}, //  ɭ
	{"\\trnm",0x0026F}, //  ɯ
	{"\\trnmlr",0x00270}, //  ɰ
	{"\\ltlmr",0x00271}, //  ɱ
	{"\\ltln",0x00272}, //  ɲ
	{"\\rtln",0x00273}, //  ɳ
	{"\\clomeg",0x00277}, //  ɷ
	{"\\ltphi",0x00278}, //  ɸ # latin ϕ
	{"\\trnr",0x00279}, //  ɹ
	{"\\trnrl",0x0027A}, //  ɺ
	{"\\rttrnr",0x0027B}, //  ɻ
	{"\\rl",0x0027C}, //  ɼ
	{"\\rtlr",0x0027D}, //  ɽ
	{"\\fhr",0x0027E}, //  ɾ
	{"\\rtls",0x00282}, //  ʂ
	{"\\esh",0x00283}, //  ʃ
	{"\\trnt",0x00287}, //  ʇ
	{"\\rtlt",0x00288}, //  ʈ
	{"\\pupsil",0x0028A}, //  ʊ
	{"\\pscrv",0x0028B}, //  ʋ
	{"\\invv",0x0028C}, //  ʌ
	{"\\invw",0x0028D}, //  ʍ
	{"\\trny",0x0028E}, //  ʎ
	{"\\rtlz",0x00290}, //  ʐ
	{"\\yogh",0x00292}, //  ʒ
	{"\\glst",0x00294}, //  ʔ
	{"\\reglst",0x00295}, //  ʕ
	{"\\inglst",0x00296}, //  ʖ
	{"\\turnk",0x0029E}, //  ʞ
	{"\\dyogh",0x002A4}, //  ʤ
	{"\\tesh",0x002A7}, //  ʧ
	{"\\rasp",0x002BC}, //  ʼ
	{"\\verts",0x002C8}, //  ˈ
	{"\\verti",0x002CC}, //  ˌ
	{"\\lmrk",0x002D0}, //  ː
	{"\\hlmrk",0x002D1}, //  ˑ
	{"\\sbrhr",0x002D2}, //  ˒
	{"\\sblhr",0x002D3}, //  ˓
	{"\\rais",0x002D4}, //  ˔
	{"\\low",0x002D5}, //  ˕
	{"\\u",0x002D8}, //  ˘
	{"\\tildelow",0x002DC}, //  ˜
	{"\\ocirc",0x0030A}, //  ̊
	{"\\palh",0x00321}, //  ̡
	{"\\rh",0x00322}, //  ̢
	{"\\sbbrg",0x0032A}, //  ̪
	{"\\strike",0x00336}, //  ̶
	{"\\Alpha",0x00391}, //  Α
	{"\\Beta",0x00392}, //  Β
	{"\\Epsilon",0x00395}, //  Ε
	{"\\Zeta",0x00396}, //  Ζ
	{"\\Eta",0x00397}, //  Η
	{"\\Iota",0x00399}, //  Ι
	{"\\Kappa",0x0039A}, //  Κ
	{"\\Rho",0x003A1}, //  Ρ
	{"\\Tau",0x003A4}, //  Τ
	{"\\Chi",0x003A7}, //  Χ
	{"\\varkappa",0x003F0}, //  ϰ
	{"\\varTheta",0x003F4}, //  ϴ
	{"\\enspace",0x02002}, //   
	{"\\thickspace",0x02005}, //   
	{"\\thinspace",0x02009}, //   
	{"\\hspace",0x0200A}, //   
	{"\\endash",0x02013}, //  –
	{"\\emdash",0x02014}, //  —
	{"\\Vert",0x02016}, //  ‖
	{"\\lq",0x02018}, //  ‘
	{"\\rq",0x02019}, //  ’
	{"\\reapos",0x0201B}, //  ‛
	{"\\ldq",0x0201C}, //  “
	{"\\rdq",0x0201D}, //  ”
	{"\\dots",0x02026}, //  …
	{"\\perthousand",0x02030}, //  ‰
	{"\\pertenthousand",0x02031}, //  ‱
	{"\\guilsinglleft",0x02039}, //  ‹
	{"\\guilsinglright",0x0203A}, //  ›
	{"\\nolinebreak",0x2060}, //  0x2060
	{"\\pes",0x020A7}, //  ₧
	{"\\numero",0x02116}, //  №
	{"\\xrat",0x0211E}, //  ℞
	{"\\trademark",0x02122}, //  ™
	{"\\bbsum",0x02140}, //  ⅀
	{"\\Game",0x02141}, //  ⅁
	{"\\dblarrowupdown",0x021C5}, //  ⇅
	{"\\DownArrowUpArrow",0x021F5}, //  ⇵
	{"\\emptyset",0x02205}, //  ∅
	{"\\surd",0x0221A}, //  √
	{"\\clwintegral",0x02231}, //  ∱
	{"\\Colon",0x02237}, //  ∷
	{"\\dotminus",0x02238}, //  ∸
	{"\\kernelcontraction",0x0223B}, //  ∻
	{"\\lazysinv",0x0223E}, //  ∾
	{"\\neqsim",0x02242}, //  ≂̸
	{"\\nsime",0x02244}, //  ≄
	{"\\approxnotequal",0x02246}, //  ≆
	{"\\tildetrpl",0x0224B}, //  ≋
	{"\\allequal",0x0224C}, //  ≌
	{"\\nBumpeq",0x0224E}, //  ≎̸
	{"\\nbumpeq",0x0224F}, //  ≏̸
	{"\\wedgeq",0x02259}, //  ≙
	{"\\starequal",0x0225B}, //  ≛
	{"\\questeq",0x0225F}, //  ≟
	{"\\ne",0x02260}, //  ≠
	{"\\le",0x02264}, //  ≤
	{"\\ge",0x02265}, //  ≥
	{"\\lvertneqq",0x02268}, //  ≨︀
	{"\\gvertneqq",0x02269}, //  ≩︀
	{"\\NotLessLess",0x0226A}, //  ≪̸
	{"\\NotGreaterGreater",0x0226B}, //  ≫̸
	{"\\notlessgreater",0x02278}, //  ≸
	{"\\notgreaterless",0x02279}, //  ≹
	{"\\nprecsim",0x0227E}, //  ≾̸
	{"\\nsuccsim",0x0227F}, //  ≿̸
	{"\\varsubsetneqq",0x0228A}, //  ⊊︀
	{"\\varsupsetneq",0x0228B}, //  ⊋︀
	{"\\cupdot",0x0228D}, //  ⊍
	{"\\NotSquareSubset",0x0228F}, //  ⊏̸
	{"\\NotSquareSuperset",0x02290}, //  ⊐̸
	{"\\indep",0x02AEB}, //  ⫫
	{"\\downvDash",0x02AEA}, //  ⫪
	{"\\upvDash",0x02AEB}, //  ⫫
	{"\\original",0x022B6}, //  ⊶
	{"\\image",0x022B7}, //  ⊷
	{"\\hermitconjmatrix",0x022B9}, //  ⊹
	{"\\rightanglearc",0x022BE}, //  ⊾
	{"\\verymuchless",0x022D8}, //  ⋘
	{"\\adots",0x022F0}, //  ⋰
	{"\\recorder",0x02315}, //  ⌕
	{"\\obar",0x0233D}, //  ⌽
	{"\\dlcorn",0x023A3}, //  ⎣
	{"\\lmoustache",0x023B0}, //  ⎰
	{"\\visiblespace",0x02423}, //  ␣
	{"\\circledS",0x024C8}, //  Ⓢ
	{"\\dshfnc",0x02506}, //  ┆
	{"\\sqfnw",0x02519}, //  ┙
	{"\\diagup",0x02571}, //  ╱
	{"\\diagdown",0x02572}, //  ╲
	{"\\vrecto",0x025AF}, //  ▯
	{"\\blacktriangle",0x025B4}, //  ▴
	{"\\vartriangle",0x025B5}, //  ▵
	{"\\triangledown",0x025BF}, //  ▿
	{"\\bigcirc",0x025CB}, //  ○
	{"\\cirfl",0x025D0}, //  ◐
	{"\\cirfr",0x025D1}, //  ◑
	{"\\cirfb",0x025D2}, //  ◒
	{"\\rvbull",0x025D8}, //  ◘
	{"\\sqfl",0x025E7}, //  ◧
	{"\\sqfr",0x025E8}, //  ◨
	{"\\sqfse",0x025EA}, //  ◪
	{"\\venus",0x02640}, //  ♀
	{"\\Uuparrow",0x0290A}, //  ⤊
	{"\\Ddownarrow",0x0290B}, //  ⤋
	{"\\bkarow",0x0290D}, //  ⤍
	{"\\dbkarow",0x0290F}, //  ⤏
	{"\\drbkarrow",0x02910}, //  ⤐
	{"\\twoheadrightarrowtail",0x02916}, //  ⤖
	{"\\hksearow",0x02925}, //  ⤥
	{"\\hkswarow",0x02926}, //  ⤦
	{"\\tona",0x02927}, //  ⤧
	{"\\toea",0x02928}, //  ⤨
	{"\\tosa",0x02929}, //  ⤩
	{"\\towa",0x0292A}, //  ⤪
	{"\\rdiagovfdiag",0x0292B}, //  ⤫
	{"\\fdiagovrdiag",0x0292C}, //  ⤬
	{"\\seovnearrow",0x0292D}, //  ⤭
	{"\\neovsearrow",0x0292E}, //  ⤮
	{"\\fdiagovnearrow",0x0292F}, //  ⤯
	{"\\rdiagovsearrow",0x02930}, //  ⤰
	{"\\neovnwarrow",0x02931}, //  ⤱
	{"\\nwovnearrow",0x02932}, //  ⤲
	{"\\Rlarr",0x02942}, //  ⥂
	{"\\rLarr",0x02944}, //  ⥄
	{"\\rarrx",0x02947}, //  ⥇
	{"\\LeftRightVector",0x0294E}, //  ⥎
	{"\\RightUpDownVector",0x0294F}, //  ⥏
	{"\\DownLeftRightVector",0x02950}, //  ⥐
	{"\\LeftUpDownVector",0x02951}, //  ⥑
	{"\\UpEquilibrium",0x0296E}, //  ⥮
	{"\\ReverseUpEquilibrium",0x0296F}, //  ⥯
	{"\\RoundImplies",0x02970}, //  ⥰
	{"\\Vvert",0x02980}, //  ⦀
	{"\\Elroang",0x02986}, //  ⦆
	{"\\ddfnc",0x02999}, //  ⦙
	{"\\Angle",0x0299C}, //  ⦜
	{"\\lpargt",0x029A0}, //  ⦠
	{"\\obslash",0x029B8}, //  ⦸
	{"\\Lap",0x029CA}, //  ⧊
	{"\\defas",0x029CB}, //  ⧋
	{"\\NotLeftTriangleBar",0x029CF}, //  ⧏̸
	{"\\NotRightTriangleBar",0x029D0}, //  ⧐̸
	{"\\dualmap",0x029DF}, //  ⧟
	{"\\shuffle",0x029E2}, //  ⧢
	{"\\RuleDelayed",0x029F4}, //  ⧴
	{"\\bigcupdot",0x02A03}, //  ⨃
	{"\\conjquant",0x02A07}, //  ⨇
	{"\\disjquant",0x02A08}, //  ⨈
	{"\\bigtimes",0x02A09}, //  ⨉
	{"\\clockoint",0x02A0F}, //  ⨏
	{"\\sqrint",0x02A16}, //  ⨖
	{"\\upint",0x02A1B}, //  ⨛
	{"\\lowint",0x02A1C}, //  ⨜
	{"\\plusdot",0x02A25}, //  ⨥
	{"\\Times",0x02A2F}, //  ⨯
	{"\\btimes",0x02A32}, //  ⨲
	{"\\And",0x02A53}, //  ⩓
	{"\\Or",0x02A54}, //  ⩔
	{"\\ElOr",0x02A56}, //  ⩖
	{"\\perspcorrespond",0x02A5E}, //  ⩞
	{"\\ddotseq",0x02A77}, //  ⩷
	{"\\nleqslant",0x02A7D}, //  ⩽̸
	{"\\ngeqslant",0x02A7E}, //  ⩾̸
	{"\\NotNestedLessLess",0x02AA1}, //  ⪡̸
	{"\\NotNestedGreaterGreater",0x02AA2}, //  ⪢̸
	{"\\partialmeetcontraction",0x02AA3}, //  ⪣
	{"\\bumpeqq",0x02AAE}, //  ⪮
	{"\\precneqq",0x02AB5}, //  ⪵
	{"\\succneqq",0x02AB6}, //  ⪶
	{"\\nsubseteqq",0x02AC5}, //  ⫅̸
	{"\\nsupseteqq",0x02AC6}, //  ⫆̸
	{"\\mlcp",0x02ADB}, //  ⫛
	{"\\forks",0x02ADC}, //  ⫝̸
	{"\\forksnot",0x02ADD}, //  ⫝
	{"\\dashV",0x02AE3}, //  ⫣
	{"\\Dashv",0x02AE4}, //  ⫤
	{"\\tdcol",0x02AF6}, //  ⫶
	{"\\openbracketleft",0x027E6}, //  ⟦
	{"\\openbracketright",0x027E7}, //  ⟧
	{"\\Zbar",0x001B5}, //  Ƶ # impedance (latin capital letter z with stroke)
	{"\\ovhook",0x00309}, //  ̉ # combining hook above
	{"\\candra",0x00310}, //  ̐ # candrabindu (non-spacing)
	{"\\oturnedcomma",0x00312}, //  ̒ # combining turned comma above
	{"\\ocommatopright",0x00315}, //  ̕ # combining comma above right
	{"\\droang",0x0031A}, //  ̚ # left angle above (non-spacing)
	{"\\wideutilde",0x00330}, //  ̰ # under tilde accent (multiple characters and non-spacing)
	{"\\upMu",0x0039C}, //  Μ # capital mu greek
	{"\\upNu",0x0039D}, //  Ν # capital nu greek
	{"\\upOmicron",0x0039F}, //  Ο # capital omicron greek
	{"\\upepsilon",0x003B5}, //  ε # rounded small epsilon greek
	{"\\upomicron",0x003BF}, //  ο # small omicron greek
	{"\\upvarbeta",0x003D0}, //  ϐ # rounded small beta greek
	{"\\upoldKoppa",0x003D8}, //  Ϙ # greek letter archaic koppa
	{"\\upoldkoppa",0x003D9}, //  ϙ # greek small letter archaic koppa
	{"\\upstigma",0x003DB}, //  ϛ # greek small letter stigma
	{"\\upkoppa",0x003DF}, //  ϟ # greek small letter koppa
	{"\\upsampi",0x003E1}, //  ϡ # greek small letter sampi
	{"\\tieconcat",0x02040}, //  ⁀ # character tie z notation sequence concatenation
	{"\\leftharpoonaccent",0x020D0}, //  ⃐ # combining left harpoon above
	{"\\rightharpoonaccent",0x020D1}, //  ⃑ # combining right harpoon above
	{"\\vertoverlay",0x020D2}, //  ⃒ # combining long vertical line overlay
	{"\\enclosecircle",0x020DD}, //  ⃝ # combining enclosing circle
	{"\\enclosesquare",0x020DE}, //  ⃞ # combining enclosing square
	{"\\enclosediamond",0x020DF}, //  ⃟ # combining enclosing diamond
	{"\\enclosetriangle",0x020E4}, //  ⃤ # combining enclosing upward pointing triangle
	{"\\annuity",0x020E7}, //  ⃧ # combining annuity symbol
	{"\\threeunderdot",0x020E8}, //  ⃨ # combining triple underdot
	{"\\widebridgeabove",0x020E9}, //  ⃩ # combining wide bridge above
	{"\\underrightharpoondown",0x20EC}, //  0x20EC # combining rightwards harpoon with barb downwards
	{"\\underleftharpoondown",0x20ED}, //  0x20ED # combining leftwards harpoon with barb downwards
	{"\\underleftarrow",0x20EE}, //  0x20EE # combining left arrow below
	{"\\underrightarrow",0x20EF}, //  0x20EF # combining right arrow below
	{"\\asteraccent",0x20F0}, //  0x20F0 # combining asterisk above
	{"\\eulermascheroni",0x02107}, //  ℇ # euler-mascheroni constant U+2107
	{"\\planck",0x0210E}, //  ℎ # planck constant
	{"\\turnediota",0x02129}, //  ℩ # turned iota
	{"\\Angstrom",0x0212B}, //  Å # angstrom capital a ring
	{"\\sansLturned",0x02142}, //  ⅂ # turned sans-serif capital l
	{"\\sansLmirrored",0x02143}, //  ⅃ # reversed sans-serif capital l
	{"\\PropertyLine",0x0214A}, //  ⅊ # property line
	{"\\upand",0x0214B}, //  ⅋ # turned ampersand
	{"\\twoheaduparrow",0x0219F}, //  ↟ # up two-headed arrow
	{"\\twoheaddownarrow",0x021A1}, //  ↡ # down two-headed arrow
	{"\\mapsup",0x021A5}, //  ↥ # maps to upward
	{"\\mapsdown",0x021A7}, //  ↧ # maps to downward
	{"\\updownarrowbar",0x021A8}, //  ↨ # up down arrow with base (perpendicular)
	{"\\downzigzagarrow",0x021AF}, //  ↯ # downwards zigzag arrow
	{"\\Ldsh",0x021B2}, //  ↲ # left down angled arrow
	{"\\Rdsh",0x021B3}, //  ↳ # right down angled arrow
	{"\\linefeed",0x021B4}, //  ↴ # rightwards arrow with corner downwards
	{"\\carriagereturn",0x021B5}, //  ↵ # downwards arrow with corner leftward = carriage return
	{"\\nHuparrow",0x021DE}, //  ⇞ # upwards arrow with double stroke
	{"\\nHdownarrow",0x021DF}, //  ⇟ # downwards arrow with double stroke
	{"\\leftdasharrow",0x021E0}, //  ⇠ # leftwards dashed arrow
	{"\\updasharrow",0x021E1}, //  ⇡ # upwards dashed arrow
	{"\\rightdasharrow",0x021E2}, //  ⇢ # rightwards dashed arrow
	{"\\downdasharrow",0x021E3}, //  ⇣ # downwards dashed arrow
	{"\\rightarrowbar",0x021E5}, //  ⇥ # rightwards arrow to bar
	{"\\leftwhitearrow",0x021E6}, //  ⇦ # leftwards white arrow
	{"\\upwhitearrow",0x021E7}, //  ⇧ # upwards white arrow
	{"\\rightwhitearrow",0x021E8}, //  ⇨ # rightwards white arrow
	{"\\downwhitearrow",0x021E9}, //  ⇩ # downwards white arrow
	{"\\whitearrowupfrombar",0x021EA}, //  ⇪ # upwards white arrow from bar
	{"\\circleonrightarrow",0x021F4}, //  ⇴ # right arrow with small circle
	{"\\rightthreearrows",0x021F6}, //  ⇶ # three rightwards arrows
	{"\\nvleftarrow",0x021F7}, //  ⇷ # leftwards arrow with vertical stroke
	{"\\nvrightarrow",0x021F8}, //  ⇸ # rightwards arrow with vertical stroke
	{"\\nvleftrightarrow",0x021F9}, //  ⇹ # left right arrow with vertical stroke
	{"\\nVleftarrow",0x021FA}, //  ⇺ # leftwards arrow with double vertical stroke
	{"\\nVrightarrow",0x021FB}, //  ⇻ # rightwards arrow with double vertical stroke
	{"\\nVleftrightarrow",0x021FC}, //  ⇼ # left right arrow with double vertical stroke
	{"\\increment",0x02206}, //  ∆ # laplacian (delta; nabla\string^2)
	{"\\smallin",0x0220A}, //  ∊ # set membership (small set membership)
	{"\\smallni",0x0220D}, //  ∍ # /ni /owns r: contains (small contains as member)
	{"\\QED",0x0220E}, //  ∎ # end of proof
	{"\\vysmblkcircle",0x02219}, //  ∙ # bullet operator
	{"\\fourthroot",0x0221C}, //  ∜ # fourth root
	{"\\dotsminusdots",0x0223A}, //  ∺ # minus with four dots geometric properties
	{"\\arceq",0x02258}, //  ≘ # arc equals; corresponds to
	{"\\veeeq",0x0225A}, //  ≚ # logical or equals
	{"\\eqdef",0x0225D}, //  ≝ # equals by definition
	{"\\measeq",0x0225E}, //  ≞ # measured by (m over equals)
	{"\\Equiv",0x02263}, //  ≣ # strict equivalence (4 lines)
	{"\\nasymp",0x0226D}, //  ≭ # not asymptotically equal to
	{"\\nlesssim",0x02274}, //  ≴ # not less similar
	{"\\ngtrsim",0x02275}, //  ≵ # not greater similar
	{"\\circledequal",0x0229C}, //  ⊜ # equal in circle
	{"\\prurel",0x022B0}, //  ⊰ # element precedes under relation
	{"\\scurel",0x022B1}, //  ⊱ # succeeds under relation
	{"\\varlrtriangle",0x022BF}, //  ⊿ # right triangle
	{"\\equalparallel",0x022D5}, //  ⋕ # parallel equal; equal or parallel
	{"\\eqless",0x022DC}, //  ⋜ # equal-or-less
	{"\\eqgtr",0x022DD}, //  ⋝ # equal-or-greater
	{"\\npreccurlyeq",0x022E0}, //  ⋠ # not precedes curly equals
	{"\\nsucccurlyeq",0x022E1}, //  ⋡ # not succeeds curly equals
	{"\\sqsubsetneq",0x022E4}, //  ⋤ # square subset not equals
	{"\\sqsupsetneq",0x022E5}, //  ⋥ # square superset not equals
	{"\\disin",0x022F2}, //  ⋲ # element of with long horizontal stroke
	{"\\varisins",0x022F3}, //  ⋳ # element of with vertical bar at end of horizontal stroke
	{"\\isins",0x022F4}, //  ⋴ # small element of with vertical bar at end of horizontal stroke
	{"\\isindot",0x022F5}, //  ⋵ # element of with dot above
	{"\\varisinobar",0x022F6}, //  ⋶ # element of with overbar
	{"\\isinobar",0x022F7}, //  ⋷ # small element of with overbar
	{"\\isinvb",0x022F8}, //  ⋸ # element of with underbar
	{"\\isinE",0x022F9}, //  ⋹ # element of with two horizontal strokes
	{"\\nisd",0x022FA}, //  ⋺ # contains with long horizontal stroke
	{"\\varnis",0x022FB}, //  ⋻ # contains with vertical bar at end of horizontal stroke
	{"\\nis",0x022FC}, //  ⋼ # small contains with vertical bar at end of horizontal stroke
	{"\\varniobar",0x022FD}, //  ⋽ # contains with overbar
	{"\\niobar",0x022FE}, //  ⋾ # small contains with overbar
	{"\\bagmember",0x022FF}, //  ⋿ # z notation bag membership
	{"\\house",0x02302}, //  ⌂ # house
	{"\\vardoublebarwedge",0x02306}, //  ⌆ # /doublebarwedge b: logical and double bar above [perspective (double bar over small wedge)]
	{"\\invnot",0x02310}, //  ⌐ # reverse not
	{"\\sqlozenge",0x02311}, //  ⌑ # square lozenge
	{"\\profline",0x02312}, //  ⌒ # profile of a line
	{"\\profsurf",0x02313}, //  ⌓ # profile of a surface
	{"\\viewdata",0x02317}, //  ⌗ # viewdata square
	{"\\turnednot",0x02319}, //  ⌙ # turned not sign
	{"\\varhexagonlrbonds",0x0232C}, //  ⌬ # six carbon ring corner down double bonds lower right etc
	{"\\conictaper",0x02332}, //  ⌲ # conical taper
	{"\\topbot",0x02336}, //  ⌶ # top and bottom
	{"\\hexagon",0x02394}, //  ⎔ # horizontal benzene ring [hexagon flat open]
	{"\\underbracket",0x023B5}, //  ⎵ # bottom square bracket
	{"\\bbrktbrk",0x023B6}, //  ⎶ # bottom square bracket over top square bracket
	{"\\lvboxline",0x023B8}, //  ⎸ # left vertical box line
	{"\\rvboxline",0x023B9}, //  ⎹ # right vertical box line
	{"\\varcarriagereturn",0x023CE}, //  ⏎ # return symbol
	{"\\trapezium",0x23E2}, //  0x23E2 # white trapezium
	{"\\benzenr",0x23E3}, //  0x23E3 # benzene ring with circle
	{"\\strns",0x23E4}, //  0x23E4 # straightness
	{"\\fltns",0x23E5}, //  0x23E5 # flatness
	{"\\accurrent",0x23E6}, //  0x23E6 # ac current
	{"\\elinters",0x23E7}, //  0x23E7 # electrical intersection
	{"\\blanksymbol",0x02422}, //  ␢ # blank symbol
	{"\\blockuphalf",0x02580}, //  ▀ # upper half block
	{"\\blocklowhalf",0x02584}, //  ▄ # lower half block
	{"\\blockfull",0x02588}, //  █ # full block
	{"\\blocklefthalf",0x0258C}, //  ▌ # left half block
	{"\\blockrighthalf",0x02590}, //  ▐ # right half block
	{"\\blockqtrshaded",0x02591}, //  ░ # 25\% shaded block
	{"\\blockhalfshaded",0x02592}, //  ▒ # 50\% shaded block
	{"\\blockthreeqtrshaded",0x02593}, //  ▓ # 75\% shaded block
	{"\\squoval",0x025A2}, //  ▢ # white square with rounded corners
	{"\\blackinwhitesquare",0x025A3}, //  ▣ # white square containing black small square
	{"\\squarehfill",0x025A4}, //  ▤ # square horizontal rule filled
	{"\\squarevfill",0x025A5}, //  ▥ # square vertical rule filled
	{"\\squarehvfill",0x025A6}, //  ▦ # square with orthogonal crosshatch fill
	{"\\squarenwsefill",0x025A7}, //  ▧ # square nw-to-se rule filled
	{"\\squareneswfill",0x025A8}, //  ▨ # square ne-to-sw rule filled
	{"\\squarecrossfill",0x025A9}, //  ▩ # square with diagonal crosshatch fill
	{"\\smblksquare",0x025AA}, //  ▪ # /blacksquare - sq bullet filled
	{"\\smwhtsquare",0x025AB}, //  ▫ # white small square
	{"\\hrectangleblack",0x025AC}, //  ▬ # black rectangle
	{"\\hrectangle",0x025AD}, //  ▭ # horizontal rectangle open
	{"\\vrectangleblack",0x025AE}, //  ▮ # black vertical rectangle
	{"\\parallelogramblack",0x025B0}, //  ▰ # black parallelogram
	{"\\parallelogram",0x025B1}, //  ▱ # parallelogram open
	{"\\bigblacktriangleup",0x025B2}, //  ▲ # 0x25b2 6 6d black up-pointing triangle
	{"\\blackpointerright",0x025BA}, //  ► # black right-pointing pointer
	{"\\whitepointerright",0x025BB}, //  ▻ # white right-pointing pointer
	{"\\bigblacktriangledown",0x025BC}, //  ▼ # big down triangle filled
	{"\\blackpointerleft",0x025C4}, //  ◄ # black left-pointing pointer
	{"\\whitepointerleft",0x025C5}, //  ◅ # white left-pointing pointer
	{"\\mdlgblkdiamond",0x025C6}, //  ◆ # black diamond
	{"\\mdlgwhtdiamond",0x025C7}, //  ◇ # white diamond; diamond open
	{"\\blackinwhitediamond",0x025C8}, //  ◈ # white diamond containing black small diamond
	{"\\fisheye",0x025C9}, //  ◉ # fisheye
	{"\\dottedcircle",0x025CC}, //  ◌ # dotted circle
	{"\\circlevertfill",0x025CD}, //  ◍ # circle with vertical fill
	{"\\bullseye",0x025CE}, //  ◎ # bullseye
	{"\\mdlgblkcircle",0x025CF}, //  ● # circle filled
	{"\\circletophalfblack",0x025D3}, //  ◓ # circle filled top half
	{"\\circleurquadblack",0x025D4}, //  ◔ # circle with upper right quadrant black
	{"\\blackcircleulquadwhite",0x025D5}, //  ◕ # circle with all but upper left quadrant black
	{"\\blacklefthalfcircle",0x025D6}, //  ◖ # left half black circle
	{"\\blackrighthalfcircle",0x025D7}, //  ◗ # right half black circle
	{"\\inversewhitecircle",0x025D9}, //  ◙ # inverse white circle
	{"\\invwhiteupperhalfcircle",0x025DA}, //  ◚ # upper half inverse white circle
	{"\\invwhitelowerhalfcircle",0x025DB}, //  ◛ # lower half inverse white circle
	{"\\ularc",0x025DC}, //  ◜ # upper left quadrant circular arc
	{"\\urarc",0x025DD}, //  ◝ # upper right quadrant circular arc
	{"\\lrarc",0x025DE}, //  ◞ # lower right quadrant circular arc
	{"\\llarc",0x025DF}, //  ◟ # lower left quadrant circular arc
	{"\\topsemicircle",0x025E0}, //  ◠ # upper half circle
	{"\\botsemicircle",0x025E1}, //  ◡ # lower half circle
	{"\\lrblacktriangle",0x025E2}, //  ◢ # lower right triangle filled
	{"\\llblacktriangle",0x025E3}, //  ◣ # lower left triangle filled
	{"\\ulblacktriangle",0x025E4}, //  ◤ # upper left triangle filled
	{"\\urblacktriangle",0x025E5}, //  ◥ # upper right triangle filled
	{"\\smwhtcircle",0x025E6}, //  ◦ # white bullet
	{"\\squareulblack",0x025E9}, //  ◩ # square filled top left corner
	{"\\trianglecdot",0x025EC}, //  ◬ # triangle with centered dot
	{"\\triangleleftblack",0x025ED}, //  ◭ # up-pointing triangle with left half black
	{"\\trianglerightblack",0x025EE}, //  ◮ # up-pointing triangle with right half black
	{"\\lgwhtcircle",0x025EF}, //  ◯ # large circle
	{"\\squareulquad",0x025F0}, //  ◰ # white square with upper left quadrant
	{"\\squarellquad",0x025F1}, //  ◱ # white square with lower left quadrant
	{"\\squarelrquad",0x025F2}, //  ◲ # white square with lower right quadrant
	{"\\squareurquad",0x025F3}, //  ◳ # white square with upper right quadrant
	{"\\circleulquad",0x025F4}, //  ◴ # white circle with upper left quadrant
	{"\\circlellquad",0x025F5}, //  ◵ # white circle with lower left quadrant
	{"\\circlelrquad",0x025F6}, //  ◶ # white circle with lower right quadrant
	{"\\circleurquad",0x025F7}, //  ◷ # white circle with upper right quadrant
	{"\\ultriangle",0x025F8}, //  ◸ # upper left triangle
	{"\\urtriangle",0x025F9}, //  ◹ # upper right triangle
	{"\\lltriangle",0x025FA}, //  ◺ # lower left triangle
	{"\\mdwhtsquare",0x025FB}, //  ◻ # white medium square
	{"\\mdblksquare",0x025FC}, //  ◼ # black medium square
	{"\\mdsmwhtsquare",0x025FD}, //  ◽ # white medium small square
	{"\\mdsmblksquare",0x025FE}, //  ◾ # black medium small square
	{"\\lrtriangle",0x025FF}, //  ◿ # lower right triangle
	{"\\bigwhitestar",0x02606}, //  ☆ # star open
	{"\\astrosun",0x02609}, //  ☉ # sun
	{"\\danger",0x02621}, //  ☡ # dangerous bend (caution sign)
	{"\\acidfree",0x267E}, //  0x267E # permanent paper sign
	{"\\dicei",0x02680}, //  ⚀ # die face-1
	{"\\diceii",0x02681}, //  ⚁ # die face-2
	{"\\diceiii",0x02682}, //  ⚂ # die face-3
	{"\\diceiv",0x02683}, //  ⚃ # die face-4
	{"\\dicev",0x02684}, //  ⚄ # die face-5
	{"\\dicevi",0x02685}, //  ⚅ # die face-6
	{"\\circledrightdot",0x02686}, //  ⚆ # white circle with dot right
	{"\\circledtwodots",0x02687}, //  ⚇ # white circle with two dots
	{"\\blackcircledrightdot",0x02688}, //  ⚈ # black circle with white dot right
	{"\\blackcircledtwodots",0x02689}, //  ⚉ # black circle with two white dots
	{"\\hermaphrodite",0x26A5}, //  0x26A5 # male and female sign
	{"\\mdwhtcircle",0x26AA}, //  0x26AA # medium white circle
	{"\\mdblkcircle",0x26AB}, //  0x26AB # medium black circle
	{"\\mdsmwhtcircle",0x26AC}, //  0x26AC # medium small white circle
	{"\\neuter",0x26B2}, //  0x26B2 # neuter
	{"\\circledstar",0x0272A}, //  ✪ # circled white star
	{"\\varstar",0x02736}, //  ✶ # six pointed black star
	{"\\dingasterisk",0x0273D}, //  ✽ # heavy teardrop-spoked asterisk
	{"\\draftingarrow",0x0279B}, //  ➛ # right arrow with bold head (drafting)
	{"\\threedangle",0x27C0}, //  0x27C0 # three dimensional angle
	{"\\whiteinwhitetriangle",0x27C1}, //  0x27C1 # white triangle containing small white triangle
	{"\\bsolhsub",0x27C8}, //  0x27C8 # reverse solidus preceding subset
	{"\\suphsol",0x27C9}, //  0x27C9 # superset preceding solidus
	{"\\wedgedot",0x027D1}, //  ⟑ # and with dot
	{"\\veedot",0x027C7}, //  ⟇ # or with dot
	{"\\upin",0x027D2}, //  ⟒ # element of opening upwards
	{"\\bigbot",0x027D8}, //  ⟘ # large up tack
	{"\\bigtop",0x027D9}, //  ⟙ # large down tack
	{"\\UUparrow",0x027F0}, //  ⟰ # upwards quadruple arrow
	{"\\DDownarrow",0x027F1}, //  ⟱ # downwards quadruple arrow
	{"\\longrightsquigarrow",0x027FF}, //  ⟿ # long rightwards squiggle arrow
	{"\\nvtwoheadrightarrow",0x02900}, //  ⤀ # rightwards two-headed arrow with vertical stroke
	{"\\nVtwoheadrightarrow",0x02901}, //  ⤁ # rightwards two-headed arrow with double vertical stroke
	{"\\nvLeftarrow",0x02902}, //  ⤂ # leftwards double arrow with vertical stroke
	{"\\nvRightarrow",0x02903}, //  ⤃ # rightwards double arrow with vertical stroke
	{"\\nvLeftrightarrow",0x02904}, //  ⤄ # left right double arrow with vertical stroke
	{"\\twoheadmapsto",0x02905}, //  ⤅ # rightwards two-headed arrow from bar
	{"\\downarrowbarred",0x02908}, //  ⤈ # downwards arrow with horizontal stroke
	{"\\uparrowbarred",0x02909}, //  ⤉ # upwards arrow with horizontal stroke
	{"\\leftbkarrow",0x0290C}, //  ⤌ # leftwards double dash arrow
	{"\\leftdbkarrow",0x0290E}, //  ⤎ # leftwards triple dash arrow
	{"\\rightdotarrow",0x02911}, //  ⤑ # rightwards arrow with dotted stem
	{"\\nvrightarrowtail",0x02914}, //  ⤔ # rightwards arrow with tail with vertical stroke
	{"\\nVrightarrowtail",0x02915}, //  ⤕ # rightwards arrow with tail with double vertical stroke
	{"\\nvtwoheadrightarrowtail",0x02917}, //  ⤗ # rightwards two-headed arrow with tail with vertical stroke
	{"\\nVtwoheadrightarrowtail",0x02918}, //  ⤘ # rightwards two-headed arrow with tail with double vertical stroke
	{"\\diamondleftarrow",0x0291D}, //  ⤝ # leftwards arrow to black diamond
	{"\\rightarrowdiamond",0x0291E}, //  ⤞ # rightwards arrow to black diamond
	{"\\diamondleftarrowbar",0x0291F}, //  ⤟ # leftwards arrow from bar to black diamond
	{"\\rightarrowplus",0x02945}, //  ⥅ # rightwards arrow with plus below
	{"\\leftarrowplus",0x02946}, //  ⥆ # leftwards arrow with plus below
	{"\\leftrightarrowcircle",0x02948}, //  ⥈ # left right arrow through small circle
	{"\\twoheaduparrowcircle",0x02949}, //  ⥉ # upwards two-headed arrow from small circle
	{"\\leftrightharpoonupdown",0x0294A}, //  ⥊ # left barb up right barb down harpoon
	{"\\leftrightharpoondownup",0x0294B}, //  ⥋ # left barb down right barb up harpoon
	{"\\updownharpoonrightleft",0x0294C}, //  ⥌ # up barb right down barb left harpoon
	{"\\updownharpoonleftright",0x0294D}, //  ⥍ # up barb left down barb right harpoon
	{"\\leftharpoonsupdown",0x02962}, //  ⥢ # leftwards harpoon with barb up above leftwards harpoon with barb down
	{"\\upharpoonsleftright",0x02963}, //  ⥣ # upwards harpoon with barb left beside upwards harpoon with barb right
	{"\\rightharpoonsupdown",0x02964}, //  ⥤ # rightwards harpoon with barb up above rightwards harpoon with barb down
	{"\\downharpoonsleftright",0x02965}, //  ⥥ # downwards harpoon with barb left beside downwards harpoon with barb right
	{"\\leftrightharpoonsup",0x02966}, //  ⥦ # leftwards harpoon with barb up above rightwards harpoon with barb up
	{"\\leftrightharpoonsdown",0x02967}, //  ⥧ # leftwards harpoon with barb down above rightwards harpoon with barb down
	{"\\rightleftharpoonsup",0x02968}, //  ⥨ # rightwards harpoon with barb up above leftwards harpoon with barb up
	{"\\rightleftharpoonsdown",0x02969}, //  ⥩ # rightwards harpoon with barb down above leftwards harpoon with barb down
	{"\\leftharpoonupdash",0x0296A}, //  ⥪ # leftwards harpoon with barb up above long dash
	{"\\dashleftharpoondown",0x0296B}, //  ⥫ # leftwards harpoon with barb down below long dash
	{"\\rightharpoonupdash",0x0296C}, //  ⥬ # rightwards harpoon with barb up above long dash
	{"\\dashrightharpoondown",0x0296D}, //  ⥭ # rightwards harpoon with barb down below long dash
	{"\\measuredangleleft",0x0299B}, //  ⦛ # measured angle opening left
	{"\\rightanglemdot",0x0299D}, //  ⦝ # measured right angle with dot
	{"\\angles",0x0299E}, //  ⦞ # angle with s inside
	{"\\angdnr",0x0299F}, //  ⦟ # acute angle
	{"\\sphericalangleup",0x029A1}, //  ⦡ # spherical angle opening up
	{"\\turnangle",0x029A2}, //  ⦢ # turned angle
	{"\\revangle",0x029A3}, //  ⦣ # reversed angle
	{"\\angleubar",0x029A4}, //  ⦤ # angle with underbar
	{"\\revangleubar",0x029A5}, //  ⦥ # reversed angle with underbar
	{"\\wideangledown",0x029A6}, //  ⦦ # oblique angle opening up
	{"\\wideangleup",0x029A7}, //  ⦧ # oblique angle opening down
	{"\\measanglerutone",0x029A8}, //  ⦨ # measured angle with open arm ending in arrow pointing up and right
	{"\\measanglelutonw",0x029A9}, //  ⦩ # measured angle with open arm ending in arrow pointing up and left
	{"\\measanglerdtose",0x029AA}, //  ⦪ # measured angle with open arm ending in arrow pointing down and right
	{"\\measangleldtosw",0x029AB}, //  ⦫ # measured angle with open arm ending in arrow pointing down and left
	{"\\measangleurtone",0x029AC}, //  ⦬ # measured angle with open arm ending in arrow pointing right and up
	{"\\measangleultonw",0x029AD}, //  ⦭ # measured angle with open arm ending in arrow pointing left and up
	{"\\measangledrtose",0x029AE}, //  ⦮ # measured angle with open arm ending in arrow pointing right and down
	{"\\measangledltosw",0x029AF}, //  ⦯ # measured angle with open arm ending in arrow pointing left and down
	{"\\revemptyset",0x029B0}, //  ⦰ # reversed empty set
	{"\\emptysetobar",0x029B1}, //  ⦱ # empty set with overbar
	{"\\emptysetocirc",0x029B2}, //  ⦲ # empty set with small circle above
	{"\\emptysetoarr",0x029B3}, //  ⦳ # empty set with right arrow above
	{"\\emptysetoarrl",0x029B4}, //  ⦴ # empty set with left arrow above
	{"\\circledparallel",0x029B7}, //  ⦷ # circled parallel
	{"\\odotslashdot",0x029BC}, //  ⦼ # circled anticlockwise-rotated division sign
	{"\\circledwhitebullet",0x029BE}, //  ⦾ # circled white bullet
	{"\\circledbullet",0x029BF}, //  ⦿ # circled bullet
	{"\\olessthan",0x029C0}, //  ⧀ # circled less-than
	{"\\ogreaterthan",0x029C1}, //  ⧁ # circled greater-than
	{"\\lrtriangleeq",0x029E1}, //  ⧡ # increases as
	{"\\eparsl",0x029E3}, //  ⧣ # equals sign and slanted parallel
	{"\\smeparsl",0x029E4}, //  ⧤ # equals sign and slanted parallel with tilde above
	{"\\eqvparsl",0x029E5}, //  ⧥ # identical to and slanted parallel
	{"\\dsol",0x029F6}, //  ⧶ # solidus with overbar
	{"\\rsolbar",0x029F7}, //  ⧷ # reverse solidus with horizontal stroke
	{"\\doubleplus",0x029FA}, //  ⧺ # double plus
	{"\\tripleplus",0x029FB}, //  ⧻ # triple plus
	{"\\modtwosum",0x02A0A}, //  ⨊ # modulo two sum
	{"\\cirfnint",0x02A10}, //  ⨐ # circulation function
	{"\\awint",0x02A11}, //  ⨑ # anticlockwise integration
	{"\\rppolint",0x02A12}, //  ⨒ # line integration with rectangular path around pole
	{"\\scpolint",0x02A13}, //  ⨓ # line integration with semicircular path around pole
	{"\\npolint",0x02A14}, //  ⨔ # line integration not including the pole
	{"\\pointint",0x02A15}, //  ⨕ # integral around a point operator
	{"\\ringplus",0x02A22}, //  ⨢ # plus sign with small circle above
	{"\\plushat",0x02A23}, //  ⨣ # plus sign with circumflex accent above
	{"\\simplus",0x02A24}, //  ⨤ # plus sign with tilde above
	{"\\plussim",0x02A26}, //  ⨦ # plus sign with tilde below
	{"\\plussubtwo",0x02A27}, //  ⨧ # plus sign with subscript two
	{"\\plustrif",0x02A28}, //  ⨨ # plus sign with black triangle
	{"\\commaminus",0x02A29}, //  ⨩ # minus sign with comma above
	{"\\opluslhrim",0x02A2D}, //  ⨭ # plus sign in left half circle
	{"\\oplusrhrim",0x02A2E}, //  ⨮ # plus sign in right half circle
	{"\\dottimes",0x02A30}, //  ⨰ # multiplication sign with dot above
	{"\\timesbar",0x02A31}, //  ⨱ # multiplication sign with underbar
	{"\\smashtimes",0x02A33}, //  ⨳ # smash product
	{"\\otimeslhrim",0x02A34}, //  ⨴ # multiplication sign in left half circle
	{"\\otimesrhrim",0x02A35}, //  ⨵ # multiplication sign in right half circle
	{"\\otimeshat",0x02A36}, //  ⨶ # circled multiplication sign with circumflex accent
	{"\\Otimes",0x02A37}, //  ⨷ # multiplication sign in double circle
	{"\\odiv",0x02A38}, //  ⨸ # circled division sign
	{"\\triangleplus",0x02A39}, //  ⨹ # plus sign in triangle
	{"\\triangleminus",0x02A3A}, //  ⨺ # minus sign in triangle
	{"\\triangletimes",0x02A3B}, //  ⨻ # multiplication sign in triangle
	{"\\capdot",0x02A40}, //  ⩀ # intersection with dot
	{"\\uminus",0x02A41}, //  ⩁ # union with minus sign
	{"\\capwedge",0x02A44}, //  ⩄ # intersection with logical and
	{"\\cupvee",0x02A45}, //  ⩅ # union with logical or
	{"\\twocups",0x02A4A}, //  ⩊ # union beside and joined with union
	{"\\twocaps",0x02A4B}, //  ⩋ # intersection beside and joined with intersection
	{"\\closedvarcup",0x02A4C}, //  ⩌ # closed union with serifs
	{"\\closedvarcap",0x02A4D}, //  ⩍ # closed intersection with serifs
	{"\\Sqcap",0x02A4E}, //  ⩎ # double square intersection
	{"\\Sqcup",0x02A4F}, //  ⩏ # double square union
	{"\\closedvarcupsmashprod",0x02A50}, //  ⩐ # closed union with serifs and smash product
	{"\\wedgeodot",0x02A51}, //  ⩑ # logical and with dot above
	{"\\veeodot",0x02A52}, //  ⩒ # logical or with dot above
	{"\\wedgeonwedge",0x02A55}, //  ⩕ # two intersecting logical and
	{"\\bigslopedvee",0x02A57}, //  ⩗ # sloping large or
	{"\\bigslopedwedge",0x02A58}, //  ⩘ # sloping large and
	{"\\wedgemidvert",0x02A5A}, //  ⩚ # logical and with middle stem
	{"\\veemidvert",0x02A5B}, //  ⩛ # logical or with middle stem
	{"\\midbarwedge",0x02A5C}, //  ⩜ # ogical and with horizontal dash
	{"\\midbarvee",0x02A5D}, //  ⩝ # logical or with horizontal dash
	{"\\wedgedoublebar",0x02A60}, //  ⩠ # logical and with double underbar
	{"\\varveebar",0x02A61}, //  ⩡ # small vee with underbar
	{"\\doublebarvee",0x02A62}, //  ⩢ # logical or with double overbar
	{"\\veedoublebar",0x02A63}, //  ⩣ # logical or with double underbar
	{"\\eqdot",0x02A66}, //  ⩦ # equals sign with dot below
	{"\\dotequiv",0x02A67}, //  ⩧ # identical with dot above
	{"\\dotsim",0x02A6A}, //  ⩪ # tilde operator with dot above
	{"\\simrdots",0x02A6B}, //  ⩫ # tilde operator with rising dots
	{"\\simminussim",0x02A6C}, //  ⩬ # similar minus similar
	{"\\congdot",0x02A6D}, //  ⩭ # congruent with dot above
	{"\\asteq",0x02A6E}, //  ⩮ # equals with asterisk
	{"\\hatapprox",0x02A6F}, //  ⩯ # almost equal to with circumflex accent
	{"\\approxeqq",0x02A70}, //  ⩰ # approximately equal or equal to
	{"\\eqqplus",0x02A71}, //  ⩱ # equals sign above plus sign
	{"\\pluseqq",0x02A72}, //  ⩲ # plus sign above equals sign
	{"\\eqqsim",0x02A73}, //  ⩳ # equals sign above tilde operator
	{"\\Coloneq",0x02A74}, //  ⩴ # double colon equal
	{"\\eqeqeq",0x02A76}, //  ⩶ # three consecutive equals signs
	{"\\equivDD",0x02A78}, //  ⩸ # equivalent with four dots above
	{"\\ltcir",0x02A79}, //  ⩹ # less-than with circle inside
	{"\\gtcir",0x02A7A}, //  ⩺ # greater-than with circle inside
	{"\\ltquest",0x02A7B}, //  ⩻ # less-than with question mark above
	{"\\gtquest",0x02A7C}, //  ⩼ # greater-than with question mark above
	{"\\lesdot",0x02A7F}, //  ⩿ # less-than or slanted equal to with dot inside
	{"\\gesdot",0x02A80}, //  ⪀ # greater-than or slanted equal to with dot inside
	{"\\lesdoto",0x02A81}, //  ⪁ # less-than or slanted equal to with dot above
	{"\\gesdoto",0x02A82}, //  ⪂ # greater-than or slanted equal to with dot above
	{"\\lesdotor",0x02A83}, //  ⪃ # less-than or slanted equal to with dot above right
	{"\\gesdotol",0x02A84}, //  ⪄ # greater-than or slanted equal to with dot above left
	{"\\lsime",0x02A8D}, //  ⪍ # less-than above similar or equal
	{"\\gsime",0x02A8E}, //  ⪎ # greater-than above similar or equal
	{"\\lsimg",0x02A8F}, //  ⪏ # less-than above similar above greater-than
	{"\\gsiml",0x02A90}, //  ⪐ # greater-than above similar above less-than
	{"\\lgE",0x02A91}, //  ⪑ # less-than above greater-than above double-line equal
	{"\\glE",0x02A92}, //  ⪒ # greater-than above less-than above double-line equal
	{"\\lesges",0x02A93}, //  ⪓ # less-than above slanted equal above greater-than above slanted equal
	{"\\gesles",0x02A94}, //  ⪔ # greater-than above slanted equal above less-than above slanted equal
	{"\\elsdot",0x02A97}, //  ⪗ # slanted equal to or less-than with dot inside
	{"\\egsdot",0x02A98}, //  ⪘ # slanted equal to or greater-than with dot inside
	{"\\eqqless",0x02A99}, //  ⪙ # double-line equal to or less-than
	{"\\eqqgtr",0x02A9A}, //  ⪚ # double-line equal to or greater-than
	{"\\eqqslantless",0x02A9B}, //  ⪛ # double-line slanted equal to or less-than
	{"\\eqqslantgtr",0x02A9C}, //  ⪜ # double-line slanted equal to or greater-than
	{"\\simless",0x02A9D}, //  ⪝ # similar or less-than
	{"\\simgtr",0x02A9E}, //  ⪞ # similar or greater-than
	{"\\simlE",0x02A9F}, //  ⪟ # similar above less-than above equals sign
	{"\\simgE",0x02AA0}, //  ⪠ # similar above greater-than above equals sign
	{"\\glj",0x02AA4}, //  ⪤ # greater-than overlapping less-than
	{"\\gla",0x02AA5}, //  ⪥ # greater-than beside less-than
	{"\\ltcc",0x02AA6}, //  ⪦ # less-than closed by curve
	{"\\gtcc",0x02AA7}, //  ⪧ # greater-than closed by curve
	{"\\lescc",0x02AA8}, //  ⪨ # less-than closed by curve above slanted equal
	{"\\gescc",0x02AA9}, //  ⪩ # greater-than closed by curve above slanted equal
	{"\\smt",0x02AAA}, //  ⪪ # smaller than
	{"\\lat",0x02AAB}, //  ⪫ # larger than
	{"\\smte",0x02AAC}, //  ⪬ # smaller than or equal to
	{"\\late",0x02AAD}, //  ⪭ # larger than or equal to
	{"\\precneq",0x02AB1}, //  ⪱ # precedes above single-line not equal to
	{"\\succneq",0x02AB2}, //  ⪲ # succeeds above single-line not equal to
	{"\\Prec",0x02ABB}, //  ⪻ # double precedes
	{"\\Succ",0x02ABC}, //  ⪼ # double succeeds
	{"\\subsetdot",0x02ABD}, //  ⪽ # subset with dot
	{"\\supsetdot",0x02ABE}, //  ⪾ # superset with dot
	{"\\subsetplus",0x02ABF}, //  ⪿ # subset with plus sign below
	{"\\supsetplus",0x02AC0}, //  ⫀ # superset with plus sign below
	{"\\submult",0x02AC1}, //  ⫁ # subset with multiplication sign below
	{"\\supmult",0x02AC2}, //  ⫂ # superset with multiplication sign below
	{"\\subedot",0x02AC3}, //  ⫃ # subset of or equal to with dot above
	{"\\supedot",0x02AC4}, //  ⫄ # superset of or equal to with dot above
	{"\\subsim",0x02AC7}, //  ⫇ # subset of above tilde operator
	{"\\supsim",0x02AC8}, //  ⫈ # superset of above tilde operator
	{"\\subsetapprox",0x02AC9}, //  ⫉ # subset of above almost equal to
	{"\\supsetapprox",0x02ACA}, //  ⫊ # superset of above almost equal to
	{"\\lsqhook",0x02ACD}, //  ⫍ # square left open box operator
	{"\\rsqhook",0x02ACE}, //  ⫎ # square right open box operator
	{"\\csub",0x02ACF}, //  ⫏ # closed subset
	{"\\csup",0x02AD0}, //  ⫐ # closed superset
	{"\\csube",0x02AD1}, //  ⫑ # closed subset or equal to
	{"\\csupe",0x02AD2}, //  ⫒ # closed superset or equal to
	{"\\subsup",0x02AD3}, //  ⫓ # subset above superset
	{"\\supsub",0x02AD4}, //  ⫔ # superset above subset
	{"\\subsub",0x02AD5}, //  ⫕ # subset above subset
	{"\\supsup",0x02AD6}, //  ⫖ # superset above superset
	{"\\suphsub",0x02AD7}, //  ⫗ # superset beside subset
	{"\\supdsub",0x02AD8}, //  ⫘ # superset beside and joined by dash with subset
	{"\\forkv",0x02AD9}, //  ⫙ # element of opening downwards
	{"\\lllnest",0x02AF7}, //  ⫷ # stacked very much less-than
	{"\\gggnest",0x02AF8}, //  ⫸ # stacked very much greater-than
	{"\\leqqslant",0x02AF9}, //  ⫹ # double-line slanted less-than or equal to
	{"\\geqqslant",0x02AFA}, //  ⫺ # double-line slanted greater-than or equal to
	{"\\squaretopblack",0x2B12}, //  0x2B12 # square with top half black
	{"\\squarebotblack",0x2B13}, //  0x2B13 # square with bottom half black
	{"\\squareurblack",0x2B14}, //  0x2B14 # square with upper right diagonal half black
	{"\\squarellblack",0x2B15}, //  0x2B15 # square with lower left diagonal half black
	{"\\diamondleftblack",0x2B16}, //  0x2B16 # diamond with left half black
	{"\\diamondrightblack",0x2B17}, //  0x2B17 # diamond with right half black
	{"\\diamondtopblack",0x2B18}, //  0x2B18 # diamond with top half black
	{"\\diamondbotblack",0x2B19}, //  0x2B19 # diamond with bottom half black
	{"\\dottedsquare",0x2B1A}, //  0x2B1A # dotted square
	{"\\lgblksquare",0x2B1B}, //  0x2B1B # black large square
	{"\\lgwhtsquare",0x2B1C}, //  0x2B1C # white large square
	{"\\vysmblksquare",0x2B1D}, //  0x2B1D # black very small square
	{"\\vysmwhtsquare",0x2B1E}, //  0x2B1E # white very small square
	{"\\pentagonblack",0x2B1F}, //  0x2B1F # black pentagon
	{"\\pentagon",0x2B20}, //  0x2B20 # white pentagon
	{"\\varhexagon",0x2B21}, //  0x2B21 # white hexagon
	{"\\varhexagonblack",0x2B22}, //  0x2B22 # black hexagon
	{"\\hexagonblack",0x2B23}, //  0x2B23 # horizontal black hexagon
	{"\\lgblkcircle",0x2B24}, //  0x2B24 # black large circle
	{"\\mdblkdiamond",0x2B25}, //  0x2B25 # black medium diamond
	{"\\mdwhtdiamond",0x2B26}, //  0x2B26 # white medium diamond
	{"\\mdblklozenge",0x2B27}, //  0x2B27 # black medium lozenge
	{"\\mdwhtlozenge",0x2B28}, //  0x2B28 # white medium lozenge
	{"\\smblkdiamond",0x2B29}, //  0x2B29 # black small diamond
	{"\\smblklozenge",0x2B2A}, //  0x2B2A # black small lozenge
	{"\\smwhtlozenge",0x2B2B}, //  0x2B2B # white small lozenge
	{"\\blkhorzoval",0x2B2C}, //  0x2B2C # black horizontal ellipse
	{"\\whthorzoval",0x2B2D}, //  0x2B2D # white horizontal ellipse
	{"\\blkvertoval",0x2B2E}, //  0x2B2E # black vertical ellipse
	{"\\whtvertoval",0x2B2F}, //  0x2B2F # white vertical ellipse
	{"\\circleonleftarrow",0x2B30}, //  0x2B30 # left arrow with small circle
	{"\\leftthreearrows",0x2B31}, //  0x2B31 # three leftwards arrows
	{"\\leftarrowonoplus",0x2B32}, //  0x2B32 # left arrow with circled plus
	{"\\longleftsquigarrow",0x2B33}, //  0x2B33 # long leftwards squiggle arrow
	{"\\nvtwoheadleftarrow",0x2B34}, //  0x2B34 # leftwards two-headed arrow with vertical stroke
	{"\\nVtwoheadleftarrow",0x2B35}, //  0x2B35 # leftwards two-headed arrow with double vertical stroke
	{"\\twoheadmapsfrom",0x2B36}, //  0x2B36 # leftwards two-headed arrow from bar
	{"\\twoheadleftdbkarrow",0x2B37}, //  0x2B37 # leftwards two-headed triple-dash arrow
	{"\\leftdotarrow",0x2B38}, //  0x2B38 # leftwards arrow with dotted stem
	{"\\nvleftarrowtail",0x2B39}, //  0x2B39 # leftwards arrow with tail with vertical stroke
	{"\\nVleftarrowtail",0x2B3A}, //  0x2B3A # leftwards arrow with tail with double vertical stroke
	{"\\twoheadleftarrowtail",0x2B3B}, //  0x2B3B # leftwards two-headed arrow with tail
	{"\\nvtwoheadleftarrowtail",0x2B3C}, //  0x2B3C # leftwards two-headed arrow with tail with vertical stroke
	{"\\nVtwoheadleftarrowtail",0x2B3D}, //  0x2B3D # leftwards two-headed arrow with tail with double vertical stroke
	{"\\leftarrowx",0x2B3E}, //  0x2B3E # leftwards arrow through x
	{"\\leftcurvedarrow",0x2B3F}, //  0x2B3F # wave arrow pointing directly left
	{"\\equalleftarrow",0x2B40}, //  0x2B40 # equals sign above leftwards arrow
	{"\\bsimilarleftarrow",0x2B41}, //  0x2B41 # reverse tilde operator above leftwards arrow
	{"\\leftarrowbackapprox",0x2B42}, //  0x2B42 # leftwards arrow above reverse almost equal to
	{"\\rightarrowgtr",0x2B43}, //  0x2B43 # rightwards arrow through greater-than
	{"\\leftarrowless",0x2977}, //  0x2977 # leftwards arrow through less-than
	{"\\rightarrowsupset",0x2B44}, //  0x2B44 # rightwards arrow through superset
	{"\\leftarrowsubset",0x297A}, //  0x297A # leftwards arrow through subset
	{"\\LLeftarrow",0x2B45}, //  0x2B45 # leftwards quadruple arrow
	{"\\RRightarrow",0x2B46}, //  0x2B46 # rightwards quadruple arrow
	{"\\bsimilarrightarrow",0x2B47}, //  0x2B47 # reverse tilde operator above rightwards arrow
	{"\\rightarrowbackapprox",0x2B48}, //  0x2B48 # rightwards arrow above reverse almost equal to
	{"\\similarleftarrow",0x2B49}, //  0x2B49 # tilde operator above leftwards arrow
	{"\\leftarrowapprox",0x2B4A}, //  0x2B4A # leftwards arrow above almost equal to
	{"\\leftarrowbsimilar",0x2B4B}, //  0x2B4B # leftwards arrow above reverse tilde operator
	{"\\rightarrowbsimilar",0x2B4C}, //  0x2B4C # righttwards arrow above reverse tilde operator
	{"\\medwhitestar",0x2B50}, //  0x2B50 # white medium star
	{"\\medblackstar",0x2B51}, //  0x2B51 # black medium star
	{"\\smwhitestar",0x2B52}, //  0x2B52 # white small star
	{"\\rightpentagonblack",0x2B53}, //  0x2B53 # black right-pointing pentagon
	{"\\rightpentagon",0x2B54}, //  0x2B54 # white right-pointing pentagon
	{"\\postalmark",0x03012}, //  〒 # postal mark
	{"\\triangleright",0x025B7}, //  ▷ # (large) right triangle, open; z notation range restriction
	{"\\triangleleft",0x025C1}, //  ◁ # (large) left triangle, open; z notation domain restriction
	{"\\leftouterjoin",0x027D5}, //  ⟕ # left outer join
	{"\\rightouterjoin",0x027D6}, //  ⟖ # right outer join
	{"\\fullouterjoin",0x027D7}, //  ⟗ # full outer join
	{"\\join",0x02A1D}, //  ⨝ # join
	{"\\underbar",0x00332}, //  ̲ # combining low line
	{"\\underleftrightarrow",0x0034D}, //  ͍ # underleftrightarrow accent
	{"\\leftwavearrow",0x0219C}, //  ↜ # left arrow-wavy
	{"\\rightwavearrow",0x0219D}, //  ↝ # right arrow-wavy
	{"\\varbarwedge",0x02305}, //  ⌅ # /barwedge b: logical and, bar above [projective (bar over small wedge)]
	{"\\smallblacktriangleright",0x025B8}, //  ▸ # right triangle, filled
	{"\\smallblacktriangleleft",0x025C2}, //  ◂ # left triangle, filled
	{"\\tricolon",0x0205D}, //  ⁝ # tricolon
	{NULL,                     0x00000},
};
const Symbol * TEXPRINTF_SYMBOLS=Symbols;
