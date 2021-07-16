#if !defined(WINBUSY_H)
#define WINBUSY_H

int widthfuncBusy(WinBusy *win, XConfigureRequestEvent *pxcre);
int heightfuncBusy(WinBusy *win, XConfigureRequestEvent *pxcre);
WinBusy *MakeBusy(Display* dpy, WinGenericFrame *par);
void BusyInit(Display *dpy);

#endif

