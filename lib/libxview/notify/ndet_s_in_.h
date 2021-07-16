#if !defined(NDET_S_IN__H)
#define NDET_S_IN__H

#include <xview/pkg.h>
#include <xview_private/ntfy.h>

Notify_func notify_set_input_func(Notify_client nclient, Notify_func func, int fd);

#endif

