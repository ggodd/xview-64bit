#if !defined(SETLOCALE__H)
#define SETLOCALE__H

#include <xview_private/i18n_impl.h>

#ifndef OS_HAS_LOCALE
char *setlocale(int category, char *locale);
#endif 

#endif

