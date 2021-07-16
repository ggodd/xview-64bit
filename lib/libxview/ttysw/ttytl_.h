#if !defined(TTYTL__H)
#define TTYTL__H

#include <xview/pkg.h>
#include <xview_private/tty_impl.h>
#include <xview_private/term_impl.h>

Pkg_private int ttytlsw_escape(Tty_view ttysw_view_public, char c, register int ac, register int *av);
Pkg_private int ttytlsw_string(caddr_t ttysw_public, CHAR type, CHAR c);

#endif

