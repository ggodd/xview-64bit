#if !defined(STAT_IMCB__H)
#define STAT_IMCB__H

#include <xview/pkg.h>
#ifdef OW_I18N
#include <X11/Xlib.h>

Xv_private void _xv_status_start(XIC *ic, XPointer client_data, XIMStatusDrawCallbackStruct *cb_data);
Xv_private void _xv_status_draw(XIC *ic, XPointer client_data, XIMStatusDrawCallbackStruct *cb_data);
Xv_private void _xv_status_done(XIC *ic, XPointer client_data, XIMStatusDrawCallbackStruct *cb_data);
#endif 

#endif

