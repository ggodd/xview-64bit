#if !defined(WINROOT_H)
#define WINROOT_H

#include <X11/Xresource.h>

void HandleHelpKey(Display *dpy, XEvent *pEvent);
WinRoot *MakeRoot(Display *dpy, Client *cli);
void RootInit(Display *dpy);

#endif

