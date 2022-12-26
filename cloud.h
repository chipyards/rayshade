/*
 * cloud.h
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
 * $Id: cloud.h,v 4.0 91/07/17 14:42:00 kolb Exp Locker: kolb $
 *
 * $Log:	cloud.h,v $
 * Revision 4.0  91/07/17  14:42:00  kolb
 * Initial version.
 * 
 */
#ifndef CLOUDTEXT_H

#define TextCloudCreate(s,h,l,n,c,o,t) TextCreate( \
			(TextRef)CloudTextCreate(s,h,l,n,c,o,t), CloudTextApply)
typedef struct {
	Float	beta,
		omega,
		lambda,
		scale,
		cthresh,
		range,
		transcale,
		maxval;
	int	octaves;
} CloudText;

extern CloudText *CloudTextCreate();
extern void CloudTextApply();

#endif /* CLOUDTEXT_H */
