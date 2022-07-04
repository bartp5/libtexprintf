#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>
#include "unicodeblocks.h"
#include "stringutils.h"
#include "error.h"

#define IsPrintable(C) iswprint((C))

int IsInSet(char c, const char *set) /* check whether char c in set */
{
	char *s;
	s=(char *)set;
	while (*s)
	{
		if ((*s)==c)
			return 1;
		s++;
	}
	return 0;
		
}
char * Unicode2Utf8(int U) /* convert unicode code point to an allocated and null teminated string (i.e. 5 bytes) */
{
	char *r, *b;
	r=calloc(5,sizeof(char));
	b=r;
	if (U<0x80)
		*b++=U;
	else if (U<0x800)
	{
		*b++=192+U/64;
		*b++=128+U%64;
	}
	else if (U-0xd800u<0x800)
	{
		fprintf(stderr, "Invalid Unicode Code Point 0x%X\n", U);
		return r;
	}
	else if (U<0x10000)
	{
		*b++=224+U/4096;
		*b++=128+U/64%64;
		*b++=128+U%64;
	}
	else if (U<0x110000)
	{
		*b++=240+U/262144;
		*b++=128+U/4096%64;
		*b++=128+U/64%64;
		*b++=128+U%64;
	}
	else 
		fprintf(stderr, "Invalid Unicode Code Point 0x%X\n", U);
	return r;
}

int NumByte(char *p) /* return the number of bytes of the multibyte char pointed to by p */
{
	int n=1;
	if (*p & 0x80) /* multibyte char */
	{
		if ((*p & 0xF0) == 0xF0)/* 4-bytes */
			n=4;
		else if ((*p & 0xE0) == 0xE0)/* 3-bytes */
			n=3;
		else if ((*p & 0xC0) == 0xC0)/* 2-bytes */
			n=2;
	}
	return n;
}

int Unicode(char *p, int *N)/* convert the UTF-8 char pointed to by p to unicode, if N is provided it will be set to the number of bytes of the character*/
{
	int u=0;
	int n;
	n=NumByte(p);
	if (N)
		*N=n;
	switch(n)
	{
			case 4:
				u=(int)(0x07&*p);
				n--;
				break;
			case 3:
				u=(int)(0x0F&*p);
				n--;
				break;
			case 2:
				u=(int)(0x1F&*p);
				n--;
				break;
			case 1:
				u=(int)(*p);
				n--;
				break;
			default:
				break;
	}
	while (n)
	{
		/* each subsequent byte contains 6 relevant bits */
		p++;
		if ((*p&0xC0)!=0x80)
			return -1;
		u=(u<<6);
		u|=((int)(0x3F&*p));
		n--;
	}
	return u;
}

int IsCombiningMark(int ch) /* check whether the unicode code point ch is a combining mark */
{
	int i=0;
	while (Combining[i].start>=0)
	{
		if ((ch>=Combining[i].start)&&(ch<=Combining[i].end))
			return 1;
		i++;
	}
	return 0;
}

int WCSPACES=2;
int FCSPACES=2;
int IsWideChar(int ch) /* check whether the unicode code point ch is a wide character */
{
	int i=0;
	while (Wide[i].start>=0)
	{
		if ((ch>=Wide[i].start)&&(ch<=Wide[i].end))
			return 1;
		i++;
	}
	return 0;
}
int IsFullChar(int ch) /* check whether the unicode code point ch is a full width character */
{
	int i=0;
	while (Full[i].start>=0)
	{
		if ((ch>=Full[i].start)&&(ch<=Full[i].end))
			return 1;
		i++;
	}
	return 0;
}


int strspaces(char *p) /* count the number of character spaces in the string where each multibyte character counts as one and combining marks as 0 */ 
{
	int l=0;
	int n;
	int u;
	while(*p)
	{
		u=Unicode(p, &n);
		if (u<0)
		{
			fprintf(stderr, "Error, string is not proper UTF-8 code\n");
			return 0;
		}
		if (!IsCombiningMark(u))
			l++;
		if (IsWideChar(u))
			l+=WCSPACES-1;
		if (IsFullChar(u)) /* we make wide characters two characters wide */
			l+=FCSPACES-1;
		p+=n;
	}
	return l;
}

typedef struct {
	int point;
	int mapped;
} UniMap;
int Nmap=24;
const UniMap Mappings[] = { 
	/* some unicode codeblocks have gaps in em wile some symbols are defined in another block. 
	 * This table maps the gaps to the correct codepoint. */
	{0x1D455, 0x210E}, /* Mathematical italic h */
	{0x1D49D, 0x212C}, /* Mathematical Script B */
	{0x1D4A0, 0x2130}, /* Mathematical Script E */
	{0x1D4A1, 0x2131}, /* Mathematical Script F */
	{0x1D4A3, 0x210B}, /* Mathematical Script H */
	{0x1D4A4, 0x2110}, /* Mathematical Script I */
	{0x1D4A7, 0x2112}, /* Mathematical Script L */
	{0x1D4A8, 0x2113}, /* Mathematical Script M */
	{0x1D4AD, 0x211B}, /* Mathematical Script R */	 
	{0x1D4BA, 0x212F}, /* Mathematical Script e */	  
	{0x1D4BC, 0x210A}, /* Mathematical Script g */	  
	{0x1D4C4, 0x2134}, /* Mathematical Script o */	 
	{0x1D506, 0x212D}, /* Mathematical Fraktur B */
	{0x1D50B, 0x210C}, /* Mathematical Fraktur H*/
	{0x1D50C, 0x2111}, /* Mathematical Fraktur I*/
	{0x1D515, 0x211C}, /* Mathematical Fraktur R*/
	{0x1D51D, 0x2128}, /* Mathematical Fraktur Z*/	
	{0x1D53A, 0x2102}, /* Mathematical double stroke capital C */
	{0x1D53F, 0x210D}, /* Mathematical double stroke capital H */
	{0x1D545, 0x2115}, /* Mathematical double stroke capital N */
	{0x1D547, 0x2119}, /* Mathematical double stroke capital P */
	{0x1D548, 0x211A}, /* Mathematical double stroke capital Q */
	{0x1D549, 0x211D}, /* Mathematical double stroke capital R */
	{0x1D551, 0x2124}, /* Mathematical double stroke capital Z */
};

int MapU(int in)
{
	int i, min=0, max=Nmap-1;
	do
	{
		i=(min+max)/2;
		if (Mappings[i].point==in)
			return Mappings[i].mapped;
		else if (Mappings[i].point<in)
			min=i;
		else
			max=i;
	} while (max-min>1);
	if (Mappings[min].point==in)
		return Mappings[min].mapped;
	if (Mappings[max].point==in)
		return Mappings[max].mapped;
	return in;
}

char * UnicodeMapper(char *in)
{
	char *out;
	char *p, *u;
	int na=2*strlen(in), len, pos=0;
	int Nin, Nout, U, Um;
	out=malloc(na*sizeof(char));
	p=in;
	len=strlen(in);
	while (*p)
	{
		U=Unicode(p, &Nin);
		p+=Nin;
		
		Um=MapU(U);
		if (U!=Um)
		{
			u=Unicode2Utf8(Um);
			Unicode(u, &Nout);
			len+=(Nout-Nin);
			Nin=Nout;
			if (len>na)
			{
				na=len+10;
				out=realloc(out,na*sizeof(char));
			}
		}
		else
			u=Unicode2Utf8(Um);
		strcpy(out+pos,u);
		pos+=Nin;
		free(u);
	}		
	return out;	
}
