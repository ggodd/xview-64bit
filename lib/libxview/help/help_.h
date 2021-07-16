#if !defined(HELP__H)
#define HELP__H

#include <xview/pkg.h>
#include <xview/window.h>


Xv_private void xv_help_save_image(Xv_Window pw, int client_width, int client_height, int mouse_x, int mouse_y);
Xv_private int xv_help_render(Xv_Window client_window, caddr_t client_data, Event *client_event);
Xv_public int xv_help_show(Xv_Window client_window, char *client_data, Event *client_event);

#endif

