#if !defined(WINICON_H)
#define WINICON_H

#include <X11/Xresource.h>

WinIconFrame *MakeIcon(Client *cli, Window panewin, XWindowAttributes *paneattrs);
void IconInit(Display *dpy);
void DrawIconToWindowLines(Display *dpy, WinIconFrame *iconInfo, WinPaneFrame *winInfo);
void IconUpdateName(Client *cli, XPropertyEvent *event);
void IconSetPos(WinIconFrame *win, int x, int y);
void IconShow(Client *cli, WinIconFrame *winIcon);
void IconHide(Client *cli, WinIconFrame *winIcon);
void IconUnparent(Client *cli, WinIconFrame *winIcon);

#endif

