/*
 * fbm.h
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
 * $Id: fbm.h,v 4.0 91/07/17 14:42:11 kolb Exp Locker: kolb $
 *
 * $Log:	fbm.h,v $
 * Revision 4.0  91/07/17  14:42:11  kolb
 * Initial version.
 * 
 */
#ifndef FBM_H
#define FBM_H

#define TextFBmCreate(o,s,h,l,n,t,m) TextCreate( \
			(TextRef)FBmCreate(o,s,h,l,n,t,m), FBmApply)
typedef struct {
	Float	beta,
		omega,
		lambda,
		scale,
		offset,
		thresh;
	int	octaves;
	Color	*colormap;
} FBm;

extern FBm *FBmCreate();
extern void FBmApply();

#endif /* FBM_H */
