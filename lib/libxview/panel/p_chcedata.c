#ifndef lint
#ifdef sccs
static char     sccsid[] = "@(#)p_chcedata.c 1.14 93/06/28";
#endif
#endif

/*
 *	(c) Copyright 1989 Sun Microsystems, Inc. Sun design patents 
 *	pending in the U.S. and foreign countries. See LEGAL NOTICE 
 *	file for terms of the license.
 */
#include <xview_private/p_choice_.h>

Xv_pkg          xv_panel_choice_pkg = {
    "Choice Item", ATTR_PKG_PANEL,
    sizeof(Xv_panel_choice),
    &xv_panel_item_pkg,
    choice_init,
    choice_set_avlist,
    choice_get_attr,
    choice_destroy,
    NULL			/* no find proc */
};
