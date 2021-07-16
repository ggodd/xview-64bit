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

#ifdef NEED_STRDUP

#include <stdio.h>
#include "xtoolplaces.h"

extern char *program;

/*Copy a string.

  Inputs:  s1      - string to copy
  Outputs: save_to - copied string
  Locals:  loop    - loop thru characters in string
           save_to - copied string
  Globals: program - name of currently executing program
           NULL    - 0
*/
char *strdup(s1)
const char *s1;
{
        int loop;
        char *save_to;

        if((save_to = malloc(strlen(s1) + 1)) == NULL) {
          perror(program);
          exit(1);
        }

        for(loop = 0;*s1;++s1,++loop)
          save_to[loop] = *s1;
        save_to[loop] = '\0';

        return(save_to);
}

#endif /*NEED_STRDUP*/

