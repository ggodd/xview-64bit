#ifndef _OLWM_CLIENT_H
#define _OLWM_CLIENT_H

#ifdef __STDC__
void ClientActivate(Display *dpy, Client *cli, Time timestamp);
void ClientBack(Client *cli);
void ClientConfigure(Client *cli, WinGeneric *win, XConfigureRequestEvent *pxcre);
void ClientDefaultWindowState(Display *dpy);
void ClientDistributeProperty(Client *cli, XPropertyEvent *event);
void ClientFlashOwner(Client *cli);
void ClientFocusTopmost(Display *dpy, ScreenInfo *scrinfo, Time timestamp);
void ClientFront(Client *cli);
void ClientFullRestoreSizeToggle(Client *cli, Time timestamp);
Client *ClientGetLastCurrent(void);
void ClientGetWindowState(Client *cli);
void *ClientInBox(Client *cli, ClientInBoxClosure *cclose);
void ClientInhibitFocus(Bool inhibit);
void *ClientKill(Client *cli, Bool pforce);
void ClientLowerTransients(Client *cli);
void ClientMove(Client *cli, XEvent *trigger);
void ClientOpenCloseToggle(Client *cli, Time timestamp);
void ClientProcessDragDropInterest(Client *cli, int state);
Client *ClientRaiseTransients(Client *cli);
void ClientRefresh(Client *cli);
void ClientResize(Client *cli, XEvent *trigger, WhichResize which, void (*callback)(), void *cbarg);
void ClientSetCurrent(Client *cli);
void ClientSetFocus(Client *cli, Bool sendTF, Time evtime);
void ClientSetInstanceVars(Client *cli);
void ClientSetWindowState(Client *cli);
void ClientSetWMState(Client *cli, WMState wmState);
void ClientStickUnstickToggle(Client *cli);
Bool ClientTogglePin(Client *cli);
void ClientToggleStacking(Client *cli);
void ClientUpdateBusy(Client *cli, XPropertyEvent *event);
void ClientUpdateDragDropInterest(Client *cli, XPropertyEvent *event);
void DestroyClient(Client *cli);
void DestroyPinnedMenuClients(void);
void InitClients(Display *dpy);
void VisitPinnedMenuClients(void (*pproc)(), void *extra);
#else
void ClientActivate();
void ClientBack();
void ClientConfigure();
void ClientDefaultWindowState();
void ClientDistributeProperty();
void ClientFlashOwner();
void ClientFocusTopmost();
void ClientFront();
void ClientFullRestoreSizeToggle();
Client *ClientGetLastCurrent();
void ClientGetWindowState();
void *ClientInBox();
void ClientInhibitFocus();
void *ClientKill();
void ClientLowerTransients();
void ClientMove();
void ClientOpenCloseToggle();
void ClientProcessDragDropInterest();
Client *ClientRaiseTransients();
void ClientRefresh();
void ClientResize();
void ClientSetCurrent();
void ClientSetFocus();
void ClientSetInstanceVars();
void ClientSetWindowState();
void ClientSetWMState();
void ClientStickUnstickToggle();
Bool ClientTogglePin();
void ClientToggleStacking();
void ClientUpdateBusy();
void ClientUpdateDragDropInterest();
void DestroyClient();
void DestroyPinnedMenuClients();
void InitClients();
void VisitPinnedMenuClients();
#endif

#endif
