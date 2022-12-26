#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
# define U(x) x
# define NLSTATE yyprevious=YYNEWLINE
# define BEGIN yybgin = yysvec + 1 +
# define INITIAL 0
# define YYLERR yysvec
# define YYSTATE (yyestate-yysvec-1)
# define YYOPTIM 1
# ifndef YYLMAX 
# define YYLMAX BUFSIZ
# endif 
#ifndef __cplusplus
# define output(c) (void)putc(c,yyout)
#else
# define lex_output(c) (void)putc(c,yyout)
#endif

#if defined(__cplusplus) || defined(__STDC__)

#if defined(__cplusplus) && defined(__EXTERN_C__)
extern "C" {
#endif
	int yyback(int *, int);
	int yyinput(void);
	int yylook(void);
	void yyoutput(int);
	int yyracc(int);
	int yyreject(void);
	void yyunput(int);
	int yylex(void);
#ifdef YYLEX_E
	void yywoutput(wchar_t);
	wchar_t yywinput(void);
#endif
#ifndef yyless
	int yyless(int);
#endif
#ifndef yywrap
	int yywrap(void);
#endif
#ifdef LEXDEBUG
	void allprint(char);
	void sprint(char *);
#endif
#if defined(__cplusplus) && defined(__EXTERN_C__)
}
#endif

#ifdef __cplusplus
extern "C" {
#endif
	void exit(int);
#ifdef __cplusplus
}
#endif

#endif
# define unput(c) {yytchar= (c);if(yytchar=='\n')yylineno--;*yysptr++=yytchar;}
# define yymore() (yymorfg=1)
#ifndef __cplusplus
# define input() (((yytchar=yysptr>yysbuf?U(*--yysptr):getc(yyin))==10?(yylineno++,yytchar):yytchar)==EOF?0:yytchar)
#else
# define lex_input() (((yytchar=yysptr>yysbuf?U(*--yysptr):getc(yyin))==10?(yylineno++,yytchar):yytchar)==EOF?0:yytchar)
#endif
#define ECHO fprintf(yyout, "%s",yytext)
# define REJECT { nstr = yyreject(); goto yyfussy;}
int yyleng;
#define YYISARRAY
char yytext[YYLMAX];
int yymorfg;
extern char *yysptr, yysbuf[];
int yytchar;
// FILE *yyin = {stdin}, *yyout = {stdout};
FILE *yyin = NULL, *yyout = NULL;
extern int yylineno;
struct yysvf { 
	struct yywork *yystoff;
	struct yysvf *yyother;
	int *yystops;};
struct yysvf *yyestate;
extern struct yysvf yysvec[], *yybgin;

# line 2 "lex.l"
/* lex.l								   */

# line 3 "lex.l"
/* Copyright (C) 1989, 1991, Craig E. Kolb				   */

# line 4 "lex.l"
/* All rights reserved.							   */

# line 5 "lex.l"
/*									   */

# line 6 "lex.l"
/* This software may be freely copied, modified, and redistributed,	   */

# line 7 "lex.l"
/* provided that this copyright notice is preserved on all copies.	   */

# line 8 "lex.l"
/*									   */

# line 9 "lex.l"
/* You may not distribute this software, in whole or in part, as part of   */

# line 10 "lex.l"
/* any commercial product without the express consent of the authors.	   */

# line 11 "lex.l"
/* 									   */

# line 12 "lex.l"
/* There is no warranty or other guarantee of fitness of this software	   */

# line 13 "lex.l"
/* for any purpose.  It is provided solely "as is".			   */

# line 14 "lex.l"
/*									   */

# line 15 "lex.l"
/* $Id: lex.l,v 4.0.1.3 92/01/14 18:28:38 cek Exp Locker: cek $ */
#include "config.h"
#include "rayshade.h"
#ifdef I_STRING
#include <string.h>
#else
#include <strings.h>
#endif
#include "light.h"
#include "atmosphere.h"
#include "surface.h"
#include "texture.h"
#include "geom.h"
#include "symtab.h"
#include "y.tab.h"
extern char *strsave();
# define YYNEWLINE 10
yylex(){
int nstr; extern int yyprevious;
#ifdef __cplusplus
/* to avoid CC and lint complaining yyfussy not being used ...*/
static int __lex_hack = 0;
if (__lex_hack) goto yyfussy;
#endif
while((nstr = yylook()) >= 0)
yyfussy: switch(nstr){
case 0:
if(yywrap()) return(0); break;
case 1:

# line 42 "lex.l"
		;
break;
case 2:

# line 43 "lex.l"
		handlehash();
break;
case 3:

# line 44 "lex.l"
		skipcomments();
break;
case 4:

# line 45 "lex.l"
		return tAMBIENT;
break;
case 5:

# line 46 "lex.l"
	return tAPERTURE;
break;
case 6:

# line 47 "lex.l"
	return tAPPLYSURF;
break;
case 7:

# line 48 "lex.l"
		return tAREA;
break;
case 8:

# line 49 "lex.l"
	return tATMOSPHERE;
break;
case 9:

# line 50 "lex.l"
	return tBACKGROUND;
break;
case 10:

# line 51 "lex.l"
		return tBLOB;
break;
case 11:

# line 52 "lex.l"
		return tBLOTCH;
break;
case 12:

# line 53 "lex.l"
		return tBODY;
break;
case 13:

# line 54 "lex.l"
		return tBOX;
break;
case 14:

# line 55 "lex.l"
		return tBUMP;
break;
case 15:

# line 56 "lex.l"
		return tCHECKER;
break;
case 16:

# line 57 "lex.l"
		return tCLOUD;
break;
case 17:

# line 58 "lex.l"
		return tCONE;
break;
case 18:

# line 59 "lex.l"
	return tCOMPONENT;
break;
case 19:

# line 60 "lex.l"
	return tCONTRAST;
break;
case 20:

# line 61 "lex.l"
		return tCROP;
break;
case 21:

# line 62 "lex.l"
		return tCURSURF;
break;
case 22:

# line 63 "lex.l"
		return tCUTOFF;
break;
case 23:

# line 64 "lex.l"
	return tCYL;
break;
case 24:

# line 65 "lex.l"
	return tCYLINDRICAL;
break;
case 25:

# line 66 "lex.l"
		return tDEFINE;
break;
case 26:

# line 67 "lex.l"
		return tDIFFUSE;
break;
case 27:

# line 68 "lex.l"
	return tDIFFERENCE;
break;
case 28:

# line 69 "lex.l"
	return tDIRECTIONAL;
break;
case 29:

# line 70 "lex.l"
		return tDISC;
break;
case 30:

# line 71 "lex.l"
		return tEND;
break;
case 31:

# line 72 "lex.l"
	return tEXTENDED;
break;
case 32:

# line 73 "lex.l"
		return tEXTINCT;
break;
case 33:

# line 74 "lex.l"
		return tEYEP;
break;
case 34:

# line 75 "lex.l"
		return tEYESEP;
break;
case 35:

# line 76 "lex.l"
		return tFILTER;
break;
case 36:

# line 77 "lex.l"
		return tFBM;
break;
case 37:

# line 78 "lex.l"
		return tFBMBUMP;
break;
case 38:

# line 79 "lex.l"
	return tFOCALDIST;
break;
case 39:

# line 80 "lex.l"
		return tFOG;
break;
case 40:

# line 81 "lex.l"
		return tFOGDECK;
break;
case 41:

# line 82 "lex.l"
		return tFOV;
break;
case 42:

# line 83 "lex.l"
	return tFRAMELENGTH;
break;
case 43:

# line 84 "lex.l"
		return tFRAMES;
break;
case 44:

# line 85 "lex.l"
		return tGAUSS;
break;
case 45:

# line 86 "lex.l"
		return tGLOSS;
break;
case 46:

# line 87 "lex.l"
		return tGRID;
break;
case 47:

# line 88 "lex.l"
	return tHEIGHTFIELD;
break;
case 48:

# line 89 "lex.l"
		return tIMAGE;
break;
case 49:

# line 90 "lex.l"
		return tINDEX;
break;
case 50:

# line 91 "lex.l"
	return tINTERSECT;
break;
case 51:

# line 92 "lex.l"
		return tJITTER;
break;
case 52:

# line 93 "lex.l"
		return tLIGHT;
break;
case 53:

# line 94 "lex.l"
		return tLIST;
break;
case 54:

# line 95 "lex.l"
		return tLOOKP;
break;
case 55:

# line 96 "lex.l"
		return tMAP;
break;
case 56:

# line 97 "lex.l"
		return tMARBLE;
break;
case 57:

# line 98 "lex.l"
	return tMAXDEPTH;
break;
case 58:

# line 99 "lex.l"
		return tMOUNT;
break;
case 59:

# line 100 "lex.l"
		return tMIST;
break;
case 60:

# line 101 "lex.l"
		return tNAME;
break;
case 61:

# line 102 "lex.l"
	return tNOJITTER;
break;
case 62:

# line 103 "lex.l"
	return tNOSHADOW;
break;
case 63:

# line 104 "lex.l"
		return tOBJECT;
break;
case 64:

# line 105 "lex.l"
		return tOUTFILE;
break;
case 65:

# line 106 "lex.l"
		return tPLANE;
break;
case 66:

# line 107 "lex.l"
		return tPLANAR;
break;
case 67:

# line 108 "lex.l"
		return tPOINT;
break;
case 68:

# line 109 "lex.l"
		return tPOLY;
break;
case 69:

# line 110 "lex.l"
		return tPOLY;
break;
case 70:

# line 111 "lex.l"
		return tPRINT;
break;
case 71:

# line 112 "lex.l"
		return tQUIET;
break;
case 72:

# line 113 "lex.l"
		return tRANGE;
break;
case 73:

# line 114 "lex.l"
		return tREFLECT;
break;
case 74:

# line 115 "lex.l"
	return tREFLECT;
break;
case 75:

# line 116 "lex.l"
		return tREPORT;
break;
case 76:

# line 117 "lex.l"
	return tSCREEN;
break;
case 77:

# line 118 "lex.l"
		return tROTATE;
break;
case 78:

# line 119 "lex.l"
		return tSAMPLE;
break;
case 79:

# line 120 "lex.l"
		return tSCALE;
break;
case 80:

# line 121 "lex.l"
		return tSCREEN;
break;
case 81:

# line 122 "lex.l"
	return tSHADOWTRANSP;
break;
case 82:

# line 123 "lex.l"
		return tSHUTTER;
break;
case 83:

# line 124 "lex.l"
		return tSKY;
break;
case 84:

# line 125 "lex.l"
		return tSMOOTH;
break;
case 85:

# line 126 "lex.l"
		return tSPHERE;
break;
case 86:

# line 127 "lex.l"
	return tSPHERICAL;
break;
case 87:

# line 128 "lex.l"
	return tSPECULAR;
break;
case 88:

# line 129 "lex.l"
		return tSPECPOW;
break;
case 89:

# line 130 "lex.l"
		return tSPOT;
break;
case 90:

# line 131 "lex.l"
	return tSTARTTIME;
break;
case 91:

# line 132 "lex.l"
		return tSTRIPE;
break;
case 92:

# line 133 "lex.l"
		return tSURFACE;
break;
case 93:

# line 134 "lex.l"
	return tTEXTSURF;
break;
case 94:

# line 135 "lex.l"
		return tTEXTURE;
break;
case 95:

# line 136 "lex.l"
		return tTILE;
break;
case 96:

# line 137 "lex.l"
		return tTORUS;
break;
case 97:

# line 138 "lex.l"
	return tTRANSFORM;
break;
case 98:

# line 139 "lex.l"
	return tTRANSLATE;
break;
case 99:

# line 140 "lex.l"
		return tTRANSLU;
break;
case 100:

# line 141 "lex.l"
	return tTRANSLU;
break;
case 101:

# line 142 "lex.l"
		return tTRANSP;
break;
case 102:

# line 143 "lex.l"
	return tTRANSP;
break;
case 103:

# line 144 "lex.l"
	return tTRIANGLE;
break;
case 104:

# line 145 "lex.l"
	return tTRIANGLEUV;
break;
case 105:

# line 146 "lex.l"
		return tUNION;
break;
case 106:

# line 147 "lex.l"
		return tUP;
break;
case 107:

# line 148 "lex.l"
		return tUV;
break;
case 108:

# line 149 "lex.l"
		return tVERBOSE;
break;
case 109:

# line 150 "lex.l"
		return tWINDOW;
break;
case 110:

# line 151 "lex.l"
		return tWINDY;
break;
case 111:

# line 152 "lex.l"
		return tWOOD;
break;
case 112:

# line 153 "lex.l"
case 113:

# line 154 "lex.l"
case 114:

# line 155 "lex.l"
case 115:

# line 156 "lex.l"
	{yylval.d = atof(yytext); return tFLOAT;}
break;
case 116:

# line 157 "lex.l"
	{yylval.c = strsave(yytext); return tSTRING;}
break;
case 117:

# line 158 "lex.l"
	{yylval.c = strsave(yytext); return tFILENAME;}
break;
case 118:

# line 159 "lex.l"
		return yytext[0];
break;
case -1:
break;
default:
(void)fprintf(yyout,"bad switch yylook %d",nstr);
} return(0); }
/* end of yylex */

