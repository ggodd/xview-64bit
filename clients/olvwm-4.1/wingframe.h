#if !defined(WINGFRAME_H)
#define WINGFRAME_H

void autoRaise(WinGenericFrame *frame);
int GFrameSelect(Display* dpy, WinGeneric *winInfo, Bool selected);
int GFrameFocus(Display* dpy, WinGenericFrame *winInfo, Bool focus);
int GFrameSetConfigFunc(Display* dpy, WinGenericFrame *win);
void GFrameSetStack(WinGenericFrame *win, int mask, int mode, Window sib);
void GFrameSetConfig(WinGenericFrame *win, int x, int y, int w, int h);
void GFrameEventButtonRelease(Display* dpy, XEvent *event, WinGenericFrame *frameInfo);
void GFrameEventMotionNotify(Display* dpy, XEvent *event, WinGenericFrame *frameInfo);
int GFrameEventButtonPress(Display* dpy, XEvent *event, WinGenericFrame *frameInfo);
int GFrameEventEnterNotify(Display* dpy, XEvent *event, WinGenericFrame *frameInfo);
int GFrameEventFocus(Display* dpy, XEvent *event, WinGenericFrame *frameInfo);

#endif

