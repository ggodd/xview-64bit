#if !defined(SITE__H)
#define SITE__H

#include <xview/pkg.h>
#include <xview_private/dndimpl.h>
#include <xview_private/site_impl.h>

Pkg_private Xv_opaque DndDropAreaOps(register Dnd_site_info *site, register Dnd_region_ops mode, register Xv_opaque area);
Pkg_private void DndSizeOfSite(register Dnd_site_info *site);
Xv_private int DndStoreSiteData(register Xv_drop_site site_public, register long **prop);

#endif

