#if !defined(NDETSELECT__H)
#define NDETSELECT__H

#include <xview/pkg.h>
#include <xview_private/ntfy.h>

int select(register int nfds, fd_set *readfds, fd_set *writefds, fd_set *exceptfds, struct timeval *timeout);

#endif