# line 162 "lex.l"
yywrap() {return 1;}
/*
 * Skip over comments.
 */
skipcomments()
{
	char c;

	while (1) {
		while (input() != '*')
			;
		if ((c = input()) == '/')
			return;
		unput(c);
	}
}
/*
 * Deal with ccp-produced lines of the form:
 * # n "filename"
 * and
 * # n
 * Where filename is the name of the file being processed, and n is
 * the current line number in that file.
 */
handlehash()
{
	char buf[BUFSIZ];
	int i;
	extern int yylineno;
	extern char yyfilename[];

	/*
	 * Read the entire line into buf.
	 */
	for (i = 0; (buf[i] = input()) != '\n'; i++)
			;
	unput(buf[i]);		/* To make sure consecutive # lines work. */
	buf[i] = (char)NULL;	/* Replace newline with NULL. */

	/*
	 * Complain if the line was not of the form #n "filename"
	 */
	if ((i = sscanf(buf,"%d \"%[^\"]s\"", &yylineno, yyfilename)) == 0 &&
	    (i = sscanf(buf," line %d \"%[^\"]s\"",&yylineno,yyfilename))==0) {
		RLerror(RL_PANIC, "Unknown '#' control (%s).\n",buf);
		exit(1);
	}
	if (i == 1 && (index(buf,'"') != (char *)NULL)) {
		/*
		 * Filename was given as ""
		 */
		(void)strcpy(yyfilename, "stdin");
	}
	yylineno--;  /* The newline we unput will increment yylineno */
}
int yyvstop[] = {
0,

118,
0, 

1,
118,
0, 

1,
0, 

118,
0, 

118,
0, 

112,
118,
0, 

116,
117,
118,
0, 

116,
117,
118,
0, 

116,
117,
118,
0, 

116,
117,
118,
0, 

116,
117,
118,
0, 

116,
117,
118,
0, 

116,
117,
118,
0, 

116,
117,
118,
0, 

116,
117,
118,
0, 

116,
117,
118,
0, 

116,
117,
118,
0, 

116,
117,
118,
0, 

116,
117,
118,
0, 

116,
117,
118,
0, 

116,
117,
118,
0, 

116,
117,
118,
0, 

116,
117,
118,
0, 

116,
117,
118,
0, 

116,
117,
118,
0, 

116,
117,
118,
0, 

116,
117,
118,
0, 

116,
117,
118,
0, 

116,
117,
118,
0, 

2,
118,
0, 

114,
0, 

3,
0, 

117,
0, 

113,
0, 

112,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

106,
116,
117,
0, 

107,
116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

113,
114,
0, 

115,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

13,
116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

30,
116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

36,
116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

39,
116,
117,
0, 

41,
116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

55,
116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

83,
116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

114,
0, 

113,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

7,
116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

10,
116,
117,
0, 

116,
117,
0, 

12,
116,
117,
0, 

14,
116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

17,
116,
117,
0, 

116,
117,
0, 

20,
116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

29,
116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

33,
116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

46,
116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

53,
116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

59,
116,
117,
0, 

116,
117,
0, 

60,
116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

68,
116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

89,
116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

95,
116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

111,
116,
117,
0, 

113,
114,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

16,
116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

44,
116,
117,
0, 

45,
116,
117,
0, 

116,
117,
0, 

48,
116,
117,
0, 

49,
116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

52,
116,
117,
0, 

54,
116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

58,
116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

65,
116,
117,
0, 

67,
116,
117,
0, 

116,
117,
0, 

70,
116,
117,
0, 

71,
116,
117,
0, 

72,
116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

79,
116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

96,
116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

105,
116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

110,
116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

11,
116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

22,
116,
117,
0, 

116,
117,
0, 

25,
116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

34,
116,
117,
0, 

116,
117,
0, 

35,
116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

43,
116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

51,
116,
117,
0, 

56,
116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

63,
116,
117,
0, 

116,
117,
0, 

66,
116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

75,
116,
117,
0, 

116,
117,
0, 

77,
116,
117,
0, 

78,
116,
117,
0, 

80,
116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

84,
116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

85,
116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

91,
116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

101,
116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

109,
116,
117,
0, 

4,
116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

15,
116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

21,
116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

26,
116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

32,
116,
117,
0, 

37,
116,
117,
0, 

116,
117,
0, 

40,
116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

64,
116,
117,
0, 

69,
116,
117,
0, 

73,
116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

82,
116,
117,
0, 

88,
116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

92,
116,
117,
0, 

116,
117,
0, 

94,
116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

99,
116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

108,
116,
117,
0, 

5,
116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

19,
116,
117,
0, 

23,
116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

31,
116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

57,
116,
117,
0, 

61,
116,
117,
0, 

62,
116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

87,
116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

93,
116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

103,
116,
117,
0, 

6,
116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

18,
116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

38,
116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

50,
116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

86,
116,
117,
0, 

90,
116,
117,
0, 

97,
116,
117,
0, 

98,
116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

8,
116,
117,
0, 

9,
116,
117,
0, 

116,
117,
0, 

27,
116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

74,
116,
117,
0, 

76,
116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

104,
116,
117,
0, 

24,
116,
117,
0, 

28,
116,
117,
0, 

42,
116,
117,
0, 

47,
116,
117,
0, 

116,
117,
0, 

116,
117,
0, 

102,
116,
117,
0, 

81,
116,
117,
0, 

100,
116,
117,
0, 
0};
# define YYTYPE int
struct yywork { YYTYPE verify, advance; } yycrank[] = {
0,0,	0,0,	1,3,	0,0,	
0,0,	0,0,	0,0,	0,0,	
0,0,	0,0,	1,4,	1,5,	
0,0,	0,0,	0,0,	0,0,	
0,0,	0,0,	0,0,	0,0,	
0,0,	0,0,	0,0,	0,0,	
0,0,	0,0,	0,0,	0,0,	
0,0,	0,0,	0,0,	0,0,	
0,0,	0,0,	0,0,	0,0,	
0,0,	0,0,	0,0,	0,0,	
0,0,	0,0,	0,0,	0,0,	
1,3,	0,0,	1,3,	1,6,	
1,7,	1,8,	0,0,	0,0,	
0,0,	0,0,	33,34,	37,33,	
37,34,	0,0,	0,0,	0,0,	
0,0,	2,32,	0,0,	0,0,	
0,0,	0,0,	1,9,	0,0,	
0,0,	0,0,	1,9,	0,0,	
0,0,	2,7,	6,33,	6,34,	
6,35,	6,35,	6,35,	6,35,	
6,35,	6,35,	6,35,	6,35,	
6,35,	6,35,	0,0,	0,0,	
0,0,	0,0,	0,0,	0,0,	
0,0,	0,0,	0,0,	0,0,	
1,3,	0,0,	1,10,	1,11,	
1,12,	1,13,	1,14,	1,15,	
1,16,	1,17,	1,18,	1,19,	
17,69,	1,20,	1,21,	1,22,	
1,23,	1,24,	1,25,	1,26,	
1,27,	1,28,	1,29,	1,30,	
1,31,	2,3,	19,72,	2,10,	
2,11,	2,12,	2,13,	2,14,	
2,15,	2,16,	2,17,	2,18,	
2,19,	25,85,	2,20,	2,21,	
2,22,	2,23,	2,24,	2,25,	
2,26,	2,27,	2,28,	2,29,	
2,30,	2,31,	7,36,	11,47,	
30,104,	10,43,	7,37,	7,34,	
10,44,	13,57,	10,45,	14,59,	
10,46,	13,58,	11,48,	18,70,	
18,71,	11,49,	20,73,	43,112,	
45,115,	14,60,	14,61,	11,50,	
20,74,	7,38,	7,38,	7,38,	
7,38,	7,38,	7,38,	7,38,	
7,38,	7,38,	7,38,	7,38,	
7,38,	7,38,	7,38,	7,38,	
7,38,	7,38,	7,38,	7,38,	
7,38,	7,38,	7,38,	7,38,	
7,38,	7,38,	7,38,	46,116,	
47,117,	48,118,	50,121,	51,122,	
52,123,	7,38,	7,38,	7,38,	
7,38,	7,38,	7,38,	7,38,	
7,38,	7,38,	7,38,	7,38,	
7,38,	7,38,	7,38,	7,38,	
7,38,	7,38,	7,38,	7,38,	
7,38,	7,38,	7,38,	7,38,	
7,38,	7,38,	7,38,	8,39,	
54,126,	8,40,	8,40,	8,40,	
8,40,	8,40,	8,40,	8,40,	
8,40,	8,40,	8,40,	12,51,	
56,129,	15,62,	16,66,	12,52,	
22,78,	31,105,	12,53,	21,75,	
15,63,	12,54,	8,41,	31,106,	
12,55,	16,67,	15,64,	21,76,	
12,56,	15,65,	22,79,	16,68,	
23,80,	21,77,	57,130,	9,42,	
9,42,	9,34,	9,42,	9,42,	
9,42,	9,42,	9,42,	9,42,	
9,42,	9,42,	9,42,	9,42,	
53,124,	53,125,	55,127,	23,81,	
55,128,	59,134,	8,41,	9,42,	
9,42,	9,42,	9,42,	9,42,	
9,42,	9,42,	9,42,	9,42,	
9,42,	9,42,	9,42,	9,42,	
9,42,	9,42,	9,42,	9,42,	
9,42,	9,42,	9,42,	9,42,	
9,42,	9,42,	9,42,	9,42,	
9,42,	60,135,	61,136,	62,137,	
63,138,	9,42,	65,142,	9,42,	
9,42,	9,42,	9,42,	9,42,	
9,42,	9,42,	9,42,	9,42,	
9,42,	9,42,	9,42,	9,42,	
9,42,	9,42,	9,42,	9,42,	
9,42,	9,42,	9,42,	9,42,	
9,42,	9,42,	9,42,	9,42,	
9,42,	24,82,	26,86,	27,89,	
24,83,	27,90,	26,87,	24,84,	
49,119,	66,143,	27,91,	67,144,	
29,101,	27,92,	29,102,	27,93,	
26,88,	28,97,	27,94,	34,37,	
29,103,	28,98,	27,95,	27,96,	
44,113,	68,145,	69,146,	28,99,	
49,120,	70,147,	28,100,	72,150,	
74,153,	76,157,	77,158,	44,114,	
78,159,	80,162,	34,38,	34,38,	
34,38,	34,38,	34,38,	34,38,	
34,38,	34,38,	34,38,	34,38,	
34,38,	34,38,	34,38,	34,38,	
34,38,	34,38,	34,38,	34,38,	
34,38,	34,38,	34,38,	34,38,	
34,38,	34,38,	34,38,	34,38,	
81,163,	82,164,	83,165,	84,167,	
85,168,	83,166,	34,38,	34,38,	
34,38,	34,38,	34,38,	34,38,	
34,38,	34,38,	34,38,	34,38,	
34,38,	34,38,	34,38,	34,38,	
34,38,	34,38,	34,38,	34,38,	
34,38,	34,38,	34,38,	34,38,	
34,38,	34,38,	34,38,	34,38,	
35,35,	35,35,	35,35,	35,35,	
35,35,	35,35,	35,35,	35,35,	
35,35,	35,35,	75,154,	79,160,	
75,155,	86,169,	88,173,	89,174,	
92,179,	93,180,	75,156,	96,186,	
79,161,	35,107,	38,38,	38,38,	
38,34,	38,38,	38,38,	38,38,	
38,38,	38,38,	38,38,	38,38,	
38,38,	38,38,	38,38,	39,108,	
39,108,	39,108,	39,108,	39,108,	
39,108,	39,108,	39,108,	39,108,	
39,108,	97,187,	98,188,	99,189,	
101,192,	104,193,	105,194,	106,195,	
41,110,	35,107,	41,110,	58,131,	
39,109,	41,111,	41,111,	41,111,	
41,111,	41,111,	41,111,	41,111,	
41,111,	41,111,	41,111,	58,132,	
58,133,	71,148,	64,139,	73,151,	
38,38,	91,177,	64,140,	90,175,	
94,181,	87,170,	95,184,	94,182,	
108,198,	112,201,	113,202,	73,152,	
114,203,	71,149,	94,183,	87,171,	
39,109,	64,141,	87,172,	100,190,	
90,176,	91,178,	115,204,	95,185,	
107,196,	116,205,	107,196,	100,191,	
117,206,	107,197,	107,197,	107,197,	
107,197,	107,197,	107,197,	107,197,	
107,197,	107,197,	107,197,	109,199,	
108,198,	109,199,	119,209,	121,210,	
109,200,	109,200,	109,200,	109,200,	
109,200,	109,200,	109,200,	109,200,	
109,200,	109,200,	110,111,	110,111,	
110,111,	110,111,	110,111,	110,111,	
110,111,	110,111,	110,111,	110,111,	
118,207,	122,211,	123,212,	124,213,	
125,214,	126,216,	127,217,	128,218,	
129,219,	130,220,	131,221,	132,222,	
133,223,	135,224,	137,228,	138,229,	
139,230,	135,225,	118,208,	125,215,	
136,226,	140,231,	142,232,	136,227,	
143,233,	144,234,	145,235,	146,236,	
147,237,	148,238,	149,239,	150,240,	
151,241,	152,242,	153,243,	155,244,	
156,245,	157,246,	158,247,	159,248,	
160,249,	161,250,	162,251,	163,252,	
164,253,	165,254,	166,255,	167,256,	
168,257,	169,258,	170,259,	171,260,	
172,261,	173,262,	174,263,	175,264,	
176,265,	177,266,	178,267,	180,268,	
181,269,	182,270,	183,271,	184,272,	
185,273,	186,274,	187,275,	188,276,	
189,277,	190,278,	191,279,	192,280,	
193,281,	194,282,	195,283,	196,197,	
196,197,	196,197,	196,197,	196,197,	
196,197,	196,197,	196,197,	196,197,	
196,197,	198,284,	201,286,	198,284,	
202,287,	203,288,	198,285,	198,285,	
198,285,	198,285,	198,285,	198,285,	
198,285,	198,285,	198,285,	198,285,	
199,200,	199,200,	199,200,	199,200,	
199,200,	199,200,	199,200,	199,200,	
199,200,	199,200,	205,289,	206,290,	
208,291,	211,292,	212,293,	213,294,	
215,295,	217,296,	218,297,	219,298,	
220,299,	221,300,	222,302,	224,303,	
225,304,	227,305,	228,306,	229,307,	
230,308,	231,309,	232,310,	233,311,	
234,312,	236,313,	237,314,	238,315,	
239,316,	221,301,	240,317,	241,318,	
243,319,	244,320,	245,321,	247,322,	
249,323,	250,324,	251,325,	252,326,	
253,327,	254,329,	255,330,	256,331,	
253,328,	257,332,	258,333,	259,334,	
260,335,	261,336,	262,337,	263,338,	
264,339,	265,340,	266,341,	267,342,	
268,343,	269,344,	270,346,	272,347,	
273,348,	274,349,	269,345,	275,350,	
277,352,	275,351,	278,353,	279,354,	
280,355,	281,356,	282,357,	286,359,	
287,360,	288,361,	289,362,	290,363,	
291,364,	292,365,	294,366,	295,367,	
282,358,	284,285,	284,285,	284,285,	
284,285,	284,285,	284,285,	284,285,	
284,285,	284,285,	284,285,	296,368,	
297,369,	298,370,	299,371,	300,372,	
301,373,	302,374,	303,375,	304,376,	
305,377,	306,378,	307,379,	308,380,	
309,381,	310,382,	313,384,	316,385,	
317,386,	320,387,	321,388,	323,389,	
310,383,	324,390,	325,391,	326,392,	
327,393,	330,394,	334,395,	335,396,	
336,397,	337,398,	338,399,	340,400,	
341,401,	342,402,	343,403,	344,404,	
345,405,	346,406,	347,408,	348,409,	
349,410,	346,407,	350,411,	351,412,	
353,413,	354,416,	356,417,	357,418,	
359,419,	360,420,	353,414,	361,421,	
362,422,	363,423,	353,415,	365,424,	
366,425,	367,426,	368,427,	370,428,	
372,430,	373,431,	374,432,	375,433,	
376,434,	378,435,	380,436,	381,437,	
382,438,	384,439,	385,440,	388,441,	
370,429,	389,442,	390,443,	392,444,	
394,445,	395,446,	397,447,	401,448,	
402,449,	404,450,	405,451,	407,452,	
408,453,	410,454,	411,455,	412,456,	
413,457,	414,458,	415,460,	416,461,	
417,462,	420,463,	421,464,	422,465,	
423,466,	425,467,	426,468,	428,469,	
429,470,	430,471,	432,472,	433,473,	
436,474,	438,475,	439,476,	440,477,	
441,478,	414,459,	442,479,	443,480,	
446,481,	447,482,	448,483,	451,484,	
452,485,	453,486,	455,487,	457,488,	
458,489,	459,490,	460,491,	461,492,	
464,493,	465,494,	466,495,	467,496,	
470,497,	471,498,	472,499,	474,500,	
475,501,	476,502,	477,503,	481,504,	
482,505,	483,506,	485,507,	486,508,	
488,509,	489,510,	490,511,	491,512,	
492,513,	494,514,	495,515,	497,516,	
498,517,	499,518,	501,519,	502,520,	
504,521,	505,522,	506,523,	511,524,	
512,525,	513,526,	516,527,	518,528,	
519,529,	520,530,	523,531,	524,532,	
525,533,	531,534,	532,535,	0,0,	
0,0};
struct yysvf yysvec[] = {
0,	0,	0,
yycrank+-1,	0,		0,	
yycrank+-26,	yysvec+1,	0,	
yycrank+0,	0,		yyvstop+1,
yycrank+0,	0,		yyvstop+3,
yycrank+0,	0,		yyvstop+6,
yycrank+28,	0,		yyvstop+8,
yycrank+104,	0,		yyvstop+10,
yycrank+181,	0,		yyvstop+12,
yycrank+218,	0,		yyvstop+15,
yycrank+40,	yysvec+9,	yyvstop+19,
yycrank+50,	yysvec+9,	yyvstop+23,
yycrank+135,	yysvec+9,	yyvstop+27,
yycrank+52,	yysvec+9,	yyvstop+31,
yycrank+45,	yysvec+9,	yyvstop+35,
yycrank+143,	yysvec+9,	yyvstop+39,
yycrank+145,	yysvec+9,	yyvstop+43,
yycrank+7,	yysvec+9,	yyvstop+47,
yycrank+50,	yysvec+9,	yyvstop+51,
yycrank+17,	yysvec+9,	yyvstop+55,
yycrank+57,	yysvec+9,	yyvstop+59,
yycrank+150,	yysvec+9,	yyvstop+63,
yycrank+147,	yysvec+9,	yyvstop+67,
yycrank+162,	yysvec+9,	yyvstop+71,
yycrank+233,	yysvec+9,	yyvstop+75,
yycrank+16,	yysvec+9,	yyvstop+79,
yycrank+245,	yysvec+9,	yyvstop+83,
yycrank+246,	yysvec+9,	yyvstop+87,
yycrank+256,	yysvec+9,	yyvstop+91,
yycrank+242,	yysvec+9,	yyvstop+95,
yycrank+47,	yysvec+9,	yyvstop+99,
yycrank+140,	yysvec+9,	yyvstop+103,
yycrank+0,	0,		yyvstop+107,
yycrank+7,	0,		0,	
yycrank+313,	0,		0,	
yycrank+388,	0,		yyvstop+110,
yycrank+0,	0,		yyvstop+112,
yycrank+9,	0,		0,	
yycrank+413,	yysvec+34,	yyvstop+114,
yycrank+423,	0,		yyvstop+116,
yycrank+0,	yysvec+8,	yyvstop+118,
yycrank+445,	0,		0,	
yycrank+0,	yysvec+9,	yyvstop+120,
yycrank+65,	yysvec+9,	yyvstop+123,
yycrank+263,	yysvec+9,	yyvstop+126,
yycrank+63,	yysvec+9,	yyvstop+129,
yycrank+86,	yysvec+9,	yyvstop+132,
yycrank+97,	yysvec+9,	yyvstop+135,
yycrank+86,	yysvec+9,	yyvstop+138,
yycrank+248,	yysvec+9,	yyvstop+141,
yycrank+89,	yysvec+9,	yyvstop+144,
yycrank+98,	yysvec+9,	yyvstop+147,
yycrank+89,	yysvec+9,	yyvstop+150,
yycrank+167,	yysvec+9,	yyvstop+153,
yycrank+117,	yysvec+9,	yyvstop+156,
yycrank+164,	yysvec+9,	yyvstop+159,
yycrank+132,	yysvec+9,	yyvstop+162,
yycrank+160,	yysvec+9,	yyvstop+165,
yycrank+389,	yysvec+9,	yyvstop+168,
yycrank+181,	yysvec+9,	yyvstop+171,
yycrank+193,	yysvec+9,	yyvstop+174,
yycrank+209,	yysvec+9,	yyvstop+177,
yycrank+202,	yysvec+9,	yyvstop+180,
yycrank+204,	yysvec+9,	yyvstop+183,
yycrank+407,	yysvec+9,	yyvstop+186,
yycrank+217,	yysvec+9,	yyvstop+189,
yycrank+232,	yysvec+9,	yyvstop+192,
yycrank+240,	yysvec+9,	yyvstop+195,
yycrank+260,	yysvec+9,	yyvstop+198,
yycrank+261,	yysvec+9,	yyvstop+201,
yycrank+272,	yysvec+9,	yyvstop+204,
yycrank+405,	yysvec+9,	yyvstop+207,
yycrank+255,	yysvec+9,	yyvstop+210,
yycrank+404,	yysvec+9,	yyvstop+213,
yycrank+261,	yysvec+9,	yyvstop+216,
yycrank+334,	yysvec+9,	yyvstop+219,
yycrank+258,	yysvec+9,	yyvstop+222,
yycrank+257,	yysvec+9,	yyvstop+225,
yycrank+267,	yysvec+9,	yyvstop+228,
yycrank+341,	yysvec+9,	yyvstop+231,
yycrank+271,	yysvec+9,	yyvstop+234,
yycrank+288,	yysvec+9,	yyvstop+237,
yycrank+308,	yysvec+9,	yyvstop+240,
yycrank+301,	yysvec+9,	yyvstop+243,
yycrank+302,	yysvec+9,	yyvstop+246,
yycrank+303,	yysvec+9,	yyvstop+249,
yycrank+339,	yysvec+9,	yyvstop+252,
yycrank+411,	yysvec+9,	yyvstop+255,
yycrank+334,	yysvec+9,	yyvstop+258,
yycrank+342,	yysvec+9,	yyvstop+261,
yycrank+414,	yysvec+9,	yyvstop+264,
yycrank+412,	yysvec+9,	yyvstop+267,
yycrank+331,	yysvec+9,	yyvstop+270,
yycrank+342,	yysvec+9,	yyvstop+273,
yycrank+411,	yysvec+9,	yyvstop+276,
yycrank+417,	yysvec+9,	yyvstop+279,
yycrank+341,	yysvec+9,	yyvstop+282,
yycrank+361,	yysvec+9,	yyvstop+285,
yycrank+374,	yysvec+9,	yyvstop+288,
yycrank+369,	yysvec+9,	yyvstop+291,
yycrank+430,	yysvec+9,	yyvstop+294,
yycrank+379,	yysvec+9,	yyvstop+297,
yycrank+0,	yysvec+9,	yyvstop+300,
yycrank+0,	yysvec+9,	yyvstop+304,
yycrank+371,	yysvec+9,	yyvstop+308,
yycrank+376,	yysvec+9,	yyvstop+311,
yycrank+376,	yysvec+9,	yyvstop+314,
yycrank+489,	0,		0,	
yycrank+447,	yysvec+39,	yyvstop+317,
yycrank+504,	0,		0,	
yycrank+514,	0,		0,	
yycrank+0,	yysvec+110,	yyvstop+320,
yycrank+412,	yysvec+9,	yyvstop+322,
yycrank+404,	yysvec+9,	yyvstop+325,
yycrank+412,	yysvec+9,	yyvstop+328,
yycrank+433,	yysvec+9,	yyvstop+331,
yycrank+422,	yysvec+9,	yyvstop+334,
yycrank+429,	yysvec+9,	yyvstop+337,
yycrank+474,	yysvec+9,	yyvstop+340,
yycrank+429,	yysvec+9,	yyvstop+343,
yycrank+0,	yysvec+9,	yyvstop+346,
yycrank+439,	yysvec+9,	yyvstop+350,
yycrank+474,	yysvec+9,	yyvstop+353,
yycrank+457,	yysvec+9,	yyvstop+356,
yycrank+463,	yysvec+9,	yyvstop+359,
yycrank+475,	yysvec+9,	yyvstop+362,
yycrank+465,	yysvec+9,	yyvstop+365,
yycrank+463,	yysvec+9,	yyvstop+368,
yycrank+468,	yysvec+9,	yyvstop+371,
yycrank+475,	yysvec+9,	yyvstop+374,
yycrank+476,	yysvec+9,	yyvstop+377,
yycrank+480,	yysvec+9,	yyvstop+380,
yycrank+482,	yysvec+9,	yyvstop+383,
yycrank+485,	yysvec+9,	yyvstop+386,
yycrank+0,	yysvec+9,	yyvstop+389,
yycrank+484,	yysvec+9,	yyvstop+393,
yycrank+480,	yysvec+9,	yyvstop+396,
yycrank+488,	yysvec+9,	yyvstop+399,
yycrank+471,	yysvec+9,	yyvstop+403,
yycrank+491,	yysvec+9,	yyvstop+406,
yycrank+493,	yysvec+9,	yyvstop+409,
yycrank+0,	yysvec+9,	yyvstop+413,
yycrank+485,	yysvec+9,	yyvstop+417,
yycrank+481,	yysvec+9,	yyvstop+420,
yycrank+482,	yysvec+9,	yyvstop+423,
yycrank+498,	yysvec+9,	yyvstop+426,
yycrank+496,	yysvec+9,	yyvstop+429,
yycrank+497,	yysvec+9,	yyvstop+432,
yycrank+500,	yysvec+9,	yyvstop+435,
yycrank+501,	yysvec+9,	yyvstop+438,
yycrank+487,	yysvec+9,	yyvstop+441,
yycrank+500,	yysvec+9,	yyvstop+444,
yycrank+489,	yysvec+9,	yyvstop+447,
yycrank+499,	yysvec+9,	yyvstop+450,
yycrank+0,	yysvec+9,	yyvstop+453,
yycrank+509,	yysvec+9,	yyvstop+457,
yycrank+508,	yysvec+9,	yyvstop+460,
yycrank+493,	yysvec+9,	yyvstop+463,
yycrank+500,	yysvec+9,	yyvstop+466,
yycrank+510,	yysvec+9,	yyvstop+469,
yycrank+507,	yysvec+9,	yyvstop+472,
yycrank+509,	yysvec+9,	yyvstop+475,
yycrank+513,	yysvec+9,	yyvstop+478,
yycrank+513,	yysvec+9,	yyvstop+481,
yycrank+506,	yysvec+9,	yyvstop+484,
yycrank+507,	yysvec+9,	yyvstop+487,
yycrank+497,	yysvec+9,	yyvstop+490,
yycrank+509,	yysvec+9,	yyvstop+493,
yycrank+519,	yysvec+9,	yyvstop+496,
yycrank+518,	yysvec+9,	yyvstop+499,
yycrank+514,	yysvec+9,	yyvstop+502,
yycrank+512,	yysvec+9,	yyvstop+505,
yycrank+513,	yysvec+9,	yyvstop+508,
yycrank+528,	yysvec+9,	yyvstop+511,
yycrank+514,	yysvec+9,	yyvstop+514,
yycrank+519,	yysvec+9,	yyvstop+517,
yycrank+527,	yysvec+9,	yyvstop+520,
yycrank+529,	yysvec+9,	yyvstop+523,
yycrank+514,	yysvec+9,	yyvstop+526,
yycrank+0,	yysvec+9,	yyvstop+529,
yycrank+520,	yysvec+9,	yyvstop+533,
yycrank+533,	yysvec+9,	yyvstop+536,
yycrank+532,	yysvec+9,	yyvstop+539,
yycrank+518,	yysvec+9,	yyvstop+542,
yycrank+521,	yysvec+9,	yyvstop+545,
yycrank+531,	yysvec+9,	yyvstop+548,
yycrank+535,	yysvec+9,	yyvstop+551,
yycrank+522,	yysvec+9,	yyvstop+554,
yycrank+538,	yysvec+9,	yyvstop+557,
yycrank+523,	yysvec+9,	yyvstop+560,
yycrank+531,	yysvec+9,	yyvstop+563,
yycrank+545,	yysvec+9,	yyvstop+566,
yycrank+532,	yysvec+9,	yyvstop+569,
yycrank+546,	yysvec+9,	yyvstop+572,
yycrank+545,	yysvec+9,	yyvstop+575,
yycrank+546,	yysvec+9,	yyvstop+578,
yycrank+599,	0,		0,	
yycrank+0,	yysvec+196,	yyvstop+581,
yycrank+614,	0,		0,	
yycrank+624,	0,		0,	
yycrank+0,	yysvec+199,	yyvstop+583,
yycrank+557,	yysvec+9,	yyvstop+585,
yycrank+544,	yysvec+9,	yyvstop+588,
yycrank+540,	yysvec+9,	yyvstop+591,
yycrank+0,	yysvec+9,	yyvstop+594,
yycrank+567,	yysvec+9,	yyvstop+598,
yycrank+580,	yysvec+9,	yyvstop+601,
yycrank+0,	yysvec+9,	yyvstop+604,
yycrank+585,	yysvec+9,	yyvstop+608,
yycrank+0,	yysvec+9,	yyvstop+611,
yycrank+0,	yysvec+9,	yyvstop+615,
yycrank+578,	yysvec+9,	yyvstop+619,
yycrank+586,	yysvec+9,	yyvstop+622,
yycrank+576,	yysvec+9,	yyvstop+625,
yycrank+0,	yysvec+9,	yyvstop+628,
yycrank+574,	yysvec+9,	yyvstop+632,
yycrank+0,	yysvec+9,	yyvstop+635,
yycrank+572,	yysvec+9,	yyvstop+639,
yycrank+588,	yysvec+9,	yyvstop+642,
yycrank+581,	yysvec+9,	yyvstop+645,
yycrank+582,	yysvec+9,	yyvstop+648,
yycrank+592,	yysvec+9,	yyvstop+651,
yycrank+595,	yysvec+9,	yyvstop+654,
yycrank+0,	yysvec+9,	yyvstop+657,
yycrank+585,	yysvec+9,	yyvstop+661,
yycrank+586,	yysvec+9,	yyvstop+664,
yycrank+0,	yysvec+9,	yyvstop+667,
yycrank+596,	yysvec+9,	yyvstop+671,
yycrank+581,	yysvec+9,	yyvstop+674,
yycrank+598,	yysvec+9,	yyvstop+677,
yycrank+592,	yysvec+9,	yyvstop+680,
yycrank+600,	yysvec+9,	yyvstop+683,
yycrank+601,	yysvec+9,	yyvstop+686,
yycrank+588,	yysvec+9,	yyvstop+689,
yycrank+589,	yysvec+9,	yyvstop+692,
yycrank+0,	yysvec+9,	yyvstop+695,
yycrank+601,	yysvec+9,	yyvstop+699,
yycrank+605,	yysvec+9,	yyvstop+702,
yycrank+587,	yysvec+9,	yyvstop+705,
yycrank+594,	yysvec+9,	yyvstop+708,
yycrank+609,	yysvec+9,	yyvstop+711,
yycrank+595,	yysvec+9,	yyvstop+714,
yycrank+0,	yysvec+9,	yyvstop+717,
yycrank+600,	yysvec+9,	yyvstop+721,
yycrank+605,	yysvec+9,	yyvstop+724,
yycrank+613,	yysvec+9,	yyvstop+727,
yycrank+0,	yysvec+9,	yyvstop+730,
yycrank+599,	yysvec+9,	yyvstop+734,
yycrank+0,	yysvec+9,	yyvstop+737,
yycrank+600,	yysvec+9,	yyvstop+741,
yycrank+620,	yysvec+9,	yyvstop+744,
yycrank+619,	yysvec+9,	yyvstop+747,
yycrank+614,	yysvec+9,	yyvstop+750,
yycrank+623,	yysvec+9,	yyvstop+753,
yycrank+605,	yysvec+9,	yyvstop+756,
yycrank+619,	yysvec+9,	yyvstop+759,
yycrank+607,	yysvec+9,	yyvstop+763,
yycrank+609,	yysvec+9,	yyvstop+766,
yycrank+625,	yysvec+9,	yyvstop+769,
yycrank+626,	yysvec+9,	yyvstop+772,
yycrank+614,	yysvec+9,	yyvstop+775,
yycrank+621,	yysvec+9,	yyvstop+778,
yycrank+614,	yysvec+9,	yyvstop+781,
yycrank+623,	yysvec+9,	yyvstop+784,
yycrank+631,	yysvec+9,	yyvstop+787,
yycrank+632,	yysvec+9,	yyvstop+790,
yycrank+623,	yysvec+9,	yyvstop+793,
yycrank+619,	yysvec+9,	yyvstop+796,
yycrank+620,	yysvec+9,	yyvstop+799,
yycrank+625,	yysvec+9,	yyvstop+802,
yycrank+624,	yysvec+9,	yyvstop+805,
yycrank+0,	yysvec+9,	yyvstop+808,
yycrank+623,	yysvec+9,	yyvstop+812,
yycrank+628,	yysvec+9,	yyvstop+815,
yycrank+644,	yysvec+9,	yyvstop+818,
yycrank+628,	yysvec+9,	yyvstop+821,
yycrank+0,	yysvec+9,	yyvstop+824,
yycrank+629,	yysvec+9,	yyvstop+828,
yycrank+631,	yysvec+9,	yyvstop+831,
yycrank+637,	yysvec+9,	yyvstop+834,
yycrank+638,	yysvec+9,	yyvstop+837,
yycrank+638,	yysvec+9,	yyvstop+840,
yycrank+639,	yysvec+9,	yyvstop+843,
yycrank+0,	yysvec+9,	yyvstop+846,
yycrank+713,	0,		0,	
yycrank+0,	yysvec+284,	yyvstop+850,
yycrank+641,	yysvec+9,	yyvstop+853,
yycrank+635,	yysvec+9,	yyvstop+856,
yycrank+638,	yysvec+9,	yyvstop+859,
yycrank+642,	yysvec+9,	yyvstop+862,
yycrank+641,	yysvec+9,	yyvstop+865,
yycrank+652,	yysvec+9,	yyvstop+868,
yycrank+656,	yysvec+9,	yyvstop+871,
yycrank+0,	yysvec+9,	yyvstop+874,
yycrank+648,	yysvec+9,	yyvstop+878,
yycrank+662,	yysvec+9,	yyvstop+881,
yycrank+657,	yysvec+9,	yyvstop+884,
yycrank+670,	yysvec+9,	yyvstop+887,
yycrank+673,	yysvec+9,	yyvstop+890,
yycrank+673,	yysvec+9,	yyvstop+893,
yycrank+661,	yysvec+9,	yyvstop+896,
yycrank+661,	yysvec+9,	yyvstop+899,
yycrank+661,	yysvec+9,	yyvstop+902,
yycrank+678,	yysvec+9,	yyvstop+905,
yycrank+680,	yysvec+9,	yyvstop+908,
yycrank+668,	yysvec+9,	yyvstop+911,
yycrank+672,	yysvec+9,	yyvstop+914,
yycrank+668,	yysvec+9,	yyvstop+917,
yycrank+683,	yysvec+9,	yyvstop+920,
yycrank+685,	yysvec+9,	yyvstop+923,
yycrank+677,	yysvec+9,	yyvstop+926,
yycrank+0,	yysvec+9,	yyvstop+929,
yycrank+0,	yysvec+9,	yyvstop+933,
yycrank+670,	yysvec+9,	yyvstop+937,
yycrank+0,	yysvec+9,	yyvstop+940,
yycrank+0,	yysvec+9,	yyvstop+944,
yycrank+672,	yysvec+9,	yyvstop+948,
yycrank+674,	yysvec+9,	yyvstop+951,
yycrank+0,	yysvec+9,	yyvstop+954,
yycrank+0,	yysvec+9,	yyvstop+958,
yycrank+688,	yysvec+9,	yyvstop+962,
yycrank+678,	yysvec+9,	yyvstop+965,
yycrank+0,	yysvec+9,	yyvstop+968,
yycrank+675,	yysvec+9,	yyvstop+972,
yycrank+693,	yysvec+9,	yyvstop+975,
yycrank+678,	yysvec+9,	yyvstop+978,
yycrank+687,	yysvec+9,	yyvstop+981,
yycrank+682,	yysvec+9,	yyvstop+984,
yycrank+0,	yysvec+9,	yyvstop+987,
yycrank+0,	yysvec+9,	yyvstop+991,
yycrank+686,	yysvec+9,	yyvstop+995,
yycrank+0,	yysvec+9,	yyvstop+998,
yycrank+0,	yysvec+9,	yyvstop+1002,
yycrank+0,	yysvec+9,	yyvstop+1006,
yycrank+699,	yysvec+9,	yyvstop+1010,
yycrank+683,	yysvec+9,	yyvstop+1013,
yycrank+683,	yysvec+9,	yyvstop+1016,
yycrank+700,	yysvec+9,	yyvstop+1019,
yycrank+701,	yysvec+9,	yyvstop+1022,
yycrank+0,	yysvec+9,	yyvstop+1025,
yycrank+693,	yysvec+9,	yyvstop+1029,
yycrank+685,	yysvec+9,	yyvstop+1032,
yycrank+704,	yysvec+9,	yyvstop+1035,
yycrank+702,	yysvec+9,	yyvstop+1038,
yycrank+696,	yysvec+9,	yyvstop+1041,
yycrank+700,	yysvec+9,	yyvstop+1044,
yycrank+708,	yysvec+9,	yyvstop+1047,
yycrank+694,	yysvec+9,	yyvstop+1050,
yycrank+710,	yysvec+9,	yyvstop+1053,
yycrank+713,	yysvec+9,	yyvstop+1056,
yycrank+697,	yysvec+9,	yyvstop+1059,
yycrank+701,	yysvec+9,	yyvstop+1062,
yycrank+0,	yysvec+9,	yyvstop+1065,
yycrank+714,	yysvec+9,	yyvstop+1069,
yycrank+714,	yysvec+9,	yyvstop+1072,
yycrank+0,	yysvec+9,	yyvstop+1075,
yycrank+703,	yysvec+9,	yyvstop+1079,
yycrank+700,	yysvec+9,	yyvstop+1082,
yycrank+0,	yysvec+9,	yyvstop+1085,
yycrank+704,	yysvec+9,	yyvstop+1089,
yycrank+707,	yysvec+9,	yyvstop+1092,
yycrank+706,	yysvec+9,	yyvstop+1095,
yycrank+720,	yysvec+9,	yyvstop+1098,
yycrank+714,	yysvec+9,	yyvstop+1101,
yycrank+0,	yysvec+9,	yyvstop+1104,
yycrank+713,	yysvec+9,	yyvstop+1108,
yycrank+727,	yysvec+9,	yyvstop+1111,
yycrank+714,	yysvec+9,	yyvstop+1114,
yycrank+728,	yysvec+9,	yyvstop+1117,
yycrank+0,	yysvec+9,	yyvstop+1120,
yycrank+730,	yysvec+9,	yyvstop+1124,
yycrank+0,	yysvec+9,	yyvstop+1127,
yycrank+731,	yysvec+9,	yyvstop+1131,
yycrank+732,	yysvec+9,	yyvstop+1134,
yycrank+729,	yysvec+9,	yyvstop+1137,
yycrank+734,	yysvec+9,	yyvstop+1140,
yycrank+720,	yysvec+9,	yyvstop+1143,
yycrank+0,	yysvec+9,	yyvstop+1146,
yycrank+725,	yysvec+9,	yyvstop+1150,
yycrank+0,	yysvec+9,	yyvstop+1153,
yycrank+733,	yysvec+9,	yyvstop+1157,
yycrank+732,	yysvec+9,	yyvstop+1160,
yycrank+739,	yysvec+9,	yyvstop+1163,
yycrank+0,	yysvec+9,	yyvstop+1166,
yycrank+739,	yysvec+9,	yyvstop+1170,
yycrank+741,	yysvec+9,	yyvstop+1173,
yycrank+0,	yysvec+9,	yyvstop+1176,
yycrank+0,	yysvec+9,	yyvstop+1180,
yycrank+727,	yysvec+9,	yyvstop+1184,
yycrank+744,	yysvec+9,	yyvstop+1187,
yycrank+735,	yysvec+9,	yyvstop+1190,
yycrank+0,	yysvec+9,	yyvstop+1193,
yycrank+746,	yysvec+9,	yyvstop+1197,
yycrank+0,	yysvec+9,	yyvstop+1200,
yycrank+738,	yysvec+9,	yyvstop+1204,
yycrank+733,	yysvec+9,	yyvstop+1207,
yycrank+0,	yysvec+9,	yyvstop+1210,
yycrank+734,	yysvec+9,	yyvstop+1214,
yycrank+0,	yysvec+9,	yyvstop+1217,
yycrank+0,	yysvec+9,	yyvstop+1221,
yycrank+0,	yysvec+9,	yyvstop+1225,
yycrank+735,	yysvec+9,	yyvstop+1229,
yycrank+738,	yysvec+9,	yyvstop+1232,
yycrank+0,	yysvec+9,	yyvstop+1235,
yycrank+734,	yysvec+9,	yyvstop+1239,
yycrank+757,	yysvec+9,	yyvstop+1242,
yycrank+0,	yysvec+9,	yyvstop+1245,
yycrank+756,	yysvec+9,	yyvstop+1249,
yycrank+751,	yysvec+9,	yyvstop+1252,
yycrank+0,	yysvec+9,	yyvstop+1255,
yycrank+756,	yysvec+9,	yyvstop+1259,
yycrank+744,	yysvec+9,	yyvstop+1262,
yycrank+758,	yysvec+9,	yyvstop+1265,
yycrank+749,	yysvec+9,	yyvstop+1268,
yycrank+764,	yysvec+9,	yyvstop+1271,
yycrank+765,	yysvec+9,	yyvstop+1274,
yycrank+755,	yysvec+9,	yyvstop+1278,
yycrank+763,	yysvec+9,	yyvstop+1281,
yycrank+0,	yysvec+9,	yyvstop+1284,
yycrank+0,	yysvec+9,	yyvstop+1288,
yycrank+764,	yysvec+9,	yyvstop+1292,
yycrank+752,	yysvec+9,	yyvstop+1295,
yycrank+766,	yysvec+9,	yyvstop+1298,
yycrank+751,	yysvec+9,	yyvstop+1301,
yycrank+0,	yysvec+9,	yyvstop+1304,
yycrank+759,	yysvec+9,	yyvstop+1308,
yycrank+754,	yysvec+9,	yyvstop+1311,
yycrank+0,	yysvec+9,	yyvstop+1314,
yycrank+757,	yysvec+9,	yyvstop+1318,
yycrank+767,	yysvec+9,	yyvstop+1321,
yycrank+763,	yysvec+9,	yyvstop+1324,
yycrank+0,	yysvec+9,	yyvstop+1327,
yycrank+763,	yysvec+9,	yyvstop+1331,
yycrank+775,	yysvec+9,	yyvstop+1334,
yycrank+0,	yysvec+9,	yyvstop+1337,
yycrank+0,	yysvec+9,	yyvstop+1341,
yycrank+761,	yysvec+9,	yyvstop+1345,
yycrank+0,	yysvec+9,	yyvstop+1348,
yycrank+767,	yysvec+9,	yyvstop+1352,
yycrank+773,	yysvec+9,	yyvstop+1355,
yycrank+780,	yysvec+9,	yyvstop+1358,
yycrank+776,	yysvec+9,	yyvstop+1361,
yycrank+768,	yysvec+9,	yyvstop+1364,
yycrank+764,	yysvec+9,	yyvstop+1367,
yycrank+0,	yysvec+9,	yyvstop+1370,
yycrank+0,	yysvec+9,	yyvstop+1374,
yycrank+779,	yysvec+9,	yyvstop+1378,
yycrank+780,	yysvec+9,	yyvstop+1382,
yycrank+772,	yysvec+9,	yyvstop+1385,
yycrank+0,	yysvec+9,	yyvstop+1388,
yycrank+0,	yysvec+9,	yyvstop+1392,
yycrank+773,	yysvec+9,	yyvstop+1396,
yycrank+791,	yysvec+9,	yyvstop+1399,
yycrank+780,	yysvec+9,	yyvstop+1402,
yycrank+0,	yysvec+9,	yyvstop+1405,
yycrank+788,	yysvec+9,	yyvstop+1409,
yycrank+0,	yysvec+9,	yyvstop+1412,
yycrank+777,	yysvec+9,	yyvstop+1416,
yycrank+776,	yysvec+9,	yyvstop+1419,
yycrank+794,	yysvec+9,	yyvstop+1422,
yycrank+780,	yysvec+9,	yyvstop+1426,
yycrank+794,	yysvec+9,	yyvstop+1429,
yycrank+0,	yysvec+9,	yyvstop+1432,
yycrank+0,	yysvec+9,	yyvstop+1436,
yycrank+794,	yysvec+9,	yyvstop+1440,
yycrank+783,	yysvec+9,	yyvstop+1443,
yycrank+788,	yysvec+9,	yyvstop+1446,
yycrank+783,	yysvec+9,	yyvstop+1449,
yycrank+0,	yysvec+9,	yyvstop+1452,
yycrank+0,	yysvec+9,	yyvstop+1456,
yycrank+801,	yysvec+9,	yyvstop+1460,
yycrank+802,	yysvec+9,	yyvstop+1463,
yycrank+792,	yysvec+9,	yyvstop+1466,
yycrank+0,	yysvec+9,	yyvstop+1469,
yycrank+787,	yysvec+9,	yyvstop+1473,
yycrank+801,	yysvec+9,	yyvstop+1476,
yycrank+804,	yysvec+9,	yyvstop+1479,
yycrank+790,	yysvec+9,	yyvstop+1482,
yycrank+0,	yysvec+9,	yyvstop+1485,
yycrank+0,	yysvec+9,	yyvstop+1489,
yycrank+0,	yysvec+9,	yyvstop+1493,
yycrank+789,	yysvec+9,	yyvstop+1497,
yycrank+797,	yysvec+9,	yyvstop+1500,
yycrank+812,	yysvec+9,	yyvstop+1503,
yycrank+0,	yysvec+9,	yyvstop+1506,
yycrank+802,	yysvec+9,	yyvstop+1510,
yycrank+810,	yysvec+9,	yyvstop+1513,
yycrank+0,	yysvec+9,	yyvstop+1516,
yycrank+803,	yysvec+9,	yyvstop+1520,
yycrank+812,	yysvec+9,	yyvstop+1523,
yycrank+813,	yysvec+9,	yyvstop+1526,
yycrank+814,	yysvec+9,	yyvstop+1529,
yycrank+799,	yysvec+9,	yyvstop+1532,
yycrank+0,	yysvec+9,	yyvstop+1536,
yycrank+816,	yysvec+9,	yyvstop+1540,
yycrank+818,	yysvec+9,	yyvstop+1543,
yycrank+0,	yysvec+9,	yyvstop+1546,
yycrank+822,	yysvec+9,	yyvstop+1550,
yycrank+819,	yysvec+9,	yyvstop+1553,
yycrank+824,	yysvec+9,	yyvstop+1556,
yycrank+0,	yysvec+9,	yyvstop+1559,
yycrank+806,	yysvec+9,	yyvstop+1563,
yycrank+815,	yysvec+9,	yyvstop+1566,
yycrank+0,	yysvec+9,	yyvstop+1569,
yycrank+823,	yysvec+9,	yyvstop+1573,
yycrank+815,	yysvec+9,	yyvstop+1576,
yycrank+816,	yysvec+9,	yyvstop+1579,
yycrank+0,	yysvec+9,	yyvstop+1582,
yycrank+0,	yysvec+9,	yyvstop+1586,
yycrank+0,	yysvec+9,	yyvstop+1590,
yycrank+0,	yysvec+9,	yyvstop+1594,
yycrank+817,	yysvec+9,	yyvstop+1598,
yycrank+818,	yysvec+9,	yyvstop+1601,
yycrank+811,	yysvec+9,	yyvstop+1604,
yycrank+0,	yysvec+9,	yyvstop+1607,
yycrank+0,	yysvec+9,	yyvstop+1611,
yycrank+822,	yysvec+9,	yyvstop+1615,
yycrank+0,	yysvec+9,	yyvstop+1618,
yycrank+823,	yysvec+9,	yyvstop+1622,
yycrank+828,	yysvec+9,	yyvstop+1625,
yycrank+833,	yysvec+9,	yyvstop+1628,
yycrank+0,	yysvec+9,	yyvstop+1631,
yycrank+0,	yysvec+9,	yyvstop+1635,
yycrank+819,	yysvec+9,	yyvstop+1639,
yycrank+836,	yysvec+9,	yyvstop+1642,
yycrank+820,	yysvec+9,	yyvstop+1645,
yycrank+0,	yysvec+9,	yyvstop+1648,
yycrank+0,	yysvec+9,	yyvstop+1652,
yycrank+0,	yysvec+9,	yyvstop+1656,
yycrank+0,	yysvec+9,	yyvstop+1660,
yycrank+0,	yysvec+9,	yyvstop+1664,
yycrank+825,	yysvec+9,	yyvstop+1668,
yycrank+817,	yysvec+9,	yyvstop+1671,
yycrank+0,	yysvec+9,	yyvstop+1674,
yycrank+0,	yysvec+9,	yyvstop+1678,
yycrank+0,	yysvec+9,	yyvstop+1682,
0,	0,	0};
struct yywork *yytop = yycrank+938;
struct yysvf *yybgin = yysvec+1;
char yymatch[] = {
  0,   1,   1,   1,   1,   1,   1,   1, 
  1,   9,  10,   1,   1,   1,   1,   1, 
  1,   1,   1,   1,   1,   1,   1,   1, 
  1,   1,   1,   1,   1,   1,   1,   1, 
  9,   1,   1,   1,   1,   1,   1,   1, 
  1,   1,   1,  43,   1,  45,  46,   1, 
 48,  48,  48,  48,  48,  48,  48,  48, 
 48,  48,   1,   1,   1,   1,   1,   1, 
  1,  65,  65,  65,  65,  69,  65,  65, 
 65,  65,  65,  65,  65,  65,  65,  65, 
 65,  65,  65,  65,  65,  65,  65,  65, 
 65,  65,  65,   1,   1,   1,   1,  46, 
  1,  65,  65,  65,  65,  69,  65,  65, 
 65,  65,  65,  65,  65,  65,  65,  65, 
 65,  65,  65,  65,  65,  65,  65,  65, 
 65,  65,  65,   1,   1,   1,   1,   1, 
  1,   1,   1,   1,   1,   1,   1,   1, 
  1,   1,   1,   1,   1,   1,   1,   1, 
  1,   1,   1,   1,   1,   1,   1,   1, 
  1,   1,   1,   1,   1,   1,   1,   1, 
  1,   1,   1,   1,   1,   1,   1,   1, 
  1,   1,   1,   1,   1,   1,   1,   1, 
  1,   1,   1,   1,   1,   1,   1,   1, 
  1,   1,   1,   1,   1,   1,   1,   1, 
  1,   1,   1,   1,   1,   1,   1,   1, 
  1,   1,   1,   1,   1,   1,   1,   1, 
  1,   1,   1,   1,   1,   1,   1,   1, 
  1,   1,   1,   1,   1,   1,   1,   1, 
  1,   1,   1,   1,   1,   1,   1,   1, 
  1,   1,   1,   1,   1,   1,   1,   1, 
  1,   1,   1,   1,   1,   1,   1,   1, 
  1,   1,   1,   1,   1,   1,   1,   1, 
0};
char yyextra[] = {
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0};
/*	Copyright (c) 1989 AT&T	*/
/*	  All Rights Reserved  	*/

