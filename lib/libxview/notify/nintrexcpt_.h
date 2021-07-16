#if !defined(NINTREXCPT__H)
#define NINTREXCPT__H

#include <xview/pkg.h>
#include <xview_private/ntfy.h>

Notify_error notify_remove_exception_func(Notify_client nclient, Notify_func func, int fd);

#endif

