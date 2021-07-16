#if !defined(NINT_I_FD__H)
#define NINT_I_FD__H

#include <xview/pkg.h>
#include <xview_private/ntfy.h>

Notify_error nint_interpose_fd_func(Notify_client nclient, Notify_func func, NTFY_TYPE type, int fd);

#endif

