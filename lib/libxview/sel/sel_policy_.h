#if !defined(SEL_POLICY__H)
#define SEL_POLICY__H

#include <xview/pkg.h>
#include <xview_private/seln_impl.h>

Xv_public Seln_response selection_figure_response(Xv_Server server, Seln_function_buffer *buffer, Seln_holder **holder);
Xv_public void selection_report_event(Xv_Server server, Seln_client seln_client, struct inputevent *event);

#endif

