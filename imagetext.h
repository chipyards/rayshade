/*
 * imagetext.h
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
 * $Id: imagetext.h,v 4.0 91/07/17 14:42:47 kolb Exp Locker: kolb $
 *
 * $Log:	imagetext.h,v $
 * Revision 4.0  91/07/17  14:42:47  kolb
 * Initial version.
 * 
 */
#ifndef IMAGETEXT_H
#define IMAGETEXT_H

#define TextImageCreate(s) TextCreate((TextRef)ImageTextCreate(s), \
				ImageTextApply)

typedef struct {
	Image	*image;		/* image to use */
	Surface *surf;		/* Alternative surface */
	int	component,	/* component to texture */
		smooth;		/* interpolate pixel values? */
	Float	lo, hi;		/* high and low values in image */
	Float	tileu, tilev;	/* tiling control */
	Mapping	*mapping;
} ImageText;

extern ImageText *ImageTextCreate();
extern void ImageTextApply(), ImageTextSetComponent();

#endif /* IMAGETEXT_H */
