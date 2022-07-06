#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>
#include "boxes.h"
#include "drawbox.h"
#include "parser.h"
#include "lexer.h"
#include "stringutils.h"
#include "testfonts.h"
char *styles[]={
	"mathsfbfit",
	"mathsfbf",
	"mathfrak",
	"mathbfit",
	"mathsfit",
	"mathcal",
	"mathscr",
	"mathbf",
	"mathbb",
	"mathsf",
	"mathtt",
	"mathnormal",
	"text",
	NULL
};

typedef struct Test_String{
	char *str, *descr;
} Test_String;

Test_String font_tests[]={
	{"abcdefghijklmnopqrstuvwxyz", 		"latin     "},
	{"ABCDEFGHIJKLMNOPQRSTUVWXYZ", 		"latin     "},
	{"1234567890", 						"numbers   "},
	{"𝙖𝙗𝙘𝙙𝙚𝙛𝙜𝙝𝙞𝙟𝙠𝙡𝙢𝙣𝙤𝙥𝙦𝙧𝙨𝙩𝙪𝙫𝙬𝙭𝙮𝙯",		"mathsfbfit"},
	{"𝘼𝘽𝘾𝘿𝙀𝙁𝙂𝙃𝙄𝙅𝙆𝙇𝙈𝙉𝙊𝙋𝙌𝙍𝙎𝙏𝙐𝙑𝙒𝙓𝙔𝙕",		"mathsfbfit"},
	{"1234567890",						"mathsfbfit"},
	{"𝗮𝗯𝗰𝗱𝗲𝗳𝗴𝗵𝗶𝗷𝗸𝗹𝗺𝗻𝗼𝗽𝗾𝗿𝘀𝘁𝘂𝘃𝘄𝘅𝘆𝘇",		"mathsfbf  "},
	{"𝗔𝗕𝗖𝗗𝗘𝗙𝗚𝗛𝗜𝗝𝗞𝗟𝗠𝗡𝗢𝗣𝗤𝗥𝗦𝗧𝗨𝗩𝗪𝗫𝗬𝗭",		"mathsfbf  "},
	{"𝟭𝟮𝟯𝟰𝟱𝟲𝟳𝟴𝟵𝟬",						"mathsfbf  "},
	{"𝔞𝔟𝔠𝔡𝔢𝔣𝔤𝔥𝔦𝔧𝔨𝔩𝔪𝔫𝔬𝔭𝔮𝔯𝔰𝔱𝔲𝔳𝔴𝔵𝔶𝔷",		"mathfrak  "},
	{"𝔄𝔅ℭ𝔇𝔈𝔉𝔊ℌℑ𝔍𝔎𝔏𝔐𝔑𝔒𝔓𝔔ℜ𝔖𝔗𝔘𝔙𝔚𝔛𝔜ℨ",		"mathfrak  "},
	{"1234567890",						"mathfrak  "},
	{"𝒂𝒃𝒄𝒅𝒆𝒇𝒈𝒉𝒊𝒋𝒌𝒍𝒎𝒏𝒐𝒑𝒒𝒓𝒔𝒕𝒖𝒗𝒘𝒙𝒚𝒛",		"mathbfit  "},
	{"𝑨𝑩𝑪𝑫𝑬𝑭𝑮𝑯𝑰𝑱𝑲𝑳𝑴𝑵𝑶𝑷𝑸𝑹𝑺𝑻𝑼𝑽𝑾𝑿𝒀𝒁",		"mathbfit  "},
	{"1234567890",						"mathbfit  "},
	{"𝘢𝘣𝘤𝘥𝘦𝘧𝘨𝘩𝘪𝘫𝘬𝘭𝘮𝘯𝘰𝘱𝘲𝘳𝘴𝘵𝘶𝘷𝘸𝘹𝘺𝘻",		"mathsfit  "},
	{"𝘈𝘉𝘊𝘋𝘌𝘍𝘎𝘏𝘐𝘑𝘒𝘓𝘔𝘕𝘖𝘗𝘘𝘙𝘚𝘛𝘜𝘝𝘞𝘟𝘠𝘡",		"mathsfit  "},
	{"1234567890",						"mathsfit  "},
	{"𝒶𝒷𝒸𝒹ℯ𝒻ℊ𝒽𝒾𝒿𝓀𝓁𝓂𝓃ℴ𝓅𝓆𝓇𝓈𝓉𝓊𝓋𝓌𝓍𝓎𝓏",		"mathcal   "},
	{"𝒜ℬ𝒞𝒟ℰℱ𝒢ℋℐ𝒥𝒦ℒℓ𝒩𝒪𝒫𝒬ℛ𝒮𝒯𝒰𝒱𝒲𝒳𝒴𝒵",		"mathcal   "},
	{"1234567890",						"mathcal   "},
	{"𝓪𝓫𝓬𝓭𝓮𝓯𝓰𝓱𝓲𝓳𝓴𝓵𝓶𝓷𝓸𝓹𝓺𝓻𝓼𝓽𝓾𝓿𝔀𝔁𝔂𝔃",		"mathscr   "},
	{"𝓐𝓑𝓒𝓓𝓔𝓕𝓖𝓗𝓘𝓙𝓚𝓛𝓜𝓝𝓞𝓟𝓠𝓡𝓢𝓣𝓤𝓥𝓦𝓧𝓨𝓩",		"mathscr   "},
	{"1234567890",						"mathscr   "},
	{"𝐚𝐛𝐜𝐝𝐞𝐟𝐠𝐡𝐢𝐣𝐤𝐥𝐦𝐧𝐨𝐩𝐪𝐫𝐬𝐭𝐮𝐯𝐰𝐱𝐲𝐳",		"mathbf    "},
	{"𝐀𝐁𝐂𝐃𝐄𝐅𝐆𝐇𝐈𝐉𝐊𝐋𝐌𝐍𝐎𝐏𝐐𝐑𝐒𝐓𝐔𝐕𝐖𝐗𝐘𝐙",		"mathbf    "},
	{"𝟏𝟐𝟑𝟒𝟓𝟔𝟕𝟖𝟗𝟎",						"mathbf    "},
	{"𝕒𝕓𝕔𝕕𝕖𝕗𝕘𝕙𝕚𝕛𝕜𝕝𝕞𝕟𝕠𝕡𝕢𝕣𝕤𝕥𝕦𝕧𝕨𝕩𝕪𝕫",		"mathbb    "},
	{"𝔸𝔹ℂ𝔻𝔼𝔽𝔾ℍ𝕀𝕁𝕂𝕃𝕄ℕ𝕆ℙℚℝ𝕊𝕋𝕌𝕍𝕎𝕏𝕐ℤ",		"mathbb    "},
	{"𝟙𝟚𝟛𝟜𝟝𝟞𝟟𝟠𝟡𝟘",						"mathbb    "},
	{"𝖺𝖻𝖼𝖽𝖾𝖿𝗀𝗁𝗂𝗃𝗄𝗅𝗆𝗇𝗈𝗉𝗊𝗋𝗌𝗍𝗎𝗏𝗐𝗑𝗒𝗓",		"mathsf    "},
	{"𝖠𝖡𝖢𝖣𝖤𝖥𝖦𝖧𝖨𝖩𝖪𝖫𝖬𝖭𝖮𝖯𝖰𝖱𝖲𝖳𝖴𝖵𝖶𝖷𝖸𝖹",		"mathsf    "},
	{"𝟣𝟤𝟥𝟦𝟧𝟨𝟩𝟪𝟫𝟢",						"mathsf    "},
	{"𝚊𝚋𝚌𝚍𝚎𝚏𝚐𝚑𝚒𝚓𝚔𝚕𝚖𝚗𝚘𝚙𝚚𝚛𝚜𝚝𝚞𝚟𝚠𝚡𝚢𝚣",		"mathtt    "},
	{"𝙰𝙱𝙲𝙳𝙴𝙵𝙶𝙷𝙸𝙹𝙺𝙻𝙼𝙽𝙾𝙿𝚀𝚁𝚂𝚃𝚄𝚅𝚆𝚇𝚈𝚉",		"mathtt    "},
	{"𝟷𝟸𝟹𝟺𝟻𝟼𝟽𝟾𝟿𝟶",						"mathtt    "},
	{"𝑎𝑏𝑐𝑑𝑒𝑓𝑔ℎ𝑖𝑗𝑘𝑙𝑚𝑛𝑜𝑝𝑞𝑟𝑠𝑡𝑢𝑣𝑤𝑥𝑦𝑧",		"mathnormal"},
	{"𝐴𝐵𝐶𝐷𝐸𝐹𝐺𝐻𝐼𝐽𝐾𝐿𝑀𝑁𝑂𝑃𝑄𝑅𝑆𝑇𝑈𝑉𝑊𝑋𝑌𝑍",		"mathnormal"},
	{"1234567890",						"mathnormal"},
	{"αβγδεζηθικλμνξοπρςστυφχψωϊ", 		"greek     "},
	{"ϋόύώϏϐϑϒϓϔϕϖϗϘϙϚϛϜϝϞϟϠϡ   ", 		"greek     "},
	{"─━│┃┄┅┆┇┈┉┊┋┌┍┎┏┐┑┒┓└┕┖┗┘┙", 		"box draw  "},
	{"┚┛├┝┞┟┠┡┢┣┤┥┦┧┨┩┪┫┬┭┮┯┰┱┲┳", 		"box draw  "},
	{"┴┵┶┷┸┹┺┻┼┽┾┿╀╁╂╃╄╅╆╇╈╉╊╋╌╍", 		"box draw  "},
	{"╎╏═║╒╓╔╕╖╗╘╙╚╛╜╝╞╟╠╡╢╣╤╥╦╧", 		"box draw  "},
	{"╨╩╪╫╬╭╮╯╰╱╲╳╴╵╶╷╸╹╺╻╼╽╾╿  ", 		"box draw  "},
	{NULL,NULL}
};

