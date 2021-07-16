#if !defined(NINTR_WAIT__H)
#define NINTR_WAIT__H

#include <xview/pkg.h>
#include <xview_private/ntfy.h>

Notify_error notify_remove_wait3_func(Notify_client nclient, Notify_func func, int pid);

#endif

