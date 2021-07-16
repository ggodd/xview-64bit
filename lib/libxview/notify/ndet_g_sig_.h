#if !defined(NDET_G_SIG__H)
#define NDET_G_SIG__H

#include <xview/pkg.h>
#include <xview_private/ntfy.h>


Notify_func notify_get_signal_func(Notify_client nclient, int signal, Notify_signal_mode mode);

#endif

