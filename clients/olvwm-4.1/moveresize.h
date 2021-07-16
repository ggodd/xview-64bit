#if !defined(MOVERESIZE_H)
#define MOVERESIZE_H

typedef enum {
    Unconstrained,		/* resizing not constrained */
    EitherConstrained,		/* constrained, but no direction yet */
    HorizConstrained,		/* constrained horizontally */
    VertConstrained		/* constrained vertically */
} Constraint;

typedef enum {
    RS_LEFT = 0,
    RS_RIGHT,
    RS_UP,
    RS_DOWN,
    RS_J_LEFT,
    RS_J_RIGHT,
    RS_J_UP,
    RS_J_DOWN
} ResizeAction;

typedef struct {
    Display	*dpy;
    Window	win;
    int		ypos;
    int		width;
    int		height;
    XFontStruct	*font;
    ScreenInfo	*scrinfo;
} StatusWinInfo;

typedef struct {
    Display		*dpy;
    int			initX, initY;
    int			offX, offY;
    int			curX, curY;
    int			rounder, divider;
    List		*winlist;
    WinGenericFrame	*frame;
    StatusWinInfo	*statuswindow;
    char		*statusfmt;
    Constraint		constraint;
    Bool		dragwin;	    /* true=dragwin, false=dragframe */
    Bool		mouse;
    Bool		AutoRaise;	    /* orig value of autoraise */
/*
 * Virtual Desktop things
 */
    int			check_vdm;
    int			vdm_screenX;
    int			vdm_screenY;
    int			inVDM;
    VirtualDesktop	*vdm;
    int			targetScreenX;
    int			targetScreenY;
    int			initScreenX;
    int			initScreenY;
    Region		region;
    Window		*children;
    unsigned int	num_children;
    int			vdm_stacking_order;
} MoveClosure;

typedef struct {
    Client		*cli;
    Constraint		constraint;
    Bool		drawn;
    Bool		moving;
    Bool		useAspect;
    Bool		baseProvided;
    int			origX, origY;
    int			curX, curY;	/* current mouse position */
    int			winX, winY;	/* current window position */
    int			winW, winH;	/* current window height */
    int			minW, minH;
    int			maxW, maxH;
    int			incW, incH;
    int			minAspectX, minAspectY;
    int			maxAspectX, maxAspectY;
    int			baseW, baseH;
    int			borderW, borderH;   /* size of frame border */
    void		(*callback)();
    void		*cbarg;
    StatusWinInfo	*statuswindow;
    char		*statusfmt;
    int			gravity;		/* see note above */
    Bool		mouse;			/* using mouse? */
} ResizeClosure;

typedef struct _rootboxclosure {
    int x0, y0;
    int x, y;
    unsigned int w, h;
    WinRoot *rootWin;
    ScreenInfo *scrInfo;
    GC rootGC;
    void *closure;
    void (*callback)();
} RootBoxClosure;

void UserMoveWindows(Client *cli, XEvent *first);
void moveUpdate(MoveClosure *mstuff, XEvent *event);
void moveKeyDelta(MoveClosure *mstuff, int dx, int dy);
void resizeDelta(ResizeClosure *rstuff, ResizeAction action);
void UserResizeWin(Client *cli, XEvent *trigger, WhichResize corner, void (*callback)(), void *cbarg);
void TraceRootBox(Display *dpy, WinRoot *winInfo, XEvent *, void (*callback)(), void *closure);

#endif

