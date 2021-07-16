#if !defined(SCRN_LYOUT__H)
#define SCRN_LYOUT__H

#include <xview/pkg.h>
#include <xview_private/scrn_impl.h>

Pkg_private int screen_layout(register Xv_Window root, register Xv_Window child, Window_layout_op op, unsigned long *d1, unsigned long *d2, unsigned long *d3, unsigned long *d4, unsigned long *d5);

#endif

