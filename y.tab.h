
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
extern YYSTYPE yylval;
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
