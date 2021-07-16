#ifndef lint
#ifdef sccs
static char     sccsid[] = "@(#)txt_data.c 1.15 93/06/28";
#endif
#endif

#include <xview_private/text_.h>
#include <xview_private/txt_attr_.h>
#include <xview_private/txt_once_.h>
#include <xview_private/txt_view_.h>

/*
 *	(c) Copyright 1989 Sun Microsystems, Inc. Sun design patents 
 *	pending in the U.S. and foreign countries. See LEGAL NOTICE 
 *	file for terms of the license.
 */

Xv_pkg          xv_textsw_pkg = {
    "Textsw",
    (Attr_pkg) ATTR_PKG_TEXTSW,
    sizeof(Xv_textsw),
    &xv_openwin_pkg,
    textsw_init,
    textsw_set,
    textsw_get,
    textsw_folio_destroy,
    NULL			/* no find proc */
};

Xv_pkg          xv_textsw_view_pkg = {
    "Textsw_view",
    (Attr_pkg) ATTR_PKG_TEXTSW_VIEW,
    sizeof(Xv_textsw_view),
    &xv_window_pkg,
    textsw_view_init,
    textsw_view_set,
    textsw_view_get,
    textsw_view_destroy,
    NULL			/* no find proc */
};
