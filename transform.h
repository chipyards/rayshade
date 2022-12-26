/*
 * transform.h
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
 * $Id: transform.h,v 4.0 91/07/17 14:32:33 kolb Exp Locker: kolb $
 *
 * $Log:	transform.h,v $
 * Revision 4.0  91/07/17  14:32:33  kolb
 * Initial version.
 * 
 */
#ifndef TRANSFORM_H
#define TRANSFORM_H

typedef voidstar TransRef;
typedef TransRef TransCreateFunc();

/*
 * Transformation 'matrix'.
 */
typedef struct RSMatrix {
	Float matrix[3][3];		/* Rotation matrix */
	Vector translate;		/* Translation */
} RSMatrix;

typedef struct {
	TransRef	(*create)();		/* Create it... */
	void		(*propagate)();		/* Propagate changes to parameters */
} TransMethods;

/* 
 * Transformation structure
 */
typedef struct Trans {
	TransRef tr;			/* transform data */
	TransMethods *methods;		/* transform methods */
	ExprAssoc *assoc;		/* animated parameters */
	short	animated;		/* is the transformation animated? */
	RSMatrix trans,		/* object space --> world space */
		 itrans;	/* worldspace --> object space */
	struct Trans *next, *prev;
} Trans;

extern void	MatrixMult(), MatrixCopy(), MatrixInit(), MatrixInvert(),
		TransCopy(), TransInit(), TransInvert(),
		TransCompose(),
		VecTransform(), PointTransform(), NormalTransform();

extern Trans	*TransCreate();

extern RSMatrix	*MatrixCreate();

void		RotationMatrix(), TranslationMatrix(),
		ScaleMatrix(), ArbitraryMatrix(), CoordSysTransform();
extern Float	RayTransform();

#endif /* TRANSFORM_H */
