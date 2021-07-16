#ifdef IDENT
#ident	"@(#)selection.h	1.3	93/06/28 SMI"
#endif

/*
 *      (c) Copyright 1992 Sun Microsystems, Inc.
 */

/*
 *	Sun design patents pending in the U.S. and foreign countries. See
 *	LEGAL_NOTICE file for terms of the license.
 */

#ifndef _OLWM_SELECTION_H
#define _OLWM_SELECTION_H

extern	Time	SelectionTime;

Bool IsSelected(Client *cli);
void AddSelection(Client *cli, Time timestamp);
Bool RemoveSelection(Client *cli);
Bool ToggleSelection(Client *cli, Time timestamp);
void ClearSelections(Display *dpy);
Client *EnumSelections(void *foo);
void SelectionRegister(Atom selection, void (*handler)(XEvent*));
void SelectionResponse(XEvent *event);
void SelectionInit(void);

#endif /* _OLWM_SELECTION_H */
