#if !defined(XV_ERROR__H)
#define XV_ERROR__H

#include <xview/pkg.h>

Xv_public char *xv_error_format(Xv_object object, Attr_avlist avlist);
Xv_public int xv_error_default(Xv_object object, Attr_avlist avlist);
Xv_public int _xv_error(Xv_object object, ...);

#endif

