/*
 * ray.h
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
 * $Id: ray.h,v 4.0 91/07/17 14:31:08 kolb Exp Locker: kolb $
 *
 * $Log:	ray.h,v $
 * Revision 4.0  91/07/17  14:31:08  kolb
 * Initial version.
 * 
 */
#ifndef RAY_H
#define RAY_H
/* 
 * Ray
 */
typedef struct Ray {
	Vector	pos,			/* Origin */
		dir;			/* Direction */
	int 	depth,			/* depth in ray tree */
		sample;			/* current sample # */
	Float	time;
	struct Medium *media;		/* Medium ray is passing through */
} Ray;
#endif
