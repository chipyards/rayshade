/*
 * checker.c
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
 * $Id: checker.c,v 4.0 91/07/17 14:41:48 kolb Exp Locker: kolb $
 *
 * $Log:	checker.c,v $
 * Revision 4.0  91/07/17  14:41:48  kolb
 * Initial version.
 * 
 */
#include "texture.h"
#include "checker.h"

/*
 * Create and return a reference to a "checker" texture.
 */
Checker *
CheckerCreate(surf)
Surface *surf;
{
	Checker *checker;
	checker = (Checker *)Malloc(sizeof(checker));
	checker->surf = surf;
	return checker;
}

/*
 * Apply a "checker" texture.
 */
void
CheckerApply(checker, prim, ray, pos, norm, gnorm, surf)
Checker *checker;
Geom *prim;
Ray *ray;
Vector *pos, *norm, *gnorm;
Surface *surf;
{
	int xp, yp, zp;

	xp = pos->x > 0. ? pos->x : 1. - pos->x;
	yp = pos->y > 0. ? pos->y : 1. - pos->y;
	zp = pos->z > 0. ? pos->z : 1. - pos->z;

	if ((xp + yp + zp) % 2)
		*surf = *checker->surf;
	/* else surface stays the same. */
}
