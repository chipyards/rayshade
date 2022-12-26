/*
 * infinite.h
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
 * $Id: infinite.h,v 4.0 91/07/17 14:34:34 kolb Exp Locker: kolb $
 *
 * $Log:	infinite.h,v $
 * Revision 4.0  91/07/17  14:34:34  kolb
 * Initial version.
 * 
 */
#ifndef INFINITE_H
#define INFINITE_H

#define LightInfiniteCreate(c,d) LightCreate((LightRef)InfiniteCreate(d), \
						InfiniteMethods(), c)
typedef struct {
	Vector dir;
} Infinite;

extern Infinite *InfiniteCreate();
extern LightMethods *InfiniteMethods();
extern int InfiniteIntens();
extern void InfiniteDirection();

#endif /* INFINITE_H */
