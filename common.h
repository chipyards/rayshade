/*
 * common.h
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
 * $Id: common.h,v 4.0.1.1 91/11/26 21:34:27 cek Exp Locker: cek $
 *
 * $Log:	common.h,v $
 * Revision 4.0.1.1  91/11/26  21:34:27  cek
 * patch3: Added EPSILON definition, redefine equal() macro.
 * 
 * Revision 4.0  91/07/17  14:30:18  kolb
 * Initial version.
 * 
 */
#ifndef COMMON_H 
#define COMMON_H

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "config.h"

typedef double Float;

#if (VOIDFLAGS & 8) == 8
typedef void * voidstar;
#else
typedef char * voidstar;
#endif

#include "expr.h"
#include "vector.h"
#include "ray.h"
#include "color.h"
#include "transform.h"
#include "error.h"

#ifndef TRUE
#define TRUE		1
#endif

#ifndef FALSE
#define FALSE		0
#endif

/*
 * Various useful constants and macros.
 */

/*
 * Minimum vector length & fp value.
 * Modify depending upon Float typedef.
 */
#define EPSILON		(Float)0.00001

#ifndef PI
#define	PI		3.14159265358979323846
#endif
#define TWOPI		(2. * PI)
#define INV_TWOPI	(1. / TWOPI)
#define deg2rad(x)	(Float)(x * PI/180.)
#define LNHALF		(-.69314718)

#ifndef NULL
#	define NULL 0
#endif

#define UNSET		-1

/*
 * Some systems, such as the RS6000, have fast fabs already defined.
 */
#ifndef fabs
extern Float RSabstmp;
#define fabs(x) 		((RSabstmp=x) < 0 ? -RSabstmp : RSabstmp)
#endif

#ifdef MULTIMAX
/*
 * On the multimax, allocate large pieces of memory as shared memory.
 */
extern char *share_malloc(), *share_calloc();
#else
/*
 * Otherwise, malloc is malloc, etc.
 */
#define share_malloc(x)		Malloc(x)
#define share_calloc(x,y)	Calloc(x,y)
#endif

/*
 * Close enough for us.
 */
#define equal(a, b)		(fabs((a) - (b)) < EPSILON)
/*
 * Maximum/Minimum functions
 */
#define max(a, b)		((a) > (b) ? (a) : (b))
#define min(a, b)		((a) < (b) ? (a) : (b))

extern voidstar Malloc(), Calloc();
extern char	*strsave();
extern double	drand48();	/* just in case */

#endif /* COMMON_H */
