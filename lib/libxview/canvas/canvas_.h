#if !defined(CANVAS__H)
#define CANVAS__H

#include <xview/pkg.h>
#include <xview/window.h>
#include <xview_private/cnvs_impl.h>

Pkg_private int canvas_init(Xv_Window parent, Canvas canvas_public, Attr_attribute avlist[]);
Pkg_private int canvas_destroy(Canvas canvas_public, Destroy_status stat);

#endif

