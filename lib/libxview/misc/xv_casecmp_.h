#if !defined(XV_CASECMP__H)
#define XV_CASECMP__H

#include <xview/pkg.h>

int xv_strcasecmp(char *str1, char *str2);
int xv_strncasecmp(char *str1, char *str2, int n);
#ifdef OW_I18N
int xv_wscasecmp(CHAR *str1, CHAR *str2);
int xv_wsncasecmp(CHAR *str1, CHAR *str2, int n);
#endif 

#endif