#define MTESTSTRLEN 255
char *AlignChars(int j)
{
	char *str;
	char *max;
	char *p, *s;
	int k,n=0;
	str=malloc(MTESTSTRLEN*sizeof(char));
	s=str;
	*s='|';
	s++;
	max=str+MTESTSTRLEN;
	p=font_tests[j].str;
	while (*p)
	{
		/* copy one utf-8 character at a time */
		k=NumByte(p);
		while(k)
		{
			*s=*p;
			p++;
			s++;
			if (s>=max)
			{
				fprintf(stderr,"Error: in AlignChars not enough space in allocated string\n");
				exit(1);
			}
			k--;
		}
		n++;
		if (n%5)
		{
			*s=' ';
			s++;
		}
		else
		{
			strncpy(s,"\\text{|}", 9);
			s+=8;
		}
		if (s>=max)
		{
			fprintf(stderr,"Error: in AlignChars not enough space in allocated string\n");
			exit(1);
		}		
	}
	*s='\0';
	return str; 
}

void MakeBlockString(int start, int end)
{
	char *str;
	char *c;
	char *s;
	int i, k;
	if (end<start)
		return;
	
	str=malloc(((end-start+1)*4+1)*sizeof(char));
	s=str;
	for (i=start;i<=end;i++)
	{
		c=Unicode2Utf8(i);
		k=NumByte(c);
		strncpy(s,c,k);
		s+=k;
		free(c);
	}
	printf(str);
	free(str);
}

	
void TestFonts()
{
	box root;
	int i=0,j;
	char *col=  "0        10        20        30        40        50        60\n";
	char *scale="|---------+---------+---------+---------+---------+---------+\n";
	char *str;
	j=0;
	printf(col);
	printf(scale);
	while (font_tests[j].str)
	{
		printf(font_tests[j].descr);
		str=AlignChars(j++);
		root=ParseString(str, 0, styles[i]);
		free(str);
		BoxPos(&root);
		PrintBox(&root);
		FreeBox(&root);
	}
	printf(scale);
	printf(col);
	printf("\n");
	i++;
	
	// MakeBlockString(0x2500, 0x257F);
}


	
