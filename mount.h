/*
 * mount.h
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
 * $Id: mount.h,v 4.0 91/07/17 14:43:26 kolb Exp Locker: kolb $
 *
 * $Log:	mount.h,v $
 * Revision 4.0  91/07/17  14:43:26  kolb
 * Initial version.
 * 
 */
#ifndef MOUNT_H

#define TextMountCreate(c,t,s)	TextCreate((TextRef) MountCreate(c,t,s), \
					MountApply)
typedef struct {
	Float turb, slope;
	Color *cmap;
} Mount;

extern Mount *MountCreate();
extern void MountApply();

#endif /* MOUNT_H */
