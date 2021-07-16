#if !defined(NINT_I_IN__H)
#define NINT_I_IN__H

#include <xview/pkg.h>
#include <xview_private/ntfy.h>

Notify_error notify_interpose_input_func(Notify_client nclient, Notify_func func, int fd);

#endif

