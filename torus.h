/*
 * torus.h
 *
 * Copyright (C) 1990, 1991, Mark Polipec, Craig E. Kolb
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
 * $Id: torus.h,v 4.0 91/07/17 14:39:31 kolb Exp Locker: kolb $
 *
 * $Log:	torus.h,v $
 * Revision 4.0  91/07/17  14:39:31  kolb
 * Initial version.
 * 
 */
#ifndef TORUS_H
#define TORUS_H

#define GeomTorusCreate(a,b,p,n) GeomCreate((GeomRef)TorusCreate(a,b,p,n), \
					TorusMethods())

/*
 * Torus
 */
typedef struct {
	Float a;		/* tube radius */
	Float b;		/* swept radius */
	Float aa, bb;		/* squares of the above */
	Trans trans;		/* general<-->canonical transform */
} Torus;

extern Torus	*TorusCreate();
extern int	TorusIntersect(), TorusEnter(), TorusNormal();
extern void	TorusBounds(), TorusUV(), TorusStats();
extern char	*TorusName();
extern Methods	*TorusMethods();

#endif /* TORUS_H */
