#if !defined(WINNOFOC_H)
#define WINNOFOC_H

WinGeneric *MakeNoFocus(Display* dpy, WinGeneric *par);
void NoFocusInit(Display *dpy);
void NoFocusTakeFocus(Display* dpy, Time evtime, ScreenInfo *scrInfo);
void NoFocusEventBeep(Display* dpy, XEvent *event, WinGeneric *winInfo);
Time TimeFresh(void);

#endif

