/*
 * infinite.c
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
 * $Id: infinite.c,v 4.0 91/07/17 14:34:28 kolb Exp Locker: kolb $
 *
 * $Log:	infinite.c,v $
 * Revision 4.0  91/07/17  14:34:28  kolb
 * Initial version.
 * 
 */
#include "light.h"
#include "infinite.h"

static LightMethods *iInfMethods = NULL;

Infinite *
InfiniteCreate(dir)
Vector *dir;
{
	Infinite *inf;

	inf = (Infinite *)share_malloc(sizeof(Infinite));
	inf->dir = *dir;
	if (VecNormalize(&inf->dir) == 0.) {
		RLerror(RL_ABORT, "Invalid directional light.\n");
		return (Infinite *)NULL;
	}
	return inf;
}

LightMethods *
InfiniteMethods()
{
	if (iInfMethods == (LightMethods *)NULL) {
		iInfMethods = LightMethodsCreate();
		iInfMethods->intens = InfiniteIntens;
		iInfMethods->dir = InfiniteDirection;
	}
	return iInfMethods;
}

int
InfiniteIntens(inf, lcolor, cache, ray, dist, noshadow, color)
Infinite *inf;
Color *lcolor, *color;
ShadowCache *cache;
Ray *ray;
Float dist;
int noshadow;
{
	return !Shadowed(color, lcolor, cache, ray, dist, noshadow);
}

void
InfiniteDirection(lp, pos, dir, dist)
Infinite *lp;
Vector *pos, *dir;
Float *dist;
{
	*dir = lp->dir;
	*dist = FAR_AWAY;
}

InfiniteMethodRegister(meth)
UserMethodType meth;
{
	if (iInfMethods)
		iInfMethods->user = meth;
}
