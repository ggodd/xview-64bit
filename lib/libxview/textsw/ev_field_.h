#if !defined(EV_FIELD__H)
#define EV_FIELD__H

#include <xview/pkg.h>
#include <xview_private/ev.h>

Pkg_private Es_index ev_match_field_in_esh(Es_handle esh, CHAR *symbol1, int symbol1_len, CHAR *symbol2, int symbol2_len, Es_index start_pattern, unsigned direction);
Pkg_private Es_index ev_find_enclose_end_marker(Es_handle esh, CHAR *symbol1, int symbol1_len, CHAR *symbol2, int symbol2_len, Es_index start_pos);

#endif

