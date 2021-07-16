#if !defined(NDETPDEATH__H)
#define NDETPDEATH__H

#include <xview/pkg.h>
#include <xview_private/ntfy.h>

Notify_error notify_post_destroy(Notify_client nclient, Destroy_status status, Notify_event_type when);

#endif

