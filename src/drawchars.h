/* Here all "drawing" characters are stored */

/* plain brackets */
int LBRACKCHAR_UTF[4]       = {0x28   ,0x0239D,0x0239C,0x0239B}; // single, lower, extender, upper
int RBRACKCHAR_UTF[4]       = {0x29   ,0x023A0,0x0239F,0x0239E}; 
int LSQUARECHAR_UTF[4]      = {0x5B   ,0x023A3,0x023A2,0x023A1};
int RSQUARECHAR_UTF[4]      = {0x5D   ,0x023A6,0x023A5,0x023A4};
int VBARCHAR_UTF[4]         = {0x023A2,0x023A2,0x023A2,0x023A2};
int DVBARCHAR_UTF[4]        = {0x02016,0x02551,0x02551,0x02551};
/* floor/ceil and up/down arrows */
int LFLOORCHAR_UTF[4]       = {0x0230A,0x023A3,0x023A2,0x023A2}; // single, lower, extender, upper
int RFLOORCHAR_UTF[4]       = {0x0230B,0x023A6,0x023A5,0x023A5};
int LCEILCHAR_UTF[4]        = {0x02308,0x023A2,0x023A2,0x023A1};
int RCEILCHAR_UTF[4]        = {0x02309,0x023A5,0x023A5,0x023A4};
int UPARROWCHAR_UTF[4]      = {0x02191,0x023A2,0x023A2,0x025B2}; // single, lower, extender, extender
int DUPARROWCHAR_UTF[4]     = {0x021D1,0x02551,0x02551,0x025B2};
int DOWNARROWCHAR_UTF[4]    = {0x02193,0x025BC,0x023A2,0x023A2}; // single, extender, extender, upper
int DDOWNARROWCHAR_UTF[4]   = {0x021D3,0x025BC,0x02551,0x02551};
int UPDOWNARROWCHAR_UTF[4]  = {0x02195,0x025BC,0x023A2,0x025B2}; // single, lower, extender, upper
int DUPDOWNARROWCHAR_UTF[4] = {0x021D5,0x025BC,0x02551,0x025B2};
/* symmetrical brackets (for use with SymBrac)*/
int LCURLYCHAR_UTF[5]       = {0x7B   ,0x023A9,0x023A8,0x023AA,0x023A7}; // single, lower, center, extender, upper
int RCURLYCHAR_UTF[5]       = {0x7D   ,0x023AD,0x023AC,0x023AE,0x023AB}; // single, lower, center, extender, upper
/* angle brackets (for use with AngleBrac) */
int ANGLECHAR_UTF[2]        = {0x02572,0x02571}; // downward, upward
int FSLASH_UTF=0x02571;    // forward slash
int BSLASH_UTF=0x02572;	   // backward slash


/* fraction, overline, underline */ 
int FRACLINE_UTF=0x02500;
int OVERLINE_UTF=0x02581;
int UNDERLINE_UTF=0x02500;

/* array characters 
 *                     0      1      2      3      4      5      6      7      8      9      10
 *                     │      ─      ┌      ┬      ┐      ├      ┼      ┤      └      ┴      ┘       */
int ARRAYCHAR_UTF[11]={0x2502,0x2500,0x250C,0x252C,0x2510,0x251C,0x253C,0x2524,0x2514,0x2534,0x2518};
int ARRAYCHAR_ASC[11]={'|',   '-',   '+',   '+',   '+',   '+',   '+',   '+',   '+',    '+',  '+'}; // ASCII version


/* integrals and sqrt */
int SQRTCHAR_UTF[5]={0x02572,0x02502,0x0250C,0x02500,0x02510}; // downward diagonal, vertical, left top corner, horizontal, right top corner
int INTCHAR_UTF[3]={0x02321,0x023AE,0x02320}; // bottom, extender, top
int IINTCHAR_UTF[4]={0x0222B,0x0222C,0x0222D,0x022EF}; // single, double, tripple, dots
int OINTCHAR_UTF[2]={0x02E26,0x02E27}; // quasi-circle
int OIINTCHAR_UTF[4]={0x0222E,0x0222F,0x02230,0x022EF}; // single, double, tripple, dots

/* row mayor*/
/* two sum symbols
 * SUMCHAR2_UTF uses two unicode symbols for the lower and upper halfs. Many fonts make those ugly though
 * SUMCHAR_UTF is based on box drawing characters and probably worke better in general
 */
int SUMCHAR2_UTF[4]={1,2,0x023B3,0x023B2}; // width, height, start lower left, end upper right
int SUMCHAR_UTF[10]={2,4,0x023BA,0x023BA,0x02571,0x00020,0x02572,0x00020,0x023AF,0x023AF}; // width, height, start lower left, end upper right
int PRODCHAR_UTF[8]={3,2,0x02502,0x00020,0x02502,0x0252C,0x02500,0x0252C}; // width, height, start lower left, end upper right

