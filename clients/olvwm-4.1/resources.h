/*
* (c) Copyright 1990 Sun Microsystems, Inc. Sun design patents
* pending in the U.S. and foreign countries. See LEGAL_NOTICE
* file for terms of the license.
*/

#ifdef IDENT
#ident "@(#)resources.h 1.3 olvwm version 25 Nov 1992"
#endif

/*
* Based on
#ident "@(#)resources.h 26.16 91/09/14 SMI"
*
*/

#ifndef _OLWM_RESOURCES_H
#define _OLWM_RESOURCES_H

#include <X11/Xresource.h>

/* maximum length of fully-specified instance/class name */
#define MAX_NAME 100
#define MAX_CLASS 100

#define BASICPTR 0
#define MOVEPTR 1
#define BUSYPTR 2
#define ICONPTR 3
#define RESIZEPTR 4
#define MENUPTR 5
#define QUESTIONPTR 6
#define TARGETPTR 7
#define PANPTR 8
#define NUM_CURSORS 9 /* number of pointers supported */

/* resource table */

typedef struct _resourceitem {
    char *instance;
    char *class;
    char *defaultString;
    void *addr;
    Bool (*converter)();
    void (*updater)();
    unsigned long flags;
    XrmQuark instanceQ;
    XrmQuark classQ;
} ResourceItem;

extern XrmQuark TopClassQ;
extern XrmQuark TopInstanceQ;
extern XrmQuark OpenWinQ;
extern XrmQuark OlwmQ;
extern XrmDatabase OlwmDB;

void strnlower(char *dest, char *src, int n);
Bool MatchString(char *value, char *pattern);
Bool matchBool(char *value, Bool *ret);
Bool BoolString(char *s, Bool dflt);
#if defined (DEBUG) && defined (OW_I18N_L3)
void dump_locale(void);
#endif
void UpdFocusStyle(Display *dpy, ResourceItem *item, Bool *cur, Bool *new);
void ScanResourceItemTable(Display *dpy, ResourceItem *table, XrmDatabase rdb, char *oldlocale, unsigned long flags);
void InitGlobals(Display *dpy, XrmDatabase cmdDB);
void UpdateGlobals(Display *dpy);
#ifdef OW_I18N_L3
void EffectOLLC(Display *dpy, Bool initial, char *oldBasicLocale, char *oldDisplayLang);
#endif 
void ReInitAllUserMenus(Display *dpy);


#endif /* _OLWM_RESOURCES_H */
