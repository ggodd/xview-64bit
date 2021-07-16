#if !defined(SB__H)
#define SB__H

#include <xview/pkg.h>
#include <xview_private/sb_impl.h>

Pkg_private int scrollbar_create_internal(Xv_opaque parent, Xv_opaque sb_public, Xv_opaque *avlist);
Pkg_private void scrollbar_create_standard_menu(Xv_scrollbar_info *sb);

#endif

