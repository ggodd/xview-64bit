/*
 *      (c) Copyright 1989, 1990 Sun Microsystems, Inc. Sun design patents
 *      pending in the U.S. and foreign countries. See LEGAL_NOTICE
 *      file for terms of the license.
 */
/* ----------------------------------------------------------------------
 *	propscmd.h
 * ---------------------------------------------------------------------*/
/* @(#) propscmd.h 1.3 93/06/28 Sun Micro */

#include "cmdstream.h"

#define		PW_SCREEN_NO		0
#define		PW_ATTR_COUNT		1

static	CmdAttr	propsCmdAttr[] = {
	{ "SCREEN_NO",	INT },
};

static Command propsCommand = {
	"SHOWPROPS", 0, PW_ATTR_COUNT, propsCmdAttr
};

#ifdef __STDC__
void RegisterPropsCmd(void);
void ReceivePropsCmd(Command *cmd);
#else
void RegisterPropsCmd();
void ReceivePropsCmd();
#endif
