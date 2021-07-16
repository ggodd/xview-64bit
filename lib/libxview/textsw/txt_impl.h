/*	@(#)txt_impl.h 20.73 93/06/28 SMI	*/

/*
 *	(c) Copyright 1989 Sun Microsystems, Inc. Sun design patents 
 *	pending in the U.S. and foreign countries. See LEGAL NOTICE 
 *	file for terms of the license.
 */

#define TEXTSW_DO_INSERT_MAKES_VISIBLE(_view)\
{\
     if ((folio->insert_makes_visible == TEXTSW_ALWAYS) &&\
         (folio->state & TXTSW_DOING_EVENT) &&\
         (!EV_INSERT_VISIBLE_IN_VIEW(_view->e_view)))\
        textsw_normalize_internal(_view, EV_GET_INSERT(folio->views),\
	   ES_INFINITY, 0,\
           (int)ev_get((Ev_handle)_view->e_view,\
                        EV_CHAIN_LOWER_CONTEXT),\
           TXTSW_NI_AT_BOTTOM|TXTSW_NI_NOT_IF_IN_VIEW|TXTSW_NI_MARK);\
}


#define TEXTSW_OUT_OF_MEMORY(_folio, _status)\
     ((status == ES_SHORT_WRITE) && (ES_TYPE_MEMORY == (Es_enum)es_get((Es_handle)es_get(folio->views->esh, ES_PS_SCRATCH), ES_TYPE)))

#ifndef textsw_impl_DEFINED
#define textsw_impl_DEFINED
/*
 * Internal structures for textsw implementation.
 */

#				ifndef timerclear
#include <sys/time.h>
#				endif
#include <xview/pkg.h>
#				ifndef NOTIFY_DEFINED
#include <xview/notify.h>
#				endif
#				ifndef scrollbar_DEFINED
#include <xview/scrollbar.h>
#				endif
#				ifndef suntool_entity_view_DEFINED
#include <xview_private/ev.h>
#				endif
#				ifndef suntool_selection_svc_DEFINED
#include <xview/sel_svc.h>
#				endif
#				ifndef suntool_selection_attributes_DEFINED
#include <xview/sel_attrs.h>
#				endif
#				ifndef suntool_textsw_DEFINED
#include <xview/textsw.h>
#				endif
#include <xview/attrol.h>
#include <xview/cursor.h>	/* laf */
#include <xview/frame.h>
#include <xview/openmenu.h>
#include <xview/dragdrop.h>

#ifdef OW_I18N
#include <xview_private/i18n_impl.h> 
#include <xview_private/convpos.h>
#endif /* OW_I18N */


/* Although not needed to support types used in this header file, the
 * following are needed to support macros defined here.
 */
#				ifndef sunwindow_win_input_DEFINED
#include <xview/win_input.h>
#				endif

#ifndef	NULL
#ifdef __STDC__
#define NULL	((void *)0)
#else
#define	NULL	0
#endif
#endif

#define TEXTSW_PRIVATE(t)     \
		   XV_PRIVATE(Text_object, Xv_textsw, t)
#define TEXTSW_PUBLIC(textsw_folio_object)  \
		   XV_PUBLIC(textsw_folio_object)

#define VIEW_PRIVATE(t)     \
		   XV_PRIVATE(Textsw_view_object, Xv_textsw_view, t)
#define VIEW_PUBLIC(view_object)  \
		   XV_PUBLIC(view_object)
		   

#define TXTSW_DO_AGAIN(_textsw)	\
	((_textsw->again_count != 0) && \
	 ((_textsw->state & TXTSW_NO_AGAIN_RECORDING) == 0))
#ifdef OW_I18N		/* Tune off undo for preedit region */
#define TXTSW_DO_UNDO(_textsw) \
        ((_textsw->undo_count != 0) && \
                 ((_textsw->state & TXTSW_NO_UNDO_RECORDING) == 0))
#else
#define TXTSW_DO_UNDO(_textsw)	(_textsw->undo_count != 0)
#endif /* OW_I18N */

#ifdef OW_I18N
#ifdef FULL_R5
#define	textsw_implicit_commit(_folio) \
    if ((_folio->xim_style & XIMPreeditCallbacks) \
		? (_folio->preedit_start ? 1 : 0) \
		: (_folio->ic && \
		   xv_get(TEXTSW_PUBLIC(_folio), WIN_IC_CONVERSION) == TRUE) \
		   ? 1 : 0) \
	textsw_implicit_commit_doit(_folio);
#else /* FULL_R5 */
#define	textsw_implicit_commit(_folio) \
    if (_folio->preedit_start) \
	textsw_implicit_commit_doit(_folio);
#endif /* FULL_R5 */
#endif /* OW_I18N */


typedef struct textsw_string {
	int	max_length;
	CHAR	*base;
	CHAR	*free;
} string_t;
Pkg_private string_t	null_string;
#define TXTSW_STRING_IS_NULL(ptr_to_string_t)				\
	((ptr_to_string_t)->base == null_string.base)
#define TXTSW_STRING_BASE(ptr_to_string_t)				\
	((ptr_to_string_t)->base)
#define TXTSW_STRING_FREE(ptr_to_string_t)				\
	((ptr_to_string_t)->free)
#define TXTSW_STRING_LENGTH(ptr_to_string_t)				\
	(TXTSW_STRING_FREE(ptr_to_string_t)-TXTSW_STRING_BASE(ptr_to_string_t))

typedef struct key_map_object {
	struct key_map_object	*next;
	short			 event_code;
	short unsigned		 type;
	short			 shifts;
	caddr_t			 maps_to;
} Key_map_object;
typedef Key_map_object	*Key_map_handle;
#define	TXTSW_KEY_FILTER	0
	/* maps_to is argv => char[][] */
#define	TXTSW_KEY_SMART_FILTER	1
	/* maps_to is argv => char[][] */
#define	TXTSW_KEY_MACRO		2
	/* maps_to is again script => string_t */
#define	TXTSW_KEY_NULL		32767


typedef struct textsw_selection_object {
	long unsigned		  type;
	Es_index		  first, last_plus_one;
	CHAR			 *buf;
	int			  buf_len, buf_max_len;
	int			  buf_is_dynamic;
	Seln_result		(*per_buffer)();
	CHAR			 *per_buffer_context;
} Textsw_selection_object;
/*	type includes modes, etc (contains return from textsw_func_selection,
 *	  see below)
 *	first == last_plus_one == ES_INFINITY when object is initialized.
 *	per_buffer == NULL when object is initialized, and should be set iff
 *	  long non-local selections are to be processed.  In this case, the
 *	  per_buffer_context slot is available to store the current program
 *	  context to the per_buffer routine.
 */
typedef Textsw_selection_object	*Textsw_selection_handle;
	/* Flags for textsw_func_selection */
