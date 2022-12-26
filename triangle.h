/*
 * triangle.h
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
 * $Id: triangle.h,v 4.0 91/07/17 14:39:43 kolb Exp Locker: kolb $
 *
 * $Log:	triangle.h,v $
 * Revision 4.0  91/07/17  14:39:43  kolb
 * Initial version.
 * 
 */
#ifndef TRIANGLE_H
#define TRIANGLE_H

#define FLATTRI		0
#define PHONGTRI	1

#define GeomTriangleCreate(t,a,b,c,d,e,f,g,h,i,s)  GeomCreate( \
		(GeomRef)TriangleCreate(t,a,b,c,d,e,f,g,h,i,s), TriangleMethods())

/*
 * Triangle
 */
typedef struct {
	Vector	nrm,		/* triangle normal */
		p[3],		/* vertices */
		e[3],		/* "edge" vectors (scaled) */
		*vnorm,		/* Array of vertex normals */
		*dpdu, *dpdv;	/* U and V direction vectors */
	Float	d,		/* plane constant  */
		b[3];		/* Array of barycentric coordinates */
	Vec2d	*uv;		/* Array of UV coordinates of vertices */
	char	index,		/* Flag used for shading/intersection test. */
		type;		/* type (to detect if phong or flat) */
} Triangle;

extern Triangle	*TriangleCreate();
extern int	TriangleIntersect(), TriangleNormal();
extern void	TriangleBounds(), TriangleUV(),
		TriangleStats();
extern Methods	*TriangleMethods();
char		*TriangleName();
#endif /* TRIANGLE_H */
