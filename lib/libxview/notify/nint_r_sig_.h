#if !defined(NINT_R_SIG__H)
#define NINT_R_SIG__H

#include <xview/pkg.h>
#include <xview_private/ntfy.h>

Notify_error notify_remove_signal_func(Notify_client nclient, Notify_func func, int signal, Notify_signal_mode mode);

#endif

