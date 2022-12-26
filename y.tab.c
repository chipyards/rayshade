
# line 16 "yacc.y"
#include "rayshade.h"

#include "symtab.h"
#include "builtin.h"

#include "atmosphere.h"
#include "surface.h"
#include "texture.h"
#include "image.h"
#include "geom.h"
#include "light.h"
#include "options.h"
#include "stats.h"
#include "viewing.h"

#include "blob.h"
#include "box.h"
#include "cone.h"
#include "csg.h"
#include "cylinder.h"
#include "disc.h"
#include "grid.h"
#include "hf.h"
#include "instance.h"
#include "list.h"
#include "plane.h"
#include "poly.h"
#include "sphere.h"
#include "torus.h"
#include "triangle.h"

#include "point.h"
#include "infinite.h"
#include "spot.h"
#include "jittered.h"
#include "extended.h"

#include "blotch.h"
#include "bump.h"
#include "checker.h"
#include "cloud.h"
#include "fbm.h"
#include "fbmbump.h"
#include "gloss.h"
#include "imagetext.h"
#include "marble.h"
#include "mount.h"
#include "sky.h"
#include "stripe.h"
#include "windy.h"
#include "wood.h"

#include "fog.h"
#include "fogdeck.h"
#include "mist.h"

#include "rotate.h"
#include "scale.h"
#include "translate.h"
#include "xform.h"

Geom *NewAggregate();
char yyfilename[BUFSIZ];			/* Input filename */
GeomList *Defstack;				/* Geom definition stack. */
int Npoints = 0;				/* # of points in Polypoints */
Surface *tmpsurf;				/* Working surface */
SurfList *CurSurf;
Texture *CurText;				/* Working list of textures */
ImageText *Imagetext;				/* Working image texture */
Trans *TransHead, *TransTail;			/* Linked list of current transformations */
Atmosphere *CurEffect = (Atmosphere *)NULL;	/* Current atmos. effects */ 
PointList *Polypoints;				/* List of vertices */
MetaList *Metapoints, *Metapoint;
extern FILE *yyin;				/* input file pointer */
extern int yylineno;				/* Current line # in file */
extern Atmosphere *AtmosEffects;		/* atmospheric effects */
extern Medium TopMedium;			/* "air" */
extern void	GeomAddToDefined(),
		LightAddToDefined(),
		SurfaceAddToDefined();
extern Surface	*SurfaceGetNamed();
extern Geom 	*GeomGetNamed();

# line 99 "yacc.y"
typedef union
#ifdef __cplusplus
	YYSTYPE
#endif
 {
	char *c;
	int i;
	Float d;
	Vector v;
	Vec2d uv;
	Color col;
	Atmosphere *atmos;
	Light *light;
	Surface *surf;
	Geom *obj;
	Texture *text;
	Mapping *map;
	Trans *trans;
	Expr *e;
	SymtabEntry *sym;
} YYSTYPE;
# define tFLOAT 257
# define tSTRING 258
# define tFILENAME 259
# define tAPERTURE 260
# define tAPPLYSURF 261
# define tBACKGROUND 262
# define tBLOB 263
# define tBLOTCH 264
# define tBOX 265
# define tBUMP 266
# define tCONE 267
# define tCYL 268
# define tDIRECTIONAL 269
# define tCURSURF 270
# define tEXTENDED 271
# define tEYEP 272
# define tFBM 273
# define tFBMBUMP 274
# define tFOCALDIST 275
# define tFOG 276
# define tFOGDECK 277
# define tFOV 278
# define tGLOSS 279
# define tGRID 280
# define tHEIGHTFIELD 281
# define tLIGHT 282
# define tLIST 283
# define tLOOKP 284
# define tMARBLE 285
# define tMAXDEPTH 286
# define tMIST 287
# define tJITTER 288
# define tNOJITTER 289
# define tDEFINE 290
# define tOBJECT 291
# define tOUTFILE 292
# define tSKY 293
# define tDISC 294
# define tDIFFERENCE 295
# define tUNION 296
# define tINTERSECT 297
# define tPLANE 298
# define tPOINT 299
# define tPOLY 300
# define tROTATE 301
# define tSPOT 302
# define tPRINT 303
# define tSCALE 304
# define tSCREEN 305
# define tSPHERE 306
# define tSURFACE 307
# define tTHRESH 308
# define tTRANSLATE 309
# define tTRANSFORM 310
# define tTRIANGLE 311
# define tTRIANGLEUV 312
# define tUP 313
# define tEND 314
# define tTEXTURE 315
# define tCHECKER 316
# define tWOOD 317
# define tCONTRAST 318
# define tCUTOFF 319
# define tCLOUD 320
# define tAMBIENT 321
# define tDIFFUSE 322
# define tREFLECT 323
# define tTRANSP 324
# define tSPECULAR 325
# define tSPECPOW 326
# define tINDEX 327
# define tATMOSPHERE 328
# define tNOSHADOW 329
# define tAREA 330
# define tTRANSLU 331
# define tTORUS 332
# define tEYESEP 333
# define tSHADOWTRANSP 334
# define tREPORT 335
# define tVERBOSE 336
# define tQUIET 337
# define tWINDOW 338
# define tCROP 339
# define tSTRIPE 340
# define tMAP 341
# define tUV 342
# define tSPHERICAL 343
# define tCYLINDRICAL 344
# define tPLANAR 345
# define tIMAGE 346
# define tSMOOTH 347
# define tCOMPONENT 348
# define tTEXTSURF 349
# define tRANGE 350
# define tTILE 351
# define tSTARTTIME 352
# define tFRAMELENGTH 353
# define tNAME 354
# define tFILTER 355
# define tGAUSS 356
# define tBODY 357
# define tSAMPLE 358
# define tEXTINCT 359
# define tWINDY 360
# define tMOUNT 361
# define tSHUTTER 362
# define tFRAMES 363
# define UMINUS 364

#include <inttypes.h>

#ifdef __STDC__
#include <stdlib.h>
#include <string.h>
#define	YYCONST	const
#else
#include <malloc.h>
#include <memory.h>
#define	YYCONST
#endif

// #include <values.h>

#if defined(__cplusplus) || defined(__STDC__)

#if defined(__cplusplus) && defined(__EXTERN_C__)
extern "C" {
#endif
#ifndef yyerror
#if defined(__cplusplus)
	void yyerror(YYCONST char *);
#endif
#endif
#ifndef yylex
	int yylex(void);
#endif
	int yyparse(void);
#if defined(__cplusplus) && defined(__EXTERN_C__)
}
#endif

#endif

#define yyclearin yychar = -1
#define yyerrok yyerrflag = 0
extern int yychar;
extern int yyerrflag;
YYSTYPE yylval;
YYSTYPE yyval;
typedef int yytabelem;
#ifndef YYMAXDEPTH
#define YYMAXDEPTH 150
#endif
#if YYMAXDEPTH > 0
int yy_yys[YYMAXDEPTH], *yys = yy_yys;
YYSTYPE yy_yyv[YYMAXDEPTH], *yyv = yy_yyv;
#else	/* user does initial allocation */
int *yys;
YYSTYPE *yyv;
#endif
static int yymaxdepth = YYMAXDEPTH;
# define YYERRCODE 256

# line 1462 "yacc.y"

/*
 * Issue error message containing filename and line number, and exit.
 */
/*VARARGS1*/
yyerror(s, pat1, pat2)
char *s, *pat1, *pat2;
{
	fprintf(stderr,"%s: Error: %s: line %d: ", Options.progname,
			yyfilename, yylineno);
	fprintf(stderr, s, pat1, pat2);
	if (*s && s[strlen(s) -1] != '\n')
		/* YACC doesn't put newlines on error messages. */
		fprintf(stderr,"\n");	
	fflush(stderr);
	exit(1);
}

Geom *
NewAggregate(obj)
Geom *obj;
{
	obj->name = Defstack->obj->name;
	obj->next = Defstack->obj->next;
	return obj;
}
static YYCONST yytabelem yyexca[] ={
-1, 1,
	0, -1,
	-2, 0,
-1, 152,
	321, 155,
	322, 155,
	323, 155,
	324, 155,
	325, 155,
	326, 155,
	327, 155,
	329, 155,
	331, 155,
	357, 155,
	359, 155,
	-2, 151,
-1, 153,
	321, 156,
	322, 156,
	323, 156,
	324, 156,
	325, 156,
	326, 156,
	327, 156,
	329, 156,
	331, 156,
	357, 156,
	359, 156,
	-2, 152,
-1, 194,
	258, 151,
	321, 155,
	322, 155,
	323, 155,
	324, 155,
	325, 155,
	326, 155,
	327, 155,
	329, 155,
	331, 155,
	357, 155,
	359, 155,
	-2, 90,
-1, 207,
	258, 151,
	259, 151,
	321, 155,
	322, 155,
	323, 155,
	324, 155,
	325, 155,
	326, 155,
	327, 155,
	329, 155,
	331, 155,
	357, 155,
	359, 155,
	-2, 276,
-1, 218,
	40, 278,
	-2, 258,
	};
# define YYNPROD 279
# define YYLAST 1040
static YYCONST yytabelem yyact[]={

   111,   132,   392,   420,   421,   228,   323,   126,   324,   458,
   459,   460,   461,   469,   179,   326,   327,   137,   452,   140,
   192,   329,   421,   144,   235,   145,   266,   325,   419,   415,
   417,   418,   416,   229,   230,   331,   180,   181,   120,   122,
   122,   124,   273,   127,   128,   129,   122,   122,   185,   134,
   136,   139,   182,   143,   136,   147,   146,   215,   322,   328,
   216,   122,   330,   122,   187,   188,   189,   190,   138,   259,
   260,   214,   244,   445,   446,   449,   450,   448,   451,   453,
   258,   156,   333,    26,   142,   183,   117,   300,   337,   116,
   271,   115,   133,   269,   112,   207,   181,   301,   270,   272,
    25,    23,   334,   335,    22,    58,   122,   153,   256,   447,
   299,   206,   213,   398,   518,   297,   295,   519,   296,   353,
   298,   223,   122,    75,   122,   226,   197,   220,   135,   349,
   222,   212,   221,   231,   232,   233,   117,   234,   287,   116,
   234,   115,   167,   166,   299,   165,   239,   164,   500,   297,
   295,   501,   296,   163,   298,   162,   161,   113,   168,   169,
   173,   174,   170,   171,   176,   160,   178,   300,   177,   139,
   139,   139,   248,   139,   250,   251,   252,   253,   254,   159,
   158,   157,   141,   148,   155,   152,   245,   246,   247,   154,
   249,   227,   125,   267,   172,   414,   175,   153,   385,   281,
   193,   300,   336,   285,   286,   332,   265,   274,   195,   289,
   290,   291,   122,   191,   293,    33,    32,    31,    30,    29,
   288,    28,    27,   205,    24,    21,   122,   306,   122,    20,
    19,    18,    17,   299,   309,   310,   242,   243,   297,    16,
    15,    14,   308,   298,    13,    12,    11,    10,   168,   169,
   173,   174,   170,   171,   176,   139,   178,     9,   177,   139,
   139,   320,   262,   168,   169,   173,   174,   170,   171,   176,
   261,   178,   317,   177,   241,     8,   318,   319,     7,   279,
   263,   302,   303,   304,   172,     6,   175,     5,   255,     4,
   300,   352,     3,   122,     2,     1,   276,   278,   219,   172,
   277,   175,   268,   114,   180,   181,   122,   364,   475,   457,
   150,   151,   122,   149,   367,   314,   315,    70,   368,   139,
   139,   371,   365,    87,   374,   375,   316,   377,   378,   102,
   379,   380,   381,   101,   100,   383,   369,   370,    85,    79,
   376,    77,   372,   264,   217,   218,    82,   393,    76,   395,
   384,    83,   386,   114,   399,    84,   355,   356,   357,   358,
   359,   360,   361,    80,   263,   263,   263,   263,   403,    81,
   404,    78,    86,    69,    67,    68,    72,   103,   407,   408,
    71,   409,   410,   411,   412,   413,    74,    52,   257,   106,
   444,   321,    54,     0,   428,     0,   316,   316,     0,     0,
   431,     0,     0,   122,   434,   435,   436,     0,   437,   438,
   439,   440,   441,   442,   443,     0,     0,   454,     0,   456,
     0,     0,   110,     0,     0,     0,     0,   264,   264,   264,
   264,     0,   466,   263,   263,   263,   263,   122,   471,   472,
   122,   122,     0,   477,     0,   476,   299,     0,     0,   373,
   467,   297,   295,   468,   296,   478,   298,   479,   118,   119,
   382,   196,   432,     0,     0,     0,   393,   486,   485,     0,
     0,   139,   122,   122,   491,   492,     0,     0,   122,     0,
     0,     0,   263,   263,   263,   263,     0,   499,   488,   139,
   503,     0,   504,   505,   506,     0,   264,   264,   264,   264,
     0,   406,     0,   300,     0,   514,   502,   515,     0,     0,
     0,     0,   393,     0,   517,     0,   520,   299,   513,   263,
   263,   524,   297,   295,   121,   296,     0,   298,     0,   487,
     0,     0,   338,   339,   340,   341,     0,     0,     0,     0,
     0,     0,     0,     0,   455,   264,   264,   264,   264,     0,
     0,   198,   199,   200,   201,   202,   203,   204,   263,   208,
   209,   210,   512,     0,   123,   236,   237,   238,     0,   240,
   130,   131,     0,     0,   300,     0,     0,     0,   263,     0,
   522,     0,   264,   264,     0,   184,     0,   186,     0,     0,
   299,     0,   263,     0,   400,   297,   295,   401,   296,     0,
   298,   387,   388,   389,   390,   263,     0,     0,     0,     0,
     0,   263,     0,     0,     0,     0,   263,     0,   263,   280,
   263,   264,   282,   283,   284,     0,     0,   299,     0,     0,
   211,   362,   297,   295,   299,   296,     0,   298,   294,   297,
   295,   264,   296,     0,   298,     0,   224,   300,   225,     0,
   422,   423,   424,   425,     0,   264,     0,     0,     0,   311,
     0,     0,   312,   313,     0,     0,     0,     0,   264,     0,
     0,     0,     0,     0,   264,     0,     0,     0,     0,   264,
     0,   264,     0,   264,   300,     0,     0,   462,   463,     0,
     0,   300,     0,     0,    56,     0,    99,     0,    90,     0,
    94,    93,     0,   342,   343,   344,   345,   346,   347,   348,
   350,     0,   351,   105,    96,     0,   104,     0,     0,     0,
     0,     0,     0,     0,    73,     0,   483,    97,   109,   107,
   108,    88,     0,    95,     0,     0,   292,     0,     0,    89,
    55,     0,     0,     0,    91,    92,   497,   275,     0,     0,
   305,     0,   307,     0,     0,     0,     0,     0,     0,     0,
   510,     0,     0,     0,     0,    98,     0,     0,   391,     0,
   394,     0,     0,   516,   396,   397,     0,     0,     0,   521,
     0,     0,     0,     0,   523,     0,   525,    59,   526,   402,
   194,    99,     0,    90,   405,    94,    93,     0,     0,     0,
     0,     0,   153,     0,     0,     0,     0,     0,   105,    96,
     0,   104,     0,     0,   426,   427,     0,   354,   429,    73,
   430,     0,    97,   109,   107,   108,    88,     0,    95,     0,
   363,     0,     0,     0,    89,     0,   366,     0,     0,    91,
    92,     0,     0,     0,     0,     0,     0,     0,     0,   464,
   465,     0,     0,   168,   169,   173,   174,   170,   171,   176,
    98,   178,     0,   177,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,   480,   481,   482,     0,     0,   484,     0,   172,
     0,   175,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,   494,   495,   496,     0,     0,   498,     0,
     0,     0,     0,     0,     0,     0,     0,   507,   508,   509,
     0,   511,     0,     0,     0,     0,     0,   433,     0,     0,
     0,     0,     0,     0,     0,     0,    42,    56,    50,    99,
     0,    90,     0,    94,    93,     0,     0,     0,    34,     0,
     0,    43,     0,     0,    37,     0,   105,    96,    53,   104,
    35,   470,    45,     0,   473,   474,    61,    73,    57,     0,
    97,   109,   107,   108,    88,     0,    95,     0,     0,    66,
     0,    38,    89,    55,     0,     0,     0,    91,    92,    36,
     0,     0,     0,     0,    48,    49,   489,   490,     0,     0,
     0,     0,   493,     0,    60,     0,     0,     0,    98,    44,
    51,    41,     0,     0,    39,    40,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,    63,    65,
    59,    47,     0,     0,    46,     0,     0,     0,    64,    62 };
