#if !defined(NINT_SET__H)
#define NINT_SET__H

#include <xview/pkg.h>
#include <xview_private/ntfy.h>

pkg_private Notify_func nint_set_func(register NTFY_CONDITION *cond, Notify_func new_func);

#endif

