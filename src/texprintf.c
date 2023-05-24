#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include "boxes.h"
#include "drawbox.h"
#include "parser.h"
#include "lexer.h"
#include "stringutils.h"
#include "error.h"

int TEXPRINTF_LW=0;
char * TEXPRINTF_FONT="text";
int TEXPRINTF_FCW=2;
int TEXPRINTF_WCW=2;

int TEXPRINTF_ERR=0;

int texprintf(const char *format, ...)
{
   	va_list ap;
   	char *str;
   	int Na=255, np;
	box root;

	ResetErrors();
	FCSPACES=TEXPRINTF_FCW;
	WCSPACES=TEXPRINTF_WCW;
	if ((WCSPACES<1)||(WCSPACES>2))
	{
		fprintf(stderr,"Error: TEXPRINTF_WCW out of range, wide characters can occupy either 1 or 2 character spaces\n");
		exit(1);
	}
	if ((FCSPACES<1)||(FCSPACES>2))
	{
		fprintf(stderr,"Error: TEXPRINTF_FCW out of range, wide characters can occupy either 1 or 2 character spaces\n");
		exit(1);
	}

   	str=malloc(Na*sizeof(char));
   	va_start (ap, format);
   	np=vsnprintf(str, Na*sizeof(char), format, ap);
   	while (np>=Na)
   	{
		Na+=255;
		str=realloc(str, Na*sizeof(char));
		va_start (ap, format);
		np=vsnprintf(str, Na*sizeof(char), format, ap);
	}

	root=ParseString(str, TEXPRINTF_LW, TEXPRINTF_FONT);
	BoxPos(&root);
	np=PrintBox(&root);
	FreeBox(&root);
	free(str);
	TEXPRINTF_ERR=ERRORSTATE;
	return np;
}

char * texstring(const char *str)
{
	box root;
	char *res;

	ResetErrors();
	FCSPACES=TEXPRINTF_FCW;
	WCSPACES=TEXPRINTF_WCW;
	if ((WCSPACES<1)||(WCSPACES>2))
	{
		fprintf(stderr,"Error: TEXPRINTF_WCW out of range, wide characters can occupy either 1 or 2 character spaces\n");
		exit(1);
	}
	if ((FCSPACES<1)||(FCSPACES>2))
	{
		fprintf(stderr,"Error: TEXPRINTF_FCW out of range, wide characters can occupy either 1 or 2 character spaces\n");
		exit(1);
	}

	root=ParseString(str, TEXPRINTF_LW, TEXPRINTF_FONT);
	BoxPos(&root);
	res=DrawBox(&root);
	FreeBox(&root);
	TEXPRINTF_ERR=ERRORSTATE;

	return res;
}


char * stexprintf(const char *format, ...)
{
   	va_list ap;
   	char *res;
   	char *str;
   	int Na=255, np;

   	str=malloc(Na*sizeof(char));
   	va_start (ap, format);
   	np=vsnprintf(str, Na*sizeof(char), format, ap);
   	while (np>=Na)
   	{
		Na+=255;
		str=realloc(str, Na*sizeof(char));
		va_start (ap, format);
		np=vsnprintf(str, Na*sizeof(char), format, ap);
	}

	res = texstring(str);
	free(str);
	return res;
}

void texfree(void *ptr)
{
    free(ptr);
}

int ftexprintf(FILE *f, const char *format, ...)
{
   	va_list ap;
   	char *res;
   	char *str;
   	int Na=255, np;
	box root;

	ResetErrors();
	FCSPACES=TEXPRINTF_FCW;
	WCSPACES=TEXPRINTF_WCW;
	if ((WCSPACES<1)||(WCSPACES>2))
	{
		fprintf(stderr,"Error: TEXPRINTF_WCW out of range, wide characters can occupy either 1 or 2 character spaces\n");
		exit(1);
	}
	if ((FCSPACES<1)||(FCSPACES>2))
	{
		fprintf(stderr,"Error: TEXPRINTF_FCW out of range, wide characters can occupy either 1 or 2 character spaces\n");
		exit(1);
	}

   	str=malloc(Na*sizeof(char));
   	va_start (ap, format);
   	np=vsnprintf(str, Na*sizeof(char), format, ap);
   	while (np>=Na)
   	{
		Na+=255;
		str=realloc(str, Na*sizeof(char));
		va_start (ap, format);
		np=vsnprintf(str, Na*sizeof(char), format, ap);
	}

	root=ParseString(str, TEXPRINTF_LW, TEXPRINTF_FONT);
	BoxPos(&root);
	res=DrawBox(&root);
	FreeBox(&root);
	free(str);
	np=strlen(res);
	fprintf(f,"%s",res);
	free(res);
	TEXPRINTF_ERR=ERRORSTATE;

	return np;
}

void texboxtree(const char *format, ...)
{
   	va_list ap;
   	char *str;
   	int Na=255, np;
	box root;

	ResetErrors();
	FCSPACES=TEXPRINTF_FCW;
	WCSPACES=TEXPRINTF_WCW;
	if ((WCSPACES<1)||(WCSPACES>2))
	{
		fprintf(stderr,"Error: TEXPRINTF_WCW out of range, wide characters can occupy either 1 or 2 character spaces\n");
		exit(1);
	}
	if ((FCSPACES<1)||(FCSPACES>2))
	{
		fprintf(stderr,"Error: TEXPRINTF_FCW out of range, wide characters can occupy either 1 or 2 character spaces\n");
		exit(1);
	}

   	str=malloc(Na*sizeof(char));
   	va_start (ap, format);
   	np=vsnprintf(str, Na*sizeof(char), format, ap);
   	while (np>=Na)
   	{
		Na+=255;
		str=realloc(str, Na*sizeof(char));
		va_start (ap, format);
		np=vsnprintf(str, Na*sizeof(char), format, ap);
	}

	root=ParseString(str, TEXPRINTF_LW, TEXPRINTF_FONT);
	BoxPos(&root);
	DrawBoxTree(&root);
	FreeBox(&root);
	free(str);
	TEXPRINTF_ERR=ERRORSTATE;

}

void texlistsymbols()
{
	ListSymbols();								/* link to lexer.o */
}

void texerrors()
{
	ERRORSTATE=TEXPRINTF_ERR;
	E_Messages();						/* link to error.o */
	ResetErrors();
}

void SetStyleASCII()
{
	style=&STYLE_ASC;
}
void SetStyleUNICODE()
{
	style=&STYLE_UNI;
}
