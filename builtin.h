/*
 * builtin.h
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
 * $Id: builtin.h,v 4.0 91/07/17 14:45:09 kolb Exp Locker: kolb $
 *
 * $Log:	builtin.h,v $
 * Revision 4.0  91/07/17  14:45:09  kolb
 * Initial version.
 * 
 */
#ifndef BUILTIN_H
#define BUILTIN_H

extern Float	SumExpr(), DiffExpr(), MultExpr(), DivideExpr(), ModExpr(), 
		NegateExpr(), LinearTime();

#endif /* BUILTIN_H */
