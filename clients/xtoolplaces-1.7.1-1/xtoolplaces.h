/*Copyright (c) 1993-1998 Xerox Corporation.  All Rights Reserved.

  Permission to use, copy, modify  and  distribute  without  charge
  this  software,  documentation, images, etc. is granted, provided
  that this copyright and the author's name is retained.

  A fee may be charged for this program ONLY to recover  costs  for
  distribution  (i.e.  media costs).  No profit can be made on this
  program.

  The author assumes no responsibility for  disasters  (natural  or
  otherwise) as a consequence of use of this software.

  Adam Stein (adam@iset.scan.mc.xerox.com)
*/

/*User modifiable defines*/
#define APPSDIR "/usr/lib/X11/app-defaults"     /*Default resource directory*/
#define APPSFILENAME "Xtoolplaces"              /*Class name*/
#define CONSOLE_CLASS "XConsole"                /*Class of console windows*/
#define DEFAULT_FILENAME ".xtoolplaces"         /*Default name to save to*/
#define DEFAULT_PROGRAM "xtoolwait"		/*Default toolwait program*/
#define DEFAULT_REMOTE "rsh -n"                 /*Default remote command*/
#define HOME "HOME"                             /*Home environment variable*/
#define MAXAPPS 50				/*Max number in missing & ignore
						  lists*/
#define USER "USER"                             /*User environment variable*/

/*3 popular console terminal windows and the method to identify when
  they are present and in console mode since there is no console class*/
#define CONTOOL_NAME "Contool"                  /*Name given to contool window*/
#define SUN_TOOLS_ICON_NAME "CONSOLE"           /*Icon name for sun consoles*/
#define XTERM_OPTION "-C"                       /*Console option for xterm*/


/*Do not modify anything below this line*/

/*Global definitions*/
#define USAGE "[-a filename] [-c] [-display host:display.screen] [-f filename] [-i filename] [-m filename] [-p program] [-r command] [-s {list | all}] [-v] [-w]"
#define VERSION "1.7.1"                      	/*Version*/

/*Use the System 5 version of index() and rindex()*/
#ifdef ANSI_STR
# define index(s,c) (strchr(s,c))
# define rindex(s,c) (strrchr(s,c))
#endif

#include <X11/Xos.h>

#ifdef __STDC__
# include <stdlib.h>
#else /* __STDC__ */
# define const

char *malloc();

#ifdef NEED_STRDUP
char *strdup();
#endif /* NEED_STRDUP */

#ifdef NEED_STRSTR
char *strstr();
#endif /* NEED_STRSTR */
#endif /* __STDC__ */

extern unsigned int do_toolwait;
extern char *tw_str;

