#if !defined(HELP_FILE__H)
#define HELP_FILE__H

#include <xview/pkg.h>


Xv_private FILE *xv_help_find_file(char *filename);
Pkg_private int xv_help_get_arg(char *data, char **more_help);
Pkg_private char *xv_help_get_text(void);

#endif

