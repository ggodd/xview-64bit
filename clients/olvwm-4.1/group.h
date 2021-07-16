/*
 *      (c) Copyright 1990 Sun Microsystems, Inc. Sun design patents
 *      pending in the U.S. and foreign countries. See LEGAL_NOTICE
 *      file for terms of the license.
 */

#ifndef _OLWM_GROUP_H
#define _OLWM_GROUP_H

#ifdef IDENT
#ident	"@(#)group.h	26.6	91/09/14 SMI"
#endif

typedef Window GroupID;
typedef void *(*GroupFunc)(/* Client *, void * */);

typedef struct _group {
	GroupID groupid;
	Client *leader;
	List *dependents; 	/* List of Client * */
	List *independents; 	/* List of Client * */
	} Group;

#define GROUP_LEADER 0x01
#define GROUP_DEPENDENT 0x02
#define GROUP_INDEPENDENT 0x04

void GroupInit(void);
void *GroupApply(GroupID grpid, GroupFunc func, void *closure, unsigned int mask);
Group *GroupLookup(GroupID group);
Bool GroupAdd(GroupID grpid, Client *cli, unsigned int mask);
Bool GroupRemove(GroupID grpid, Client *cli);
Bool GroupIsLeader(GroupID grpid, Client *cli);
Client *GroupLeader(GroupID grpid);

#endif /* _OLWM_GROUP_H */
