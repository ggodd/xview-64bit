#if !defined(NINTREMOVE__H)
#define NINTREMOVE__H

#include <xview/pkg.h>
#include <xview_private/ntfy.h>

pkg_private Notify_error nint_remove_func(Notify_client nclient, Notify_func func, NTFY_TYPE type, caddr_t data, int use_data);

#endif

