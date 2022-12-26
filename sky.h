/*
 * sky.h
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
 * $Id: sky.h,v 4.0 91/07/17 14:43:46 kolb Exp Locker: kolb $
 *
 * $Log:	sky.h,v $
 * Revision 4.0  91/07/17  14:43:46  kolb
 * Initial version.
 * 
 */
#ifndef SKY_H

#define TextSkyCreate(s,h,l,n,c,t) TextCreate((TextRef)SkyCreate(s,h,l,n,c,t),\
					SkyApply)
typedef struct {
	Float	beta,
		omega,
		lambda,
		scale,
		cthresh,
		lthresh;
	int	octaves;
} Sky;

extern Sky *SkyCreate();
extern void SkyApply();

#endif /* SKY_H */
