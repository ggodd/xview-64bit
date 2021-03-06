#ident	"@(#)st.h	26.7	93/06/28 SMI"

/* This is a general purpose hash table package written by Peter Moore @ UCB. */

#ifndef _OLWM_ST_H
#define _OLWM_ST_H

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

int st_delete(), st_insert();
void st_foreach(), st_add_direct();
int st_lookup(), st_find_or_add();

#ifdef __STDC__
st_table *st_init_table(int (*compare)(), int (*hash)());
st_table *st_init_table_with_params(int (*compare)(), int (*hash)(), int size, int density, double grow_factor, int reorder_flag);
void st_free_table(st_table *table);
int st_lookup(st_table *table, char *key, char **value);
#else
st_table *st_init_table();
st_table *st_init_table_with_params();
void st_free_table();
int st_lookup();
#endif


#define ST_NUMCMP	((int (*)()) 0)
#define ST_NUMHASH	((int (*)()) -2)

#define ST_PTRCMP	((int (*)()) 0)
#define ST_PTRHASH	((int (*)()) -1)

#define st_numcmp	ST_NUMCMP
#define st_numhash	ST_NUMHASH
#define st_ptrcmp	ST_PTRCMP
#define st_ptrhash	ST_PTRHASH

#define ST_DEFAULT_MAX_DENSITY 5
#define ST_DEFAULT_INIT_TABLE_SIZE 11
#define ST_DEFAULT_GROW_FACTOR 2.0
#define ST_DEFAULT_REORDER_FLAG 0

int st_strhash();

#endif /* _OLWM_ST_H */
