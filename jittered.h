/*
 * jittered.h
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
 * $Id: jittered.h,v 4.0 91/07/17 14:34:50 kolb Exp Locker: kolb $
 *
 * $Log:	jittered.h,v $
 * Revision 4.0  91/07/17  14:34:50  kolb
 * Initial version.
 * 
 */
#ifndef JITTERED_H
#define JITTERED_H

#define LightJitteredCreate(c,p,u,v) LightCreate( \
			(LightRef)JitteredCreate(p,u,v), JitteredMethods(), c)
typedef struct {
	Vector pos, curpos, e1, e2;
} Jittered;

extern Jittered *JitteredCreate();
extern LightMethods *JitteredMethods();
extern int JitteredIntens();
extern void JitteredDirection();

#endif /* JITTERED_H */
