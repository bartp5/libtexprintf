#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <getopt.h>
#include "texprintf.h"
#include "testfonts.h"
#include "config.h"
#ifdef __MINGW32__
#include <windows.h>
#endif

int main(int argc, char **argv)
{
	int i, c;
	int printsource=0;
	int boxtree=0;
	int done=0;
	char *font=NULL;
#ifdef __MINGW32__
	UINT oldcp = GetConsoleOutputCP();	
	SetConsoleOutputCP(CP_UTF8);
#endif
	while (1)
	{
		static struct option long_options[] =
		{
			{"line-width",  required_argument, 0, 'l'},
			{"symbol-list",       no_argument, 0, 's'},
			{"version",           no_argument, 0, 'v'},
			{"show-input",        no_argument, 0, 'i'},
			{"wchar-width", required_argument, 0, 'w'},
			{"fchar-width", required_argument, 0, 'f'},
			{"default-font",required_argument, 0, 'F'},
			{"box-tree",          no_argument, 0, 'B'},
			{"test-fonts",  required_argument, 0, 't'},
			{0, 0, 0, 0}
		};
		int option_index = 0;
		c = getopt_long (argc, argv, "l:sviw:f:F:Bt",long_options, &option_index);
		
		if (c == -1)
			break;
			
		switch (c)
		{
			case 'l':
				if (!optarg)
				{
					fprintf(stderr, "Error: --line-width requires an integer as argument\n");
					return 1;	
				}
				
				TEXPRINTF_LW=atoi(optarg);
				break;
			case 's':
				texlistsymbols();
				done++;
				break;
			case 't':
				TestFonts();
				done++;
				break;
			case 'v':
				printf("   __  ____________________    _  __\n");
				printf("  / / / /_  __/ ____/_  __/__ | |/ /\n");
				printf(" / / / / / / / /_    / / / _ \\|   / \n");
				printf("/ /_/ / / / / __/   / / /  __/   |  \n");
				printf("\\____/ /_/ /_/     /_/  \\___/_/|_|  \n");
				printf("This is utftex version %s\nPowered by %s\n", UTFTEXVERSION, PACKAGE_STRING);
				done++;
				break;
			case 'i':				
				printsource=1;
				break;
			case 'w':
				if (!optarg)
				{
					fprintf(stderr, "Error: --wchar-width requires the number of spaces for a wide character (1 or 2)\n");
					return 1;	
				}
				
				TEXPRINTF_WCW=atoi(optarg);
				break;
			case 'f':
				if (!optarg)
				{
					fprintf(stderr, "Error: --fchar-width requires the number of spaces for a full width character (1 or 2)\n");
					return 1;	
				}
				
				TEXPRINTF_FCW=atoi(optarg);
				break;
			case 'F':
				if (!optarg)
				{
					fprintf(stderr, "Error: --default-font requires the default font style name\n");
					return 1;	
				}
				font=malloc((strlen(optarg)+1)*sizeof(char));
				strcpy(font, optarg);
				TEXPRINTF_FONT=font;
				break;
			case 'B':
				boxtree=1;
				break;
			case '?':
			default:
				exit(1);
		}
	}

	if (optind < argc)
	{
      while (optind < argc)
      {
			if (printsource)
				printf("%s\n",argv[optind]);			
			texprintf("%s\n",argv[optind]);
			texerrors();
			if (boxtree)
				texboxtree("%s\n",argv[optind]);
			done++;
			optind++;
		}
	}
	
	if (!done)
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
		if (printsource)
			printf("%s\n",argv[optind]);			
		texprintf("%s\n",argv[optind]);
		texerrors();
		if (boxtree)
			texboxtree("%s\n",argv[optind]);
	}
	
#ifdef __MINGW32__
	SetConsoleOutputCP(oldcp);
#endif
}
