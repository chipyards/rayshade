/*
 * plane.h
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
 * $Id: plane.h,v 4.0 91/07/17 14:38:54 kolb Exp Locker: kolb $
 *
 * $Log:	plane.h,v $
 * Revision 4.0  91/07/17  14:38:54  kolb
 * Initial version.
 * 
 */
#ifndef PLANE_H
#define PLANE_H

#define GeomPlaneCreate(p,n)	GeomCreate((GeomRef)PlaneCreate(p,n), \
					PlaneMethods())

/*
 * Plane
 */
typedef struct {
	Vector norm, pos;	/* Plane normal, point on plane */
	Float d;		/* Plane constant. */
} Plane;

extern Plane	*PlaneCreate();
extern int	PlaneIntersect(), PlaneNormal();
extern void	PlaneBounds(), PlaneUV(), PlaneStats();
extern char	*PlaneName();
extern Methods	*PlaneMethods();

#endif /* PLANE_H */
