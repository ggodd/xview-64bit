#if !defined(NDET_S_OUT__H)
#define NDET_S_OUT__H

#include <xview/pkg.h>
#include <xview_private/ntfy.h>

Notify_func notify_set_output_func(Notify_client nclient, Notify_func func, int fd);

#endif

