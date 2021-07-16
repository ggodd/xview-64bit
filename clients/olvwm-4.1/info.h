#ifndef _OLWM_INFO_H
#define _OLWM_INFO_H

#include "st.h"

void WIInit(Display *dpy);
void WIInstallInfo(WinGeneric *info);
Bool WIUninstallInfo(Window win);
WinGeneric *WIGetInfo(Window win);
void WIApply(enum st_retval (*f)(), void *c);
void VInstallInfo(WinGeneric *info);
Bool VUninstallInfo(Window win);
WinGeneric *VGetInfo(Window win);

#endif
