#if !defined(NINT_INTER__H)
#define NINT_INTER__H

#include <xview/pkg.h>
#include <xview_private/ntfy.h>

pkg_private Notify_error nint_interpose_func(Notify_client nclient, Notify_func func, NTFY_TYPE type, caddr_t data, int use_data);

#endif