#define	TFS_FILL_IF_OTHER	1
#define	TFS_FILL_IF_SELF	2
#define	TFS_FILL_ALWAYS		(TFS_FILL_IF_OTHER|TFS_FILL_IF_SELF)
	/* Return values for textsw_func_selection */
#define	TFS_ERROR		 EV_SEL_CLIENT_FLAG(0x4000)
#define	TFS_IS_ERROR(arg)	(arg & TFS_ERROR)
#define	TFS_SELN_SVC_ERROR	(TFS_ERROR|1)
#define	TFS_WARNING		 EV_SEL_CLIENT_FLAG((unsigned)0x8000)
#define	TFS_IS_WARNING(arg)	(arg & TFS_WARNING)
#define	TFS_BAD_ATTR_WARNING	(EV_SEL_CLIENT_FLAG(0x0100)|TFS_WARNING)
#define	TFS_IS_OTHER		 EV_SEL_CLIENT_FLAG(0x0001)
#define	TFS_IS_SELF		 EV_SEL_CLIENT_FLAG(0x0002)

typedef struct textsw_view_object {
	long unsigned			  magic;
	struct textsw_object		 *folio;
	struct textsw_view_object	 *next;
	Textsw_view			  public_self;
/* Alpha compatibility, mbuck@debian.org */
#if defined(__alpha) || defined(__x86_64__)
	Xv_window			  window_fd;
#else
	int				  window_fd;
#endif
	Rect				  rect;
	Ev_handle			  e_view;
	Scrollbar			  scrollbar;
	int				  cursor_type;
	long unsigned			  state;
	Xv_drop_site                      drop_site;
	int				  obscured;
} Textsw_view_object;

typedef Textsw_view_object *Textsw_view_handle;

#define	TEXTSW_VIEW_NULL	((Textsw_view_handle)0)
#define	TEXTSW_VIEW_MAGIC	0xF0110A0A

#define PIXWIN_FOR_VIEW(_view)		((_view)->e_view->pw)
#define WIN_FD_FOR_VIEW(_view)		((_view)->window_fd)
Pkg_private Scrollbar		textsw_get_scrollbar();
#define SCROLLBAR_FOR_VIEW(_view)	\
          (((_view)->scrollbar) ?       \
            ((_view)->scrollbar) : textsw_get_scrollbar(_view))

	/* Bit flags for Textsw_view->state */
/* For textsw_do_input() */
#define TXTSW_DONT_UPDATE_SCROLLBAR		0x00000000
#define TXTSW_UPDATE_SCROLLBAR			0x00000001
#define TXTSW_UPDATE_SCROLLBAR_IF_NEEDED	0x00000002
#define TXTSW_SCROLLBAR_DISABLED		0x00000004

#define TXTSW_VIEW_IS_MAPPED    0x00000008
#define TXTSW_DONT_REDISPLAY	0x10000000
#define TXTSW_VIEW_DISPLAYED	0x40000000	
#define TXTSW_VIEW_DYING	0x80000000
#define TXTSW_IS_FIRST_VIEW	0x00000010


#define	TEXTSW_MAGIC		0xF2205050
#ifdef OW_I18N
#define TXTSW_UI_BUFLEN	256
#else
#define TXTSW_UI_BUFLEN	12
#endif
typedef struct textsw_object {
	long unsigned	  magic;
	struct textsw_object
			 *next;
	Textsw_view_handle  first_view;
	Textsw		  public_self;
	Xv_opaque	  menu;
	Ev_chain	  views;
	Es_handle	(*es_create)();
	int		(*notify)();
	unsigned	  notify_level;
	CHAR		  to_insert[TXTSW_UI_BUFLEN];
	CHAR		 *to_insert_next_free;
	unsigned	  to_insert_counter;
	Es_handle	  trash;	/* Stuff deleted from piece_source */
	long unsigned	  state,
			  func_state;
	short unsigned	  caret_state,
			  holder_state,
			  track_state;
	int		  multi_click_space,
			  multi_click_timeout;
	Textsw_enum	  insert_makes_visible;
	unsigned	  span_level;
	struct timeval	  last_ie_time,
			  last_adjust,
			  last_point,
			  selection_died,
			  timer;
	short		  last_click_x,
			  last_click_y;
	short             drag_threshold;
	Es_index	  adjust_pivot;	/* Valid iff TXTSW_TRACK_ADJUST */
	Ev_mark_object	  read_only_boundary;
	Ev_mark_object	  save_insert;	/* Valid iff TXTSW_GET/PUTTING	*/
	unsigned	  again_count;
	unsigned	  undo_count;
	string_t	 *again;
	Es_index	  again_first, again_last_plus_one;
	int		  again_insert_length; /* Offset from again[0]->base */
	caddr_t		 *undo;
	Seln_client	  selection_client;
	Seln_function_buffer
			  selection_func;
	Seln_holder	 *selection_holder;
	short		  func_x,
			  func_y;
	Textsw_view_handle  func_view;
	Key_map_handle	  key_maps;
	int		  owed_by_filter;
	unsigned	  es_mem_maximum;
	unsigned	  ignore_limit;
	char		  edit_bk_char,
			  edit_bk_word,
			  edit_bk_line;
	Xv_opaque	  client_data;
	Menu_item 	  *menu_table; 
	Menu		  *sub_menu_table;   /*  Menu handle to all submenus */
	int		  checkpoint_frequency;
	int		  checkpoint_number;
	CHAR		 *checkpoint_name;
	Textsw_view_handle  coalesce_with;
	unsigned	  event_code;
	char		 *temp_filename; /* For cmdsw log */
	Es_index          move_first, move_last_plus_one;	/* laf */
	Xv_Cursor         main_cursor, move_cursor, dup_cursor;	/* laf */
	int		  (*layout_proc)(); /* interposed window layout proc */
	Xv_Window	  focus_view;	/* view window with the kbd focus */
	unsigned	  accel_menus:1; /* Are core menu items accelerated */
#ifdef OW_I18N
	int		  blocking_newline; /* This is used for bug# 1090046 */
	int		  need_im; /* TRUE if XV_IM and XV_USE_IM are TRUE */
	XIC		  ic;
	Ev_mark_object	  preedit_start;
	/*
	 * This variable is used for OnTheSpot input style.
	 * preedit_start saves an insertion point for preedit text.
	 * If preedit_start is non NULL, IC exists, conversion mode is ON
	 * and preedit text exists.
	 */
	XIMCallback	  start_pecb_struct; 
	XIMCallback	  draw_pecb_struct;
	XIMCallback	  done_pecb_struct;
#ifdef FULL_R5
        XIMStyle	  xim_style;
#endif /* FULL_R5 */    	
	eucwidth_t	  euc_width;
	int		  locale_is_ale;
	Conv_pos_handle	  cph;	/* conversion pos handle */
#endif /* OW_I18N */
} Text_object;
typedef Text_object *	Textsw_folio;
#define	TEXTSW_FOLIO_NULL	((Textsw_folio)0)

