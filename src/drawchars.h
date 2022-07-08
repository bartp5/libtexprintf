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

int FSLASH_UTF=0x02571;
int BSLASH_UTF=0x02572;
