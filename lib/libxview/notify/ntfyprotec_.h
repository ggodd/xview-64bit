#if !defined(NTFYPROTEC__H)
#define NTFYPROTEC__H

#include <xview/pkg.h> 
#include <xview_private/ntfy.h>

pkg_private void ntfy_end_critical(void);
pkg_private char *ntfy_malloc(u_int size);
pkg_private void ntfy_free_malloc(NTFY_DATA ptr);
pkg_private void ntfy_flush_tb_freed(void);

#endif