static YYCONST yytabelem yypact[]={

-10000000,   676,-10000000,-10000000,-10000000,-10000000,-10000000,-10000000,-10000000,-10000000,
-10000000,-10000000,-10000000,-10000000,-10000000,-10000000,-10000000,-10000000,-10000000,-10000000,
-10000000,-10000000,-10000000,-10000000,-10000000,-10000000,-10000000,-10000000,-10000000,-10000000,
-10000000,-10000000,-10000000,-10000000,    96,    96,    96,    96,    96,    96,
    96,  -329,    96,    96,    96,    96,    96,  -264,    96,    96,
    96,-10000000,  -310,    96,  -246,  -203,   -73,  -222,-10000000,  -206,
    96,  -210,    96,    96,    96,    96,    96,-10000000,-10000000,-10000000,
-10000000,-10000000,-10000000,   532,-10000000,-10000000,-10000000,-10000000,-10000000,-10000000,
-10000000,-10000000,-10000000,-10000000,-10000000,-10000000,-10000000,-10000000,   -73,   -73,
   -73,   -73,   -73,   -73,   -73,   -73,  -163,   -73,   -73,   -73,
-10000000,-10000000,-10000000,-10000000,-10000000,    96,-10000000,-10000000,-10000000,-10000000,
-10000000,    96,-10000000,-10000000,-10000000,  -186,  -200,    87,-10000000,-10000000,
    96,    96,-10000000,    96,    96,  -332,-10000000,-10000000,-10000000,-10000000,
-10000000,  -255,    96,    96,    96,-10000000,    96,-10000000,-10000000,    96,
-10000000,  -297,    96,    96,    96,    96,    96,   -73,-10000000,-10000000,
-10000000,-10000000,-10000000,-10000000,   -58,   -58,-10000000,-10000000,-10000000,-10000000,
-10000000,-10000000,-10000000,-10000000,-10000000,-10000000,-10000000,-10000000,    96,    96,
    96,    96,    96,    96,    96,    96,    96,    96,-10000000,-10000000,
-10000000,-10000000,   528,  -207,-10000000,    96,-10000000,-10000000,-10000000,-10000000,
-10000000,  -289,  -211,  -216,-10000000,   433,    96,-10000000,    96,    96,
    96,    96,    96,    96,-10000000,  -222,-10000000,-10000000,    96,    96,
    96,    96,  -211,    96,-10000000,-10000000,   597,-10000000,-10000000,    57,
    87,    87,    87,-10000000,-10000000,    96,    96,    46,-10000000,-10000000,
-10000000,-10000000,-10000000,    96,    96,-10000000,    96,-10000000,-10000000,    96,
    96,-10000000,-10000000,-10000000,   -58,-10000000,-10000000,-10000000,-10000000,-10000000,
-10000000,-10000000,-10000000,-10000000,    96,-10000000,-10000000,-10000000,    96,    96,
    96,  -207,-10000000,-10000000,-10000000,-10000000,  -258,-10000000,-10000000,    96,
    96,    96,    96,-10000000,-10000000,-10000000,-10000000,-10000000,-10000000,-10000000,
    96,    96,    96,    96,    96,    96,    96,    96,-10000000,    96,
    96,-10000000,    96,-10000000,-10000000,    87,    87,    87,    87,    87,
    87,    87,   590,    -7,    -7,    96,    96,  -222,-10000000,-10000000,
-10000000,    96,-10000000,    96,   -58,   -58,-10000000,    96,    96,    96,
    96,-10000000,   -73,    96,    96,  -222,    96,    96,-10000000,    96,
    96,    96,-10000000,   -73,    96,  -222,-10000000,  -222,    96,    96,
    96,    96,-10000000,-10000000,-10000000,    96,    96,    96,    96,-10000000,
-10000000,    96,    96,    96,-10000000,   196,   196,    -7,    -7,    -7,
    -7,   553,-10000000,-10000000,-10000000,-10000000,    96,    96,-10000000,    96,
-10000000,    96,  -211,-10000000,   -73,-10000000,-10000000,    96,    96,-10000000,
    96,    96,    96,    96,    96,  -319,-10000000,    96,    96,    96,
    96,    96,    96,    96,-10000000,    96,-10000000,    96,-10000000,    96,
-10000000,    87,    96,    96,    96,    96,-10000000,    96,    96,    96,
    96,    96,    96,    96,-10000000,  -248,    96,   -73,    96,-10000000,
-10000000,  -333,-10000000,-10000000,    96,    96,    96,    96,-10000000,-10000000,
-10000000,    96,   409,  -316,-10000000,-10000000,    96,    96,    96,    96,
    96,  -337,    96,-10000000,-10000000,-10000000,-10000000,-10000000,-10000000,-10000000,
-10000000,-10000000,-10000000,-10000000,    96,-10000000,    96,-10000000,-10000000,    96,
    96,    96,-10000000,    96,    96,    96,    96,-10000000,    87,-10000000,
    96,    96,    96,    96,    96,-10000000,-10000000,    96,-10000000,-10000000,
    96,    96,    96,    96,-10000000,    96,    96,   107,    96,    96,
-10000000,    96,    96,    96,    96,    96,    96,    96,    96,-10000000,
-10000000,    87,-10000000,  -222,    96,-10000000,    96,-10000000,-10000000,-10000000,
    96,    96,    73,-10000000,-10000000,    96,    96,-10000000,-10000000,    87,
-10000000,    96,   480,    96,-10000000,    96,-10000000 };
static YYCONST yytabelem yypgo[]={

     0,    14,   262,    60,   157,     0,    94,   422,     2,    17,
   128,   392,   391,   390,   524,   389,   388,   387,   386,   380,
   105,   377,   376,   375,   374,   373,   372,   371,   369,   363,
   355,   351,   348,   346,   341,   339,   338,   334,   333,   329,
   323,   317,   126,   461,   313,   311,   310,     3,   309,   308,
   302,   298,   295,   294,   292,   289,   287,   285,   278,   275,
   257,   247,   246,   245,   244,   241,   240,   239,   232,   231,
   230,   229,   225,   104,   101,   224,   100,    83,   222,   221,
   219,   218,   217,   216,   215,   213,    20,   208,   207,   206,
   205,   202,   198,   195,   193,   192,   191,   189,    81,    72,
   184,   181,   180,   179,   165,   156,   155,   153,   147,   145,
   143,   142,   138,   129,   123,   119,   113,    85,   108 };
static YYCONST yytabelem yyr1[]={

     0,    52,    52,    53,    53,    53,    53,    53,    53,    53,
    53,    53,    53,    53,    53,    53,    53,    53,    53,    53,
    53,    53,    53,    53,    53,    53,    53,    53,    53,    53,
    53,    53,    53,    53,    76,    20,    24,    23,    23,    25,
    25,    19,    18,    18,    18,    18,    18,    18,    18,    18,
    18,    18,    18,    77,    87,    87,    88,    88,    88,    88,
    85,    85,    89,    12,    12,    12,    12,    12,    12,    12,
    12,    12,    12,    12,    12,    12,    12,    12,    12,    90,
    91,    92,    92,    93,    93,    93,    93,    93,    93,    41,
    41,    86,    86,    94,    50,    50,    50,    50,    50,    54,
    55,    56,    57,    57,    66,    66,    66,    67,    67,    67,
    67,    81,    80,    83,    82,    68,    69,    58,    59,    60,
    61,    61,    61,    61,    95,    95,    96,    96,    62,    63,
    64,    65,    70,    71,    72,    72,    72,    72,    72,    17,
    17,    17,    17,    17,    11,    74,    43,    43,    42,    42,
    42,    44,    44,    46,    46,    97,   100,    45,    73,    73,
    99,    99,    98,    98,    98,    98,    98,    98,    98,    98,
    98,    98,    98,   101,   102,   103,   105,   108,   104,   106,
   107,   109,   110,   111,    31,    31,    33,   112,   112,   113,
    22,   114,    40,    37,    37,    37,    38,    39,    21,    15,
    15,    15,    28,    29,    34,    30,    27,    35,    35,    35,
    32,    36,    26,   115,   115,   116,    75,    78,    78,   117,
   117,   118,    16,    16,    16,     9,     7,     8,    49,    49,
    47,    48,    48,    48,    48,    48,    48,    48,    13,    13,
    13,    13,    13,    13,    13,    13,    13,    10,    10,    84,
    79,    14,     5,     5,     2,     2,     4,     3,     3,     3,
     3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
     3,     3,     3,     6,     6,     6,     1,     1,    51 };
static YYCONST yytabelem yyr2[]={

     0,     0,     4,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     3,     5,     5,     3,     2,     2,
     2,     3,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     7,     4,     0,     2,     2,     2,     2,
     4,     0,     7,     5,     7,     5,     3,     5,    15,    17,
    13,     3,     5,    17,    15,     3,    11,    19,     9,     4,
     5,     4,     0,     5,     7,     5,     7,     3,     3,     7,
     5,     4,     1,     3,     9,     9,    11,    21,    27,     7,
     5,     5,     7,     5,     7,     7,     5,     7,     5,     7,
     5,     5,     5,     5,     5,     9,     5,     7,    11,    11,
    11,     9,     9,     6,     3,     0,     3,     0,     5,     5,
     5,     5,     5,     3,     3,     5,     7,    15,    17,     7,
     7,     9,    11,    15,     5,     5,     2,     1,     2,     2,
     2,     3,     3,     7,     7,     3,     3,     5,     7,     5,
     4,     0,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     5,     5,     5,     5,     5,     5,     5,
     5,     5,     9,     3,     7,     5,     7,     0,     4,     3,
     3,     7,     3,     2,     2,     2,     3,     9,     3,     3,
     3,     3,    13,    11,     9,    11,     9,    11,    17,    23,
     9,    13,     9,     0,     4,    11,     5,     5,     7,     4,
     0,     3,    11,     7,    17,     7,     7,     5,     2,     1,
     5,     3,     3,     9,     3,     9,     3,     9,     3,     3,
     3,     3,     3,     3,     3,     3,     3,     3,     2,     5,
     7,     3,     2,     3,     3,     2,     7,     3,     3,     9,
    13,    17,    21,    25,     7,     7,     7,     7,     7,     7,
     5,     5,     7,     2,     5,     5,     2,     2,     3 };
