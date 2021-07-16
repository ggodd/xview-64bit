#if !defined(NOTICE_GET__H)
#define NOTICE_GET__H

#include <xview/pkg.h>
#include <xview/notice.h>


Pkg_private Xv_opaque notice_get_attr(Xv_notice_struct *notice_public, int *status, Notice_attribute attr, va_list valist);

#endif

