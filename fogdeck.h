/*
 * fogdeck.h
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
 * $Id: fogdeck.h,v 4.0 91/07/17 14:40:35 kolb Exp Locker: kolb $
 *
 * $Log:	fogdeck.h,v $
 * Revision 4.0  91/07/17  14:40:35  kolb
 * Initial version.
 * 
 */
#ifndef FOGDECK_H

#define AtmosFogdeckCreate(z,a,s,p,o,c,t) AtmosCreate( \
		(AtmosRef) FogdeckCreate(z,a,s,p,o,c,t), FogdeckApply)	
typedef struct Fogdeck {
	Float	alt,	/* Z value below which fogdeck deck exists. */
		offset,
		chaoscale;
	Vector	scale;
	Color	color,		/* Fogdeck color */
		trans;		/* Fogdeck transmissivity */
	int	octaves;
} Fogdeck;

extern Fogdeck *FogdeckCreate();
extern void FogdeckApply();

#endif /* FOGDECK_H */
