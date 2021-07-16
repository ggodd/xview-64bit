#if !defined(NINTI_WAIT__H)
#define NINTI_WAIT__H

#include <xview/pkg.h>
#include <xview_private/ntfy.h>

Notify_error notify_interpose_wait3_func(Notify_client nclient, Notify_func func, int pid);

#endif

