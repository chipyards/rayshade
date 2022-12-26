/*
 * bump.h
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
 * $Id: bump.h,v 4.0 91/07/17 14:41:43 kolb Exp Locker: kolb $
 *
 * $Log:	bump.h,v $
 * Revision 4.0  91/07/17  14:41:43  kolb
 * Initial version.
 * 
 */
#ifndef BUMP_H

#define TextBumpCreate(s)	TextCreate((TextRef) BumpCreate(s), \
					BumpApply)
typedef struct {
	Float size;
} Bump;

extern Bump *BumpCreate();
extern void BumpApply();

#endif /* BUMP_H */
