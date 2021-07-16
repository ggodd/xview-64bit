/*	@(#)scrn_impl.h 20.36 93/06/28 SMI	*/

/****************************************************************************/
/*	
 *	(c) Copyright 1989 Sun Microsystems, Inc. Sun design patents 
 *	pending in the U.S. and foreign countries. See LEGAL_NOTICE 
 *	file for terms of the license. 
 */
/****************************************************************************/

#ifndef _screen_impl_h_already_included
#define _screen_impl_h_already_included

#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <xview/pkg.h>
#include <xview/screen.h>
#include <xview_private/scrn_vis.h>
#include <xview/xv_xrect.h>
#include <xview/window.h>
#include <xview/cms.h>

typedef struct scrn_cache_window {
    Xv_window			window;
    short			busy;
    short			borders;
    Visual			*visual;
    struct scrn_cache_window	*next;
} Xv_cached_window;

typedef struct scrn_gc_list {
    int			 depth;
    GC			 gcs[SCREEN_OLGC_LIST_SIZE];
    struct scrn_gc_list *next;
} Screen_OLGC_List;

typedef struct {
    Xv_Screen		 public_self;		/* back pointer */
    int			 number;		/* screen number on server */
    Xv_opaque		 server;		/* always a Server */
    Xv_opaque		 root_window;		/* always a Window */
    XVisualInfo	        *visual_infos;	 	/* List of available visuals
						 * for this screen */
    int			 num_visuals;	  	/* number of available visuals
						 * for this screen */
    Screen_visual       *screen_visuals;	/* list of screen visuals
						 * (first is always default) */
    Cms			 default_cms;		
    Xv_xrectlist         clip_xrects;    	/* clipping rectangle list */
    Xv_cached_window    *cached_windows;
    short                retain_windows;  	/* retain leaf windows for
						 * perf */
    Screen_OLGC_List	*gc_list;		/* List of gc lists */
    int			*sun_wm_protocols;	/* Sun specific WM_PROTOCOLS */
    int			 num_sun_wm_protocols;	/* No. of protocols in above */
    Atom		 sel_state;
} Screen_info;

#define	SCREEN_PRIVATE(screen)	\
	XV_PRIVATE(Screen_info, Xv_screen_struct, screen)
#define	SCREEN_PUBLIC(screen)	XV_PUBLIC(screen)


#ifdef __STDC__

/* screen_get.c */
Pkg_private Xv_opaque screen_get_attr(Xv_Screen screen_public, int *status, Attr_attribute attr, va_list args);
Pkg_private XVisualInfo *screen_match_visual_info(Screen_info *screen, long mask, XVisualInfo *template);
Xv_private void screen_adjust_gc_color(Xv_Window window, int gc_index);

/* screen.c */
Pkg_private Xv_opaque screen_set_avlist(Xv_Screen screen_public, Attr_attribute avlist[]);
Xv_private int screen_get_sun_wm_protocols(Xv_Screen screen_public);
Xv_private int screen_check_sun_wm_protocols(Xv_Screen screen_public, Atom check_atom);
Xv_private void screen_set_clip_rects(Xv_Screen screen_public, XRectangle *xrect_array, int rect_count);

/* screen_layout.c */
#if defined(__alpha) || defined(__x86_64__) || defined(_XV_API_BROKEN_64BIT)
Pkg_private int screen_layout(Xv_Window root, Xv_Window child, Window_layout_op op, unsigned long *d1, unsigned long *d2, unsigned long *d3, unsigned long *d4, unsigned long *d5);
#else
Pkg_private int screen_layout();
#endif

#else

/* screen_get.c */
Pkg_private Xv_opaque screen_get_attr();
Pkg_private XVisualInfo *screen_match_visual_info();
Xv_private void screen_adjust_gc_color();

/* screen.c */
Pkg_private Xv_opaque screen_set_avlist();
Xv_private int screen_get_sun_wm_protocols();
Xv_private int screen_check_sun_wm_protocols();
Xv_private void screen_set_clip_rects();

/* screen_layout.c */
Pkg_private int screen_layout();

#endif


#endif
