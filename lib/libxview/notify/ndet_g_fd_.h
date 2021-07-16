#if !defined(NDET_G_FD__H)
#define NDET_G_FD__H

#include <xview/pkg.h>
#include <xview_private/ntfy.h>

Notify_func ndet_get_fd_func(Notify_client nclient, int fd, NTFY_TYPE type);

#endif

