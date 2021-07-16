#if !defined(OPENWIN__H)
#define OPENWIN__H

#include <xview/pkg.h>
#include <xview/openwin.h>

Pkg_private int openwin_init(Xv_opaque parent, Xv_opaque owin_public, Xv_opaque *avlist);
Pkg_private int openwin_destroy(Openwin owin_public, Destroy_status destroy_status);
#ifndef NO_OPENWIN_PAINT_BG
Pkg_private void openwin_set_bg_color(Openwin  owin_public);
#endif 

#endif

