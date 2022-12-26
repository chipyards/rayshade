/*
 * checker.h
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
 * $Id: checker.h,v 4.0 91/07/17 14:41:51 kolb Exp Locker: kolb $
 *
 * $Log:	checker.h,v $
 * Revision 4.0  91/07/17  14:41:51  kolb
 * Initial version.
 * 
 */
#ifndef CHECKER_H

#define TextCheckerCreate(s)	TextCreate((TextRef) CheckerCreate(s), \
					CheckerApply)
typedef struct {
	Surface *surf;		/* Alternate surface */
} Checker;

extern Checker *CheckerCreate();
extern void CheckerApply();

#endif /* CHECKER_H */
