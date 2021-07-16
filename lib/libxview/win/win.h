/*
 * Just some forward declarations...
 * -ukh
 */

#ifndef xview_win_DEFINED
#define xview_win_DEFINED

#include <xview/rectlist.h>
#include <xview/window.h>
#include <xview/win_input.h>

#ifdef __STDC__

/* win_bell.c */
Xv_private void win_beep(Display *display, struct timeval tv);
void win_bell(Xv_object window, struct timeval tv, Xv_object pw);

/* win_cursor.c */
void win_setmouseposition(Xv_object window, short x, short y);
void win_setmouseposition_internal(Display *display, unsigned int xid, short x, short y);
void win_getmouseposition(Xv_object window, short *x, short *y);

/* win_damage.c */
Xv_public int win_set_clip(Xv_object window, Rectlist *rl);
void win_clear_damage(Xv_object window);
Pkg_private int win_do_expose_event(Display *display, Event *event, register XExposeEvent *e, Xv_opaque *window, short collapse_exposures);
Xv_private int win_convert_to_x_rectlist(Rectlist *rl, XRectangle *xrect_array, int xrect_count);

/* win_geom.c */
Xv_private void win_getsize(Xv_object window, Rect *rect);
Xv_private int win_translate_xy_internal(Display *display, XID src_id, XID dst_id, int src_x, int src_y, int *dst_x, int *dst_y);
Xv_private void win_get_outer_rect(Xv_object window, Rect *rect);
Xv_private void win_getrect(Xv_object window, Rect *rect);
Xv_private void win_setrect(Xv_object window, Rect *rect);
Xv_private void win_set_outer_rect(Xv_object window, Rect *rect);
Xv_private void win_x_getrect(Display *display, XID xid, Rect *rect);
Xv_private int win_get_retained(Xv_object window);

/* win_global.c */
void win_lockdata(Xv_object window);
void win_unlockdata(Xv_object window);
void win_releaseio(Xv_object window);
int win_grabio(Xv_object window);
int win_xgrabio_sync(Xv_object window, Inputmask *im, Xv_object cursor_window, Xv_object cursor);

/* win_input.c */
void input_imnull(struct inputmask *im);
void input_imall(struct inputmask *im);
Xv_private void win_xmask_to_im(unsigned int xevent_mask, Inputmask *im);
Xv_private unsigned int win_im_to_xmask(Xv_object window, Inputmask *im);
int win_set_kbd_focus(Xv_object window, XID xid);

/* win_treeop.c */
Xv_private void win_change_property(Xv_object window, Server_attr property_name, Atom property_type, int data_size, unsigned char *property_data, int data_count);
void win_remove(Xv_object window);
void win_insert(Xv_object window);
Xv_public void win_setlink(Xv_object window, int linkname, XID number);
Xv_private int win_view_state(Display *display, XID xid);
Xv_private void win_set_parent(Xv_object window, Xv_object parent, int x, int y);
Xv_private void win_free(Xv_object window);

#else

/* win_bell.c */
Xv_private void win_beep();
void win_bell();

/* win_cursor.c */
void win_setmouseposition();
void win_setmouseposition_internal();
void win_getmouseposition();

/* win_damage.c */
Xv_public int win_set_clip();
void win_clear_damage();
Pkg_private int win_do_expose_event();
Xv_private int win_convert_to_x_rectlist();

/* win_geom.c */
Xv_private void win_getsize();
Xv_private int win_translate_xy_internal();
Xv_private void win_get_outer_rect();
Xv_private void win_getrect();
Xv_private void win_setrect();
Xv_private void win_set_outer_rect();
Xv_private void win_x_getrect();
Xv_private int win_get_retained();

/* win_global.c */
void win_lockdata();
void win_unlockdata();
void win_releaseio();
int win_grabio();
int win_xgrabio_sync();

/* win_input.c */
void input_imnull();
void input_imall();
Xv_private void win_xmask_to_im();
Xv_private unsigned int win_im_to_xmask();
int win_set_kbd_focus();

/* win_treeop.c */
Xv_private void win_change_property();
Xv_private void win_xmask_to_im();
void win_remove();
void win_insert();
Xv_public void win_setlink();
Xv_private int win_view_state();
Xv_private void win_set_parent();
Xv_private void win_free();

#endif

#endif
