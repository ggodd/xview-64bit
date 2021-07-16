#if !defined(WINDOW_SET__H)
#define WINDOW_SET__H

#include <xview/pkg.h>
#include <xview_private/windowimpl.h>

Pkg_private Xv_opaque window_set_avlist(Xv_Window win_public, Attr_attribute avlist[]);
Pkg_private void sync_rect(Window_info *win, Rect *old_rect, Rect *new_rect);
Xv_private void window_get_grab_flag(void);
Xv_private void window_release_selectbutton(Xv_Window window, Event *event);
Xv_private void window_x_allow_events(Display *display);



#endif

