#if !defined(WINFRAME_H)
#define WINFRAME_H

#include "win.h"
#include <X11/Xresource.h>

void FrameSetupGrabs(Client *cli, Window win, Bool activate);
void FrameAllowEvents(Client *cli, Time timestamp);
WinPaneFrame *MakeFrame(Client *cli, Window panewin, XWindowAttributes *paneattrs);
void FrameInit(Display *dpy);
void FrameGetGravityOffset(WinPaneFrame *frame, int *dx, int *dy);
void FrameMoveRelative(WinPaneFrame *win, int dx, int dy);
void FrameSetPosAbsolute(WinPaneFrame *win, int x, int y);
void FrameSetPosFromPane(WinPaneFrame *win, int x, int y);
void FrameUnparentPane(Client *cli, WinPaneFrame *winFrame, WinPane *winPane);
void FrameUpdateHeader(Client *cli, XPropertyEvent *event);
void FrameUpdateFooter(Client *cli, XPropertyEvent *event);
#ifdef OW_I18N_L4
void FrameUpdateIMStatus(Client *cli, XPropertyEvent *event);
#endif
void FrameFlashTitleBar(WinPaneFrame *winInfo);
void FrameSetBusy(WinPaneFrame *win, Bool newBusy);
void FrameWarpPointer(Client *cli);
void FrameUnwarpPointer(Client *cli);
void FrameUpdateShape(Client *cli, WinPaneFrame *winInfo);
void FrameMinSize(WinPaneFrame *frame, int *width, int *height);

#endif

