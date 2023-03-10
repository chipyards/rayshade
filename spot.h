/*
 * spot.h
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
 * $Id: spot.h,v 4.0 91/07/17 14:35:50 kolb Exp Locker: kolb $
 *
 * $Log:	spot.h,v $
 * Revision 4.0  91/07/17  14:35:50  kolb
 * Initial version.
 * 
 */
#ifndef SPOT_H
#define SPOT_H

#define LightSpotCreate(c,f,t,p,i,o) LightCreate( \
			(LightRef)SpotCreate(f,t,p,i,o), SpotMethods(), c)
typedef struct {
	Vector pos, dir;
	Float coef, radius, falloff;
} Spotlight;

extern Spotlight *SpotCreate();
extern LightMethods *SpotMethods();
extern int SpotIntens();
extern void SpotDirection();

#endif /* SPOT_H */
