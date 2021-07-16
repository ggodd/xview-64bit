#ifndef _OLWM_PIXMAP_H
#define _OLWM_PIXMAP_H

typedef enum { BadFormat, XBitmapFormat,
                SunIconFormat, XPixmapFormat, GifFormat } ImageFormat;

void _swaplong (register char *bp, register unsigned n);
unsigned ImageSize(XImage *image);
int readGifFile(Display* dpy, ScreenInfo *scrInfo, Drawable drawable, char *fn, unsigned int *w, unsigned int *h, Pixmap *pPix, int *hotx, int *hoty, Colormap *colormap, int *ncolors, XColor **colors);
void FreePixmapColors(Display* dpy, int ncolors, XColor *colors, Colormap *colormap);
void doPseudo8(Display* dpy, Colormap *colormap, int ncolors, XColor *colors, register XImage *in_image, register XImage *out_image);
void doPseudo24(Display* dpy, Colormap *colormap, int ncolors, XColor *colors, register XImage *in_image, register XImage *out_image);
void doPseudo(Display* dpy, Colormap *colormap, int ncolors, XColor *colors, register XImage *in_image, register XImage *out_image);
#ifdef SUNICON
SunReadIconFile(Display* dpy, Window drawable, char *filename, int *width, int *height, Pixmap *bitmap);
#endif 
ImageFormat imageFileFormat(char *filename);
Bool MakePixmap(Display* dpy, ScreenInfo *scrInfo, char *filename, PixInfo *pixinfo);

#endif
