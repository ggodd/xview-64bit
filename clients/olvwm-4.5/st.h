
/* This is a general purpose hash table package written by Peter Moore @ UCB. */

#ifdef IDENT
#ident "@(#)st.h	1.1 olvwm version 09/22/03"
#endif

/*
 * Based on
#ident	"@(#)st.h	26.5	91/09/14 SMI"
 *
 */

#ifndef ST_INCLUDED

#define ST_INCLUDED

typedef struct st_table_entry st_table_entry;

struct st_table_entry {
    char *key;
    char *record;
    st_table_entry *next;
};

typedef struct st_table st_table;

struct st_table {
    int (*compare)();
    int (*hash)();
    int num_bins;
    int num_entries;
    int max_density;
    int reorder_flag;
    double grow_factor;
    st_table_entry **bins;
};

#define st_is_member(table,key) st_lookup(table,key,(char **) 0)

enum st_retval {ST_CONTINUE, ST_STOP, ST_DELETE};

#ifdef __STDC__
int st_delete(st_table *table, char **key, char **value);
int st_find_or_add(st_table *table, char *key, char ***slot);
st_table *st_init_table(int (*compare)(), int (*hash)());
st_table *st_init_table_with_params(int (*compare)(), int (*hash)(), int size, int density, double grow_factor, int reorder_flag);
void st_free_table(st_table *table);
int st_insert(st_table *table, char *key, char *value);
int st_lookup(st_table *table, char *key, char **value);
void st_add_direct(st_table *table, char *key, char *value);
void st_foreach(st_table *table, enum st_retval (*func)(), char *arg);
int st_strhash(char *string, int modulus);
#else
int st_delete();
int st_find_or_add();
st_table *st_init_table();
st_table *st_init_table_with_params();
void st_free_table();
int st_insert();
int st_lookup();
void st_add_direct();
void st_foreach();
int st_strhash();
#endif

#ifdef NOT
#define ST_NUMCMP	((int (*)()) 0)
#define ST_NUMHASH	((int (*)()) -2)

#define ST_PTRCMP	((int (*)()) 0)
#define ST_PTRHASH	((int (*)()) -1)

#define st_numcmp	ST_NUMCMP
#define st_numhash	ST_NUMHASH
#define st_ptrcmp	ST_PTRCMP
#define st_ptrhash	ST_PTRHASH
#endif

#define ST_DEFAULT_MAX_DENSITY 5
#define ST_DEFAULT_INIT_TABLE_SIZE 11
#define ST_DEFAULT_GROW_FACTOR 2.0
#define ST_DEFAULT_REORDER_FLAG 0

#endif ST_INCLUDED
