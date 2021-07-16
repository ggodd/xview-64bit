/*
 *      (c) Copyright 1989 Sun Microsystems, Inc. Sun design patents
 *      pending in the U.S. and foreign countries. See LEGAL_NOTICE
 *      file for terms of the license.
 */

#ifndef _OLWM_LIST_H
#define _OLWM_LIST_H

#ifdef IDENT
#ident	"@(#)list.h	26.6	91/09/14 SMI"
#endif

typedef struct _List {
	void *value;
	struct _List *next;
	} List;

#define NULL_LIST ((List *)0)

void ListInit(void);
List *ListCons(void *val, List *next);
int ListCount(List *l);
void ListDestroy(List *l);
void ListDestroyCell(List **l);
void *ListApply(List *l, void *(*f)(), void *c);
void *ListEnum(List **l);
List *ListDestroyCellByValue(void *val, List *l);
Bool ListIsAMember(void *val, List *l);
void ListReverse(List **l);

#endif /* _OLWM_LIST_H */
