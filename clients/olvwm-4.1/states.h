#ifndef _OLWM_STATES_H
#define _OLWM_STATES_H

#include <X11/Intrinsic.h>
#include <X11/Xresource.h>

WMDecorations *getOLWinDecors(Display* dpy, Window win, Bool transient, Client *cli);
int stateGetScreen(Client *cli);
Client *StateNew(Display* dpy, Window rootWin, Window window, Bool fexisting, WinPane *ourWinInfo);
void ReparentTree(Display* dpy, Window treeroot);
void StateIconic(Client *cli, Time timestamp);
void StateNormal(Client *cli, Time timestamp);
void StateWithdrawn(Client *cli, Time timestamp);
void StateInvisible(Client *cli, Time timestamp);
void StateUpdateWMNormalHints(Client *cli, XPropertyEvent *event);
void StateUpdateWMHints(Client *cli, XPropertyEvent *event);
void StateUpdateWMProtocols(Client *cli, XPropertyEvent *event);
void StateUpdateWinAttr(Client *cli, XPropertyEvent *event);
void StateUpdateDecorAdd(Client *cli, XPropertyEvent *event);
void StateUpdateDecorDel(Client *cli, XPropertyEvent *event);
void CheckBindingState(WinGenericFrame *win, Boolean focus);

#endif
