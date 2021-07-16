#if !defined(WINMENU_H)
#define WINMENU_H

WinMenu *MakeMenu(Display *dpy, WinGeneric *winInfo);
void MapMenuWindow(Display *dpy, WinMenu *winInfo, MenuInfo *menuInfo);
void UnmapMenuWindow(Display *dpy, WinMenu *winInfo);
int MenuEventExpose(Display *dpy, XEvent *event, WinGeneric *winInfo);
int MenuEventDrawMenu(Display *dpy, WinGeneric *winInfo);
void MenuInit(Display *dpy);

#endif

