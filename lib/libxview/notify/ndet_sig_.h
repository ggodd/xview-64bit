#if !defined(NDET_SIG__H)
#define NDET_SIG__H

#include <xview/pkg.h>
#include <xview_private/ntfy.h>

pkg_private int ndet_check_mode(Notify_signal_mode mode, NTFY_TYPE *type_ptr);
pkg_private int ndet_check_sig(int sig);

#endif

