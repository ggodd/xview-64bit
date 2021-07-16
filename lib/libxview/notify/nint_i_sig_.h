#if !defined(NINT_I_SIG__H)
#define NINT_I_SIG__H

#include <xview/pkg.h>
#include <xview_private/ntfy.h>

Notify_error notify_interpose_signal_func(Notify_client nclient, Notify_func func, int signal, Notify_signal_mode mode);

#endif

