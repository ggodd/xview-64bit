#if !defined(PF__H)
#define PF__H

#include <xview/pkg.h>
#include <pixrect/pixrect.h>
#include <pixrect/pixfont.h>

Xv_public Pixfont *xv_pf_default(void);
Xv_public Pixfont *xv_pf_open(char *fontname);
Xv_public Pixfont *xv_pf_open_private(char *fontname);
Xv_public int xv_pf_close(Pixfont* pf);
#ifdef SUNVIEW1
static Pixfont *xv_pf_load_vfont(char *fontname);
#endif

#endif

