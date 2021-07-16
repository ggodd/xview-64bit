#if !defined(WINPANE_H)
#define WINPANE_H

WinPane *MakePane(Client *cli, WinGeneric *par, Window win, XWindowAttributes *paneattrs);
void PaneInit(Display *dpy);

#endif

