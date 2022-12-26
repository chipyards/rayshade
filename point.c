/*
 * point.c
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
 * $Id: point.c,v 4.0 91/07/17 14:35:20 kolb Exp Locker: kolb $
 *
 * $Log:	point.c,v $
 * Revision 4.0  91/07/17  14:35:20  kolb
 * Initial version.
 * 
 */
#include "light.h"
#include "point.h"

static LightMethods *iPointMethods = NULL;

Pointlight *
PointCreate(pos)
Vector *pos;
{
	Pointlight *p;

	p = (Pointlight *)share_malloc(sizeof(Pointlight));
	p->pos = *pos;
	return p;
}

LightMethods *
PointMethods()
{
	if (iPointMethods == (LightMethods *)NULL) {
		iPointMethods = LightMethodsCreate();
		iPointMethods->intens = PointIntens;
		iPointMethods->dir = PointDirection;
	}
	return iPointMethods;
}

int
PointIntens(lp, lcolor, cache, ray, dist, noshadow, color)
Pointlight *lp;
Color *lcolor, *color;
ShadowCache *cache;
Ray *ray;
Float dist;
int noshadow;
{
	return !Shadowed(color, lcolor, cache, ray, dist, noshadow);
}

void
PointDirection(lp, pos, dir, dist)
Pointlight *lp;
Vector *pos, *dir;
Float *dist;
{
	/*
	 * Calculate dir from position to center of
	 * light source.
	 */
	VecSub(lp->pos, *pos, dir);
	*dist = VecNormalize(dir);
}

PointMethodRegister(meth)
UserMethodType meth;
{
	if (iPointMethods)
		iPointMethods->user = meth;
}
