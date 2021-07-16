#if !defined(NINT_R_OUT__H)
#define NINT_R_OUT__H

#include <xview/pkg.h>
#include <xview_private/ntfy.h>

Notify_error notify_remove_output_func(Notify_client nclient, Notify_func func, int fd);

#endif

