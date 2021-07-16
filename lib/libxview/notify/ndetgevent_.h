#if !defined(NDETGEVENT__H)
#define NDETGEVENT__H

#include <xview/pkg.h>
#include <xview_private/ntfy.h>

Notify_func notify_get_event_func(Notify_client nclient, Notify_event_type when);

#endif

