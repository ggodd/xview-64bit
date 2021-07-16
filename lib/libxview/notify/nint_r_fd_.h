#if !defined(NINT_R_FD__H)
#define NINT_R_FD__H

#include <xview/pkg.h>
#include <xview_private/ntfy.h>

pkg_private Notify_error nint_remove_fd_func(Notify_client nclient, Notify_func func, NTFY_TYPE type, int fd);

#endif

