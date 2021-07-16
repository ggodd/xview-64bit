#if !defined(REDUCE_H)
#define REDUCE_H

typedef struct
{
    long        value;
    XColor      *color;
} ColorHist;

typedef ColorHist *colorhist_vector;

int VDMPixCmp (ColorHist *el1, ColorHist *el2);
colorhist_vector ComputeColorHist(XImage *image, int maxcolors, XColor *pal, int *pNcolors);
XColor *reduce(XImage *image, int ncolors, XColor *pal, int n);

#endif