/*	THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF AT&T	*/
/*	The copyright notice above does not evidence any   	*/
/*	actual or intended publication of such source code.	*/

#pragma ident	"@(#)ncform	6.12	97/12/08 SMI"

int yylineno =1;
# define YYU(x) x
# define NLSTATE yyprevious=YYNEWLINE
struct yysvf *yylstate [YYLMAX], **yylsp, **yyolsp;
char yysbuf[YYLMAX];
char *yysptr = yysbuf;
int *yyfnd;
extern struct yysvf *yyestate;
int yyprevious = YYNEWLINE;
#if defined(__cplusplus) || defined(__STDC__)
int yylook(void)
#else
yylook()
#endif
{
	register struct yysvf *yystate, **lsp;
	register struct yywork *yyt;
	struct yysvf *yyz;
	int yych, yyfirst;
	struct yywork *yyr;
# ifdef LEXDEBUG
	int debug;
# endif
	char *yylastch;
	/* start off machines */
# ifdef LEXDEBUG
	debug = 0;
# endif
	yyfirst=1;
	if (!yymorfg)
		yylastch = yytext;
	else {
		yymorfg=0;
		yylastch = yytext+yyleng;
		}
	for(;;){
		lsp = yylstate;
		yyestate = yystate = yybgin;
		if (yyprevious==YYNEWLINE) yystate++;
		for (;;){
# ifdef LEXDEBUG
			if(debug)fprintf(yyout,"state %d\n",yystate-yysvec-1);
# endif
			yyt = yystate->yystoff;
			if(yyt == yycrank && !yyfirst){  /* may not be any transitions */
				yyz = yystate->yyother;
				if(yyz == 0)break;
				if(yyz->yystoff == yycrank)break;
				}
#ifndef __cplusplus
			*yylastch++ = yych = input();
#else
			*yylastch++ = yych = lex_input();
#endif
#ifdef YYISARRAY
			if(yylastch > &yytext[YYLMAX]) {
				fprintf(yyout,"Input string too long, limit %d\n",YYLMAX);
				exit(1);
			}
#else
			if (yylastch >= &yytext[ yytextsz ]) {
				int	x = yylastch - yytext;

				yytextsz += YYTEXTSZINC;
				if (yytext == yy_tbuf) {
				    yytext = (char *) malloc(yytextsz);
				    memcpy(yytext, yy_tbuf, sizeof (yy_tbuf));
				}
				else
				    yytext = (char *) realloc(yytext, yytextsz);
				if (!yytext) {
				    fprintf(yyout,
					"Cannot realloc yytext\n");
				    exit(1);
				}
				yylastch = yytext + x;
			}
#endif
			yyfirst=0;
		tryagain:
# ifdef LEXDEBUG
			if(debug){
				fprintf(yyout,"char ");
				allprint(yych);
				putchar('\n');
				}
# endif
			yyr = yyt;
			if ( (uintptr_t)yyt > (uintptr_t)yycrank){
				yyt = yyr + yych;
				if (yyt <= yytop && yyt->verify+yysvec == yystate){
					if(yyt->advance+yysvec == YYLERR)	/* error transitions */
						{unput(*--yylastch);break;}
					*lsp++ = yystate = yyt->advance+yysvec;
					if(lsp > &yylstate[YYLMAX]) {
						fprintf(yyout,"Input string too long, limit %d\n",YYLMAX);
						exit(1);
					}
					goto contin;
					}
				}
# ifdef YYOPTIM
			else if((uintptr_t)yyt < (uintptr_t)yycrank) {	/* r < yycrank */
				yyt = yyr = yycrank+(yycrank-yyt);
# ifdef LEXDEBUG
				if(debug)fprintf(yyout,"compressed state\n");
# endif
				yyt = yyt + yych;
				if(yyt <= yytop && yyt->verify+yysvec == yystate){
					if(yyt->advance+yysvec == YYLERR)	/* error transitions */
						{unput(*--yylastch);break;}
					*lsp++ = yystate = yyt->advance+yysvec;
					if(lsp > &yylstate[YYLMAX]) {
						fprintf(yyout,"Input string too long, limit %d\n",YYLMAX);
						exit(1);
					}
					goto contin;
					}
				yyt = yyr + YYU(yymatch[yych]);
# ifdef LEXDEBUG
				if(debug){
					fprintf(yyout,"try fall back character ");
					allprint(YYU(yymatch[yych]));
					putchar('\n');
					}
# endif
				if(yyt <= yytop && yyt->verify+yysvec == yystate){
					if(yyt->advance+yysvec == YYLERR)	/* error transition */
						{unput(*--yylastch);break;}
					*lsp++ = yystate = yyt->advance+yysvec;
					if(lsp > &yylstate[YYLMAX]) {
						fprintf(yyout,"Input string too long, limit %d\n",YYLMAX);
						exit(1);
					}
					goto contin;
					}
				}
			if ((yystate = yystate->yyother) && (yyt= yystate->yystoff) != yycrank){
# ifdef LEXDEBUG
				if(debug)fprintf(yyout,"fall back to state %d\n",yystate-yysvec-1);
# endif
				goto tryagain;
				}
# endif
			else
				{unput(*--yylastch);break;}
		contin:
# ifdef LEXDEBUG
			if(debug){
				fprintf(yyout,"state %d char ",yystate-yysvec-1);
				allprint(yych);
				putchar('\n');
				}
# endif
			;
			}
# ifdef LEXDEBUG
		if(debug){
			fprintf(yyout,"stopped at %d with ",*(lsp-1)-yysvec-1);
			allprint(yych);
			putchar('\n');
			}
# endif
		while (lsp-- > yylstate){
			*yylastch-- = 0;
			if (*lsp != 0 && (yyfnd= (*lsp)->yystops) && *yyfnd > 0){
				yyolsp = lsp;
				if(yyextra[*yyfnd]){		/* must backup */
					while(yyback((*lsp)->yystops,-*yyfnd) != 1 && lsp > yylstate){
						lsp--;
						unput(*yylastch--);
						}
					}
				yyprevious = YYU(*yylastch);
				yylsp = lsp;
				yyleng = yylastch-yytext+1;
				yytext[yyleng] = 0;
# ifdef LEXDEBUG
				if(debug){
					fprintf(yyout,"\nmatch ");
					sprint(yytext);
					fprintf(yyout," action %d\n",*yyfnd);
					}
# endif
				return(*yyfnd++);
				}
			unput(*yylastch);
			}
		if (yytext[0] == 0  /* && feof(yyin) */)
			{
			yysptr=yysbuf;
			return(0);
			}
#ifndef __cplusplus
		yyprevious = yytext[0] = input();
		if (yyprevious>0)
			output(yyprevious);
#else
		yyprevious = yytext[0] = lex_input();
		if (yyprevious>0)
			lex_output(yyprevious);
#endif
		yylastch=yytext;
# ifdef LEXDEBUG
		if(debug)putchar('\n');
# endif
		}
	}
#if defined(__cplusplus) || defined(__STDC__)
int yyback(int *p, int m)
#else
yyback(p, m)
	int *p;
#endif
{
	if (p==0) return(0);
	while (*p) {
		if (*p++ == m)
			return(1);
	}
	return(0);
}
	/* the following are only used in the lex library */
#if defined(__cplusplus) || defined(__STDC__)
int yyinput(void)
#else
yyinput()
#endif
{
#ifndef __cplusplus
	return(input());
#else
	return(lex_input());
#endif
	}
#if defined(__cplusplus) || defined(__STDC__)
void yyoutput(int c)
#else
yyoutput(c)
  int c; 
#endif
{
#ifndef __cplusplus
	output(c);
#else
	lex_output(c);
#endif
	}
#if defined(__cplusplus) || defined(__STDC__)
void yyunput(int c)
#else
yyunput(c)
   int c; 
#endif
{
	unput(c);
	}
