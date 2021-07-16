#if !defined(NDETSEVENT__H)
#define NDETSEVENT__H

#include <xview/pkg.h>
#include <xview_private/ntfy.h>

Notify_func notify_set_event_func(Notify_client nclient, Notify_func func, Notify_event_type when);

#endif