static YYCONST yytabelem yychk[]={

-10000000,   -52,   -53,   -54,   -55,   -56,   -57,   -58,   -59,   -60,
   -61,   -62,   -63,   -64,   -65,   -66,   -67,   -68,   -69,   -70,
   -71,   -72,   -73,   -74,   -75,   -76,   -77,   -78,   -79,   -80,
   -81,   -82,   -83,   -84,   272,   284,   313,   278,   305,   338,
   339,   335,   260,   275,   333,   286,   358,   355,   318,   319,
   262,   334,   -17,   282,   -11,   307,   261,   292,   -20,   354,
   328,   290,   363,   352,   362,   353,   303,   -24,   -23,   -25,
   -41,   -19,   -22,   291,   -18,  -114,   -32,   -34,   -27,   -35,
   -29,   -28,   -33,   -31,   -30,   -36,   -26,   -40,   298,   306,
   265,   311,   312,   268,   267,   300,   281,   294,   332,   263,
   -37,   -38,   -39,   -21,   283,   280,   -15,   296,   297,   295,
    -7,    -5,    -6,    -4,   257,    45,    43,    40,    -7,    -7,
    -5,   -14,    -5,   -14,    -5,   -95,   336,    -5,    -5,    -5,
   -14,   -14,   265,   356,    -5,   -10,    -5,    -9,    -9,    -5,
   329,   -10,   330,   299,   269,   271,   302,   258,   -42,   -44,
   -46,   -45,   258,   270,   -97,  -100,   -98,  -101,  -102,  -103,
  -104,  -105,  -106,  -107,  -108,  -109,  -110,  -111,   321,   322,
   325,   326,   357,   323,   324,   359,   327,   331,   329,    -1,
   258,   259,   258,  -117,   -14,   258,   -14,    -5,    -5,    -5,
    -5,   -85,   -86,   -42,   258,   -87,   -43,   -42,   -43,   -43,
   -43,   -43,   -43,   -43,   -43,   -42,    -1,   258,   -43,   -43,
   -43,   -14,   -86,    -5,   257,   257,    -3,   257,   258,   -51,
    40,    45,    43,    -5,   -14,   -14,    -5,   -96,   337,   288,
   289,    -5,    -5,    -5,    -5,   321,    -7,    -7,    -7,    -5,
    -7,   -42,   -98,   -98,   -99,    -9,    -9,    -9,    -5,    -9,
    -5,    -5,    -5,    -5,    -5,   -20,  -118,   -16,   287,   276,
   277,  -117,    -2,    -6,    -4,   -89,   315,   -94,   -50,   304,
   309,   301,   310,   258,   -88,   314,   -76,   -73,   -74,   -77,
    -7,    -5,    -7,    -7,    -7,    -5,    -5,  -112,    -1,    -5,
    -5,    -5,   -14,    -5,    41,    43,    45,    42,    47,    37,
    94,    40,    -3,    -3,    -3,   -14,    -5,   -14,    -1,    -5,
    -5,    -7,    -7,    -7,   -99,   -99,   -98,    -9,    -9,    -9,
    -5,   -12,   316,   264,   266,   285,   273,   274,   317,   279,
   320,   293,   -90,   340,   360,   361,   -91,   346,    -2,    -2,
    -2,    -2,    -7,    -7,    -7,    -7,    -7,    -7,    -7,  -113,
    -7,    -7,    -5,  -115,   -14,    -3,    -3,    -3,    -3,    -3,
    -3,    -3,    41,   -14,    -5,    -1,   -14,    -5,    -5,    -9,
    -9,    -5,   -86,   -42,    -5,    -5,    -1,    -5,    -5,    -5,
    -5,    -5,   -42,    -5,    -1,   -92,    -1,    -2,    -2,    -2,
    -2,    -7,    -8,    -5,    -7,    -5,    -7,    -7,  -116,    -5,
    41,    44,    -7,    -5,    -5,    -7,   -42,    -5,    -5,    -5,
    -5,    -5,    -5,    -5,   -93,   348,   351,   349,   350,   347,
   -47,   341,    -2,    -2,    -2,    -2,    -7,    -7,    -5,    -7,
    -7,    -5,    -3,   -14,    -5,    -5,    -5,    -5,    -5,    -5,
    -5,    -5,    -5,    -5,   -13,   321,   322,   357,   325,   323,
   324,   326,   266,   327,    -5,   -42,    -5,   -48,   342,   343,
   344,   345,    -2,    -2,    -7,    -7,    -5,    41,    44,   329,
   -14,    -5,    -5,   -14,   -14,   -49,   -47,    -5,    -5,    -5,
    -7,    -7,    -7,    -2,    -7,    -8,    -5,    -3,    -9,   -14,
   -14,    -5,    -5,   -14,    -7,    -7,    -7,    -2,    -7,    -5,
    41,    44,    -9,    -5,    -5,    -5,    -5,    -7,    -7,    -7,
    -2,    -7,    -3,    -1,    -5,    -5,    -2,    -8,    41,    44,
    -5,    -2,    -3,    -2,    41,    -2,    -2 };
static YYCONST yytabelem yydef[]={

     1,    -2,     2,     3,     4,     5,     6,     7,     8,     9,
    10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
    20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
    30,    31,    32,    33,     0,     0,     0,     0,     0,     0,
     0,   125,     0,     0,     0,     0,     0,     0,     0,     0,
     0,   133,   134,     0,     0,     0,     0,     0,    34,     0,
   220,     0,     0,     0,     0,     0,     0,    61,    92,    37,
    38,    39,    40,     0,    41,   190,    42,    43,    44,    45,
    46,    47,    48,    49,    50,    51,    52,    55,   147,   147,
   147,   147,   147,   147,   147,   147,     0,   147,   147,   147,
   192,   193,   194,   195,   196,     0,   198,   199,   200,   201,
    92,     0,   252,   253,   273,     0,     0,     0,   100,   101,
   103,     0,   251,     0,     0,   127,   124,   128,   129,   130,
   131,   106,   108,   110,     0,   116,   247,   248,   132,     0,
   135,   144,     0,     0,     0,     0,     0,   159,   145,   148,
   149,   150,    -2,    -2,     0,     0,   161,   162,   163,   164,
   165,   166,   167,   168,   169,   170,   171,   172,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,   183,   216,
   276,   277,     0,   217,   220,     0,   112,   111,   114,   113,
   249,    35,    36,     0,    -2,     0,     0,   146,     0,     0,
     0,     0,     0,     0,   187,     0,   185,    -2,     0,     0,
     0,     0,    99,     0,   274,   275,     0,   257,    -2,     0,
     0,     0,     0,   102,   117,     0,     0,   123,   126,   104,
   105,   107,   109,     0,     0,   136,     0,   139,   140,     0,
     0,   158,   161,   161,   157,   173,   174,   175,   178,   176,
   179,   180,   177,   181,     0,    53,   219,   221,     0,     0,
     0,   218,   250,   254,   255,    60,     0,    91,    93,     0,
     0,     0,     0,    89,    54,   191,    56,    57,    58,    59,
     0,     0,     0,     0,     0,     0,     0,   186,   184,     0,
     0,   213,     0,   226,   256,     0,     0,     0,     0,     0,
     0,     0,     0,   270,   271,     0,     0,   121,   122,   115,
   225,     0,   141,     0,   153,   154,   160,     0,     0,     0,
     0,    92,     0,     0,     0,    66,     0,     0,    71,     0,
     0,     0,    75,     0,     0,     0,    82,     0,     0,     0,
     0,     0,   210,   204,   206,     0,     0,     0,     0,   188,
   189,     0,     0,   212,   197,   265,   266,   267,   268,   269,
   272,     0,   264,   118,   119,   120,     0,   142,   182,     0,
   223,     0,    62,    63,     0,    65,    67,     0,     0,    72,
     0,     0,     0,     0,     0,    79,    80,     0,     0,     0,
     0,   207,     0,     0,   203,     0,   205,     0,   214,     0,
   259,     0,     0,     0,     0,     0,    64,     0,     0,     0,
     0,     0,     0,     0,    81,     0,     0,     0,     0,    87,
    88,     0,    94,    95,     0,     0,     0,     0,   227,   202,
   211,     0,     0,   137,   143,   222,     0,     0,     0,     0,
     0,   229,     0,    78,    83,   238,   239,   240,   241,   242,
   243,   244,   245,   246,     0,    85,     0,   230,   231,   232,
   234,   236,    96,     0,     0,     0,     0,   260,     0,   138,
     0,     0,     0,     0,     0,    76,   228,     0,    84,    86,
     0,     0,     0,     0,   208,     0,     0,     0,     0,     0,
    70,     0,     0,     0,     0,     0,     0,     0,     0,   215,
   261,     0,   224,    68,     0,    74,     0,   233,   235,   237,
     0,     0,     0,    69,    73,     0,     0,   209,   262,     0,
    77,    97,     0,     0,   263,     0,    98 };
typedef struct
#ifdef __cplusplus
	yytoktype
#endif
{
#ifdef __cplusplus
const
#endif
char *t_name; int t_val; } yytoktype;
#ifndef YYDEBUG
#	define YYDEBUG	0	/* don't allow debugging */
#endif

#if YYDEBUG

yytoktype yytoks[] =
{
	"tFLOAT",	257,
	"tSTRING",	258,
	"tFILENAME",	259,
	"tAPERTURE",	260,
	"tAPPLYSURF",	261,
	"tBACKGROUND",	262,
	"tBLOB",	263,
	"tBLOTCH",	264,
	"tBOX",	265,
	"tBUMP",	266,
	"tCONE",	267,
	"tCYL",	268,
	"tDIRECTIONAL",	269,
	"tCURSURF",	270,
	"tEXTENDED",	271,
	"tEYEP",	272,
	"tFBM",	273,
	"tFBMBUMP",	274,
	"tFOCALDIST",	275,
	"tFOG",	276,
	"tFOGDECK",	277,
	"tFOV",	278,
	"tGLOSS",	279,
	"tGRID",	280,
	"tHEIGHTFIELD",	281,
	"tLIGHT",	282,
	"tLIST",	283,
	"tLOOKP",	284,
	"tMARBLE",	285,
	"tMAXDEPTH",	286,
	"tMIST",	287,
	"tJITTER",	288,
	"tNOJITTER",	289,
	"tDEFINE",	290,
	"tOBJECT",	291,
	"tOUTFILE",	292,
	"tSKY",	293,
	"tDISC",	294,
	"tDIFFERENCE",	295,
	"tUNION",	296,
	"tINTERSECT",	297,
	"tPLANE",	298,
	"tPOINT",	299,
	"tPOLY",	300,
	"tROTATE",	301,
	"tSPOT",	302,
	"tPRINT",	303,
	"tSCALE",	304,
	"tSCREEN",	305,
	"tSPHERE",	306,
	"tSURFACE",	307,
	"tTHRESH",	308,
	"tTRANSLATE",	309,
	"tTRANSFORM",	310,
	"tTRIANGLE",	311,
	"tTRIANGLEUV",	312,
	"tUP",	313,
	"tEND",	314,
	"tTEXTURE",	315,
	"tCHECKER",	316,
	"tWOOD",	317,
	"tCONTRAST",	318,
	"tCUTOFF",	319,
	"tCLOUD",	320,
	"tAMBIENT",	321,
	"tDIFFUSE",	322,
	"tREFLECT",	323,
	"tTRANSP",	324,
	"tSPECULAR",	325,
	"tSPECPOW",	326,
	"tINDEX",	327,
	"tATMOSPHERE",	328,
	"tNOSHADOW",	329,
	"tAREA",	330,
	"tTRANSLU",	331,
	"tTORUS",	332,
	"tEYESEP",	333,
	"tSHADOWTRANSP",	334,
	"tREPORT",	335,
	"tVERBOSE",	336,
	"tQUIET",	337,
	"tWINDOW",	338,
	"tCROP",	339,
	"tSTRIPE",	340,
	"tMAP",	341,
	"tUV",	342,
	"tSPHERICAL",	343,
	"tCYLINDRICAL",	344,
	"tPLANAR",	345,
	"tIMAGE",	346,
	"tSMOOTH",	347,
	"tCOMPONENT",	348,
	"tTEXTSURF",	349,
	"tRANGE",	350,
	"tTILE",	351,
	"tSTARTTIME",	352,
	"tFRAMELENGTH",	353,
	"tNAME",	354,
	"tFILTER",	355,
	"tGAUSS",	356,
	"tBODY",	357,
	"tSAMPLE",	358,
	"tEXTINCT",	359,
	"tWINDY",	360,
	"tMOUNT",	361,
	"tSHUTTER",	362,
	"tFRAMES",	363,
	"+",	43,
	"-",	45,
	"*",	42,
	"/",	47,
	"%",	37,
	"UMINUS",	364,
	"^",	94,
	"-unknown-",	-1	/* ends search */
};

