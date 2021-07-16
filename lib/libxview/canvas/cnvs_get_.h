#if !defined(CNVS_GET__H)
#define CNVS_GET__H

#include <xview/pkg.h>
#include <xview/canvas.h>

Pkg_private Xv_opaque canvas_get_attr(Canvas canvas_public, int *stat, Attr_attribute attr, va_list valist);

#endif

