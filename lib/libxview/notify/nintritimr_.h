#if !defined(NINTRITIMR__H)
#define NINTRITIMR__H

#include <xview/pkg.h>
#include <xview_private/ntfy.h>

Notify_error notify_remove_itimer_func(Notify_client nclient, Notify_func func, int which);

#endif

