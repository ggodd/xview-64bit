#if !defined(SYS_FCNTL__H)
#define SYS_FCNTL__H

#include <xview/pkg.h>
#include <xview_private/ntfy.h>

pkg_private int notify_fcntl(int fd, int cmd, int arg);

#endif
