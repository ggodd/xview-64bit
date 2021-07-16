#ifndef _OLWM_USERMENU_H
#define _OLWM_USERMENU_H

#ifdef __STDC__
void CreateWindowMenuInfo(Display *dpy, ScreenInfo *scrInfo);
Menu *GetEnabledMenu(Client *cli, Bool flfull, Bool flnotitle, Bool flsticky);
void RootMenuShow(Display *dpy, WinGeneric *winInfo, XEvent *pEvent);
void ReInitUserMenu(Display *dpy, ScreenInfo  *scrInfo, Bool forceReRead);
void SetWindowMenuTitle(ScreenInfo *scrInfo);
void ShowStandardMenu(WinGenericFrame *win, XEvent *eve, Bool flbutton);
void ShowStandardMenuSync(WinGenericFrame *win, XEvent *eve, Bool flbutton, void (*proc)(), void *data);
void WindowMenuCreate(Display *dpy, ScreenInfo *scrInfo);
#else
void CreateWindowMenuInfo();
Menu *GetEnabledMenu();
void RootMenuShow();
void ReInitUserMenu();
void SetWindowMenuTitle();
void ShowStandardMenu();
void ShowStandardMenuSync();
void WindowMenuCreate();
#endif

#endif
