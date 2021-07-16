#ifndef _OLWM_STATES_H
#define _OLWM_STATES_H

#ifdef __STDC__
#include <X11/Intrinsic.h>
#endif

#ifdef __STDC__
void CheckBindingState(WinGenericFrame *win, Boolean focus);
void StateIconic(Client *cli, Time timestamp);
void StateInvisible(Client *cli, Time timestamp);
void StateNormal(Client *cli, Time timestamp);
void StateUpdateWMHints(Client *cli, XPropertyEvent *event);
void StateUpdateWMNormalHints(Client *cli, XPropertyEvent *event);
void StateUpdateWMProtocols(Client *cli, XPropertyEvent *event);
#else
void CheckBindingState();
void StateIconic();
void StateInvisible();
void StateNormal();
void StateUpdateWMHints();
void StateUpdateWMNormalHints();
void StateUpdateWMProtocols();
#endif

#endif
