/*
 *      (c) Copyright 1989, 1990 Sun Microsystems, Inc. Sun design patents
 *      pending in the U.S. and foreign countries. See LEGAL_NOTICE
 *      file for terms of the license.
 */

#ifndef _OLWM_OLWM_H
#define _OLWM_OLWM_H

#ifdef IDENT
#ident "@(#)olwm.h	1.5 olvwm version 07 Jan 1994"
#endif

/*
 * Based on
#ident	"@(#)olwm.h	26.27	93/06/28 SMI"
 *
 */

#ifndef ABS
#define ABS(a)		(((a) < 0) ? -(a) : (a))
#endif

#ifndef MAX
#define	MAX(a,b)	(((a) > (b)) ? (a) : (b))
#endif

#ifndef MIN
#define MIN(a,b)        ((a) < (b) ? (a) : (b))
#endif

/*
 * path and file name lengths -- if not defined already
 */
#ifndef MAXPATHLEN
#define MAXPATHLEN 1024
#endif
#ifndef MAXNAMELEN
#define MAXNAMELEN 256
#endif

/* Determine the size of an object type in 32bit multiples.
 * Rounds up to make sure the result is large enough to hold the object. */
#define LONG_LENGTH(a)	((long)(( sizeof(a) + 3 ) / 4))

#define	FOOTLEN	50L

/* protocols bits */
#define		TAKE_FOCUS		(1<<0)
#define		SAVE_YOURSELF		(1<<1)
#define		DELETE_WINDOW		(1<<2)

/* Workspace Background Styles */
typedef enum { WkspDefault, WkspColor, WkspPixmap } WorkspaceStyle;

/* Icon positioning modes */
typedef enum { AlongTop, AlongBottom, AlongRight, AlongLeft,
	       AlongTopRL, AlongBottomRL, AlongRightBT, AlongLeftBT
	     } IconPreference;

/* size of icon window */
#define ICON_WIN_WIDTH 60
#define ICON_WIN_HEIGHT 60
#define ICON_GRID_WIDTH (GRV.IconGridWidth)
#define ICON_GRID_HEIGHT (GRV.IconGridHeight)

/* min/max/inc icon sizes */
#define ICON_MIN_WIDTH 		1
#define ICON_MIN_HEIGHT 	1
#define ICON_MAX_WIDTH		160
#define ICON_MAX_HEIGHT		160
#define ICON_WIDTH_INC		1
#define ICON_HEIGHT_INC		1

/* minimum window size */
#define MINSIZE 5

/* Globals */
extern  char   *ProgramName;

/* adornment pixmaps */
extern	Pixmap	pixIcon;
extern	Pixmap	pixmapGray;
extern	Pixmap	pixGray;


/* no-focus window information and functions */
extern Window NoFocusWin;
extern struct _wingeneric *NoFocusWinInfo;


/* client information and functions */
extern struct _List *ActiveClientList;

typedef struct _clientinboxclose {
	Display *dpy;
	int 	screen;
	int 	(*func)();
	short 	bx, by, bw, bh;
	Time 	timestamp;
} ClientInBoxClosure;

void Exit(Display *dpy);
int RestartOLWM(void);
int ExitOLWM(void);
void ReapChildren(void);

#endif /* _OLWM_OLWM_H */
