#if !defined(NINTIEVENT__H)
#define NINTIEVENT__H

#include <xview/pkg.h>
#include <xview_private/ntfy.h>

Notify_error notify_interpose_event_func(Notify_client nclient, Notify_func func, Notify_event_type when);

#endif

