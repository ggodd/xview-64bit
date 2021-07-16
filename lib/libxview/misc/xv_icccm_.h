#if !defined(XV_ICCCM__H)
#define XV_ICCCM__H

#include <X11/Xlib.h>


#ifdef PRE_R4_ICCCM
Status xv_iconify_window(Display *dpy, Window win, int scrn);
Status xv_withdraw_window(Display *dpy, Window win, int scrn);
#endif 

#endif

