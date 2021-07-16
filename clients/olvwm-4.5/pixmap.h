#ifndef _OLWM_PIXMAP_H
#define _OLWM_PIXMAP_H

#ifdef __STDC__
void FreePixmapColors(Display *dpy, int ncolors, XColor *colors, Colormap *colormap);
unsigned ImageSize(XImage *image);
Bool MakePixmap(Display *dpy, ScreenInfo *scrInfo, char *filename, PixInfo *pixinfo);
void doPseudo8(Display *dpy, Colormap *colormap, int ncolors, XColor *colors, XImage *in_image, XImage *out_image);
void doPseudo24(Display *dpy, Colormap *colormap, int ncolors, XColor *colors, XImage *in_image, XImage *out_image);
void doPseudo(Display *dpy, Colormap *colormap, int ncolors, XColor *colors, XImage *in_image, XImage *out_image);
void _swaplong(char *bp, unsigned n);
#else
void FreePixmapColors();
unsigned ImageSize();
Bool MakePixmap();
void doPseudo8();
void doPseudo24();
void doPseudo();
void _swaplong();
#endif

#endif
