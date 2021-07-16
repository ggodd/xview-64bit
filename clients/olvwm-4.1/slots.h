/*
 *      (c) Copyright 1990 Sun Microsystems, Inc. Sun design patents
 *      pending in the U.S. and foreign countries. See LEGAL_NOTICE
 *      file for terms of the license.
 */

#ifdef IDENT
#ident	"@(#)slots.h	26.7	91/09/14 SMI"
#endif

#ifndef _OLWM_SLOT_H
#define _OLWM_SLOT_H

typedef enum {SOTopToBottom, SOBottomToTop, SOLeftToRight, SORightToLeft} SlotOrder;

typedef struct _iconSlot {
	int 	ma, mi, maw, miw;
	Bool 	positioned;
	int	off_x, off_y;
} IconSlot;

typedef struct _iconGrid {
	SlotOrder	SOmajor,SOminor;
	int		*occupancy;
	int		minoccupancy;
	List		*iconList;
	int		maslots,mislots;
	int		slotshoriz,slotsvert;
	int		pixhoriz,pixvert;
} IconGrid;

IconGrid *SlotInit(Display *dpy, int screenno);
struct _iconSlot *SlotAlloc(WinIconFrame *winicon, Bool positioned, Bool snaptogrid);
void SlotFree(WinIconFrame *winicon);
void SlotSetLocations(Display *dpy, IconGrid *iconGrid);

#endif /* _OLWM_SLOT_H */