#ifdef __cplusplus
const
#endif
char * yyreds[] =
{
	"-no such reduction-",
	"Items : /* empty */",
	"Items : Items Item",
	"Item : Eyep",
	"Item : Lookp",
	"Item : Up",
	"Item : Fov",
	"Item : Screen",
	"Item : Window",
	"Item : Crop",
	"Item : Report",
	"Item : Aperture",
	"Item : Focaldist",
	"Item : Eyesep",
	"Item : Maxdepth",
	"Item : Sample",
	"Item : Filter",
	"Item : Contrast",
	"Item : Cutoff",
	"Item : Background",
	"Item : Shadowtransp",
	"Item : Light",
	"Item : SurfDef",
	"Item : CurSurf",
	"Item : Outfile",
	"Item : Instance",
	"Item : NameObject",
	"Item : GlobalEffects",
	"Item : Define",
	"Item : Frames",
	"Item : Starttime",
	"Item : Shutter",
	"Item : Framelength",
	"Item : Print",
	"Instance : TransTextObj",
	"TransTextObj : TransObj Textures",
	"TransObj : Object Transforms",
	"Object : ObjType",
	"Object : NamedObject",
	"ObjType : Primitive",
	"ObjType : Aggregate",
	"Primitive : PrimType",
	"PrimType : Plane",
	"PrimType : Sphere",
	"PrimType : Box",
	"PrimType : Triangle",
	"PrimType : Cylinder",
	"PrimType : Cone",
	"PrimType : Poly",
	"PrimType : HeightField",
	"PrimType : Disc",
	"PrimType : Torus",
	"PrimType : Blob",
	"NameObject : tNAME tSTRING TransTextObj",
	"Aggdefs : Aggdefs Aggdef",
	"Aggdefs : /* empty */",
	"Aggdef : Instance",
	"Aggdef : SurfDef",
	"Aggdef : CurSurf",
	"Aggdef : NameObject",
	"Textures : Textures Texture",
	"Textures : /* empty */",
	"Texture : tTEXTURE Texturetype Transforms",
	"Texturetype : tCHECKER Surface",
	"Texturetype : tBLOTCH Expr Surface",
	"Texturetype : tBUMP Expr",
	"Texturetype : tMARBLE",
	"Texturetype : tMARBLE Filename",
	"Texturetype : tFBM Expr Expr Expr Expr IExpr Expr",
	"Texturetype : tFBM Expr Expr Expr Expr IExpr Expr Filename",
	"Texturetype : tFBMBUMP Expr Expr Expr Expr IExpr",
	"Texturetype : tWOOD",
	"Texturetype : tGLOSS Expr",
	"Texturetype : tCLOUD Expr Expr Expr IExpr Expr Expr Expr",
	"Texturetype : tSKY Expr Expr Expr IExpr Expr Expr",
	"Texturetype : ImageText",
	"Texturetype : tSTRIPE Surface Expr Expr OptMapping",
	"Texturetype : tWINDY Expr Expr Expr Expr IExpr Expr Expr Expr",
	"Texturetype : tMOUNT Filename Expr Expr",
	"ImageText : ImageTextType ImageTextOptions",
	"ImageTextType : tIMAGE Filename",
	"ImageTextOptions : ImageTextOptions ImageTextOption",
	"ImageTextOptions : /* empty */",
	"ImageTextOption : tCOMPONENT SurfCompName",
	"ImageTextOption : tTILE Expr Expr",
	"ImageTextOption : tTEXTSURF Surface",
	"ImageTextOption : tRANGE Expr Expr",
	"ImageTextOption : tSMOOTH",
	"ImageTextOption : Mapping",
	"NamedObject : tOBJECT Surface tSTRING",
	"NamedObject : tOBJECT tSTRING",
	"Transforms : Transforms PostTransform",
	"Transforms : /* empty */",
	"PostTransform : TransformType",
	"TransformType : tSCALE AnimExpr AnimExpr AnimExpr",
	"TransformType : tTRANSLATE AnimExpr AnimExpr AnimExpr",
	"TransformType : tROTATE AnimExpr AnimExpr AnimExpr AnimExpr",
	"TransformType : tTRANSFORM AnimExpr AnimExpr AnimExpr AnimExpr AnimExpr AnimExpr AnimExpr AnimExpr AnimExpr",
	"TransformType : tTRANSFORM AnimExpr AnimExpr AnimExpr AnimExpr AnimExpr AnimExpr AnimExpr AnimExpr AnimExpr AnimExpr AnimExpr AnimExpr",
	"Eyep : tEYEP Vector Transforms",
	"Lookp : tLOOKP Vector",
	"Up : tUP Vector",
	"Fov : tFOV Expr Expr",
	"Fov : tFOV Expr",
	"Sample : tSAMPLE IExpr tJITTER",
	"Sample : tSAMPLE IExpr tNOJITTER",
	"Sample : tSAMPLE IExpr",
	"Filter : tFILTER tBOX Expr",
	"Filter : tFILTER tBOX",
	"Filter : tFILTER tGAUSS Expr",
	"Filter : tFILTER tGAUSS",
	"Starttime : tSTARTTIME Expr",
	"Frames : tFRAMES IExpr",
	"Framelength : tFRAMELENGTH Expr",
	"Shutter : tSHUTTER Expr",
	"Contrast : tCONTRAST Expr Expr Expr",
	"Cutoff : tCUTOFF Intensity",
	"Screen : tSCREEN IExpr IExpr",
	"Window : tWINDOW IExpr IExpr IExpr IExpr",
	"Crop : tCROP Expr Expr Expr Expr",
	"Report : tREPORT Verbose Quiet IExpr Filename",
	"Report : tREPORT Verbose Quiet IExpr",
	"Report : tREPORT Verbose Quiet Filename",
	"Report : tREPORT Verbose Quiet",
	"Verbose : tVERBOSE",
	"Verbose : /* empty */",
	"Quiet : tQUIET",
	"Quiet : /* empty */",
	"Aperture : tAPERTURE Expr",
	"Focaldist : tFOCALDIST Expr",
	"Eyesep : tEYESEP Expr",
	"Maxdepth : tMAXDEPTH IExpr",
	"Background : tBACKGROUND Color",
	"Shadowtransp : tSHADOWTRANSP",
	"Light : LightType",
	"Light : LightType tNOSHADOW",
	"Light : tLIGHT Intensity tAMBIENT",
	"Light : Lightdef tAREA Vector Vector IExpr Vector IExpr",
	"Light : Lightdef tAREA Vector Vector IExpr Vector IExpr tNOSHADOW",
	"LightType : Lightdef tPOINT Vector",
	"LightType : Lightdef tDIRECTIONAL Vector",
	"LightType : Lightdef tEXTENDED Expr Vector",
	"LightType : Lightdef tSPOT Vector Vector Expr",
	"LightType : Lightdef tSPOT Vector Vector Expr Expr Expr",
	"Lightdef : tLIGHT Intensity",
	"CurSurf : tAPPLYSURF Surface",
	"OptSurface : Surface",
	"OptSurface : /* empty */",
	"Surface : NamedSurf",
	"Surface : ModifyNamedSurf",
	"Surface : SurfSpec",
	"NamedSurf : tSTRING",
	"NamedSurf : tCURSURF",
	"ModifyNamedSurf : CopyNamedSurf SurfComponent SurfComponents",
	"ModifyNamedSurf : CopyCurSurf SurfComponent SurfComponents",
	"CopyNamedSurf : tSTRING",
	"CopyCurSurf : tCURSURF",
	"SurfSpec : SurfComponent SurfComponents",
	"SurfDef : tSURFACE tSTRING Surface",
	"SurfDef : tSURFACE tSTRING",
	"SurfComponents : SurfComponents SurfComponent",
	"SurfComponents : /* empty */",
	"SurfComponent : Ambient",
	"SurfComponent : Diffuse",
	"SurfComponent : Specular",
	"SurfComponent : Specpow",
	"SurfComponent : Body",
	"SurfComponent : Reflect",
	"SurfComponent : Transp",
	"SurfComponent : Extinct",
	"SurfComponent : Index",
	"SurfComponent : Translu",
	"SurfComponent : Noshadow",
	"Ambient : tAMBIENT Color",
	"Diffuse : tDIFFUSE Color",
	"Specular : tSPECULAR Color",
	"Body : tBODY Color",
	"Extinct : tEXTINCT Expr",
	"Specpow : tSPECPOW Expr",
	"Reflect : tREFLECT Expr",
	"Transp : tTRANSP Expr",
	"Index : tINDEX Expr",
	"Translu : tTRANSLU Expr Color Expr",
	"Noshadow : tNOSHADOW",
	"HeightField : tHEIGHTFIELD Surface Filename",
	"HeightField : tHEIGHTFIELD Filename",
	"Poly : tPOLY OptSurface Polypoints",
	"Polypoints : /* empty */",
	"Polypoints : Polypoints Polypoint",
	"Polypoint : Vector",
	"Aggregate : AggregateDef",
	"AggregateDef : AggregateCreate Aggdefs tEND",
	"AggregateCreate : AggregateType",
	"AggregateType : List",
	"AggregateType : Grid",
	"AggregateType : Csg",
	"List : tLIST",
	"Grid : tGRID IExpr IExpr IExpr",
	"Csg : CombineOp",
	"CombineOp : tUNION",
	"CombineOp : tINTERSECT",
	"CombineOp : tDIFFERENCE",
	"Cone : tCONE OptSurface Expr Vector Expr Vector",
	"Cylinder : tCYL OptSurface Expr Vector Vector",
	"Sphere : tSPHERE OptSurface Expr Vector",
	"Disc : tDISC OptSurface Expr Vector Vector",
	"Box : tBOX OptSurface Vector Vector",
	"Triangle : tTRIANGLE OptSurface Vector Vector Vector",
	"Triangle : tTRIANGLE OptSurface Vector Vector Vector Vector Vector Vector",
	"Triangle : tTRIANGLEUV OptSurface Vector Vector Vec2d Vector Vector Vec2d Vector Vector Vec2d",
	"Plane : tPLANE OptSurface Vector Vector",
	"Torus : tTORUS OptSurface Expr Expr Vector Vector",
	"Blob : tBLOB OptSurface Expr MetaPoints",
	"MetaPoints : /* empty */",
	"MetaPoints : MetaPoints MetaPoint",
	"MetaPoint : Expr Expr Expr Expr Expr",
	"Outfile : tOUTFILE Filename",
	"GlobalEffects : tATMOSPHERE Effects",
	"GlobalEffects : tATMOSPHERE IExpr Effects",
	"Effects : Effects Effect",
	"Effects : /* empty */",
	"Effect : EffectType",
	"EffectType : tMIST Color Color Expr Expr",
	"EffectType : tFOG Color Color",
	"EffectType : tFOGDECK Expr Expr Vector Expr IExpr Color Color",
	"Color : Expr Expr Expr",
	"Vector : Expr Expr Expr",
	"Vec2d : Expr Expr",
	"OptMapping : Mapping",
	"OptMapping : /* empty */",
	"Mapping : tMAP MapMethod",
	"MapMethod : tUV",
	"MapMethod : tSPHERICAL",
	"MapMethod : tSPHERICAL Vector Vector Vector",
	"MapMethod : tCYLINDRICAL",
	"MapMethod : tCYLINDRICAL Vector Vector Vector",
	"MapMethod : tPLANAR",
	"MapMethod : tPLANAR Vector Vector Vector",
	"SurfCompName : tAMBIENT",
	"SurfCompName : tDIFFUSE",
	"SurfCompName : tBODY",
	"SurfCompName : tSPECULAR",
	"SurfCompName : tREFLECT",
	"SurfCompName : tTRANSP",
	"SurfCompName : tSPECPOW",
	"SurfCompName : tBUMP",
	"SurfCompName : tINDEX",
	"Intensity : Expr",
	"Intensity : Color",
	"Print : tPRINT Expr",
	"Define : tDEFINE tSTRING AnimExpr",
	"IExpr : Expr",
	"Expr : Float",
	"Expr : ParenExpr",
	"AnimExpr : Float",
	"AnimExpr : ParenExpr",
	"ParenExpr : '(' MExpr ')'",
	"MExpr : tFLOAT",
	"MExpr : tSTRING",
	"MExpr : Symtabent '(' MExpr ')'",
	"MExpr : Symtabent '(' MExpr ',' MExpr ')'",
	"MExpr : Symtabent '(' MExpr ',' MExpr ',' MExpr ')'",
	"MExpr : Symtabent '(' MExpr ',' MExpr ',' MExpr ',' MExpr ')'",
	"MExpr : Symtabent '(' MExpr ',' MExpr ',' MExpr ',' MExpr ',' MExpr ')'",
	"MExpr : '(' MExpr ')'",
	"MExpr : MExpr '+' MExpr",
	"MExpr : MExpr '-' MExpr",
	"MExpr : MExpr '*' MExpr",
	"MExpr : MExpr '/' MExpr",
	"MExpr : MExpr '%' MExpr",
	"MExpr : '-' MExpr",
	"MExpr : '+' MExpr",
	"MExpr : MExpr '^' MExpr",
	"Float : tFLOAT",
	"Float : '-' tFLOAT",
	"Float : '+' tFLOAT",
	"Filename : tSTRING",
	"Filename : tFILENAME",
	"Symtabent : tSTRING",
};
#endif /* YYDEBUG */
# line	1 "/usr/ccs/bin/yaccpar"
/*
 * Copyright (c) 1993 by Sun Microsystems, Inc.
 */

#pragma ident	"@(#)yaccpar	6.16	99/01/20 SMI"

/*
** Skeleton parser driver for yacc output
*/

/*
** yacc user known macros and defines
*/
#define YYERROR		goto yyerrlab
#define YYACCEPT	return(0)
#define YYABORT		return(1)
#define YYBACKUP( newtoken, newvalue )\
{\
	if ( yychar >= 0 || ( yyr2[ yytmp ] >> 1 ) != 1 )\
	{\
		yyerror( "syntax error - cannot backup" );\
		goto yyerrlab;\
	}\
	yychar = newtoken;\
	yystate = *yyps;\
	yylval = newvalue;\
	goto yynewstate;\
}
#define YYRECOVERING()	(!!yyerrflag)
#define YYNEW(type)	malloc(sizeof(type) * yynewmax)
#define YYCOPY(to, from, type) \
	(type *) memcpy(to, (char *) from, yymaxdepth * sizeof (type))
#define YYENLARGE( from, type) \
	(type *) realloc((char *) from, yynewmax * sizeof(type))
#ifndef YYDEBUG
#	define YYDEBUG	1	/* make debugging available */
#endif

