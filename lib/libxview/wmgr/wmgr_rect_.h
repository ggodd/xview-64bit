#if !defined(WMGR_RECT__H)
#define WMGR_RECT__H

#include <xview/pkg.h>
#include <xview/wmgr.h>

Xv_public void wmgr_completechangerect(Xv_opaque window, Rect *rectnew, Rect *rectoriginal, int parentprleft, int parentprtop);
Xv_public void wmgr_refreshwindow(Xv_opaque window);

#endif

