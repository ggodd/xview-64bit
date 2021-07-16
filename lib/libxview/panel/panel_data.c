#ifndef lint
#ifdef sccs
static char     sccsid[] = "@(#)panel_data.c 1.17 93/06/28";
#endif
#endif

/*
 *	(c) Copyright 1989 Sun Microsystems, Inc. Sun design patents 
 *	pending in the U.S. and foreign countries. See LEGAL NOTICE 
 *	file for terms of the license.
 */
#include <xview_private/panel_.h>
#include <xview_private/p_gauge_.h>
#include <xview_private/p_get_.h>
#include <xview_private/p_set_.h>
#include <xview_private/p_slider_.h>
#include <xview_private/p_view_.h>

Xv_pkg          xv_panel_pkg = {
    "Panel", ATTR_PKG_PANEL,
    sizeof(Xv_panel),
    &xv_window_pkg,
    panel_init,
    panel_set_avlist,
    panel_get_attr,
    panel_destroy,
    NULL			/* no find proc */
};
Xv_pkg          xv_scrollable_panel_pkg = {
    "Panel", ATTR_PKG_PANEL,
    sizeof(Xv_panel),
    &xv_canvas_pkg,
    panel_init,
    panel_set_avlist,
    panel_get_attr,
    panel_destroy,
    NULL			/* no find proc */
};


Xv_pkg          xv_panel_view_pkg = {
    "Panel", ATTR_PKG_PANEL,
    sizeof(Xv_panel),
    &xv_canvas_view_pkg,
    panel_view_init,
    NULL,
    NULL,
    NULL,
    NULL			/* no find proc */
};

Xv_pkg          xv_panel_gauge_pkg = {
    "Slider Item", ATTR_PKG_PANEL,
    sizeof(Xv_panel_gauge),
    &xv_panel_item_pkg,
    gauge_init,
    gauge_set_avlist,
    gauge_get_attr,
    gauge_destroy,
    NULL			/* no find proc */
};

Xv_pkg          xv_panel_slider_pkg = {
    "Slider Item", ATTR_PKG_PANEL,
    sizeof(Xv_panel_slider),
    &xv_panel_item_pkg,
    slider_init,
    slider_set_avlist,
    slider_get_attr,
    slider_destroy,
    NULL			/* no find proc */
};
