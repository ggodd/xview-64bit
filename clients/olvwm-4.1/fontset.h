#if !defined(FONTSET_H)
#define FONTSET_H

XFontSet loadQueryFontSet(Display *dpy, char *font, char *locale);
void freeFontSet(Display *dpy, XFontSet fs);

#endif
