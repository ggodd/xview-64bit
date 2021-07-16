#if !defined(NINTIITIMR__H)
#define NINTIITIMR__H

#include <xview/pkg.h>
#include <xview_private/ntfy.h>

Notify_error notify_interpose_itimer_func(Notify_client nclient, Notify_func func, int which);

#endif

