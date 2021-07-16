#if !defined(ITEM_SET__H)
#define ITEM_SET__H

#include <xview/pkg.h>
#include <xview_private/panel_impl.h>


Pkg_private Xv_opaque item_set_avlist(Panel_item item_public, Attr_avlist avlist);
Pkg_private void panel_fix_label_position(register Item_info *ip);
Xv_private void panel_item_parent(Panel_item item, Panel parent);

#endif

