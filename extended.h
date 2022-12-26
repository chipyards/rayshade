/*
 * extended.h
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
 * $Id: extended.h,v 4.0 91/07/17 14:34:18 kolb Exp Locker: kolb $
 *
 * $Log:	extended.h,v $
 * Revision 4.0  91/07/17  14:34:18  kolb
 * Initial version.
 * 
 */
#ifndef EXTENDED_H
#define EXTENDED_H

#define LightExtendedCreate(c,r,p) LightCreate( \
		(LightRef)ExtendedCreate(r,p), ExtendedMethods(), c)

typedef struct {
	Vector pos;
	Float radius;
} Extended;

extern Extended *ExtendedCreate();
extern LightMethods *ExtendedMethods();
extern int ExtendedIntens();
extern void ExtendedDirection();

#endif /* EXTENDED_H */