#ifdef DEBUG
Pkg_private Textsw_folio	textsw_folio_for_view();
Pkg_private Textsw		textsw_view_rep_to_abs();

#define	FOLIO_FOR_VIEW(_view)		textsw_folio_for_view(_view)
#define	VIEW_REP_TO_ABS(_private)	textsw_view_rep_to_abs(_private)
#else
#define	FOLIO_FOR_VIEW(_view)		((_view)->folio)
#define	VIEW_REP_TO_ABS(_private)	(VIEW_PUBLIC(_private))
#endif

#define	FOLIO_REP_TO_ABS(_private)	(TEXTSW_PUBLIC(_private))
#define	FOLIO_ABS_TO_REP(_public)	(TEXTSW_PRIVATE(_public))

Pkg_private Textsw_view_handle		textsw_view_abs_to_rep();
#define	VIEW_ABS_TO_REP(_public)	textsw_view_abs_to_rep(_public)

#define	IS_FOLIO(_folio)		((_folio)->magic == TEXTSW_MAGIC)
#define	IS_VIEW(_view)			((_view)->magic == TEXTSW_VIEW_MAGIC)
#define	VALIDATE_FOLIO(_folio)		ASSERT(IS_FOLIO(_folio))
#define	VALIDATE_VIEW(_view)		ASSERT(IS_VIEW(_view))

#ifdef lint
#define	VIEW_FROM_FOLIO_OR_VIEW(_folio_or_view)	\
	(Textsw_view_handle)(_folio_or_view ? 0 : 0)

#define FRAME_FROM_FOLIO_OR_VIEW(_folio_or_view) \
	((_folio_or_view) ? 0 : 0)

#define	WINDOW_FROM_VIEW(_view)	\
	(TEXTSW_PUBLIC(_view) ? 0 : 0)
#else
#define	VIEW_FROM_FOLIO_OR_VIEW(_folio_or_view)				\
	(IS_VIEW((Textsw_view_handle)_folio_or_view)				\
	 ? (Textsw_view_handle)_folio_or_view				\
	 : ((Textsw_folio)_folio_or_view)->first_view)

#define	WINDOW_FROM_VIEW(_view)		TEXTSW_PUBLIC(_view)

#define FRAME_FROM_FOLIO_OR_VIEW(_folio_or_view) \
	xv_get(VIEW_REP_TO_ABS(VIEW_FROM_FOLIO_OR_VIEW(_folio_or_view)), \
		WIN_FRAME)	
#endif

#define	FOLIO_FROM_VIEW(_view)		(_view)->folio		

#define	FORALL_TEXT_VIEWS(_folio, _view)			\
	for (_view = (_folio)->first_view; (_view); _view = _view->next)

#define	TXTSW_HAS_READ_ONLY_BOUNDARY(folio_formal)	\
	(!EV_MARK_IS_NULL(&folio_formal->read_only_boundary))

	/* Synonyms for input event codes */
	/* Meta A is 225 */
#define TXTSW_ADJUST		ACTION_ADJUST
#define TXTSW_MENU		ACTION_MENU
#define TXTSW_POINT		ACTION_SELECT
#define TXTSW_FIND_FORWARD	ACTION_FIND_FORWARD
#define TXTSW_FIND_BACKWARD	ACTION_FIND_BACKWARD
#define TXTSW_NEXT_FIELD	ACTION_SELECT_FIELD_FORWARD
#define TXTSW_PREV_FIELD	ACTION_SELECT_FIELD_BACKWARD


#define TXTSW_AGAIN		ACTION_AGAIN
#define TXTSW_DELETE		ACTION_CUT
#define TXTSW_REPLACE		ACTION_REPLACE
#define TXTSW_GET		ACTION_PASTE
#define TXTSW_PUT		ACTION_COPY
#define TXTSW_UNDO		ACTION_UNDO

#define TXTSW_LOAD_FILE		033		/* Do not map this */
#define TXTSW_LOAD_FILE_AS_MENU	ACTION_LOAD
#define TXTSW_STORE_FILE	ACTION_STORE

#define TXTSW_PROPS		ACTION_PROPS
#define TXTSW_REDO		ACTION_REDO
#define TXTSW_STOP		ACTION_STOP
#define TXTSW_TOP		ACTION_FRONT
#define TXTSW_BOTTOM		ACTION_BACK
#define TXTSW_OPEN		ACTION_OPEN
#define TXTSW_DO_IT		ACTION_DO_IT
#define TXTSW_MATCH_DELIMITER	ACTION_MATCH_DELIMITER

#define TXTSW_EMPTY_DOCUMENT	ACTION_EMPTY
#define TXTSW_INCLUDE_FILE	ACTION_INCLUDE_FILE


#ifdef VT_100_HACK
#else
#define TXTSW_CAPS_LOCK			ACTION_CAPS_LOCK
#endif

#define TXTSW_MOVE_LEFT			ACTION_GO_CHAR_BACKWARD
#define TXTSW_MOVE_RIGHT		ACTION_GO_CHAR_FORWARD
#define TXTSW_MOVE_UP			ACTION_GO_COLUMN_BACKWARD
#define TXTSW_MOVE_DOWN			ACTION_GO_COLUMN_FORWARD
#define TXTSW_MOVE_WORD_END		ACTION_GO_WORD_END
#define TXTSW_MOVE_WORD_FORWARD		ACTION_GO_WORD_FORWARD
#define TXTSW_MOVE_WORD_BACKWARD	ACTION_GO_WORD_BACKWARD
#define TXTSW_MOVE_TO_LINE_END		ACTION_GO_LINE_END
#define TXTSW_MOVE_TO_LINE_START	ACTION_GO_LINE_BACKWARD 
#define TXTSW_MOVE_TO_NEXT_LINE_START	ACTION_GO_LINE_FORWARD
#define TXTSW_MOVE_TO_DOC_START		ACTION_GO_DOCUMENT_START
#define TXTSW_MOVE_TO_DOC_END		ACTION_GO_DOCUMENT_END

#define TXTSW_ERASE_CHAR_BACKWARD	ACTION_ERASE_CHAR_BACKWARD
#define TXTSW_ERASE_CHAR_FORWARD	ACTION_ERASE_CHAR_FORWARD
#define TXTSW_ERASE_WORD_BACKWARD	ACTION_ERASE_WORD_BACKWARD
#define TXTSW_ERASE_WORD_FORWARD	ACTION_ERASE_WORD_FORWARD
#define TXTSW_ERASE_LINE_BACKWARD	ACTION_ERASE_LINE_BACKWARD
#define TXTSW_ERASE_LINE_END		ACTION_ERASE_LINE_END



	/* Bit flags for Textsw_handle->state */
#define TXTSW_AGAIN_HAS_FIND	0x00000001
#define TXTSW_AGAIN_HAS_MATCH   0x00000002
#ifdef OW_I18N
#define TXTSW_NO_UNDO_RECORDING	0x00000004
#endif
#define TXTSW_DELETE_REPLACES_CLIPBOARD         \
                                0x00000008
