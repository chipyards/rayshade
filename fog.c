/*
 * fog.c
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
 * $Id: fog.c,v 4.0 91/07/17 14:40:14 kolb Exp Locker: kolb $
 *
 * $Log:	fog.c,v $
 * Revision 4.0  91/07/17  14:40:14  kolb
 * Initial version.
 * 
 */
#include "atmosphere.h"
#include "fog.h"

Fog *
FogCreate(color, trans)
Color *color, *trans;
{
	Fog *fog;
	static void ComputeFog();

	fog = (Fog *)Malloc(sizeof(Fog));

	if (color == (Color *)NULL)
		fog->color.r = fog->color.g = fog->color.b = 0.;
	else
		fog->color = *color;
	if (trans == (Color *)NULL)
		fog->trans.r = fog->trans.g = fog->trans.b = FAR_AWAY;
	else {
		fog->trans = *trans;
	}
	return fog;
}

/*
 * Add fog to the given color.
 */
void
FogApply(fog, ray, pos, dist, color)
Fog *fog;
Ray *ray;
Vector *pos;
Float dist;
Color *color;
{
	Float atten;
	extern Float ExpAtten();

	atten = ExpAtten(dist, fog->trans.r);
	if (fog->trans.r == fog->trans.g && fog->trans.r == fog->trans.b) {
		ColorBlend(color, &fog->color, atten, 1. - atten);
		return;
	}
	color->r = atten*color->r + (1. - atten) * fog->color.r;

	atten = ExpAtten(dist, fog->trans.g);
	color->g = atten*color->g + (1. - atten) * fog->color.g;
	atten = ExpAtten(dist, fog->trans.b);
	color->b = atten*color->b + (1. - atten) * fog->color.b;
}
