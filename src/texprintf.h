#ifndef __TEXPRINTF_H__
#define __TEXPRINTF_H__

typedef struct {
	char *name;
	unsigned int unicode;
} Symbol;

extern Symbol * TEXPRINTF_SYMBOLS;
extern int TEXPRINTF_LW;								/* line width, if it is 0 the line width is infinite */
extern char * TEXPRINTF_FONT;							/* default font, one of:
														 *  "mathsfbfit"
														 *  "mathsfbf"
														 *  "mathfrak"
														 *  "mathbfit"
														 *  "mathsfit"
														 *  "mathcal"
														 *  "mathscr"
														 *  "mathbf"
														 *  "mathbb"
														 *  "mathsf"
														 *  "mathtt"
														 *  "mathnormal"
														 *  "text" */
extern int TEXPRINTF_FCW;								/* full width character width */
extern int TEXPRINTF_WCW;								/* wide character width */
extern int TEXPRINTF_ERR;
int texprintf(const char *format, ...);					/* prints to stdout */
char * stexprintf(const char *format, ...);				/* prints to string */
char * texstring(const char *str);                      /* stextprintf, but no printf formatting */
void texfree(void *ptr);								/* free memory from results */
int ftexprintf(FILE *f, const char *format, ...);		/* prints to file */
void texboxtree(const char *format, ...);				/* print the box-tree, for debugging purposes */
void texlistsymbols();
char *texsymbols_str();
void texerrors();
char *texerrors_str();
void SetStyleASCII();
void SetStyleUNICODE();

#endif
