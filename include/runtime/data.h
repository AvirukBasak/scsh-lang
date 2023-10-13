#ifndef RT_DATA_H
#define RT_DATA_H

#include <stdbool.h>
#include <stdint.h>

#include "ast.h"

typedef struct RT_Data_t RT_Data_t;
typedef struct RT_DataStr_t RT_DataStr_t;
typedef struct RT_DataList_t RT_DataList_t;
typedef struct RT_DataMap_t RT_DataMap_t;
typedef struct RT_DataProc_t RT_DataProc_t;

/* based on the mapping of datatype IDs provided
   by the Shsc IR Spec
   https://github.com/AvirukBasak/shsc-runtime/docs/ShscIrSpec.md */
enum RT_DataType_t {
    RT_DATA_TYPE_BUL = 0,        /* boolean        : 1 B */
    RT_DATA_TYPE_CHR = 1,        /* char           : 1 B */
    RT_DATA_TYPE_I64 = 2,        /* int64_t        : 8 B */
    RT_DATA_TYPE_F64 = 3,        /* double         : 8 B */
    RT_DATA_TYPE_STR = 4,        /* char*          : variable  */
    RT_DATA_TYPE_INTERP_STR = 5, /* parsable char* : variable  */
    RT_DATA_TYPE_LST = 6,        /* list           : variable  */
    RT_DATA_TYPE_ANY = 7,        /* void*          : undefined */
    RT_DATA_TYPE_MAP = 8,        /* hash map       : variable  */
    RT_DATA_TYPE_PROC = 9,       /* procedure      : ??  */
};

struct RT_DataProc_t {
    const AST_Identifier_t *modulename;
    const AST_Identifier_t *procname;
};

struct RT_Data_t {
    union {
        bool bul;
        char chr;
        int64_t i64;
        double f64;
        RT_DataStr_t *str;
        RT_DataList_t *lst;
        RT_DataMap_t *mp;
        RT_DataProc_t proc;
        void *any;
    } data;
    enum RT_DataType_t type;
};

RT_Data_t RT_Data_bul(bool val);
RT_Data_t RT_Data_chr(char val);
RT_Data_t RT_Data_i64(int64_t val);
RT_Data_t RT_Data_f64(double val);
RT_Data_t RT_Data_str(RT_DataStr_t *str);
RT_Data_t RT_Data_interp_str(const char *str);
RT_Data_t RT_Data_list(RT_DataList_t *lst);
RT_Data_t RT_Data_map(RT_DataMap_t *mp);
RT_Data_t RT_Data_any(void *ptr);
RT_Data_t RT_Data_null(void);
void RT_Data_copy(RT_Data_t *var);
void RT_Data_destroy(RT_Data_t *var);

bool RT_Data_isnull(const RT_Data_t var);
char *RT_Data_interp_str_parse(const char *str);
bool RT_Data_tobool(const RT_Data_t var);
char *RT_Data_tostr(const RT_Data_t var);
const char *RT_Data_typename(const RT_Data_t var);
int RT_Data_print(const RT_Data_t var);

#endif
