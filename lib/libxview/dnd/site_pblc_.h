#if !defined(SITE_PBLC__H)
#define SITE_PBLC__H

#include <xview/pkg.h>
#include <X11/Xresource.h>
#include <xview_private/dndimpl.h>

Pkg_private int dnd_site_init(Xv_Window owner, Xv_drop_site site_public, Attr_avlist avlist);
Pkg_private Xv_opaque dnd_site_set_avlist(Xv_drop_site site_public, Attr_attribute avlist[]);
Pkg_private Xv_opaque dnd_site_get_attr(Xv_drop_site site_public, int *error, Attr_attribute attr, va_list args);
Pkg_private int dnd_site_destroy(Xv_drop_site site_public, Destroy_status state);

#endif

