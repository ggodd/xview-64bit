#if !defined(SYS_READ__H)
#define SYS_READ__H

#include <xview/pkg.h>
#include <xview_private/ntfy.h>


pkg_private int notify_read(int fd, char *buf, int nbytes);

#endif

