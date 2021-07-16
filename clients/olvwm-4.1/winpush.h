#if !defined(WINPUSH_H)
#define WINPUSH_H

#include <X11/Xresource.h>

WinPushPin *MakePushPin(Display *dpy, WinGeneric *par, Window pane, int x, int y);
void PushPinInit(Display *dpy);
void PushPinChangePinState(Display *dpy, WinPushPin *winInfo, Bool sendDelete);
void PushPinSetPinState(Display *dpy, WinPushPin *winInfo, int newState, Bool sendDelete);
void PushPinTogglePinState(Display *dpy, WinPushPin *winInfo, Bool sendDelete);

#endif

