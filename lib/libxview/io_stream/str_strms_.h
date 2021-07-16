#if !defined(STR_STRMS__H)
#define STR_STRMS__H

#include <xview/pkg.h>
#include <xview_private/io_stream.h>


STREAM *string_input_stream(char *s, STREAM *in);
STREAM * string_output_stream(char *s, STREAM *out);

#endif

