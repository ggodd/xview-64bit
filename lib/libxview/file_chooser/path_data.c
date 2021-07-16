#ifndef lint
#ifdef sccs
static char     sccsid[] = "@(#)path_data.c 1.4 93/06/28";
#endif
#endif

/*
 *	(c) Copyright 1989 Sun Microsystems, Inc. Sun design patents 
 *	pending in the U.S. and foreign countries. See LEGAL_NOTICE
 *	file for terms of the license.
 */


/*
 * Path package information
 */

#include <xview/xview.h>
#include <xview_private/path_.h>

Xv_pkg path_pkg = {
    "Path_name",
    ATTR_PKG_PATH,
    sizeof(Path_public),
    PANEL_TEXT,
    path_init_avlist,
    path_set_avlist,
    path_get_attr,
    path_destroy_private,
    NULL                     /* no find */
};
