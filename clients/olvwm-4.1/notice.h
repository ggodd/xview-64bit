#ifdef IDENT
#ident	"@(#)notice.h	26.12	93/06/28 SMI"
#endif

/*
 *      (c) Copyright 1989 Sun Microsystems, Inc.
 */

/*
 *      Sun design patents pending in the U.S. and foreign countries. See
 *      LEGAL_NOTICE file for terms of the license.
 */

#ifndef _OLWM_NOTICE_H
#define _OLWM_NOTICE_H

#define NOTICE_CANCEL	(-1)

#define NOTICE_BUTTON_COUNT(b)	sizeof((b))/sizeof(char *)

typedef struct _noticeBox {
	int	numButtons;	/* number of buttons */
	int	defaultButton;	/* index into buttonText array */
	Text	**buttonText;	/* array of strings for button text */
	Text	*msgText;
	int	boxX;		/* box origin (-1 =use default/centered) */
	int	boxY;		/* box origin (-1 =use default/centered) */
} NoticeBox;

typedef struct {
	int		x;
	int		y;
	unsigned int	width;		/* space taken up by text */
	unsigned int	fullWidth;	/* width including endcaps */
	char		accelerator;	/* mouseless accelerator key */
} noticeButtonDetails;

typedef struct {
	Display			*dpy;
	ScreenInfo		*scrInfo;
	NoticeBox		*noticeBox;
	int			numStrings;
	Text			**stringText;
	Window			window;
	unsigned int		buttonHeight;
	unsigned int		fontHeight;
	unsigned int		boxHeight;
	unsigned int		boxWidth;
	int			x;
	int			y;
	int			totalButtonWidth;
	noticeButtonDetails	*buttonInfo;
	int			buttonSelected;
	int			buttonFocus;
	int			buttonDown;
	int			buttonDrawnDown;
	void			(*noticeCallback)();
	int			pointerX,pointerY;
	Bool			ignoreExpose;
	Bool			warped;
} noticeBoxDetails;

/* function declarations */
noticeBoxDetails *CreateNoticeBox(Display *dpy, int screen, NoticeBox *noticeBox, void (*callback)());
void DestroyNoticeBox(noticeBoxDetails *boxDetails);
void ShowNoticeBox(Display *dpy, noticeBoxDetails *details);
void UseNoticeBoxSync(Display *dpy, int screen, NoticeBox *noticeBox, void (*callback)());
int UseNoticeBox(Display *dpy, int screen, NoticeBox *noticeBox );

#endif /* _OLWM_NOTICE_H */
