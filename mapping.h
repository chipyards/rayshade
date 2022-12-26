/*
 * mapping.h
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
 * $Id: mapping.h,v 4.0 91/07/17 14:43:00 kolb Exp Locker: kolb $
 *
 * $Log:	mapping.h,v $
 * Revision 4.0  91/07/17  14:43:00  kolb
 * Initial version.
 * 
 */
#ifndef MAPPING_H
#define MAPPING_H

#define PRIMSPACE	01	/* Mapping uses data in prim space */
#define OBJSPACE	02	/* Mapping uses data in object space */

typedef struct Mapping {
	int flags;		/* mapping flags */
	Vector center, uaxis, vaxis, norm;
	Float dist;
	RSMatrix m;
	void (*method)();
} Mapping;

extern Mapping *UVMappingCreate(), *SphereMappingCreate(), *CylMappingCreate(),
	*LinearMappingCreate();

#endif /* MAPPING_H */
