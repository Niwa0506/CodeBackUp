#include <stdbool.h>
struct iset;
typedef struct iset *isetp; 
isetp iset_new();
void iset_free(isetp s);
bool iset_isempty(isetp s);
bool iset_isin(isetp s, int e);
int iset_max(isetp s);
void iset_addelt(isetp s, int e);
void iset_subelt(isetp s, int e);
isetp iset_union(isetp s, isetp q); 
isetp iset_int(isetp s,isetp q);
isetp iset_dif(isetp s,isetp q);
isetp iset_ex(isetp s,isetp q);