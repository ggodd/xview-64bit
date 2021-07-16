#if !defined(NDET_DEATH__H)
#define NDET_DEATH__H

#include <xview/pkg.h>
#include <xview_private/ntfy.h>

pkg_private int ndet_check_status(Destroy_status status);
pkg_private NTFY_ENUM ndet_immediate_destroy(NTFY_CLIENT *client, register NTFY_CONDITION *condition, NTFY_ENUM_DATA context);

#endif

