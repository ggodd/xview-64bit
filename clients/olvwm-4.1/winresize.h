#if !defined(WINRESIZE_H)
#define WINRESIZE_H

WinResize *MakeResize(Display* dpy, WinGeneric *par, WhichResize which, int x, int y);
void ResizeInit(Display *dpy);

#endif

