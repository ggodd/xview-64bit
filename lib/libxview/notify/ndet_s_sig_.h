#if !defined(NDET_S_SIG__H)
#define NDET_S_SIG__H

#include <xview/pkg.h>
#include <xview_private/ntfy.h>

Notify_func notify_set_signal_func(Notify_client nclient, Notify_func func, int sig, Notify_signal_mode mode);

#endif

