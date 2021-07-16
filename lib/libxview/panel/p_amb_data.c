#ifndef lint
#ifdef sccs
static char     sccsid[] = "@(#)p_amb_data.c 1.5 93/06/28";
#endif
#endif

/*
 *	(c) Copyright 1990 Sun Microsystems, Inc. Sun design patents 
 *	pending in the U.S. and foreign countries. See LEGAL NOTICE 
 *	file for terms of the license.
 */
#include <xview_private/p_ambtn_.h>

Xv_pkg          xv_panel_ambtn_pkg = {
    "Abbreviated Menu Button Item",
    ATTR_PKG_PANEL,
    sizeof(Xv_panel_ambtn),
    &xv_panel_item_pkg,
    panel_ambtn_init,
    panel_ambtn_set_avlist,
    NULL,
    panel_ambtn_destroy,
    NULL			/* no find proc */
};
