#if !defined(WINCOLOR_H)
#define WINCOLOR_H

#include <X11/Xresource.h>

void ColormapInhibit(Bool inhibit);
void PreenColormapInhibit(Client *cli);
void InstallColormap(Display *dpy, WinGeneric *winInfo);
void InstallDefaultColormap(Display *dpy, WinGeneric *winInfo, Bool lock);
void LockColormap(Display *dpy, Client *cli, WinGeneric *winInfo);
void InstallPointerColormap(Display *dpy, Window root, int rootx, int rooty, Bool setfocusclient);
void UnlockColormap(Display *dpy, Window root, int rootx, int rooty);
void ColormapChange(Display *dpy, XEvent *event, WinGeneric *winInfo);
void ColorWindowCrossing(Display *dpy, XEvent *event, WinGeneric *winInfo);
void TrackSubwindows(Client *cli);
void UnTrackSubwindows(Client *cli, Bool destroyed);
void ColorUpdateColorMapWindows(Client *cli, XPropertyEvent *event);
WinColormap *MakeColormap(Client *cli, Window win);
void ColormapInit(Display *dpy);
void ColorFocusInit(Display *dpy, WinGeneric *root);
WinColormap *ColormapUnhook(Window w);
void ColormapTransmogrify(WinColormap *winc, WinPane *winp);

#endif

