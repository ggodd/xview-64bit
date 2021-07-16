#if !defined(OM_GET__H)
#define OM_GET__H

#include <xview/pkg.h>
#include <xview/openmenu.h>


Pkg_private Xv_opaque menu_gets(Menu menu_public, int *status, Attr_attribute attr, va_list args);
Pkg_private Xv_opaque menu_item_gets(Menu_item menu_item_public, int *status, Attr_attribute attr, va_list args);

#endif

