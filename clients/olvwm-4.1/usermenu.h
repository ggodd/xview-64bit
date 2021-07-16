#ifndef _OLWM_USERMENU_H
#define _OLWM_USERMENU_H

#include "menu.h"

void WindowMenuCreate(Display* dpy, ScreenInfo *scrInfo);
void WindowMenuDestroy(Display *dpy);
void InitUserMenu(Display* dpy, ScreenInfo *scrInfo);
void ReInitUserMenu(Display* dpy, ScreenInfo *scrInfo, Bool forceReRead);
void RootMenuShow(Display* dpy, WinGeneric *winInfo, XEvent *pEvent);
void ReInitAllMenus(Display* dpy, ScreenInfo *scrInfo);
char *ExpandPath(char *pin, Bool messages);
void SetWindowMenuLabels(void);
void SetWindowMenuTitle(ScreenInfo *scrInfo);
void initMenuButtons(Display* dpy, ScreenInfo *scrInfo);
void InitMenus(Display* dpy, ScreenInfo *scrInfo);
void CreateWindowMenuInfo(Display* dpy, ScreenInfo *scrInfo);
Menu *GetEnabledMenu(Client *cli, Bool flfull, Bool flnotitle, Bool flsticky);
void ShowStandardMenuSync(WinGenericFrame *win, XEvent *eve, Bool flbutton, void (*proc)(), void *data);
void ShowStandardMenu(WinGenericFrame *win, XEvent *eve, Bool flbutton);

#endif
