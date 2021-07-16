#if !defined(NINTIEXCPT__H)
#define NINTIEXCPT__H

#include <xview/pkg.h>
#include <xview_private/ntfy.h>

Notify_error notify_interpose_exception_func(Notify_client nclient, Notify_func func, int fd);

#endif

