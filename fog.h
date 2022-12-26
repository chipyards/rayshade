/*
 * fog.h
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
 * $Id: fog.h,v 4.0 91/07/17 14:40:22 kolb Exp Locker: kolb $
 *
 * $Log:	fog.h,v $
 * Revision 4.0  91/07/17  14:40:22  kolb
 * Initial version.
 * 
 */
#ifndef FOG_H

#define AtmosFogCreate(c,t)	AtmosCreate((AtmosRef) FogCreate(c,t), \
						FogApply)	
typedef struct Fog {
	Color	color,		/* Fog color */
		trans;		/* Fog transmissivity */
} Fog;

extern Fog *FogCreate();
extern void FogApply();

#endif /* FOG_H */
