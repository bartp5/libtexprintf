#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "stringutils.h"
#include "lexer.h"
#include "parsedef.h"
#ifdef __MINGW32__
#include <windows.h>
#endif
/* lookup the unicode symbol in the latex symbol list to sort out the latex command */
Symbol LookupSymbol(unsigned int U, int N)
{
	int j=0, n=-1;
	while (Symbols[j].name)
	{
		if (Symbols[j].unicode==U)
		{
			n++;
			if (n==N)
				return Symbols[j];
		}
		j++;
	}
	return Symbols[j];
}

int main(int argc, char **argv)
{
	int i, j, k, l,N;
	char *p, c;
	Symbol S;
#ifdef __MINGW32__
	UINT oldcp = GetConsoleOutputCP();	
	SetConsoleOutputCP(CP_UTF8);
#endif
	p=Unicode2Utf8(0x25CC); /*dotted circle for combining marks */
	if (argc==1)
	{
		char *buffer;
		int Na=50;
		char ch;
		buffer=malloc(Na*sizeof(char));
		i=0;
		while(read(STDIN_FILENO, &ch, 1) > 0)
		{
			buffer[i++]=ch;
			if (i==Na)
			{
				Na+=50;
				buffer=realloc(buffer, Na*sizeof(char));
			}
		}
		buffer[i]='\0';
		printf("Input String:\n%s\n", buffer);
		j=strlen(buffer);
		printf("length in chars: %d\n", j);
		
		k=strlen(buffer);
		j=0;
		printf("Char\tUnicode\tUTF-8                    texprintf\n");
		while(j<k)
		{
			int U, n;
			U=Unicode(buffer+j, &n);
			c=buffer[j+n];
			buffer[j+n]='\0';
			if (IsCombiningMark(U))
				printf("%s%s\t0x%05X\t", p, buffer+j, U);
			else
			{
				switch(buffer[j])
				{
					// first the non printable ASCII stuff */
					case 0x01:
						printf("SOH\t0x%05X\t", U);
						break;
					case 0x02:
						printf("STX\t0x%05X\t", U);
						break;
					case 0x03:
						printf("ETX\t0x%05X\t", U);
						break;
					case 0x04:
						printf("EOT\t0x%05X\t", U);
						break;
					case 0x05:
						printf("ENQ\t0x%05X\t", U);
						break;
					case 0x06:
						printf("ACK\t0x%05X\t", U);
						break;
					case '\a':
						printf("\\a\t0x%05X\t", U);
						break;
					case '\b':
						printf("\\b\t0x%05X\t", U);
						break;
					case '\t':
						printf("\\t\t0x%05X\t", U);
						break;
					case '\n':
						printf("\\n\t0x%05X\t", U);
						break;
					case '\v':
						printf("\\t\t0x%05X\t", U);
						break;
					case '\f':
						printf("\\f\t0x%05X\t", U);
						break;
					case '\r':
						printf("\\r\t0x%05X\t", U);
						break;
					case 0x0E:
						printf("SO\t0x%05X\t", U);
						break;
					case 0x0F:
						printf("SI\t0x%05X\t", U);
						break;
					case 0x10:
						printf("DLE\t0x%05X\t", U);
						break;
					case 0x11:
						printf("DC1\t0x%05X\t", U);
						break;
					case 0x12:
						printf("DC2\t0x%05X\t", U);
						break;
					case 0x13:
						printf("DC3\t0x%05X\t", U);
						break;
					case 0x14:
						printf("DC4\t0x%05X\t", U);
						break;
					case 0x15:
						printf("NAK\t0x%05X\t", U);
						break;
					case 0x16:
						printf("SYN\t0x%05X\t", U);
						break;
					case 0x17:
						printf("ETB\t0x%05X\t", U);
						break;
					case 0x18:
						printf("CAN\t0x%05X\t", U);
						break;
					case 0x19:
						printf("EM\t0x%05X\t", U);
						break;
					case 0x1A:
						printf("SUB\t0x%05X\t", U);
						break;
					case '\e':
						printf("\\e\t0x%05X\t", U);
						break;
					case 0x1C:
						printf("FS\t0x%05X\t", U);
						break;
					case 0x1D:
						printf("GS\t0x%05X\t", U);
						break;
					case 0x1E:
						printf("RS\t0x%05X\t", U);
						break;
					case 0x1F:
						printf("US\t0x%05X\t", U);
						break;
					case 0x7F:
						printf("DEL\t0x%05X\t", U);
						break;
					default:
						printf("%s\t0x%05X\t", buffer+j, U);
					break;
				}
			}
			putchar('{');
			printf("0x%02X", buffer[j]&0x000000FF);
			for (l=1;l<n;l++)
				printf(", 0x%02X", buffer[j+l]&0x000000FF);
			putchar('}');
			for (;l<4;l++) // fill up space to align table
				printf("      ");
			N=0;
			S=LookupSymbol(U,N);
			N++;
			if (S.name)
			{
				printf(" %s", S.name);
				while (S.name)
				{
					S=LookupSymbol(U,N);
					N++;
					if (S.name)
						printf(", %s", S.name);
				}					
			}
			putchar('\n');		
			
			buffer[j+n]=c;
			j+=n;
		}
		printf("--------------------------------------------------------------------------------\n");
		free(buffer);		
	}
	else
	{
		for (i=1;i<argc;i++)
		{
			printf("Input String:\n%s\n", argv[i]);
			j=strlen(argv[i]);
			printf("length in chars: %d\n", j);
			
			k=strlen(argv[i]);
			j=0;
			while(j<k)
			{
				int U, n;
				U=Unicode(argv[i]+j, &n);
				c=argv[i][j+n];
				argv[i][j+n]='\0';
				if (IsCombiningMark(U))
					printf("%s%s\tUnicode:0x%05X\t\tUTF-8:", p, argv[i]+j, U);
				else
					printf("%s\tUnicode:0x%05X\t\tUTF-8:", argv[i]+j, U);
				putchar('{');
				printf("0x%02X", argv[i][j]&0x000000FF);
				for (l=1;l<n;l++)
					printf(", 0x%02X", argv[i][j+l]&0x000000FF);
				putchar('}');
				N=0;
				S=LookupSymbol(U,N);
				N++;
				if (S.name)
				{
					printf("\tutftex: %s", S.name);
					while (S.name)
					{
						S=LookupSymbol(U,N);
						N++;
						if (S.name)
							printf(", %s", S.name);
					}					
				}
				putchar('\n');		
				
				argv[i][j+n]=c;
				j+=n;
			}
			printf("--------------------------------------------------------------------------------\n");
		}
	}
	free(p);
#ifdef __MINGW32__
	SetConsoleOutputCP(oldcp);
#endif
}
