#if !defined(NDET_FCNTL__H)
#define NDET_FCNTL__H

#include <xview/pkg.h>

#ifndef __linux__
#ifdef SVR4
int xv_fcntl(int fd, int cmd, int arg);
#else
int fcntl(int fd, int cmd, int arg);
#endif /* SVR4 */
#endif

#endif

