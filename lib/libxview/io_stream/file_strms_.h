#if !defined(FILE_STRMS__H)
#define FILE_STRMS__H

#include <xview/pkg.h>
#include <xview_private/io_stream.h>


STREAM *xv_file_input_stream(char *s, FILE *fp);
STREAM *xv_file_output_stream(char *s, FILE *fp, Bool append);

#endif

