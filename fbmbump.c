/*
 * fbmbump.c
 *
 * Copyright (C) 1989, 1991, Craig E. Kolb
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
 * $Id: fbmbump.c,v 4.0 91/07/17 14:42:21 kolb Exp Locker: kolb $
 *
 * $Log:	fbmbump.c,v $
 * Revision 4.0  91/07/17  14:42:21  kolb
 * Initial version.
 * 
 */
#include "texture.h"
#include "fbm.h"
#include "fbmbump.h"

FBm *
FBmBumpCreate(offset, scale, h, lambda, octaves)
Float offset, h, lambda, scale;
int octaves;
{
	FBm *fbm;
	fbm = FBmCreate(offset, scale, h, lambda, octaves, 0., (char *)NULL);
	return fbm;
}

/*ARGSUSED*/
void
FBmBumpApply(fbm, prim, ray, pos, norm, gnorm, surf)
FBm *fbm;
Geom *prim;
Ray *ray;
Vector *pos, *norm, *gnorm;
Surface *surf;
{
	Vector disp;

	VfBm(pos, fbm->omega, fbm->lambda, fbm->octaves, &disp);
	norm->x += fbm->offset + disp.x * fbm->scale;
	norm->y += fbm->offset + disp.y * fbm->scale;
	norm->z += fbm->offset + disp.z * fbm->scale;
}
