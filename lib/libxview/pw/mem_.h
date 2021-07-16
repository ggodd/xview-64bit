#if !defined(MEM__H)
#define MEM__H

#include <xview/pkg.h>
#include <pixrect/pixrect.h>
#include <xview_private/xv_.h>


Xv_private Pixrect *xv_mem_point(int w, int h, int depth, short *image);
Xv_private Pixrect *xv_mem_create(int w, int h, int depth);
Xv_private int xv_mem_destroy(Pixrect* pr);

#endif

