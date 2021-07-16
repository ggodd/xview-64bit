#if !defined(WINIPANE_H)
#define WINIPANE_H

WinIconPane *MakeIconPane(Client *cli, WinGeneric *par, XWMHints *wmHints, Bool fexisting);
void IconPaneInit(Display *dpy);
void IconPaneSetPixmap(Display* dpy, WinIconPane *winInfo, Pixmap pixmap);
void IconPaneSetMask(Display* dpy, WinIconPane *winInfo, Pixmap mask);

#endif

