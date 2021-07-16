#ifndef _OLWM_EVBIND_H
#define _OLWM_EVBIND_H

#include <X11/Intrinsic.h>

typedef struct {
    KeySym sym;
    unsigned int mod;
} modsym;

SemanticAction ResolveMouseBinding(Display* dpy, XEvent *pevent, unsigned long ignoremask);
void AddKeyBinding(KeyCode kc, unsigned int mod, KeyDescriptor *desc);
unsigned int stringToModifier(Display* dpy, char *word);
unsigned int polyStringToModifier(Display* dpy, char *str);
KeyBinding *LookupKeyBinding(SemanticAction action);
SemanticAction FindKeyboardAction(Display* dpy, XEvent *event);
SemanticAction FindNewKeyboardAction(Display* dpy, XEvent *event);
Bool ExecuteKeyboardFunction(Display* dpy, XEvent *event);
void GrabVKeys(Display* dpy, Bool grab, Bool virtual_only);
void GrabKeys(Display* dpy, Bool grab);
void RefreshKeyGrabsFile(Display* dpy, XrmDatabase rdb, char *file);
void RefreshKeyGrabs(Display* dpy, XrmDatabase rdb);
void GrabButtons(Display* dpy, Bool grab);
void RefreshButtonGrabs(Display* dpy);
Bool UpdateBindings(Display* dpy, XrmDatabase newDB, Bool regrabKeys);
void InitBindings(Display *dpy);
void SetProgKeys(Display* dpy, KeySym start_sym, KeySym end_sym, unsigned long modstate, Boolean off);

#endif
