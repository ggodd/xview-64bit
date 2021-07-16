/*
 *      (c) Copyright 1989, 1990 Sun Microsystems, Inc. Sun design patents
 *      pending in the U.S. and foreign countries. See LEGAL_NOTICE
 *      file for terms of the license.
 */

#ifndef _OLWM_KBDFUNCS_H
#define _OLWM_KBDFUNCS_H

#ifdef IDENT
#ident	"@(#)kbdfuncs.h	1.5 olvwm version 07 Jan 1994"
#endif

/*
 * Based on
#ident	"@(#)kbdfuncs.h	1.8	93/06/28 SMI"
 *
 */

long itheta(int p1x, int p1y, int p2x, int p2y);
void KeyBeep(Display *dpy, XKeyEvent *ke);
Bool KeyLockColormap(Display *dpy, XKeyEvent *ke);
void KeyUnlockColormap(Display *dpy, XKeyEvent *ke);
void KeyRaiseLowerPointer(Display *dpy, XKeyEvent *ke);
void KeyOpenClosePointer(Display *dpy, XKeyEvent *ke);
void KeyFocusToPointer(Display *dpy, XKeyEvent *ke);
void KeyNextApp(Display *dpy, XKeyEvent *ke);
void KeyPrevApp(Display *dpy, XKeyEvent *ke);
void KeyNextWindow(Display *dpy, XKeyEvent *ke);
void KeyPrevWindow(Display *dpy, XKeyEvent *ke);
void KeyToggleInput(Display *dpy, XKeyEvent *ke);
void KeyTogglePin(Display *dpy, XKeyEvent *ke);
void KeyRefresh(Display *dpy, XKeyEvent *ke);
void KeyFrontFocus(Display *dpy, XKeyEvent *ke);
void KeyBackFocus(Display *dpy, XKeyEvent *ke);
void KeyOpenCloseFocus(Display *dpy, XKeyEvent *ke);
void KeyFullRestore(Display *dpy, XKeyEvent *ke);
void KeyQuit(Display *dpy, XKeyEvent *ke);
void KeyOwner(Display *dpy, XKeyEvent *ke);
void KeyMove(Display *dpy, XKeyEvent *ke);
void KeyResize(Display *dpy, XKeyEvent *ke);
void KeyProperties(Display *dpy, XKeyEvent *ke);
void KeyWorkspaceMenu(Display *dpy, XKeyEvent *ke);
void KeyWindowMenu(Display *dpy, XKeyEvent *ke);
void KeyMakeInvisibleFocus(Display *dpy, XKeyEvent *ke);
void KeyMakeInvisiblePointer(Display *dpy, XKeyEvent *ke);
void KeyMakeVisibleAll(Display *dpy, XKeyEvent *ke);
void KeyToggleFullSizeZoomX(Display *dpy, XKeyEvent *ke);
void KeyToggleDragWindow(Display *dpy, XKeyEvent *ke);
void KeyToggleMoveGroups(Display *dpy, XKeyEvent *ke);
void KeyToggleSticky(Display *dpy, XKeyEvent *ke);
void KeySaveWorkspace(Display *dpy, XEvent *ev);

#endif /* _OLWM_KBDFUNCS_H */