#define TXTSW_ADJUST_IS_PD	0x00000010
#define TXTSW_AUTO_INDENT	0x00000020
#define TXTSW_CONFIRM_OVERWRITE	0x00000040
#define TXTSW_CONTINUOUS_BUBBLE	0x00000080
#define TXTSW_NO_CD		0x00000100
#define TXTSW_NO_LOAD		0x00000200
#define TXTSW_DIFF_CR_LF        0x00000400	/*1030878*/
#define TXTSW_STORE_CHANGES_FILE		\
				0x00000800
#define TXTSW_READ_ONLY_ESH	0x00001000
#define TXTSW_READ_ONLY_SW	0x00002000
#define TXTSW_RETAINED		0x00008000
#define TXTSW_CAPS_LOCK_ON	0x00010000
#define TXTSW_DISPLAYED		0x00020000
#define TXTSW_EDITED		0x00040000
#define TXTSW_INITIALIZED	0x00080000
#define TXTSW_IN_NOTIFY_PROC	0x00100000
#define TXTSW_DOING_EVENT	0x00200000
#define TXTSW_NO_RESET_TO_SCRATCH		\
				0x00400000
#define TXTSW_NO_AGAIN_RECORDING		\
				0x00800000
#define TXTSW_HAS_FOCUS		0x01000000
#define TXTSW_OPENED_FONT	0x02000000
#define TXTSW_PENDING_DELETE	0x04000000
#define TXTSW_DESTROY_ALL_VIEWS	0x08000000
#define TXTSW_CONTROL_DOWN	0x10000000
#define TXTSW_SHIFT_DOWN	0x20000000
#define TXTSW_DELAY_SEL_INQUIRE 0x40000000

#define TXTSW_MISC_UNUSED	0x8000000c

	/* Bit flags for Textsw_handle->caret_state */
#define TXTSW_CARET_FLASHING	0x0001
#define TXTSW_CARET_ON		0x0002
#define TXTSW_CARET_MUST_SHOW	0x0004
#define TXTSW_CARET_TIMER_ON	0x0008
#define TXTSW_CARET_FROZEN	0x0010
#define	TXTSW_CARET_UNUSED	0xffe

	/* Bit flags for Textsw_handle->func_state */
#define TXTSW_FUNC_AGAIN	0x00000001
#define TXTSW_FUNC_DELETE	0x00000002
#define TXTSW_FUNC_FIELD	0x00000004
#define TXTSW_FUNC_FILTER	0x00000008
#define TXTSW_FUNC_FIND		0x00000010
#define TXTSW_FUNC_GET		0x00000020
#define TXTSW_FUNC_PUT		0x00000040
#define TXTSW_FUNC_UNDO		0x00000080
#define TXTSW_FUNC_ALL		(TXTSW_FUNC_AGAIN | TXTSW_FUNC_DELETE | \
				 TXTSW_FUNC_FIELD | TXTSW_FUNC_FILTER | \
				 TXTSW_FUNC_FIND  | TXTSW_FUNC_GET    | \
				 TXTSW_FUNC_PUT   | TXTSW_FUNC_UNDO)
#define	TXTSW_FUNC_SVC_SAW(flags)	\
				((flags) << 8)
#define	TXTSW_FUNC_SVC_SAW_ALL	TXTSW_FUNC_SVC_SAW(TXTSW_FUNC_ALL)
#define	TXTSW_FUNC_EXECUTE	0x01000000
#define TXTSW_FUNC_SVC_REQUEST	0x10000000
#define	TXTSW_FUNC_SVC_ALL	(TXTSW_FUNC_SVC_SAW_ALL | \
				 TXTSW_FUNC_SVC_REQUEST)
#define TXTSW_FUNCTION_UNUSED	0xeeff8080


	/* Bit flags for Textsw_handle->holder_state */
#define TXTSW_HOLDER_OF_CARET	0x0001
#define TXTSW_HOLDER_OF_PSEL	0x0002
#define TXTSW_HOLDER_OF_SSEL	0x0004
#define TXTSW_HOLDER_OF_SHELF	0x0008
#define TXTSW_HOLDER_OF_ALL	(TXTSW_HOLDER_OF_CARET | \
				 TXTSW_HOLDER_OF_PSEL  | \
				 TXTSW_HOLDER_OF_SSEL  | \
				 TXTSW_HOLDER_OF_SHELF)
#define TXTSW_HOLDER_UNUSED	0xfff0

	/* Bit flags for Textsw_handle->track_state */
#define TXTSW_TRACK_ADJUST	0x0001
#define TXTSW_TRACK_ADJUST_END	0x0002
#define TXTSW_TRACK_POINT	0x0004
#define TXTSW_TRACK_SECONDARY	0x0008
#define TXTSW_TRACK_WIPE        0x0010	
#define TXTSW_TRACK_MOVE        0x0020	
#define TXTSW_TRACK_DUPLICATE   0x0040	
#define TXTSW_TRACK_QUICK_MOVE  0x0080
#define TXTSW_TRACK_ALL		(TXTSW_TRACK_ADJUST|TXTSW_TRACK_ADJUST_END|\
				 TXTSW_TRACK_POINT|TXTSW_TRACK_SECONDARY)
#define TXTSW_TRACK_UNUSED	0xfff0

#define	TXTSW_IS_BUSY(textsw)				\
	((textsw->state & TXTSW_PENDING_DELETE) ||	\
	 (textsw->func_state & TXTSW_FUNC_ALL) ||	\
	 (textsw->track_state & TXTSW_TRACK_ALL))

#define	TXTSW_IS_READ_ONLY(textsw)			\
	(textsw->state & (TXTSW_READ_ONLY_ESH | TXTSW_READ_ONLY_SW))

	/* Flags for textsw_flush_caches */
#define TFC_INSERT		0x01
#define TFC_DO_PD		0x02
#define	TFC_SEL			0x04
#define TFC_PD_SEL		(TFC_DO_PD|TFC_SEL)
#define TFC_PD_IFF_INSERT	0x08
		/* Delete selection iff chars will be inserted. */
#define TFC_SEL_IFF_INSERT	0x10
		/* Clear selection iff chars will be inserted. */
#define TFC_IFF_INSERTING	(TFC_PD_IFF_INSERT | TFC_SEL_IFF_INSERT | \
				 TFC_INSERT)
#define TFC_ALL			(TFC_IFF_INSERTING|TFC_PD_SEL)
#define TFC_STD			TFC_ALL

	/* Flags for textsw_find_selection_and_normalize */
