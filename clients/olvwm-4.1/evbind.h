#ifndef _OLWM_EVBIND_H
#define _OLWM_EVBIND_H

#ifdef __STDC__
#include <X11/Intrinsic.h>
#endif

#ifdef __STDC__
void SetProgKeys(Display *dpy, KeySym start_sym, KeySym end_sym, unsigned long modstate, Boolean off);
void GrabVKeys(Display *dpy, Bool grab, Bool virtual_only);
SemanticAction FindKeyboardAction(Display *dpy, XEvent *event);
void RefreshKeyGrabsFile(Display *dpy, XrmDatabase rdb, char *file);
SemanticAction ResolveMouseBinding(Display *dpy, XEvent *pevent, unsigned long ignoremask);
#else
void SetProgKeys();
void GrabVKeys();
SemanticAction FindKeyboardAction();
void RefreshKeyGrabsFile();
SemanticAction ResolveMouseBinding();
#endif

#endif
