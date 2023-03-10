/*
 * windy.h
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
 * $Id: windy.h,v 4.0 91/07/17 14:44:28 kolb Exp Locker: kolb $
 *
 * $Log:	windy.h,v $
 * Revision 4.0  91/07/17  14:44:28  kolb
 * Initial version.
 * 
 */
#ifndef WINDY_H

#define TextWindyCreate(s,w,c,b,o,t,h,i) TextCreate( \
		(TextRef)WindyCreate(s,w,c,b,o,t,h,i), WindyApply)

typedef struct {
	Float	scale,
		windscale,
		chaoscale,
		bumpscale,
		tscale,
		hscale,
		offset;
	int	octaves;
} WindyText;

extern WindyText *WindyCreate();
extern void WindyApply();

#endif /* WINDY_H */
