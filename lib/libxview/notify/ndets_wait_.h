#if !defined(NDETS_WAIT__H)
#define NDETS_WAIT__H

#include <xview/pkg.h>
#include <xview_private/ntfy.h>

Notify_func notify_set_wait3_func(Notify_client nclient, Notify_func func, int pid);

#endif

