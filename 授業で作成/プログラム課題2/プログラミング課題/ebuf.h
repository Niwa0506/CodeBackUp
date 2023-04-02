#include <stdio.h>
#include <stdbool.h>
#define MAXSTR 100
struct ebuf;
typedef struct ebuf *ebufp;
ebufp ebuf_new();
bool ebuf_iseof(ebufp e);
bool ebuf_forward(ebufp e);
bool ebuf_backward(ebufp e);
void ebuf_top(ebufp e);
char *ebuf_str(ebufp e); 
void ebuf_insert(ebufp e, char *s);
void ebuf_delete(ebufp e);