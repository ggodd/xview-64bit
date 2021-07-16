#if !defined(NDET_VALUE__H)
#define NDET_VALUE__H

#include <xview/pkg.h>
#include <xview_private/ntfy.h>

Notify_error notify_itimer_value(Notify_client nclient, int which, struct itimerval *value);

#endif

