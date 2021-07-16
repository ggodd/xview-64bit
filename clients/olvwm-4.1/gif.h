#if !defined(GIF_H)
#define GIF_H

XImage *ReadGIF(Display *dpy, FILE *fd, int *pNcolors, XColor **pColors);

#endif
