
#include <stdlib.h>
#include <string.h>
#include "ebuf.h"
#include <stdbool.h>
struct line {
	struct line *prev, *next; char str[MAXSTR];
};

struct ebuf { struct line *head, *cur; }; 
ebufp ebuf_new() {
	ebufp r = (ebufp)malloc(sizeof(struct ebuf)); 
	r->head = (struct line*)malloc(sizeof(struct line)); 
	r->cur = r->head->next = r->head->prev = r->head; 
	strcpy(r->head->str, "EOF"); 
	return r;
}

bool ebuf_iseof(ebufp e) { 
	return e->cur == e->head; 
}

bool ebuf_forward(ebufp e) {
	if(e->cur == e->head) { 
		return false; 
	}
	e->cur = e->cur->next; 
	return true;
}

bool ebuf_backward(ebufp e) {
	if(e->cur->prev == e->head) { 
		return false; 
	} 
	e->cur = e->cur->prev; 
	return true;
}

void ebuf_top(ebufp e) { 
	e->cur = e->head->next; 
}

char *ebuf_str(ebufp e) { 
	return e->cur->str; 
}
void ebuf_replace(ebufp e, char *s) {
	struct line *p = (struct line*)malloc(sizeof(struct line)); 
		strncpy(p->str, s, MAXSTR); 
		p->str[MAXSTR-1] = '\0';
		p->prev = e->cur->prev;
		p->next = e->cur->next;
		e->cur->prev->next = p;
		e->cur= p;
}

void ebuf_insert(ebufp e, char *s) {
	struct line *p = (struct line*)malloc(sizeof(struct line)); 
		strncpy(p->str, s, MAXSTR); 
		p->str[MAXSTR-1] = '\0';
		p->prev = e->cur->prev;
		p->next = e->cur;
		e->cur->prev->next = p;
		e->cur->prev = p;
}



void expect_str(char *s1, char *s2, char *msg) {
	printf("%s ’%s’:’%s’ %s\n", strcmp(s1, s2)?"NG":"OK", s1, s2, msg); 
}

int main(void) {
	ebufp e = ebuf_new(); ebuf_insert(e, "abc"); ebuf_insert(e, "def");
	ebuf_top(e); 		expect_str(ebuf_str(e), "abc", "line 1: abc"); printf("%s\n",ebuf_str(e));
	ebuf_forward(e); 	expect_str(ebuf_str(e), "def", "line 2: def");printf("%s\n",ebuf_str(e));
	ebuf_insert(e, "ghi"); 
	ebuf_top(e);
	ebuf_forward(e); 	expect_str(ebuf_str(e), "ghi", "new line 2: ghi");printf("%s\n",ebuf_str(e));
	ebuf_forward(e); 	expect_str(ebuf_str(e), "def", "new line 3: def"); printf("%s\n",ebuf_str(e));
	ebuf_replace(e,"qwe");printf("replaceの結果は%s\n",ebuf_str(e));
	ebuf_top(e);
	ebuf_forward(e); 	expect_str(ebuf_str(e), "ghi", "new line 2: ghi");printf("%s\n",ebuf_str(e));
	ebuf_forward(e); 	expect_str(ebuf_str(e), "qwe", "new line 3: def"); printf("%s\n",ebuf_str(e));
	ebuf_forward(e);	expect_str(ebuf_str(e), "EOF","new line 4:EOF");
	return 0;
}