/*
** user known globals
*/
int yydebug;			/* set to 1 to get debugging */

/*
** driver internal defines
*/
#define YYFLAG		(-10000000)

/*
** global variables used by the parser
*/
YYSTYPE *yypv;			/* top of value stack */
int *yyps;			/* top of state stack */

int yystate;			/* current state */
int yytmp;			/* extra var (lasts between blocks) */

int yynerrs;			/* number of errors */
int yyerrflag;			/* error recovery flag */
int yychar;			/* current input token number */



#ifdef YYNMBCHARS
#define YYLEX()		yycvtok(yylex())
/*
** yycvtok - return a token if i is a wchar_t value that exceeds 255.
**	If i<255, i itself is the token.  If i>255 but the neither 
**	of the 30th or 31st bit is on, i is already a token.
*/
#if defined(__STDC__) || defined(__cplusplus)
int yycvtok(int i)
#else
int yycvtok(i) int i;
#endif
{
	int first = 0;
	int last = YYNMBCHARS - 1;
	int mid;
	wchar_t j;

	if(i&0x60000000){/*Must convert to a token. */
		if( yymbchars[last].character < i ){
			return i;/*Giving up*/
		}
		while ((last>=first)&&(first>=0)) {/*Binary search loop*/
			mid = (first+last)/2;
			j = yymbchars[mid].character;
			if( j==i ){/*Found*/ 
				return yymbchars[mid].tvalue;
			}else if( j<i ){
				first = mid + 1;
			}else{
				last = mid -1;
			}
		}
		/*No entry in the table.*/
		return i;/* Giving up.*/
	}else{/* i is already a token. */
		return i;
	}
}
#else/*!YYNMBCHARS*/
#define YYLEX()		yylex()
#endif/*!YYNMBCHARS*/

