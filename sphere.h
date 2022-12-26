/*
 * sphere.h
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
 * $Id: sphere.h,v 4.0 91/07/17 14:39:23 kolb Exp Locker: kolb $
 *
 * $Log:	sphere.h,v $
 * Revision 4.0  91/07/17  14:39:23  kolb
 * Initial version.
 * 
 */
#ifndef SPHERE_H
#define SPHERE_H

#define GeomSphereCreate(r,p)	GeomCreate((GeomRef)SphereCreate(r,p), \
					SphereMethods())

/*
 * Sphere
 */
typedef struct {
	Float r, rsq;		/* radius, radius squared */
	Float x, y, z;		/* position */
} Sphere;

extern Sphere	*SphereCreate();
extern Methods	*SphereMethods();
extern int	SphereIntersect(), SphereEnter(), SphereNormal();
extern void	SphereBounds(), SphereUV(), SphereStats();
extern char	*SphereName();

#endif /* SPHERE_H */
