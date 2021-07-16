/*      @(#)xview.h 1.2 89/04/09 SMI      */

/*
 *	(c) Copyright 1989 Sun Microsystems, Inc. Sun design patents 
 *	pending in the U.S. and foreign countries. See LEGAL NOTICE 
 *	file for terms of the license.
 */

#ifndef xview_xview_DEFINED
#define xview_xview_DEFINED

/*
 * Make sure NULL is something reasonable
 */

#ifdef __GNUC__
#include <stddef.h>
#endif

#ifndef NULL
#ifdef __STDC__
#define NULL	((void *)0)
#else
#define NULL	0
#endif
#endif

/*
 ***********************************************************************
 *			Include Files
 ***********************************************************************
 */

#include <xview/xview_xvin.h>
#include <xview/xv_version.h>

#include <xview/icon.h>
#include <xview/frame.h>
#include <xview/openmenu.h>

#endif /* ~xview_xview_DEFINED */
