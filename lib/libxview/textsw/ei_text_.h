#if !defined(EI_TEXT__H)
#define EI_TEXT__H

#include <xview/pkg.h>
#include <xview_private/ei.h>

Pkg_private Ei_handle ei_plain_text_create(void);
Pkg_private int ei_plain_text_line_height(Ei_handle eih);
int ei_plain_text_set(Ei_handle eih, Attr_attribute *attributes);

#endif

