#define PRINTABLE(C) iswprint((C))
extern int WCSPACES;
extern int FCSPACES;

int strspaces(char *str);
char * Unicode2Utf8(int U);
int NumByte(char *p); /* return the number of bytes of the multibyte char pointed to by p */
int IsInSet(char c, const char *set);
int Unicode(char *p, int *N);
int IsCombiningMark(int ch);
char * UnicodeMapper(char *in);
