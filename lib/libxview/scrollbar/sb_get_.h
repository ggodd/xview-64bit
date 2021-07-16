#if !defined(SB_GET__H)
#define SB_GET__H

#include <xview/pkg.h>
#include <xview_private/sb_impl.h>

Pkg_private Xv_opaque scrollbar_get_internal(Scrollbar scroll_public, int *status, Attr_attribute attr, va_list valist);

#endif

