#if !defined(NDETSEXCEP__H)
#define NDETSEXCEP__H

#include <xview/pkg.h>
#include <xview_private/ntfy.h>

Notify_func notify_set_exception_func(Notify_client nclient, Notify_func func, int fd);

#endif

