#ifndef _OLWM_CLIENT_H
#define _OLWM_CLIENT_H

#ifdef __STDC__
void ClientActivate(Display *dpy, Client *cli, Time time);
void ClientBack(Client *cli);
void ClientConfigure(Client *cli, WinGeneric *win, XConfigureRequestEvent *pxcre);
void ClientDefaultWindowState(Display *dpy);
void ClientDistributeProperty(Client *cli, XPropertyEvent *event);
void ClientFlashOwner(Client *cli);
void ClientFocusTopmost(Display *dpy, ScreenInfo *scrinfo, Time time);
void ClientFront(Client *cli);
void ClientFullRestoreSizeToggle(Client *cli, Time timestamp);
Client *ClientGetLastCurrent(void);
void ClientGetWindowState(Client *cli);
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
Bool ClientTogglePin(Client *cli);
void DestroyClient(Client *cli);
void InitClients(Display *dpy);
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
Bool ClientTogglePin();
void DestroyClient();
void InitClients();
#endif

#endif
