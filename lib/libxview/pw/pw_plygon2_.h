#if !defined(PW_PLYGON2__H)
#define PW_PLYGON2__H

#include <xview/pkg.h>
#include <xview_private/pw_impl.h>

Xv_public int pw_polygon_2(register struct pixwin *pw, int dx, int dy, int nbds, int npts[], struct pr_pos *vlist, int op, struct pixrect *spr, int sx, int sy);

#endif