/* These flags potentially include an EV_SEL_BASE_TYPE */
#define	TFSAN_BACKWARD		EV_SEL_CLIENT_FLAG(0x0001)
#define	TFSAN_REG_EXP		EV_SEL_CLIENT_FLAG(0x0002)
#define	TFSAN_SHELF_ALSO	EV_SEL_CLIENT_FLAG(0x0004)
#define	TFSAN_TAG		EV_SEL_CLIENT_FLAG(0x0008)

#define SET_TEXTSW_TIMER(_timer_h)					\
	(_timer_h)->tv_sec = 0; (_timer_h)->tv_usec = 500000;
#define TIMER_EXPIRED(timer)						\
	(*timer && ((*timer)->tv_sec == 0) && ((*timer)->tv_usec == 0))
#define SCROLLBAR_ENTER_FEEDBACK	1

/* For caret motion */
typedef enum {
	TXTSW_CHAR_BACKWARD,
 	TXTSW_CHAR_FORWARD,
	TXTSW_DOCUMENT_END,
	TXTSW_DOCUMENT_START,
	TXTSW_LINE_END,
	TXTSW_LINE_START,
	TXTSW_NEXT_LINE_START,
	TXTSW_NEXT_LINE,
	TXTSW_PREVIOUS_LINE,
	TXTSW_WORD_BACKWARD,
	TXTSW_WORD_FORWARD,
	TXTSW_WORD_END
} Textsw_Caret_Direction;

/* Sub menu handles */
typedef enum {
	TXTSW_FILE_SUB_MENU,
	TXTSW_EDIT_SUB_MENU,
	TXTSW_VIEW_SUB_MENU,
	TXTSW_FIND_SUB_MENU,
	TXTSW_EXTRAS_SUB_MENU
} Textsw_sub_menu;

Pkg_private void
textsw_begin_function( /* textsw, function */ );
#							ifdef notdef
	register Textsw_handle	textsw;
	unsigned		function;
#							endif

Pkg_private void
textsw_end_function( /* textsw, function */ );
#							ifdef notdef
	register Textsw_handle	textsw;
	unsigned		function;
#							endif

Pkg_private int
textsw_adjust_delete_span( /* folio, first, last_plus_one */ );
#							ifdef notdef
	Textsw_folio	 folio;
	Es_index	*first, *last_plus_one;
#							endif
#define	TXTSW_PE_ADJUSTED	0x10000
#define	TXTSW_PE_EMPTY_INTERVAL	0x20000

Pkg_private Es_index
textsw_delete_span( /* folio, first, last_plus_one, flags */ );
#							ifdef notdef
	register Textsw_folio	folio;
	Es_index		first, last_plus_one;
	unsigned		flags;
#							endif
#define	TXTSW_DS_DEFAULT		 EV_SEL_CLIENT_FLAG(0x0)
#define	TXTSW_DS_ADJUST			 EV_SEL_CLIENT_FLAG(0x1)
#define	TXTSW_DS_CLEAR_IF_ADJUST(sel)	(EV_SEL_CLIENT_FLAG(0x2)|(sel))
#define	TXTSW_DS_SHELVE			 EV_SEL_CLIENT_FLAG(0x4)
#define	TXTSW_DS_RECORD			 EV_SEL_CLIENT_FLAG(0x8)
#ifdef OW_I18N
#define	TXTSW_DS_RETURN_BYTES		EV_SEL_CLIENT_FLAG(0x10)
#endif

Pkg_private Es_index
textsw_do_input( /* view, buf, buf_len, flag */ );
#							ifdef notdef
	Textsw_view_handle		 view;
	char			*buf;
	long int		 buf_len;
	unsigned		 flag;
#							endif

Pkg_private Es_index
textsw_input_after( /* view, old_insert_pos, old_length, record */ );
#							ifdef notdef
	Textsw_view_handle		view;
	Es_index		old_insert_pos, old_length;
	int			record;
#							endif

Pkg_private Es_index
textsw_do_pending_delete( /* view, type, flags */ );
#							ifdef notdef
	Textsw_view_handle		view;
	unsigned		type;
	int			flags;
#							endif

Pkg_private void
textsw_normalize_internal( /*
	view, first, last_plus_one, upper_context, lower_context, flags */ );
#							ifdef notdef
        register Textsw_view_handle	view;
	Es_index		first, last_plus_one;
	int			upper_context, lower_context;
	register unsigned	flags;
#							endif
#define	TXTSW_NI_DEFAULT		 EV_SEL_CLIENT_FLAG(0x0)
#define	TXTSW_NI_AT_BOTTOM		 EV_SEL_CLIENT_FLAG(0x1)
#define	TXTSW_NI_MARK			 EV_SEL_CLIENT_FLAG(0x2)
#define	TXTSW_NI_NOT_IF_IN_VIEW		 EV_SEL_CLIENT_FLAG(0x4)
#define	TXTSW_NI_SELECT(sel)		(EV_SEL_CLIENT_FLAG(0x8)|(sel))
#define	TXTSW_NI_DONT_UPDATE_SCROLLBAR	 EV_SEL_CLIENT_FLAG(0x10)


Pkg_private Es_index
textsw_set_insert( /* textsw, pos */ );
#							ifdef notdef
	Textsw_folio	textsw;
	Es_index	pos;
#							endif

Pkg_private void
textsw_add_timer( /* textsw, timeout */ );
#							ifdef notdef
	register Textsw_folio	 textsw;
	register struct timeval	*timeout;
#							endif

Pkg_private Notify_value
textsw_timer_expired( /* textsw, which */ );
#							ifdef notdef
	register Textsw_folio	 textsw;
	int			 which;
#							endif

Pkg_private void
textsw_remove_timer( /* textsw */ );
#							ifdef notdef
	register Textsw_handle	textsw;
#							endif

Pkg_private void
textsw_invert_caret( /* textsw */ );
#							ifdef notdef
	register Textsw_handle	textsw;
#							endif

Pkg_private void
textsw_take_down_caret( /* textsw */ );
#							ifdef notdef
	register Textsw_handle	textsw;
#							endif

Pkg_private void
textsw_may_win_exit( /* textsw */ );
#							ifdef notdef
	Textsw_handle	  textsw;
#							endif

EXTERN_FUNCTION( void textsw_notify, (Textsw_view_handle view, DOTDOTDOT) );
#							ifdef notdef
	Textsw_opaque	folio_or_view;
	Attr_avlist	attributes;
#							endif

Pkg_private void
textsw_post_error( /* folio_or_view, locx, locy, msg1, msg2 */ );
#							ifdef notdef
	Textsw_opaque	 folio_or_view;
	int		 locx, locy;
	char		*msg1, *msg2;
#							endif

Pkg_private void
textsw_read_only_msg( /* textsw, locx, locy */ );
#							ifdef notdef
	Textsw_folio	textsw;
	int		locx, locy;
#							endif

Pkg_private Textsw_status
textsw_set_internal( /* view, attrs */ );
#							ifdef notdef
	Textsw_view_handle		view;
	Attr_avlist		attrs;
