/* macro definitions
 * This struct contains:
 * name of the command:				 name without preceding '\'
 * number of mandatory arguments: 	 
 * number of optional arguments: 	 	 
 * replacement: 					 string with replacement command. 
 * 									 Mandatory arguments are inserted 
 * 									 using $(n), optional with %(n). If 
 * 									 an optional argument is not present
 * 									 it is replaced with an empy string
 */

const macro_def macros[] = {
	{"boxed", 		1,0,	"\\begin{array}{|c|} \\hline $(0) \\\\\\hline\\end{array}"},
	{"xrightarrow",	1,1,	"\\stackrel{\\underrightarrow{$(0)}}{%(0)}"},
	{"overset", 	2,0,	"\\stackrel{$(0)}{$(1)}"},
	{"underset", 	2,0,	"\\stackrel{$(1)}{$(0)}"},
	{NULL,0,0,NULL},
}; 
