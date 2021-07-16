#if !defined(GETTEXT__H)
#define GETTEXT__H


char *bindtextdomain(char *domain_name, unsigned char *binding);
char *textdomain(char *domain_name);
char *gettext(char *msg_id);
char *dgettext(char *domain_name, char *msg_id);

#endif

