/* macro definitions
 * This struct contains:
 * Macro definition modeled after NewDocumentCommand
 * Only rudementary functionality, not all of NewDocumentCommand is 
 * supported! (e.g no D, o, and s options)
 * name of the command:				 name without preceding '\'
 * args:							 argument specifications with O for 
 *                                   optional arguments, followed by the 
 *                                   default between curly brackets, e.g.
 *                                   "O{default}", and m for mandatory 
 *                                   arguments 
 * replacement: 					 string with replacement command. 
 * 									 Mandatory arguments are inserted 
 * 									 using $(n), optional with %(n). If 
 * 									 an optional argument is not present
 * 									 it is replaced with an empy string
 */

const macro_def default_macros[] = {
	{"boxed", 		"m",	"\\begin{array}{|c|} \\hline $(0) \\\\\\hline\\end{array}"},
	{"xrightarrow",	"O{}m",	"\\stackrel{\\underrightarrow{$(0)}}{%(0)}"},
	{"xleftarrow",	"O{}m",	"\\stackrel{\\underleftarrow{$(0)}}{%(0)}"},
	{"overset", 	"mm",	"\\stackrel{$(0)}{$(1)}"},
	{"underset", 	"mm",	"\\stackrel{$(1)}{$(0)}"},
	{NULL,NULL,NULL},
}; 
