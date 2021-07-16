#ifdef IDENT
#ident	"@(#)mem.h	26.15	93/06/28 SMI"
#endif

/*
 *      (c) Copyright 1989 Sun Microsystems, Inc.
 */

/*
 *      Sun design patents pending in the U.S. and foreign countries. See
 *      LEGAL_NOTICE file for terms of the license.
 */

#ifndef _OLWM_MEM_H
#define _OLWM_MEM_H

#ifdef MEMDEBUG

#define MemAlloc(s)	d_MemAlloc((s), __FILE__, __LINE__, NULL)
#define MemCalloc(n,s)	d_MemCalloc((n),(s), __FILE__, __LINE__)
#define MemFree(p)	d_MemFree(p)
#define MemRealloc(p,s)	d_MemRealloc((p),(s))

#define MemNew(X) 	d_MemAlloc(sizeof(X), __FILE__, __LINE__, #X)
#define MemNewString(s) (strcpy(d_MemAlloc(strlen(s)+1,__FILE__,__LINE__,"(string)"),s))

extern int MemAcct;
extern int AcctTag;
#else
#define MemNew(t) ((t *)MemAlloc((unsigned int)sizeof(t)))
#define MemNewString(s) (strcpy((char *)MemAlloc(strlen(s)+1),s))
#endif /* MEMDEBUG */

#ifdef OW_I18N_L4

#define MemNewText(s)	wscpy((wchar_t *)MemAlloc((wslen(s)+1)*sizeof(wchar_t)),s)

#else

#define MemNewText(s)	MemNewString((char *)s)

#endif /* OW_I18N_L4 */

#ifdef MEMDEBUG
void DumpExtant(void);
#endif
void *MemAllocN(unsigned int sz
#ifdef MEMDEBUG
, char *f, int l, char *k
#endif
);
void *MemAlloc(unsigned int sz
#ifdef MEMDEBUG
, char *f, int l, char *k
#endif
);
void *MemCalloc(unsigned int num, unsigned int sz
#ifdef MEMDEBUG
, char *f, int l
#endif
);
void *MemRealloc(void *p, unsigned int sz);
void MemFree(void *p);

#endif /* _OLWM_MEM_H */
