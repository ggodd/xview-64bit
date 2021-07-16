#if !defined(DROP__H)
#define DROP__H

#include <xview/window.h>

int xv_decode_drop(Event *ev, char* buffer, unsigned int bsize);
static int HandleNewDrop(Event *ev, XClientMessageEvent *cM, Xv_window window, char* buffer, unsigned int bsize);

#endif

