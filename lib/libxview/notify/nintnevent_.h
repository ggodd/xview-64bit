#if !defined(NINTNEVENT__H)
#define NINTNEVENT__H

#include <xview/pkg.h>
#include <xview_private/ntfy.h>

Notify_value notify_next_event_func(Notify_client nclient, Notify_event event, Notify_arg arg, Notify_event_type when);

#endif

