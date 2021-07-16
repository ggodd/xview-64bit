#if !defined(NDETSITIMR__H)
#define NDETSITIMR__H

#include <xview/pkg.h>
#include <xview_private/ntfy.h>

Notify_func notify_set_itimer_func(Notify_client nclient, Notify_func func, int which, struct itimerval *value, struct itimerval *ovalue);

#endif

