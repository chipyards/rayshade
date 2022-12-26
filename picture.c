/*
 * picture.c
 *
 * Copyright (C) 1989, 1991, Craig E. Kolb, Rod G. Bogart
 * All rights reserved.
 *
 * This software may be freely copied, modified, and redistributed
 * provided that this copyright notice is preserved on all copies.
 *
 * You may not distribute this software, in whole or in part, as part of
 * any commercial product without the express consent of the authors.
 *
 * There is no warranty or other guarantee of fitness of this software
 * for any purpose.  It is provided solely "as is".
 *
 * $Id: picture.c,v 4.0.1.2 92/02/07 09:22:20 cek Exp Locker: cek $
 *
 * patch 7 de JLN : stocke l'image entiere en RAM
 *
 */
#include <stdlib.h>

#include "rayshade.h"
#include "picture.h"
#include "viewing.h"
#include "options.h"
#include "stats.h"

#include "bmp_.h"

/*
 * Convert floating-point (0.-1.) to unsigned char (0-255), with no gamma
 * correction.
 * Note : il y a aussi 2 macros :
	#define CORRECT(x)		(correct(GAMMACORRECT(x)))
	#define GAMMACORRECT(x)		(Options.gamma == 1. ? (x) \
					   : (pow(x, Options.gamma)))
 */
unsigned char correct( Float x )
{
	/*
	 * Truncate values < 0 or > 1.
	 */
	if (x < 0)
		return 0;
	if (x > 1.)
		return 255;
	return (unsigned char)(x * 255.);
}

// buffer pour l'image entiere, 32 bits/pixel
unsigned char * RGBAbuf = NULL;
int iRGBA;	// index dans ce buffer

// cette fonction va reserver la RAM 
void PictureStart( char **argv )
{

RGBAbuf = malloc( 4 * Screen.xsize * Screen.ysize );
if 	( RGBAbuf == NULL )
	RLerror(RL_ABORT, "malloc failed for PictureStart");
iRGBA = 0;

fprintf( stderr, "---> --> PictureStart %d %d\n",Screen.xsize, Screen.ysize);
}


// cette fonction convertit et stocke une rangee de pixels float en RGBA 4 bytes
void PictureWriteLine( Pixel *buf )
{
int i;
for	( i = 0; i < Screen.xsize; i++ )
	{
	RGBAbuf[iRGBA++] = CORRECT(buf[i].r);
	RGBAbuf[iRGBA++] = CORRECT(buf[i].g);
	RGBAbuf[iRGBA++] = CORRECT(buf[i].b);
	RGBAbuf[iRGBA++] = correct(buf[i].alpha);	// Don't gamma correct alpha
	}
fprintf( stderr, ".");
}

void PictureFrameEnd()
{ //* Don't do anything -- generic format has no end-of-image marker.
fprintf( stderr, "---> --> PictureFrameEnd\n");
}

void save_bmp( char * fnam );

void PictureEnd()
{
if	( iRGBA != 4 * Screen.xsize * Screen.ysize )
	RLerror(RL_ABORT, "total image size error");

if	(Options.imgname)
	save_bmp( Options.imgname );
else	save_bmp( "rays.bmp" );

fprintf( stderr, "---> --> Ok PictureEnd\n");

free( RGBAbuf ); RGBAbuf = NULL;
}


// ===================== B M P specific stuff ==========================

void save_bmp( char * fnam )
{
impars im;
int x, y, i, j;

// 1) preparer descripteur image

im.fnam = fnam;
im.wi = Screen.xsize;
im.he = Screen.ysize;

// ce calcul existe dans writeBMPfile(), on l'a reproduit ici
// car ll est necessaire pour acceder aux pixels
im.ll = im.wi * 3;
i =  ( im.ll & 3 );        /* residu division par 4 */
if (i) im.ll += ( 4 - i ); /* maintenant ll est divisible par 4 */

// 2) allouer memoire

im.data = malloc( im.ll * im.he );
if ( im.data == NULL )
   RLerror(RL_ABORT, "BMP malloc failed for %d bytes", im.ll * im.he );

printf("RAM = %d bytes\n", im.ll * im.he );

// 3) generer pixels

// x = 0 est a gauche, y = 0 est en BAS

iRGBA = 0;
for ( y = im.he - 1; y > 0;  y-- )
    {
    i = y * im.ll;
    for ( x = 0; x < im.wi; x++ )
        {
        j = i + 3 * x;
        im.data[j+2] = RGBAbuf[iRGBA++];	// R 
        im.data[j+1] = RGBAbuf[iRGBA++];	// G
        im.data[j]   = RGBAbuf[iRGBA++];	// B
	iRGBA++;				// alpha
        }
    }    

// 4) ecrire fichier

writeBMPfile( &im );
free( im.data );
}
