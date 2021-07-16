#if !defined(OL_BUTTON_413_H)
#define OL_BUTTON_413_H

#if !defined(SVR4) && !defined(XVIEW32)
void olgx_draw_button(Graphics_info *info, Window win, int x, int y, int width, int height, int label, int state);
void olgx_draw_varheight_button(Graphics_info *info, Window win, int x, int y, int width, int height, int state);
void olgx_draw_menu_mark(Graphics_info *info, Window win, int x, int y, int state, int fill_in);
void olgx_draw_abbrev_button(Graphics_info *info, Window win, int x, int y, int state);
void olgx_stipple_rect(Graphics_info *info, Window win, int x, int y, int width, int height);
#ifdef OW_I18N
void olgx_draw_text(Graphics_info *info, Window win, wchar_t *string, int x, int y, int max_width, int state);
#else
void olgx_draw_text(Graphics_info *info, Window win, char *string, int x, int y, int max_width, int state);
#endif 
void olgx_draw_pixmap_label(Graphics_info *info, Window win, Pixmappix, int x, int y, int width, int height, int state);
void olgx_draw_textscroll_button(Graphics_info *info, Window win, int x, int y, int state);
void olgx_draw_numscroll_button(Graphics_info *info, Window win, int x, int y, int state);
#endif 

#endif

