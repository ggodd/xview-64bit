#if !defined(WHITESPACE__H)
#define WHITESPACE__H

#include <xview/pkg.h>
#include <xview/str_utils.h>

enum CharClass xv_white_space(char c);
struct CharAction xv_everything(char c);

#endif

