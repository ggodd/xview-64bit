#if !defined(CSR_INIT__H)
#define CSR_INIT__H

#include <xview/pkg.h>
#include <pixrect/pixrect.h>
#include <pixrect/pixfont.h>

Pkg_private int wininit(Xv_object win, int *maximagewidth, int *maximageheight);
#ifdef OW_I18N
Pkg_private void xv_new_tty_chr_font(Xv_opaque font);
#else
Pkg_private void xv_new_tty_chr_font(Pixfont *font);
#endif

#endif

