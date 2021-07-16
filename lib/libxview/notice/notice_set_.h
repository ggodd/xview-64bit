#if !defined(NOTICE_SET__H)
#define NOTICE_SET__H

#include <xview/pkg.h>
#include <xview_private/noticeimpl.h>


Pkg_private Xv_opaque notice_set_avlist(register Xv_Notice notice_public, register Attr_attribute *avlist);
Pkg_private Xv_opaque notice_generic_set(register notice_handle notice, register Attr_attribute *avlist, Bool is_object);
Pkg_private int notice_do_show(Notice_info *notice);

#endif

