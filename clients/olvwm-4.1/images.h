#if !defined(IMAGES_H)
#define IMAGES_H

Button *MakeOpenButton(Display *dpy, ScreenInfo *scrInfo);
Button *MakeFullSizeButton(Display *dpy, ScreenInfo *scrInfo);
Button *MakeStickyButton(Display *dpy, ScreenInfo *scrInfo);
Button *MakePropertiesButton(Display *dpy, ScreenInfo *scrInfo);
Button *MakeBackButton(Display *dpy, ScreenInfo *scrInfo);
Button *MakeResizeButton(Display *dpy, ScreenInfo *scrInfo);
Button *MakeMoveButton(Display *dpy, ScreenInfo *scrInfo);
Button *MakeQuitButton(Display *dpy, ScreenInfo *scrInfo);
Button *MakeRefreshButton(Display *dpy, ScreenInfo *scrInfo);
Button *MakeDismissButton(Display *dpy, ScreenInfo *scrInfo);
Button *MakeDismissAllButton(Display *dpy, ScreenInfo *scrInfo);
Button *MakeDismissThisButton(Display *dpy, ScreenInfo *scrInfo);
Button *MakeOwnerButton(Display *dpy, ScreenInfo *scrInfo);
Button *MakeUpLeftButton(Display *dpy, ScreenInfo *scrInfo);
Button *MakeLeftButton(Display *dpy, ScreenInfo *scrInfo);
Button *MakeDownLeftButton(Display *dpy, ScreenInfo *scrInfo);
Button *MakeUpButton(Display *dpy, ScreenInfo *scrInfo);
Button *MakeHomeButton(Display *dpy, ScreenInfo *scrInfo);
Button *MakeDownButton(Display *dpy, ScreenInfo *scrInfo);
Button *MakeUpRightButton(Display *dpy, ScreenInfo *scrInfo);
Button *MakeRightButton(Display *dpy, ScreenInfo *scrInfo);
Button *MakeDownRightButton(Display *dpy, ScreenInfo *scrInfo);

#endif

