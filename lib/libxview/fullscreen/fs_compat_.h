#if !defined(FS_COMAPAT__H)
#define FS_COMAPAT__H

#include <xview/pkg.h>
#include <xview/fullscreen.h>


Xv_public struct fullscreen *fullscreen_init(Xv_Window window);
Xv_public int fullscreen_set_cursor(struct fullscreen *fs, Xv_Cursor cursor);
Xv_public int fullscreen_set_inputmask(struct fullscreen *fs, Inputmask *im);
Xv_public int fullscreen_destroy(struct fullscreen *fs);

#endif