#							endif
#define	TEXTSW_CONSUME_ATTRS	TEXTSW_ATTR(ATTR_BOOLEAN, 240)

Pkg_private Es_status
textsw_checkpoint( /* folio */ );
#							ifdef notdef
	Text_folio		folio;
#							endif

extern caddr_t
textsw_checkpoint_undo( /* abstract, undo_mark */ );
#							ifdef notdef
	Textsw			abstract;
	caddr_t			undo_mark;
#							endif

extern void
textsw_display( /* abstract */ );
#							ifdef notdef
	Textsw			abstract;
#							endif

extern void
textsw_display_view( /* abstract, rect */ );
#							ifdef notdef
	Textsw			 abstract;
	register Rect		*rect;
#							endif

Pkg_private void
textsw_display_view_margins( /* abstract, rect */ );
#							ifdef notdef
	Textsw			 abstract;
	register Rect		*rect;
#							endif

Pkg_private int
textsw_is_seln_nonzero( /* textsw, type */ );
#							ifdef notdef
	register Text_folio	textsw;
	unsigned		type;
#							endif

Pkg_private Es_index
textsw_find_mark_internal( /* textsw, mark */ );
#							ifdef notdef
	Textsw_folio	textsw;
	Ev_mark_object	mark;
#							endif

Pkg_private Es_index
textsw_get_saved_insert( /* textsw */ );
#							ifdef notdef
	register Textsw_folio	textsw;
#							endif

Pkg_private Es_index
textsw_read_only_boundary_is_at( /* folio */ );
#							ifdef notdef
	register Textsw_folio	folio;
#							endif

Pkg_private Es_index
textsw_insert_pieces( /* view, pos, pieces */ );
#							ifdef notdef
	Textsw_view_handle		view;
	register Es_index	pos;
	Es_handle		pieces;
#							endif

extern unsigned
textsw_save( /* abstract, locx, locy */ );
#							ifdef notdef
	Textsw		abstract;
	int		locx, locy;
#							endif

extern unsigned
textsw_store_file( /* abstract, filename, locx, locy */ );
#							ifdef notdef
	Textsw		abstract;
	char		*filename;
	int		locx, locy;
#							endif

Pkg_private Es_status
textsw_store_to_selection( /* textsw, locx, locy */ );
#							ifdef notdef
	Textsw_folio		textsw;
	int			locx, locy;
#							endif

