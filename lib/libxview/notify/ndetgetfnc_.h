#if !defined(NDETGETFNC__H)
#define NDETGETFNC__H

#include <xview/pkg.h>
#include <xview_private/ntfy.h>

pkg_private Notify_func ndet_get_func(Notify_client nclient, NTFY_TYPE type, NTFY_DATA data, int use_data);

#endif

