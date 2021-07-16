#ifndef _OLWM_SERVICES_H
#define _OLWM_SERVICES_H

#include <X11/Xresource.h>
#include "menu.h"

int ExecCommand(char **env, char *cmd);
void ExitCallback(Display *dpy, int button);
int ExitFunc(Display *dpy, WinGeneric *winInfo, MenuInfo *menuInfo, int idx);
int ExitNoConfirmFunc(Display *dpy, WinGeneric *winInfo, MenuInfo *menuInfo, int idx);
int AppMenuFunc(Display *dpy, WinGeneric *winInfo, MenuInfo *menuInfo, int idx);
int PshFunc(Display *dpy, WinGeneric *winInfo, MenuInfo *menuInfo, int idx);
int FlipDragFunc(Display *dpy, WinGeneric *winInfo, MenuInfo *menuInfo, int idx);
int FlipFocusFunc(Display *dpy, WinGeneric *winInfo, MenuInfo *menuInfo, int idx);
int NopFunc(Display *dpy, WinGeneric *winInfo, MenuInfo *menuInfo, int idx);
int ClipboardFunc(Display *dpy, WinGeneric *winInfo, MenuInfo *menuInfo, int idx);
int PrintScreenFunc(Display *dpy, WinGeneric *winInfo, MenuInfo *menuInfo, int idx);
void RecursiveRefresh(Display *dpy, Window win);
int RefreshFunc(Display *dpy, WinGeneric *winInfo, MenuInfo *menuInfo, int idx);
int PropertiesFunc(Display *dpy, WinGeneric *winInfo, MenuInfo *menuInfo, int idx);
int SaveWorkspaceFunc(Display *dpy, WinGeneric *winInfo, MenuInfo *menuInfo, int idx);
int ReReadUserMenuFunc(Display *dpy, WinGeneric *winInfo, MenuInfo *menuInfo, int idx);
int WindowOpenCloseAction(Display *dpy, WinGeneric *winInfo, MenuInfo *menuInfo, int idx);
int WindowFullRestoreSizeAction(Display *dpy, WinGeneric *winInfo, MenuInfo *menuInfo, int idx);
int WindowMoveAction(Display *dpy, WinGeneric *winInfo, MenuInfo *menuInfo, int idx);
int WindowResizeAction(Display *dpy, WinGeneric *winInfo, MenuInfo *menuInfo, int idx);
int WindowPropsAction(Display *dpy, WinGeneric *winInfo, MenuInfo *menuInfo, int idx);
int WindowBackAction(Display *dpy, WinGeneric *winInfo, MenuInfo *menuInfo, int idx);
int WindowRefreshAction(Display *dpy, WinGeneric *winInfo, MenuInfo *menuInfo, int idx);
int WindowStickAction(Display *dpy, WinGeneric *winInfo, MenuInfo *menuInfo, int idx);
int WindowQuitAction(Display *dpy, WinGeneric *winInfo, MenuInfo *menuInfo, int idx);
int WindowFlashOwnerAction(Display *dpy, WinGeneric *winInfo, MenuInfo *menuInfo, int idx);
int WindowDismissThisAction(Display *dpy, WinGeneric *winInfo, MenuInfo *menuInfo, int idx);
void _dismissSiblingMenus(Client *cli, WinGeneric *winInfo);
int WindowDismissAllAction(Display *dpy, WinGeneric *winInfo, MenuInfo *menuInfo, int idx);
int OpenCloseSelnFunc(Display *dpy, WinGeneric *winInfo, MenuInfo *menuInfo, int idx);
int FullRestoreSizeSelnFunc(Display *dpy, WinGeneric *winInfo, MenuInfo *menuInfo, int idx);
int BackSelnFunc(Display *dpy, WinGeneric *winInfo, MenuInfo *menuInfo, int idx);
int QuitSelnFunc(Display *dpy, WinGeneric *winInfo, MenuInfo *menuInfo, int idx);
int StickSelnFunc(Display *dpy, WinGeneric *winInfo, MenuInfo *menuInfo, int idx);
int StartDSDMFunc(Display *dpy, WinGeneric *winInfo, MenuInfo *menuInfo, int idx);
int StopDSDMFunc(Display *dpy, WinGeneric *winInfo, MenuInfo *menuInfo, int idx);

#endif