/*
** yyparse - return 0 if worked, 1 if syntax error not recovered from
*/
#if defined(__STDC__) || defined(__cplusplus)
int yyparse(void)
#else
int yyparse()
#endif
{
	register YYSTYPE *yypvt = 0;	/* top of value stack for $vars */

#if defined(__cplusplus) || defined(lint)
/*
	hacks to please C++ and lint - goto's inside
	switch should never be executed
*/
	static int __yaccpar_lint_hack__ = 0;
	switch (__yaccpar_lint_hack__)
	{
		case 1: goto yyerrlab;
		case 2: goto yynewstate;
	}
#endif

	/*
	** Initialize externals - yyparse may be called more than once
	*/
	yypv = &yyv[-1];
	yyps = &yys[-1];
	yystate = 0;
	yytmp = 0;
	yynerrs = 0;
	yyerrflag = 0;
	yychar = -1;

#if YYMAXDEPTH <= 0
	if (yymaxdepth <= 0)
	{
		if ((yymaxdepth = YYEXPAND(0)) <= 0)
		{
			yyerror("yacc initialization error");
			YYABORT;
		}
	}
#endif

	{
		register YYSTYPE *yy_pv;	/* top of value stack */
		register int *yy_ps;		/* top of state stack */
		register int yy_state;		/* current state */
		register int  yy_n;		/* internal state number info */
	goto yystack;	/* moved from 6 lines above to here to please C++ */

		/*
		** get globals into registers.
		** branch to here only if YYBACKUP was called.
		*/
	yynewstate:
		yy_pv = yypv;
		yy_ps = yyps;
		yy_state = yystate;
		goto yy_newstate;

		/*
		** get globals into registers.
		** either we just started, or we just finished a reduction
		*/
	yystack:
		yy_pv = yypv;
		yy_ps = yyps;
		yy_state = yystate;

		/*
		** top of for (;;) loop while no reductions done
		*/
	yy_stack:
		/*
		** put a state and value onto the stacks
		*/
#if YYDEBUG
		/*
		** if debugging, look up token value in list of value vs.
		** name pairs.  0 and negative (-1) are special values.
		** Note: linear search is used since time is not a real
		** consideration while debugging.
		*/
		if ( yydebug )
		{
			register int yy_i;

			printf( "State %d, token ", yy_state );
			if ( yychar == 0 )
				printf( "end-of-file\n" );
			else if ( yychar < 0 )
				printf( "-none-\n" );
			else
			{
				for ( yy_i = 0; yytoks[yy_i].t_val >= 0;
					yy_i++ )
				{
					if ( yytoks[yy_i].t_val == yychar )
						break;
				}
				printf( "%s\n", yytoks[yy_i].t_name );
			}
		}
#endif /* YYDEBUG */
		if ( ++yy_ps >= &yys[ yymaxdepth ] )	/* room on stack? */
		{
			/*
			** reallocate and recover.  Note that pointers
			** have to be reset, or bad things will happen
			*/
			long yyps_index = (yy_ps - yys);
			long yypv_index = (yy_pv - yyv);
			long yypvt_index = (yypvt - yyv);
			int yynewmax;
#ifdef YYEXPAND
			yynewmax = YYEXPAND(yymaxdepth);
#else
			yynewmax = 2 * yymaxdepth;	/* double table size */
			if (yymaxdepth == YYMAXDEPTH)	/* first time growth */
			{
				char *newyys = (char *)YYNEW(int);
				char *newyyv = (char *)YYNEW(YYSTYPE);
				if (newyys != 0 && newyyv != 0)
				{
					yys = YYCOPY(newyys, yys, int);
					yyv = YYCOPY(newyyv, yyv, YYSTYPE);
				}
				else
					yynewmax = 0;	/* failed */
			}
			else				/* not first time */
			{
				yys = YYENLARGE(yys, int);
				yyv = YYENLARGE(yyv, YYSTYPE);
				if (yys == 0 || yyv == 0)
					yynewmax = 0;	/* failed */
			}
#endif
			if (yynewmax <= yymaxdepth)	/* tables not expanded */
			{
				yyerror( "yacc stack overflow" );
				YYABORT;
			}
			yymaxdepth = yynewmax;

			yy_ps = yys + yyps_index;
			yy_pv = yyv + yypv_index;
			yypvt = yyv + yypvt_index;
		}
		*yy_ps = yy_state;
		*++yy_pv = yyval;

		/*
		** we have a new state - find out what to do
		*/
	yy_newstate:
		if ( ( yy_n = yypact[ yy_state ] ) <= YYFLAG )
			goto yydefault;		/* simple state */
#if YYDEBUG
		/*
		** if debugging, need to mark whether new token grabbed
		*/
		yytmp = yychar < 0;
#endif
		if ( ( yychar < 0 ) && ( ( yychar = YYLEX() ) < 0 ) )
			yychar = 0;		/* reached EOF */
#if YYDEBUG
		if ( yydebug && yytmp )
		{
			register int yy_i;

			printf( "Received token " );
			if ( yychar == 0 )
				printf( "end-of-file\n" );
			else if ( yychar < 0 )
				printf( "-none-\n" );
			else
			{
				for ( yy_i = 0; yytoks[yy_i].t_val >= 0;
					yy_i++ )
				{
					if ( yytoks[yy_i].t_val == yychar )
						break;
				}
				printf( "%s\n", yytoks[yy_i].t_name );
			}
		}
#endif /* YYDEBUG */
		if ( ( ( yy_n += yychar ) < 0 ) || ( yy_n >= YYLAST ) )
			goto yydefault;
		if ( yychk[ yy_n = yyact[ yy_n ] ] == yychar )	/*valid shift*/
		{
			yychar = -1;
			yyval = yylval;
			yy_state = yy_n;
			if ( yyerrflag > 0 )
				yyerrflag--;
			goto yy_stack;
		}

	yydefault:
		if ( ( yy_n = yydef[ yy_state ] ) == -2 )
		{
#if YYDEBUG
			yytmp = yychar < 0;
#endif
			if ( ( yychar < 0 ) && ( ( yychar = YYLEX() ) < 0 ) )
				yychar = 0;		/* reached EOF */
#if YYDEBUG
			if ( yydebug && yytmp )
			{
				register int yy_i;

				printf( "Received token " );
				if ( yychar == 0 )
					printf( "end-of-file\n" );
				else if ( yychar < 0 )
					printf( "-none-\n" );
				else
				{
					for ( yy_i = 0;
						yytoks[yy_i].t_val >= 0;
						yy_i++ )
					{
						if ( yytoks[yy_i].t_val
							== yychar )
						{
							break;
						}
					}
					printf( "%s\n", yytoks[yy_i].t_name );
				}
			}
#endif /* YYDEBUG */
			/*
			** look through exception table
			*/
			{
				register YYCONST int *yyxi = yyexca;

				while ( ( *yyxi != -1 ) ||
					( yyxi[1] != yy_state ) )
				{
					yyxi += 2;
				}
				while ( ( *(yyxi += 2) >= 0 ) &&
					( *yyxi != yychar ) )
					;
				if ( ( yy_n = yyxi[1] ) < 0 )
					YYACCEPT;
			}
		}

		/*
		** check for syntax error
		*/
		if ( yy_n == 0 )	/* have an error */
		{
			/* no worry about speed here! */
			switch ( yyerrflag )
			{
			case 0:		/* new error */
				yyerror( "syntax error" );
				goto skip_init;
			yyerrlab:
				/*
				** get globals into registers.
				** we have a user generated syntax type error
				*/
				yy_pv = yypv;
				yy_ps = yyps;
				yy_state = yystate;
			skip_init:
				yynerrs++;
				/* FALLTHRU */
			case 1:
			case 2:		/* incompletely recovered error */
					/* try again... */
				yyerrflag = 3;
				/*
				** find state where "error" is a legal
				** shift action
				*/
				while ( yy_ps >= yys )
				{
					yy_n = yypact[ *yy_ps ] + YYERRCODE;
					if ( yy_n >= 0 && yy_n < YYLAST &&
						yychk[yyact[yy_n]] == YYERRCODE)					{
						/*
						** simulate shift of "error"
						*/
						yy_state = yyact[ yy_n ];
						goto yy_stack;
					}
					/*
					** current state has no shift on
					** "error", pop stack
					*/
#if YYDEBUG
#	define _POP_ "Error recovery pops state %d, uncovers state %d\n"
					if ( yydebug )
						printf( _POP_, *yy_ps,
							yy_ps[-1] );
#	undef _POP_
#endif
					yy_ps--;
					yy_pv--;
				}
				/*
				** there is no state on stack with "error" as
				** a valid shift.  give up.
				*/
				YYABORT;
			case 3:		/* no shift yet; eat a token */
#if YYDEBUG
				/*
				** if debugging, look up token in list of
				** pairs.  0 and negative shouldn't occur,
				** but since timing doesn't matter when
				** debugging, it doesn't hurt to leave the
				** tests here.
				*/
				if ( yydebug )
				{
					register int yy_i;

					printf( "Error recovery discards " );
					if ( yychar == 0 )
						printf( "token end-of-file\n" );
					else if ( yychar < 0 )
						printf( "token -none-\n" );
					else
					{
						for ( yy_i = 0;
							yytoks[yy_i].t_val >= 0;
							yy_i++ )
						{
							if ( yytoks[yy_i].t_val
								== yychar )
							{
								break;
							}
						}
						printf( "token %s\n",
							yytoks[yy_i].t_name );
					}
				}
#endif /* YYDEBUG */
				if ( yychar == 0 )	/* reached EOF. quit */
					YYABORT;
				yychar = -1;
				goto yy_newstate;
			}
		}/* end if ( yy_n == 0 ) */
		/*
		** reduction by production yy_n
		** put stack tops, etc. so things right after switch
		*/
#if YYDEBUG
		/*
		** if debugging, print the string that is the user's
		** specification of the reduction which is just about
		** to be done.
		*/
		if ( yydebug )
			printf( "Reduce by (%d) \"%s\"\n",
				yy_n, yyreds[ yy_n ] );
#endif
		yytmp = yy_n;			/* value to switch over */
		yypvt = yy_pv;			/* $vars top of value stack */
		/*
		** Look in goto table for next state
		** Sorry about using yy_state here as temporary
		** register variable, but why not, if it works...
		** If yyr2[ yy_n ] doesn't have the low order bit
		** set, then there is no action to be done for
		** this reduction.  So, no saving & unsaving of
		** registers done.  The only difference between the
		** code just after the if and the body of the if is
		** the goto yy_stack in the body.  This way the test
		** can be made before the choice of what to do is needed.
		*/
		{
			/* length of production doubled with extra bit */
			register int yy_len = yyr2[ yy_n ];

			if ( !( yy_len & 01 ) )
			{
				yy_len >>= 1;
				yyval = ( yy_pv -= yy_len )[1];	/* $$ = $1 */
				yy_state = yypgo[ yy_n = yyr1[ yy_n ] ] +
					*( yy_ps -= yy_len ) + 1;
				if ( yy_state >= YYLAST ||
					yychk[ yy_state =
					yyact[ yy_state ] ] != -yy_n )
				{
					yy_state = yyact[ yypgo[ yy_n ] ];
				}
				goto yy_stack;
			}
			yy_len >>= 1;
			yyval = ( yy_pv -= yy_len )[1];	/* $$ = $1 */
			yy_state = yypgo[ yy_n = yyr1[ yy_n ] ] +
				*( yy_ps -= yy_len ) + 1;
			if ( yy_state >= YYLAST ||
				yychk[ yy_state = yyact[ yy_state ] ] != -yy_n )
			{
				yy_state = yyact[ yypgo[ yy_n ] ];
			}
		}
					/* save until reenter driver code */
		yystate = yy_state;
		yyps = yy_ps;
		yypv = yy_pv;
	}
	/*
	** code supplied by user is placed in this switch
	*/
	switch( yytmp )
	{
		
case 34:
# line 197 "yacc.y"
{
			if (yypvt[-0].obj) {
				/*
				 * Add instance to current object.
				 */
				yypvt[-0].obj->next = Defstack->obj->next;
				Defstack->obj->next = yypvt[-0].obj;
			}
		} break;
case 35:
# line 207 "yacc.y"
{
			if (yyval.obj && CurText) {
				yyval.obj->texture = TextAppend(CurText, yyval.obj->texture);
			}
			CurText = (Texture *)NULL;
		} break;
case 36:
# line 215 "yacc.y"
{
			yyval.obj = yypvt[-1].obj;
			if (yyval.obj != (Geom *)NULL) {
				if (TransHead) {
					yyval.obj->trans = TransHead;
					yyval.obj->transtail = TransTail;
					/*
					 * We compose non-animated tranformation lists,
					 * so we're only animated if it's one long,
					 * or it's animated itself.
					 */
					if (yyval.obj->trans->assoc || yyval.obj->trans->next)
						/* geometry is animated...*/
						yyval.obj->animtrans = TRUE;
				}
			}
		} break;
case 37:
# line 234 "yacc.y"
{
			if (yyval.obj)
				StatsAddRep(yyval.obj);
		} break;
case 41:
# line 244 "yacc.y"
{
			if (yyval.obj)
				yyval.obj->prims = 1;	/* one primitive */
		} break;
case 53:
# line 262 "yacc.y"
{
			if (yypvt[-0].obj) {
				yypvt[-0].obj->name = yypvt[-1].c;
				GeomAddToDefined(yypvt[-0].obj);
			}
		} break;
case 62:
# line 280 "yacc.y"
{
			if (yypvt[-1].text != (Texture *)NULL) {
				/*
				 * Set transformation information.
				 */
				if (TransHead) {
					yypvt[-1].text->trans = TransHead;
					/*
					 * We compose non-animated tranformation lists,
					 * so we're only animated if it's one long,
					 * or it's animated itself.
					 */
					if (yypvt[-1].text->trans->assoc || yypvt[-1].text->trans->next)
						/* texture transformation is animated...*/
						yypvt[-1].text->animtrans = TRUE;
				}
				/*
				 * Walk to the end of list of textures and
				 * append new texture.  This is done so that
				 * textures are applied in the expected order.
				 */
				CurText = TextAppend(yypvt[-1].text, CurText);
			}
		} break;
case 63:
# line 306 "yacc.y"
{
			yyval.text = TextCheckerCreate(yypvt[-0].surf);
		} break;
case 64:
# line 310 "yacc.y"
{
			yyval.text = TextBlotchCreate(yypvt[-1].d, yypvt[-0].surf);
		} break;
case 65:
# line 314 "yacc.y"
{
			yyval.text = TextBumpCreate(yypvt[-0].d);
		} break;
case 66:
# line 318 "yacc.y"
{
			yyval.text = TextMarbleCreate((char *)NULL);
		} break;
case 67:
# line 322 "yacc.y"
{
			yyval.text = TextMarbleCreate(yypvt[-0].c);
		} break;
case 68:
# line 326 "yacc.y"
{
			yyval.text = TextFBmCreate(yypvt[-5].d, yypvt[-4].d, yypvt[-3].d, yypvt[-2].d, yypvt[-1].i, yypvt[-0].d,
						(char *)NULL);
		} break;
case 69:
# line 331 "yacc.y"
{
			yyval.text = TextFBmCreate(yypvt[-6].d, yypvt[-5].d, yypvt[-4].d, yypvt[-3].d, yypvt[-2].i, yypvt[-1].d, yypvt[-0].c);
		} break;
case 70:
# line 335 "yacc.y"
{
			yyval.text = TextFBmBumpCreate(yypvt[-4].d, yypvt[-3].d, yypvt[-2].d, yypvt[-1].d, yypvt[-0].i);
		} break;
case 71:
# line 339 "yacc.y"
{
			yyval.text = TextWoodCreate();
		} break;
case 72:
# line 343 "yacc.y"
{
			yyval.text = TextGlossCreate(yypvt[-0].d);
		} break;
case 73:
# line 347 "yacc.y"
{
			yyval.text = TextCloudCreate(yypvt[-6].d, yypvt[-5].d, yypvt[-4].d, yypvt[-3].i, yypvt[-2].d, yypvt[-1].d, yypvt[-0].d);
		} break;
case 74:
# line 351 "yacc.y"
{
			yyval.text = TextSkyCreate(yypvt[-5].d, yypvt[-4].d, yypvt[-3].d, yypvt[-2].i, yypvt[-1].d, yypvt[-0].d);
		} break;
case 75:
# line 355 "yacc.y"
{
			/*
			 * Image texturing has so many options
			 * that specification is keyword-based.
			 */
			if (Imagetext->image == (Image *)NULL)
				yyval.text = (Texture *)NULL;
			else
				yyval.text = TextCreate(Imagetext, ImageTextApply);
			Imagetext = (ImageText *)NULL;
		} break;
case 76:
# line 367 "yacc.y"
{
			yyval.text = TextStripeCreate(yypvt[-3].surf, yypvt[-2].d, yypvt[-1].d, yypvt[-0].map);
		} break;
case 77:
# line 371 "yacc.y"
{
			yyval.text = TextWindyCreate(yypvt[-7].d, yypvt[-6].d, yypvt[-5].d, yypvt[-4].d, yypvt[-3].i, yypvt[-2].d, yypvt[-1].d, yypvt[-0].d);
		} break;
case 78:
# line 375 "yacc.y"
{
			yyval.text = TextMountCreate(yypvt[-2].c, yypvt[-1].d, yypvt[-0].d);
		} break;
case 80:
# line 382 "yacc.y"
{
			Imagetext = ImageTextCreate(yypvt[-0].c);
		} break;
case 83:
# line 390 "yacc.y"
{
			/* set texture to modify given component */	
			ImageTextSetComponent(Imagetext, yypvt[-0].i);
		} break;
case 84:
# line 395 "yacc.y"
{
			Imagetext->tileu = yypvt[-1].d;
			Imagetext->tilev = yypvt[-0].d;
		} break;
case 85:
# line 400 "yacc.y"
{
			Imagetext->surf = yypvt[-0].surf;
		} break;
case 86:
# line 404 "yacc.y"
{
			Imagetext->hi = yypvt[-1].d;
			Imagetext->lo = yypvt[-0].d;
		} break;
case 87:
# line 409 "yacc.y"
{
			Imagetext->smooth = TRUE;
		} break;
case 88:
# line 413 "yacc.y"
{
			Imagetext->mapping = yypvt[-0].map;
		} break;
case 89:
# line 417 "yacc.y"
{
			Geom *otmp;
			/*
			 * Create an instance of the named object.
			 */
			otmp = GeomGetNamed(yypvt[-0].c);
			if (otmp == (Geom *)NULL)
				RLerror(RL_PANIC,
				  "There is no object named \"%s\".", yypvt[-0].c);
			yyval.obj = GeomInstanceCreate(otmp);
			yyval.obj->surf = yypvt[-1].surf;
			yyval.obj->prims = otmp->prims;
		} break;
case 90:
# line 431 "yacc.y"
{
			Geom *otmp;

			otmp = GeomGetNamed(yypvt[-0].c);
			if (otmp == (Geom *)NULL)
				RLerror(RL_PANIC,
				  "There is no object named \"%s\".", yypvt[-0].c);
			yyval.obj = GeomInstanceCreate(otmp);
			yyval.obj->surf = CurSurf->surf;
			yyval.obj->prims = otmp->prims;
		} break;
case 92:
# line 444 "yacc.y"
{
			TransHead = TransTail = (Trans *)NULL;
		} break;
case 93:
# line 448 "yacc.y"
{
			if (TransHead == (Trans *)NULL) {
				/* we're the list, head and tail */
				TransHead = TransTail = yypvt[-0].trans;
			} else {
				if (yypvt[-0].trans->animated || TransTail->animated) {
					/* new tail */
					yypvt[-0].trans->prev = TransTail;
					TransTail->next = yypvt[-0].trans;
					TransTail = yypvt[-0].trans;
				} else {
					/* collapse with tail */
					TransCompose(TransTail, yypvt[-0].trans, TransTail);
					TransFree(yypvt[-0].trans);
				}
			}
		} break;
case 94:
# line 467 "yacc.y"
{
			yyval.trans = TransScaleCreate();
			TransScaleSetX(yyval.trans, yypvt[-2].e);
			TransScaleSetY(yyval.trans, yypvt[-1].e);
			TransScaleSetZ(yyval.trans, yypvt[-0].e);
			if (!yyval.trans->animated)
				TransPropagate(yyval.trans);
				
		} break;
case 95:
# line 477 "yacc.y"
{
			yyval.trans = TransTranslateCreate();
			TransTranslateSetX(yyval.trans, yypvt[-2].e);
			TransTranslateSetY(yyval.trans, yypvt[-1].e);
			TransTranslateSetZ(yyval.trans, yypvt[-0].e);
			if (!yyval.trans->animated)
				TransPropagate(yyval.trans);
		} break;
case 96:
# line 486 "yacc.y"
{
			yyval.trans = TransRotateCreate();
			TransRotateSetX(yyval.trans, yypvt[-3].e);
			TransRotateSetY(yyval.trans, yypvt[-2].e);
			TransRotateSetZ(yyval.trans, yypvt[-1].e);
			TransRotateSetTheta(yyval.trans, yypvt[-0].e);
			if (!yyval.trans->animated)
				TransPropagate(yyval.trans);
		} break;
case 97:
# line 498 "yacc.y"
{
			yyval.trans = TransXformCreate();
			TransXformSetX0(yyval.trans, yypvt[-8].e);
			TransXformSetY0(yyval.trans, yypvt[-7].e);
			TransXformSetZ0(yyval.trans, yypvt[-6].e);
			TransXformSetX1(yyval.trans, yypvt[-5].e);
			TransXformSetY1(yyval.trans, yypvt[-4].e);
			TransXformSetZ1(yyval.trans, yypvt[-3].e);
			TransXformSetX2(yyval.trans, yypvt[-2].e);
			TransXformSetY2(yyval.trans, yypvt[-1].e);
			TransXformSetZ2(yyval.trans, yypvt[-0].e);
			if (!yyval.trans->animated)
				TransPropagate(yyval.trans);
		} break;
case 98:
# line 516 "yacc.y"
{
			yyval.trans = TransXformCreate();
			TransXformSetX0(yyval.trans, yypvt[-11].e);
			TransXformSetY0(yyval.trans, yypvt[-10].e);
			TransXformSetZ0(yyval.trans, yypvt[-9].e);
			TransXformSetX1(yyval.trans, yypvt[-8].e);
			TransXformSetY1(yyval.trans, yypvt[-7].e);
			TransXformSetZ1(yyval.trans, yypvt[-6].e);
			TransXformSetX2(yyval.trans, yypvt[-5].e);
			TransXformSetY2(yyval.trans, yypvt[-4].e);
			TransXformSetZ2(yyval.trans, yypvt[-3].e);
			TransXformSetXt(yyval.trans, yypvt[-2].e);
			TransXformSetYt(yyval.trans, yypvt[-1].e);
			TransXformSetZt(yyval.trans, yypvt[-0].e);
			if (!yyval.trans->animated)
				TransPropagate(yyval.trans);
		} break;
case 99:
# line 534 "yacc.y"
{
			Camera.pos = yypvt[-1].v;
			/*
			 * Eye can be transformed...
			if (CurMatrix) {
				PointTransform(&Camera.pos, CurMatrix);
				free((voidstar)CurMatrix);
				CurMatrix = (Matrix*)NULL;
			}
			 */
		} break;
case 100:
# line 547 "yacc.y"
{
			Camera.lookp = yypvt[-0].v;
		} break;
case 101:
# line 552 "yacc.y"
{
			Camera.up = yypvt[-0].v;
		} break;
case 102:
# line 557 "yacc.y"
{
			Camera.hfov = yypvt[-1].d;
			Camera.vfov = yypvt[-0].d;
		} break;
case 103:
# line 562 "yacc.y"
{
			Camera.hfov = yypvt[-0].d;
			Camera.vfov = UNSET;
		} break;
case 104:
# line 568 "yacc.y"
{
			if (!Options.samples_set)
				Options.samples = yypvt[-1].i;
			if (!Options.jitter_set)
				Options.jitter = TRUE;
		} break;
case 105:
# line 575 "yacc.y"
{
			if (!Options.samples_set)
				Options.samples = yypvt[-1].i;
			if (!Options.jitter_set)
				Options.jitter = FALSE;
		} break;
case 106:
# line 582 "yacc.y"
{
			if (!Options.samples_set)
				Options.samples = yypvt[-0].i;
		} break;
case 107:
# line 588 "yacc.y"
{
			Options.gaussian = FALSE;
			Options.filterwidth = yypvt[-0].d;
		} break;
case 108:
# line 593 "yacc.y"
{
			Options.gaussian = FALSE;
		} break;
case 109:
# line 597 "yacc.y"
{
			Options.gaussian = TRUE;
			Options.filterwidth = yypvt[-0].d;
		} break;
case 110:
# line 602 "yacc.y"
{
			Options.gaussian = TRUE;
		} break;
case 111:
# line 606 "yacc.y"
{
			Options.starttime = yypvt[-0].d;
		} break;
case 112:
# line 610 "yacc.y"
{
			if (!Options.totalframes_set)
				Options.totalframes = yypvt[-0].i;
		} break;
case 113:
# line 615 "yacc.y"
{
			Options.framelength = yypvt[-0].d;
		} break;
case 114:
# line 619 "yacc.y"
{
			Options.shutterspeed = yypvt[-0].d;
		} break;
case 115:
# line 623 "yacc.y"
{
			if (!Options.contrast_set) {
				Options.contrast.r = yypvt[-2].d;
				Options.contrast.g = yypvt[-1].d;
				Options.contrast.b = yypvt[-0].d;
			}
		} break;
case 116:
# line 632 "yacc.y"
{
			if (!Options.cutoff_set)
				Options.cutoff = yypvt[-0].col;
		} break;
case 117:
# line 638 "yacc.y"
{
			if (!Options.resolution_set) {
				Screen.xres = yypvt[-1].i;
				Screen.yres = yypvt[-0].i;
			}
		} break;
case 118:
# line 646 "yacc.y"
{
			if (!Options.window_set) {
				Options.window[LOW][X] = yypvt[-3].i;
				Options.window[HIGH][X] = yypvt[-2].i;
				Options.window[LOW][Y] = yypvt[-1].i;
				Options.window[HIGH][Y] = yypvt[-0].i;
				/*
				 * We must let ViewingSetup know
				 * that a window has been defined.
				 */
				Options.window_set = TRUE;
			}
		} break;
case 119:
# line 661 "yacc.y"
{
			if (!Options.crop_set) {
				Options.crop[LOW][X] = yypvt[-3].d;
				Options.crop[HIGH][X] = yypvt[-2].d;
				Options.crop[LOW][Y] = yypvt[-1].d;
				Options.crop[HIGH][Y] = yypvt[-0].d;
			}
		} break;
case 120:
# line 671 "yacc.y"
{
			if (!Options.freq_set)
				Options.report_freq = yypvt[-1].i;
			if (Options.statsname == (char *)NULL)
				Options.statsname = strsave(yypvt[-0].c);
		} break;
case 121:
# line 678 "yacc.y"
{
			if (!Options.freq_set)
				Options.report_freq = yypvt[-0].i;
		} break;
case 122:
# line 683 "yacc.y"
{
			if (Options.statsname == (char *)NULL)
				Options.statsname = strsave(yypvt[-0].c);
		} break;
case 124:
# line 690 "yacc.y"
{ Options.verbose = TRUE; } break;
case 126:
# line 694 "yacc.y"
{ Options.quiet = TRUE; } break;
case 128:
# line 698 "yacc.y"
{
			Camera.aperture = yypvt[-0].d;
		} break;
case 129:
# line 703 "yacc.y"
{
			Camera.focaldist = yypvt[-0].d;
		} break;
case 130:
# line 708 "yacc.y"
{
			if (!Options.eyesep_set)
				Options.eyesep = yypvt[-0].d;
		} break;
case 131:
# line 714 "yacc.y"
{
			if (!Options.maxdepth_set)
				Options.maxdepth = yypvt[-0].i;
		} break;
case 132:
# line 720 "yacc.y"
{
			Screen.background = yypvt[-0].col;
		} break;
case 133:
# line 725 "yacc.y"
{
			Options.shadowtransp = !Options.shadowtransp;
		} break;
case 134:
# line 730 "yacc.y"
{
			LightAddToDefined(yypvt[-0].light);
		} break;
case 135:
# line 734 "yacc.y"
{
			yypvt[-1].light->shadow = FALSE;
			LightAddToDefined(yypvt[-1].light);
		} break;
case 136:
# line 739 "yacc.y"
{
			Options.ambient = yypvt[-1].col;
		} break;
case 137:
# line 743 "yacc.y"
{
			extern void AreaLightCreate();
			/* Area light is strange in that the
			 * Creation routine does the installation.
			 */
			AreaLightCreate(&yypvt[-6].col, &yypvt[-4].v, &yypvt[-3].v, yypvt[-2].i, &yypvt[-1].v, yypvt[-0].i, TRUE);
		} break;
case 138:
# line 751 "yacc.y"
{
			extern void AreaLightCreate();
			/* Area light is strange in that the
			 * Creation routine does the installation.
			 */
			AreaLightCreate(&yypvt[-7].col, &yypvt[-5].v, &yypvt[-4].v, yypvt[-3].i, &yypvt[-2].v, yypvt[-1].i, FALSE);
		} break;
case 139:
# line 759 "yacc.y"
{
			yyval.light = LightPointCreate(&yypvt[-2].col, &yypvt[-0].v);
		} break;
case 140:
# line 763 "yacc.y"
{
			yyval.light = LightInfiniteCreate(&yypvt[-2].col, &yypvt[-0].v);
		} break;
case 141:
# line 767 "yacc.y"
{
			yyval.light = LightExtendedCreate(&yypvt[-3].col, yypvt[-1].d, &yypvt[-0].v);
		} break;
case 142:
# line 771 "yacc.y"
{
			yyval.light = LightSpotCreate(&yypvt[-4].col, &yypvt[-2].v, &yypvt[-1].v, yypvt[-0].d, 0., 0.);
		} break;
case 143:
# line 775 "yacc.y"
{
			/* light <intens> spot from <to> coef inner_rad
					outer_rad */
			yyval.light = LightSpotCreate(&yypvt[-6].col, &yypvt[-4].v, &yypvt[-3].v, yypvt[-2].d, yypvt[-1].d, yypvt[-0].d);
		} break;
case 144:
# line 781 "yacc.y"
{
			yyval.col = yypvt[-0].col;
		} break;
case 145:
# line 786 "yacc.y"
{
			CurSurf->surf = yypvt[-0].surf;
		} break;
case 147:
# line 792 "yacc.y"
{
			yyval.surf = CurSurf->surf;
		} break;
case 151:
# line 801 "yacc.y"
{
			yyval.surf = SurfaceGetNamed(yypvt[-0].c);
			/*
			 * Free up memory allocated for surf name.
			 * We bother doing this because for large models
			 * converted from 3.0, surfnames this can account
			 * for lots o' bytes.
			 */
			free((voidstar)yypvt[-0].c);
		} break;
case 152:
# line 812 "yacc.y"
{
			extern Surface DefaultSurface;

			if (CurSurf->surf)
				yyval.surf = CurSurf->surf;
			else
				yyval.surf = &DefaultSurface;
		} break;
case 153:
# line 822 "yacc.y"
{
			yyval.surf = tmpsurf;
			tmpsurf = (Surface *)NULL;
		} break;
case 154:
# line 827 "yacc.y"
{
			yyval.surf = tmpsurf;
			tmpsurf = (Surface *)NULL;
		} break;
case 155:
# line 833 "yacc.y"
{
			tmpsurf = SurfaceCopy(SurfaceGetNamed(yypvt[-0].c));
		} break;
case 156:
# line 838 "yacc.y"
{
			extern Surface DefaultSurface;
			if (CurSurf->surf)
				tmpsurf = SurfaceCopy(CurSurf->surf);
			else
				tmpsurf = SurfaceCopy(&DefaultSurface);
		} break;
case 157:
# line 847 "yacc.y"
{
			yyval.surf = tmpsurf;
			tmpsurf = (Surface *)NULL;
		} break;
case 158:
# line 853 "yacc.y"
{
			tmpsurf = SurfaceCopy(yypvt[-0].surf);
			tmpsurf->name = strsave(yypvt[-1].c);
			SurfaceAddToDefined(tmpsurf);
			tmpsurf = (Surface *)NULL;
		} break;
case 159:
# line 860 "yacc.y"
{
			/* black surface */
			tmpsurf = SurfaceCreate();
			tmpsurf->name = strsave(yypvt[-0].c);
			SurfaceAddToDefined(tmpsurf);
			tmpsurf = (Surface *)NULL;
		} break;
case 173:
# line 884 "yacc.y"
{
			if (tmpsurf == (Surface *)NULL)
				tmpsurf = SurfaceCreate();
			tmpsurf->amb = yypvt[-0].col;
		} break;
case 174:
# line 891 "yacc.y"
{
			if (tmpsurf == (Surface *)NULL)
				tmpsurf = SurfaceCreate();
			tmpsurf->diff = yypvt[-0].col;
		} break;
case 175:
# line 898 "yacc.y"
{
			if (tmpsurf == (Surface *)NULL)
				tmpsurf = SurfaceCreate();
			tmpsurf->spec = yypvt[-0].col;
		} break;
case 176:
# line 905 "yacc.y"
{
			if (tmpsurf == (Surface *)NULL)
				tmpsurf = SurfaceCreate();
			tmpsurf->body = yypvt[-0].col;
		} break;
case 177:
# line 911 "yacc.y"
{
			if (tmpsurf == (Surface *)NULL)
				tmpsurf = SurfaceCreate();
			tmpsurf->statten = yypvt[-0].d;
		} break;
case 178:
# line 917 "yacc.y"
{
			if (tmpsurf == (Surface *)NULL)
				tmpsurf = SurfaceCreate();
			tmpsurf->srexp = yypvt[-0].d;
		} break;
case 179:
# line 924 "yacc.y"
{
			if (tmpsurf == (Surface *)NULL)
				tmpsurf = SurfaceCreate();
			tmpsurf->reflect = yypvt[-0].d;
		} break;
case 180:
# line 931 "yacc.y"
{
			if (tmpsurf == (Surface *)NULL)
				tmpsurf = SurfaceCreate();
			tmpsurf->transp = yypvt[-0].d;
		} break;
case 181:
# line 938 "yacc.y"
{
			if (tmpsurf == (Surface *)NULL)
				tmpsurf = SurfaceCreate();
			tmpsurf->index = yypvt[-0].d;
		} break;
case 182:
# line 945 "yacc.y"
{
			if (tmpsurf == (Surface *)NULL)
				tmpsurf = SurfaceCreate();
			tmpsurf->translucency = yypvt[-2].d;
			tmpsurf->translu = yypvt[-1].col;
			tmpsurf->stexp = yypvt[-0].d;
		} break;
case 183:
# line 954 "yacc.y"
{
			if (tmpsurf == (Surface *)NULL)
				tmpsurf = SurfaceCreate();
			tmpsurf->noshadow = TRUE;
		} break;
case 184:
# line 961 "yacc.y"
{
			yyval.obj = GeomHfCreate(yypvt[-0].c);
			if (yyval.obj)
				yyval.obj->surf = yypvt[-1].surf;
		} break;
case 185:
# line 967 "yacc.y"
{
			yyval.obj = GeomHfCreate(yypvt[-0].c);
		} break;
case 186:
# line 972 "yacc.y"
{
			yyval.obj = GeomPolygonCreate(Polypoints, Npoints,
				Options.flipnorm);
			if (yyval.obj)
				yyval.obj->surf = yypvt[-1].surf;
			Polypoints = (PointList *)NULL;
			Npoints = 0;
		} break;
case 189:
# line 985 "yacc.y"
{
			PointList *ptmp;

			ptmp = (PointList *)Malloc(sizeof(PointList));
			ptmp->vec = yypvt[-0].v;
			ptmp->next = Polypoints;
			Polypoints = ptmp;
			Npoints++;
		} break;
case 190:
# line 996 "yacc.y"
{
			if (Defstack->obj) {
				/*
				 * Set object texture to current texture.
				 */
				Defstack->obj->texture = CurText;
			}
			CurText = (Texture *)NULL;
			/*
			 * Pop topmost object on stack.
			 */
			yyval.obj = Defstack->obj;
			Defstack = GeomStackPop(Defstack);
			/* Pop current surface */
			CurSurf = SurfPop(CurSurf);
			/* Make current default surf aggregate's default */
			yyval.obj->surf = CurSurf->surf;
		} break;
case 191:
# line 1016 "yacc.y"
{
			/* Convert aggregate, pop stacks, etc. */
			if (yypvt[-2].obj) {
				if (Defstack->obj->next == (Geom *)NULL) {
					RLerror(RL_WARN,
						"Null object defined.\n");
					Defstack->obj = (Geom *)NULL;
				} else {
					/*
					 * Convert the linked list of objects
					 * associated with the topmost object
					 * to the appropriate aggregate type.
					 */
					Defstack->obj->prims=AggregateConvert(
						Defstack->obj,
						Defstack->obj->next);
					/*
					 * Make sure conversion worked OK.
					 */
					if (Defstack->obj->prims <= 0)
						Defstack->obj = (Geom *)NULL;
				}
			}
		} break;
case 192:
# line 1042 "yacc.y"
{
			if (yypvt[-0].obj) {
				Defstack = GeomStackPush(yypvt[-0].obj, Defstack);
				CurSurf = SurfPush((Surface *)NULL, CurSurf);
			}
		} break;
case 196:
# line 1053 "yacc.y"
{
			yyval.obj = GeomListCreate();
		} break;
case 197:
# line 1058 "yacc.y"
{
			yyval.obj = GeomGridCreate(yypvt[-2].i, yypvt[-1].i, yypvt[-0].i);
		} break;
case 198:
# line 1063 "yacc.y"
{
			yyval.obj = GeomCsgCreate(yypvt[-0].i);
			Options.csg = TRUE;
		} break;
case 199:
# line 1069 "yacc.y"
{
		    yyval.i = CSG_UNION;
		} break;
case 200:
# line 1073 "yacc.y"
{
		    yyval.i = CSG_INTERSECT;
		} break;
case 201:
# line 1077 "yacc.y"
{
		    yyval.i = CSG_DIFFERENCE;
		} break;
case 202:
# line 1082 "yacc.y"
{
			if (equal(yypvt[-3].d, yypvt[-1].d)) {
				/* It's really a cylinder */
				yyval.obj = GeomCylinderCreate(yypvt[-3].d, &yypvt[-2].v, &yypvt[-0].v);
			} else
				yyval.obj = GeomConeCreate(yypvt[-3].d, &yypvt[-2].v, yypvt[-1].d, &yypvt[-0].v);
			if (yyval.obj)
				yyval.obj->surf = yypvt[-4].surf;
		} break;
case 203:
# line 1093 "yacc.y"
{
			yyval.obj = GeomCylinderCreate(yypvt[-2].d, &yypvt[-1].v, &yypvt[-0].v);
			if (yyval.obj)
				yyval.obj->surf = yypvt[-3].surf;
		} break;
case 204:
# line 1100 "yacc.y"
{
			yyval.obj = GeomSphereCreate(yypvt[-1].d, &(yypvt[-0].v));
			if (yyval.obj)
				yyval.obj->surf = yypvt[-2].surf;
		} break;
case 205:
# line 1107 "yacc.y"
{
			yyval.obj = GeomDiscCreate(yypvt[-2].d, &(yypvt[-1].v), &(yypvt[-0].v));
			if (yyval.obj)
				yyval.obj->surf = yypvt[-3].surf;
		} break;
case 206:
# line 1114 "yacc.y"
{
			yyval.obj = GeomBoxCreate(&yypvt[-1].v, &yypvt[-0].v);
			if (yyval.obj)
				yyval.obj->surf = yypvt[-2].surf;
		} break;
case 207:
# line 1121 "yacc.y"
{
			yyval.obj = GeomTriangleCreate(FLATTRI, &(yypvt[-2].v), &(yypvt[-1].v), &(yypvt[-0].v),
				(Vector *)NULL, (Vector *)NULL, (Vector *)NULL,
				(Vec2d *)NULL, (Vec2d *)NULL, (Vec2d *)NULL,
				Options.flipnorm);
			if (yyval.obj)
				yyval.obj->surf = yypvt[-3].surf;
		} break;
case 208:
# line 1132 "yacc.y"
{
			yyval.obj = GeomTriangleCreate(PHONGTRI, &(yypvt[-5].v), &(yypvt[-3].v),
				&(yypvt[-1].v), &(yypvt[-4].v), &(yypvt[-2].v), &(yypvt[-0].v),
				(Vec2d *)NULL, (Vec2d *)NULL, (Vec2d *)NULL,
				Options.flipnorm);
			if (yyval.obj)
				yyval.obj->surf = yypvt[-6].surf;
		} break;
case 209:
# line 1143 "yacc.y"
{
			yyval.obj = GeomTriangleCreate(PHONGTRI, &(yypvt[-8].v), &(yypvt[-5].v), &(yypvt[-2].v),
						&(yypvt[-7].v), &(yypvt[-4].v), &(yypvt[-1].v),
						&(yypvt[-6].uv), &(yypvt[-3].uv), &(yypvt[-0].uv),
						Options.flipnorm);
			if (yyval.obj)
				yyval.obj->surf = yypvt[-9].surf;
		} break;
case 210:
# line 1153 "yacc.y"
{
			yyval.obj = GeomPlaneCreate(&(yypvt[-1].v), &(yypvt[-0].v));
			if (yyval.obj)
				yyval.obj->surf = yypvt[-2].surf;
		} break;
case 211:
# line 1160 "yacc.y"
{
			yyval.obj = GeomTorusCreate(yypvt[-3].d, yypvt[-2].d, &(yypvt[-1].v), &(yypvt[-0].v));
			if (yyval.obj)
				yyval.obj->surf = yypvt[-4].surf;
		} break;
case 212:
# line 1167 "yacc.y"
{
			yyval.obj = GeomBlobCreate(yypvt[-1].d, Metapoints, Npoints);
			if (yyval.obj)
				yyval.obj->surf = yypvt[-2].surf;
			Metapoints = (MetaList *)NULL;
			Npoints = 0;
		} break;
case 215:
# line 1179 "yacc.y"
{
			Metapoint = (MetaList *)Malloc(sizeof(MetaList));
			Metapoint->mvec.c0 = yypvt[-4].d;
			Metapoint->mvec.rs = yypvt[-3].d;
			Metapoint->mvec.x = yypvt[-2].d;
			Metapoint->mvec.y = yypvt[-1].d;
			Metapoint->mvec.z = yypvt[-0].d;
			Metapoint->next = Metapoints;
			Metapoints = Metapoint;
			Npoints++;
		} break;
case 216:
# line 1192 "yacc.y"
{
			if (Options.imgname != (char *)NULL)
				/* Already set on command line. */
				RLerror(RL_WARN,
					"Ignoring output file name \"%s\".\n",
					yypvt[-0].c);
			else
				Options.imgname = strsave(yypvt[-0].c);
		} break;
case 217:
# line 1203 "yacc.y"
{
			AtmosEffects = CurEffect;
			CurEffect = (Atmosphere *)NULL;
		} break;
case 218:
# line 1208 "yacc.y"
{
			if (yypvt[-1].i <= 0.)
				RLerror(RL_PANIC,
				"Index of refraction must be positive.\n");
			TopMedium.index = yypvt[-1].i;
			AtmosEffects = CurEffect;
			CurEffect = (Atmosphere *)NULL;
		} break;
case 221:
# line 1221 "yacc.y"
{
			yypvt[-0].atmos->next = CurEffect;
			CurEffect = yypvt[-0].atmos;
		} break;
case 222:
# line 1227 "yacc.y"
{
			yyval.atmos = AtmosMistCreate(&(yypvt[-3].col), &(yypvt[-2].col), yypvt[-1].d, yypvt[-0].d);
		} break;
case 223:
# line 1231 "yacc.y"
{
			yyval.atmos = AtmosFogCreate(&(yypvt[-1].col), &(yypvt[-0].col));
		} break;
case 224:
# line 1235 "yacc.y"
{
			yyval.atmos = AtmosFogdeckCreate(yypvt[-6].d, yypvt[-5].d, &yypvt[-4].v, yypvt[-3].d, yypvt[-2].i, &yypvt[-1].col, &yypvt[-0].col);
		} break;
case 225:
# line 1240 "yacc.y"
{
			yyval.col.r = yypvt[-2].d;
			yyval.col.g = yypvt[-1].d;
			yyval.col.b = yypvt[-0].d;
		} break;
case 226:
# line 1247 "yacc.y"
{
			yyval.v.x = yypvt[-2].d;
			yyval.v.y = yypvt[-1].d;
			yyval.v.z = yypvt[-0].d;
		} break;
case 227:
# line 1254 "yacc.y"
{
			yyval.uv.u = yypvt[-1].d;
			yyval.uv.v = yypvt[-0].d;
		} break;
case 229:
# line 1261 "yacc.y"
{
			yyval.map = UVMappingCreate();
		} break;
case 230:
# line 1266 "yacc.y"
{
			yyval.map = yypvt[-0].map;
		} break;
case 231:
# line 1271 "yacc.y"
{
			yyval.map = UVMappingCreate();
		} break;
case 232:
# line 1275 "yacc.y"
{
			yyval.map = SphereMappingCreate((Vector *)NULL,
				(Vector *)NULL, (Vector *)NULL);
		} break;
case 233:
# line 1280 "yacc.y"
{
			/* origin up uaxis */
			yyval.map = SphereMappingCreate(&yypvt[-2].v, &yypvt[-1].v, &yypvt[-0].v);
		} break;
case 234:
# line 1285 "yacc.y"
{
			yyval.map = CylMappingCreate((Vector *)NULL,
				(Vector *)NULL, (Vector *)NULL);
		} break;
case 235:
# line 1290 "yacc.y"
{
			/* origin up uaxis */
			yyval.map = CylMappingCreate(&yypvt[-2].v, &yypvt[-1].v, &yypvt[-0].v);
		} break;
case 236:
# line 1295 "yacc.y"
{
			yyval.map = LinearMappingCreate((Vector *)NULL,
				(Vector *)NULL, (Vector *)NULL);
		} break;
case 237:
# line 1300 "yacc.y"
{
			/* origin up uaxis */
			yyval.map = LinearMappingCreate(&yypvt[-2].v, &yypvt[-1].v, &yypvt[-0].v);
		} break;
case 238:
# line 1306 "yacc.y"
{
			yyval.i = AMBIENT;
		} break;
case 239:
# line 1310 "yacc.y"
{
			yyval.i = DIFFUSE;
		} break;
case 240:
# line 1314 "yacc.y"
{
			yyval.i = BODY;
		} break;
case 241:
# line 1318 "yacc.y"
{
			yyval.i = SPECULAR;
		} break;
case 242:
# line 1322 "yacc.y"
{
			yyval.i = REFLECT;
		} break;
case 243:
# line 1326 "yacc.y"
{
			yyval.i = TRANSP;
		} break;
case 244:
# line 1330 "yacc.y"
{
			yyval.i = SPECPOW;
		} break;
case 245:
# line 1334 "yacc.y"
{
			yyval.i = BUMP;
		} break;
case 246:
# line 1338 "yacc.y"
{
			yyval.i = INDEX;
		} break;
case 247:
# line 1343 "yacc.y"
{ yyval.col.r = yyval.col.g = yyval.col.b = yypvt[-0].d; } break;
case 249:
# line 1347 "yacc.y"
{
			fprintf(stderr,"%f\n",yypvt[-0].d);
		} break;
case 250:
# line 1351 "yacc.y"
{
			SymtabAddEntry(yypvt[-1].c, yypvt[-0].e->type, yypvt[-0].e, NULL, yypvt[-0].e->timevary, 0);
		} break;
case 251:
# line 1355 "yacc.y"
{ yyval.i = (int)yypvt[-0].d; } break;
case 253:
# line 1359 "yacc.y"
{
			if (!yypvt[-0].e->timevary) {
				yyval.d = ExprEval(yypvt[-0].e);
			} else {
				RLerror(RL_PANIC, "Illegal expression use.\n");
			}
		} break;
case 254:
# line 1368 "yacc.y"
{
			yyval.e = ExprReuseFloatCreate(yypvt[-0].d);
		} break;
case 256:
# line 1374 "yacc.y"
{
			yyval.e = yypvt[-1].e;
		} break;
case 257:
# line 1378 "yacc.y"
{
			yyval.e = ExprFloatCreate(yypvt[-0].d, FALSE);
		} break;
case 258:
# line 1382 "yacc.y"
{
			yyval.e = ExprFloatSymtabFind(yypvt[-0].c);
		} break;
case 259:
# line 1386 "yacc.y"
{
			yyval.e = ExprResolve1(yypvt[-1].e, yypvt[-3].sym->value.fp, yypvt[-3].sym->timevary);
		} break;
case 260:
# line 1390 "yacc.y"
{
			yyval.e = ExprResolve2(yypvt[-3].e, yypvt[-1].e,
					yypvt[-5].sym->value.fp,
					yypvt[-5].sym->timevary);
		} break;
case 261:
# line 1396 "yacc.y"
{
			yyval.e = ExprResolve3(yypvt[-5].e, yypvt[-3].e, yypvt[-1].e, 
					yypvt[-7].sym->value.fp,
					yypvt[-7].sym->timevary);
		} break;
case 262:
# line 1402 "yacc.y"
{
			yyval.e = ExprResolve4(yypvt[-7].e, yypvt[-5].e, yypvt[-3].e, yypvt[-1].e, 
					yypvt[-9].sym->value.fp,
					yypvt[-9].sym->timevary);
		} break;
case 263:
# line 1409 "yacc.y"
{
			yyval.e = ExprResolve5(yypvt[-9].e, yypvt[-7].e, yypvt[-5].e, yypvt[-3].e, yypvt[-1].e,
					yypvt[-11].sym->value.fp,
					yypvt[-11].sym->timevary);
		} break;
case 264:
# line 1415 "yacc.y"
{
			yyval.e = yypvt[-1].e;
		} break;
case 265:
# line 1419 "yacc.y"
{
			yyval.e = ExprResolve2(yypvt[-2].e, yypvt[-0].e, SumExpr, FALSE);
		} break;
case 266:
# line 1423 "yacc.y"
{
			yyval.e = ExprResolve2(yypvt[-2].e, yypvt[-0].e, DiffExpr, FALSE);
		} break;
case 267:
# line 1427 "yacc.y"
{
			yyval.e = ExprResolve2(yypvt[-2].e, yypvt[-0].e, MultExpr, FALSE);
		} break;
case 268:
# line 1431 "yacc.y"
{
			yyval.e = ExprResolve2(yypvt[-2].e, yypvt[-0].e, DivideExpr, FALSE);
		} break;
case 269:
# line 1435 "yacc.y"
{
			yyval.e = ExprResolve2(yypvt[-2].e, yypvt[-0].e, ModExpr, FALSE);
		} break;
case 270:
# line 1439 "yacc.y"
{
			yyval.e = ExprResolve1(yypvt[-0].e, NegateExpr, FALSE);
		} break;
case 271:
# line 1443 "yacc.y"
{
			yyval.e = yypvt[-0].e;
		} break;
case 272:
# line 1447 "yacc.y"
{
			yyval.e = ExprResolve2(yypvt[-2].e, yypvt[-0].e, pow, FALSE);
		} break;
case 274:
# line 1452 "yacc.y"
{ yyval.d = -yypvt[-0].d; } break;
case 275:
# line 1454 "yacc.y"
{ yyval.d = yypvt[-0].d; } break;
case 278:
# line 1459 "yacc.y"
{
			yyval.sym = SymtabBuiltinFind(yypvt[-0].c);
		} break;
# line	531 "/usr/ccs/bin/yaccpar"
	}
	goto yystack;		/* reset registers in driver code */
}

