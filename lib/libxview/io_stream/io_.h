#if !defined(IO__H)
#define IO__H

#include <xview/pkg.h>
#include <xview_private/io_stream.h>


void stream_close(STREAM *stream);
struct posrec stream_get_pos(STREAM *stream);

#endif

