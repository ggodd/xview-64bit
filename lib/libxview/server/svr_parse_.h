#if !defined(SVR_PARSE__H)
#define SVR_PARSE__H

#include <xview/pkg.h>
#include <xview/server.h>
#include <xview_private/i18n_impl.h>
#include <X11/Xresource.h>


Xv_private int server_parse_keystr(Xv_server server_public, CHAR *keystr, KeySym *keysym, KeyCode *code, unsigned int *modifiers, unsigned int diamond_mask, char *qual_str);

#endif