#ifdef __STDC__
Pkg_private Xv_opaque textsw_set(Textsw abstract, Textsw_attribute avlist[]);
Pkg_private unsigned textsw_determine_selection_type(Textsw_folio textsw, int acquire);
Pkg_private void textsw_clear_secondary_selection(Textsw_folio textsw, unsigned type);
Pkg_private void textsw_init_selection_object(Textsw_folio textsw, Textsw_selection_handle selection, CHAR *buf, int buf_max_len, int buf_is_dynamic);
Pkg_private void textsw_update_scrollbars(Textsw_folio folio, Textsw_view_handle only_view);
Pkg_private void textsw_display_view_margins(Textsw_view_handle view, struct rect *rect);
Pkg_private void textsw_give_shelf_to_svc(Textsw_folio folio);
Pkg_private Seln_rank seln_rank_from_textsw_info(int type);
Pkg_private void textsw_input_before(Textsw_view_handle view, Es_index *old_insert_pos, Es_index *old_length);
Pkg_private Key_map_handle textsw_do_filter(Textsw_view_handle view, Event *ie);
Pkg_private Seln_rank textsw_acquire_seln(Textsw_folio textsw, Seln_rank rank);
Pkg_private void textsw_notify_replaced(Textsw_opaque folio_or_view, Es_index insert_before, Es_index length_before, Es_index replaced_from, Es_index replaced_to, Es_index count_inserted);
Pkg_private void textsw_remove_mark_internal(Textsw_folio textsw, Ev_mark_object mark);
Pkg_private void textsw_record_input(Textsw_folio textsw, CHAR *buffer, long int buffer_length);
Pkg_private void textsw_record_piece_insert(Textsw_folio textsw, Es_handle pieces);
Pkg_private void textsw_record_edit(Textsw_folio textsw, unsigned unit, unsigned direction);
Pkg_private void textsw_record_delete(Textsw_folio textsw);
#ifdef OW_I18N
Xv_public void textsw_set_selection_wcs(Textsw abstract, Es_index first, Es_index last_plus_one, unsigned type);
Xv_public void textsw_set_selection(Textsw abstract, Es_index first, Es_index last_plus_one, unsigned type);
#else
Xv_public void textsw_set_selection(Textsw abstract, Es_index first, Es_index last_plus_one, unsigned type);
#endif
Pkg_private void textsw_esh_failed_msg(Textsw_view_handle view, char *preamble);
#ifdef OW_I18N
Pkg_private Es_index textsw_do_edit(Textsw_view_handle view, unsigned unit, unsigned direction, unsigned byte_return);
#else
Pkg_private Es_index textsw_do_edit(Textsw_view_handle view, unsigned unit, unsigned direction);
#endif
Pkg_private Es_index textsw_input_partial(Textsw_view_handle view, CHAR *buf, long int buf_len);
Pkg_private void textsw_put_then_get(Textsw_view_handle view);
Pkg_private Es_index textsw_stuff_selection(Textsw_view_handle view, int type);
Pkg_private void textsw_record_trash_insert(Textsw_folio textsw);
Pkg_private int textsw_inform_seln_svc(Textsw_folio textsw, int function, int is_down);
Pkg_private void textsw_begin_get(Textsw_view_handle view);
Pkg_private void textsw_post_need_selection(Textsw abstract, Event *ie);
Pkg_private void textsw_get_and_set_selection(Frame popup_frame, Textsw_view_handle view, int popup_type);
Pkg_private int textsw_end_get(Textsw_view_handle view);
Pkg_private int textsw_end_quick_move(Textsw_view_handle view);
Pkg_private void textsw_create_popup_frame(Textsw_view_handle view, int popup_type);
Pkg_private void textsw_start_seln_tracking(Textsw_view_handle view, Event *ie);
Pkg_private void textsw_set_dir_str(int popup_type);
Pkg_private int textsw_match_selection_and_normalize(Textsw_view_handle view, CHAR *start_marker, unsigned field_flag);
Pkg_private int textsw_end_put(Textsw_view_handle view);
Pkg_private void textsw_begin_find(Textsw_view_handle view);
Pkg_private void textsw_scroll(Scrollbar sb);
Pkg_private void textsw_move_caret(Textsw_view_handle view, Textsw_Caret_Direction direction);
Pkg_private int textsw_flush_caches(Textsw_view_handle view, int flags);
Pkg_private int textsw_end_find(Textsw_view_handle view, unsigned event_code, int x, int y);
Pkg_private int textsw_file_name(Textsw_folio textsw, CHAR **name);
Pkg_private Es_index textsw_has_been_modified(Textsw abstract);
Pkg_private int textsw_func_selection(Textsw_folio textsw, Textsw_selection_handle selection, int flags);
Pkg_private void textsw_do_drag_copy_move(Textsw_view_handle view, Event *ie, int is_copy);
Pkg_private void textsw_do_remote_drag_copy_move(Textsw_view_handle view, Event *ie, short is_copy);
Pkg_private void textsw_begin_put(Textsw_view_handle view, int inform_svc);
Pkg_private void textsw_do_menu(Textsw_view_handle view, Event *ie);
Pkg_private void textsw_undo(Textsw_folio textsw);
Pkg_private void textsw_again(Textsw_view_handle view, int x, int y);
Pkg_private void textsw_checkpoint_again(Textsw abstract);
Pkg_private void textsw_do_again(Textsw_view_handle view, int x, int y);
Pkg_private void textsw_set_base_mask(Xv_object win);
Pkg_private void textsw_clear_pending_func_state(Textsw_folio textsw);
Pkg_private void textsw_find_pattern(Textsw_folio textsw, Es_index *first, Es_index *last_plus_one, CHAR *buf, unsigned buf_len, unsigned flags);
Pkg_private void textsw_record_filter(Textsw_folio textsw, Event *event);
Pkg_private int textsw_func_selection_internal(Textsw_folio textsw, Textsw_selection_handle selection, int type, int flags);
Pkg_private Es_index textsw_get_selection(Textsw_view_handle view, Es_index *first, Es_index *last_plus_one, CHAR *selected_str, int max_str_len);
Pkg_private int save_cmd_proc(Frame fc, CHAR *path, int exists);
Pkg_private void textsw_do_save(Textsw abstract, Textsw_folio textsw, Textsw_view_handle view);
Pkg_private int textsw_get_selection_as_string(Textsw_folio folio, unsigned type, CHAR *buf, int buf_max_len);
Pkg_private void textsw_init_selection_object(Textsw_folio textsw, Textsw_selection_handle selection, CHAR *buf, int buf_max_len, int buf_is_dynamic);
Pkg_private int textsw_match_field_and_normalize(Textsw_view_handle view, Es_index *first, Es_index *last_plus_one, CHAR *buf1, int buf_len1, unsigned field_flag, int do_search);
Pkg_private void textsw_do_duplicate(Textsw_view_handle view, Event *ie);
Pkg_private void xv_do_move(Textsw_view_handle view, Event *ie);
Pkg_private void textsw_find_pattern_and_normalize(Textsw_view_handle view, int x, int y, Es_index *first, Es_index *last_plus_one, CHAR *buf, unsigned buf_len, unsigned flags);
Pkg_private int textsw_call_filter(Textsw_view_handle view, char *filter_argv[]);
Pkg_private void textsw_possibly_normalize_and_set_selection(Textsw abstract, Es_index first, Es_index last_plus_one, unsigned type);
Pkg_private int textsw_function_get(Textsw_view_handle view);
Pkg_private int textsw_function_delete(Textsw_view_handle view);
Pkg_private void textsw_record_match(Textsw_folio textsw, unsigned flag, CHAR *start_marker);
Pkg_private void textsw_possibly_edited_now_notify(Textsw_folio folio);
Pkg_private void textsw_init_again(Textsw_folio folio, int count);
Pkg_private void textsw_record_find(Textsw_folio textsw, CHAR *pattern, int pattern_length, int direction);
Pkg_private int textsw_parse_rc(Textsw_folio textsw);
Pkg_private Textsw_status textsw_file_stuff_from_str(Textsw_view_handle view, CHAR *buf, int locx, int locy);
#ifdef OW_I18N
Pkg_private int textsw_expand_filename(Textsw_folio textsw, CHAR *buf, int buf_len, int locx, int locy);
#else
Pkg_private int textsw_expand_filename(Textsw_folio textsw, char *buf, int locx, int locy);
#endif
Pkg_private void textsw_record_extras(Textsw_folio folio, CHAR *cmd_line);
Pkg_private int include_cmd_proc(Frame fc, CHAR *path, CHAR *file, Xv_opaque client_data);
Pkg_private int open_cmd_proc(Frame fc, CHAR *path, CHAR *file, Xv_opaque client_data);
Pkg_private void textsw_abort(Textsw_folio textsw);
Pkg_private int textsw_do_move(Textsw_view_handle view, int selection_is_local);
Pkg_private int textsw_mouseless_scroll_event(Textsw_view_handle view, Event *ie, Notify_arg arg);
Pkg_private void textsw_resize(Textsw_view_handle view);
Pkg_private int textsw_empty_document(Textsw abstract, Event *ie);
#ifdef OW_I18N
Pkg_private int textsw_change_directory(Textsw_folio textsw, CHAR *filename_wc, int might_not_be_dir, int locx, int locy);
#else
Pkg_private int textsw_change_directory(Textsw_folio textsw, char *filename, int might_not_be_dir, int locx, int locy);
#endif
Pkg_private void textsw_set_internal_tier2(Textsw_folio textsw, Textsw_view_handle view, Attr_attribute *attrs, int is_folio, Textsw_status *status_ptr, char **error_msg_addr, CHAR *file, CHAR *name_wc, int *reset_mode, int *all_views, int *update_scrollbar, int *read_only_changed);
Pkg_private void textsw_put(Textsw_view_handle view);
Pkg_private int textsw_load_file(Textsw abstract, CHAR *filename, int reset_views, int locx, int locy);
Pkg_private int match_in_table(char *to_match, char **table);
Pkg_private void textsw_begin_match_field(Textsw_view_handle view);
Pkg_private void textsw_match_field(Textsw_folio textsw, Es_index *first, Es_index *last_plus_one, CHAR *symbol1, int symbol1_len, CHAR *symbol2, int symbol2_len, unsigned field_flag, int do_search);
Pkg_private void textsw_default_notify(Textsw abstract, Attr_attribute *attrs);
Pkg_private int textsw_screen_column_count(Textsw abstract);
Pkg_private int textsw_sync_with_seln_svc(Textsw_folio folio);
Pkg_private void textsw_clear_move(Textsw_view_handle view);
Pkg_private void textsw_clear_duplicate(Textsw_view_handle view);
Pkg_private void textsw_set_cursor(Textsw textsw, int cursor_type);
Pkg_private int textsw_mouseless_select_event(Textsw_view_handle view, Event *ie, Notify_arg arg);
Pkg_private int textsw_mouseless_misc_event(Textsw_view_handle view, Event *event);
Pkg_private int textsw_get_selection_as_filename(Textsw_folio textsw, CHAR *buf, int sizeof_buf, int locx, int locy);
Pkg_private void textsw_reset_2(Textsw abstract, int locx, int locy, int preserve_memory, int cmd_is_undo_all_edit);
Pkg_private void textsw_format_load_error_quietly(char *msg, Es_status status, CHAR *filename, CHAR *scratch_name);
Pkg_private void textsw_replace_esh(Textsw_folio textsw, Es_handle new_esh);
Pkg_private Es_index textsw_get_saved_insert(Textsw_folio textsw);
Pkg_private Es_index textsw_set_insert(Textsw_folio folio, Es_index pos);
Pkg_private Ev_mark_object textsw_add_mark_internal(Textsw_folio textsw, Es_index position, unsigned flags);
Pkg_private void textsw_free_again(Textsw_folio textsw, string_t *again);
Pkg_private void textsw_normalize_internal(Textsw_view_handle view, Es_index first, Es_index last_plus_one, int upper_context, int lower_context, unsigned flags);
Pkg_private int textsw_prepare_buf_for_es_read(int *to_read, CHAR **buf, int buf_max_len, int fixed_size);
Pkg_private void textsw_repaint(Textsw_view_handle view);
Pkg_private void textsw_show_caret(Textsw_folio textsw);
Pkg_private void textsw_set_null_view_avlist(Textsw_folio folio, Attr_avlist attrs);
#ifdef OW_I18N
Pkg_private int textsw_do_newline(Textsw_view_handle view, int action);
#endif
#else
Pkg_private Xv_opaque textsw_set();
Pkg_private unsigned textsw_determine_selection_type();
Pkg_private void textsw_clear_secondary_selection();
Pkg_private void textsw_init_selection_object();
Pkg_private void textsw_update_scrollbars();
Pkg_private void textsw_display_view_margins();
Pkg_private void textsw_give_shelf_to_svc();
Pkg_private Seln_rank seln_rank_from_textsw_info();
Pkg_private void textsw_input_before();
Pkg_private Key_map_handle textsw_do_filter();
Pkg_private Seln_rank textsw_acquire_seln();
Pkg_private void textsw_notify_replaced();
Pkg_private void textsw_remove_mark_internal();
Pkg_private void textsw_record_input();
Pkg_private void textsw_record_piece_insert();
Pkg_private void textsw_record_edit();
Pkg_private void textsw_record_delete();
#ifdef OW_I18N
Xv_public void textsw_set_selection_wcs();
#endif
Xv_public void textsw_set_selection();
Pkg_private void textsw_esh_failed_msg();
Pkg_private Es_index textsw_do_edit();
Pkg_private Es_index textsw_input_partial();
Pkg_private void textsw_put_then_get();
Pkg_private Es_index textsw_stuff_selection();
Pkg_private void textsw_record_trash_insert();
Pkg_private int textsw_inform_seln_svc();
Pkg_private void textsw_begin_get();
Pkg_private void textsw_post_need_selection();
Pkg_private void textsw_get_and_set_selection();
Pkg_private int textsw_end_get();
Pkg_private int textsw_end_quick_move();
Pkg_private void textsw_create_popup_frame();
Pkg_private void textsw_start_seln_tracking();
Pkg_private void textsw_set_dir_str();
Pkg_private int textsw_match_selection_and_normalize();
Pkg_private int textsw_end_put();
Pkg_private void textsw_begin_find();
Pkg_private void textsw_scroll();
Pkg_private void textsw_move_caret();
Pkg_private int textsw_flush_caches();
Pkg_private int textsw_end_find();
Pkg_private int textsw_file_name();
Pkg_private Es_index textsw_has_been_modified();
Pkg_private int textsw_func_selection();
Pkg_private void textsw_do_drag_copy_move();
Pkg_private void textsw_do_remote_drag_copy_move();
Pkg_private void textsw_begin_put();
Pkg_private void textsw_do_menu();
Pkg_private void textsw_undo();
Pkg_private void textsw_again();
Pkg_private void textsw_checkpoint_again();
Pkg_private void textsw_do_again();
Pkg_private void textsw_set_base_mask();
Pkg_private void textsw_clear_pending_func_state();
Pkg_private void textsw_find_pattern();
Pkg_private void textsw_record_filter();
Pkg_private int textsw_func_selection_internal();
Pkg_private Es_index textsw_get_selection();
Pkg_private int save_cmd_proc();
Pkg_private void textsw_do_save();
Pkg_private int textsw_get_selection_as_string();
Pkg_private void textsw_init_selection_object();
Pkg_private int textsw_match_field_and_normalize();
Pkg_private void textsw_do_duplicate();
Pkg_private void xv_do_move();
Pkg_private void textsw_find_pattern_and_normalize();
Pkg_private int textsw_call_filter();
Pkg_private void textsw_possibly_normalize_and_set_selection();
Pkg_private int textsw_function_get();
Pkg_private int textsw_function_delete();
Pkg_private void textsw_record_match();
Pkg_private void textsw_possibly_edited_now_notify();
Pkg_private void textsw_init_again();
Pkg_private void textsw_record_find();
Pkg_private int textsw_parse_rc();
Pkg_private Textsw_status textsw_file_stuff_from_str();
Pkg_private int textsw_expand_filename();
Pkg_private void textsw_record_extras();
Pkg_private int include_cmd_proc();
Pkg_private int open_cmd_proc();
Pkg_private void textsw_abort();
Pkg_private int textsw_do_move();
Pkg_private int textsw_mouseless_scroll_event();
Pkg_private void textsw_resize();
Pkg_private int textsw_empty_document();
Pkg_private int textsw_change_directory();
Pkg_private void textsw_set_internal_tier2();
Pkg_private void textsw_put();
Pkg_private int textsw_load_file();
Pkg_private int match_in_table();
Pkg_private void textsw_begin_match_field();
Pkg_private void textsw_match_field();
Pkg_private void textsw_default_notify();
Pkg_private int textsw_screen_column_count();
Pkg_private int textsw_sync_with_seln_svc();
Pkg_private void textsw_clear_move();
Pkg_private void textsw_clear_duplicate();
Pkg_private void textsw_set_cursor();
Pkg_private int textsw_mouseless_select_event();
Pkg_private int textsw_mouseless_misc_event();
Pkg_private int textsw_get_selection_as_filename();
Pkg_private void textsw_reset_2();
Pkg_private void textsw_format_load_error_quietly();
Pkg_private void textsw_replace_esh();
Pkg_private Es_index textsw_get_saved_insert();
Pkg_private Es_index textsw_set_insert();
Pkg_private Ev_mark_object textsw_add_mark_internal();
Pkg_private void textsw_free_again();
Pkg_private void textsw_normalize_internal();
Pkg_private int textsw_prepare_buf_for_es_read();
Pkg_private void textsw_repaint();
Pkg_private void textsw_show_caret();
Pkg_private void textsw_set_null_view_avlist();
#ifdef OW_I18N
Pkg_private int textsw_do_newline();
#endif
#endif

Pkg_private int text_notice_key;

/* Used as dampers to hand motion when trying to select an insertion point */
#define	TXTSW_X_POINT_SLOP 2
#define TXTSW_Y_POINT_SLOP 1


#endif
