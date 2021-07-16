#if !defined(FILTER__H)
#define FILTER__H

#include <xview/pkg.h>
#include <xview_private/filter.h>

struct filter_rec **xv_parse_filter_table(STREAM *in, char *filename);
void xv_free_filter_table(struct filter_rec **table);

#endif

