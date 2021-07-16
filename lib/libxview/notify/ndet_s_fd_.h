#if !defined(NDET_S_FD__H)
#define NDET_S_FD__H

#include <xview/pkg.h>
#include <xview_private/ntfy.h>

Notify_func ndet_set_fd_func(Notify_client nclient, Notify_func func, int fd, NTFY_TYPE type);

#endif

