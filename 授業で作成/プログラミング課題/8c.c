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
	
//完成
void ebuf_delete(ebufp e,ebufp p){
	if(e->cur != e->head ){
		/*p->cur = p->head;
		p->cur = p->cur->prev->prev;
		p->cur->next = e->cur;
		p->head->prev = e->cur;
		p->cur->next = e->cur;
		p->cur = p->head->prev; */
		struct line *k = (struct line*)malloc(sizeof(struct line)); 
		strncpy(k->str, e->cur->str,MAXSTR);
		k->str[MAXSTR-1] = '\0';
		k->prev = p->cur->prev;
		k->next = p->cur;
		p->cur->prev->next = k;
		p->cur->prev = k;
		p->cur = p->cur->prev;
		/*k->str[MAXSTR-1] = '\0';
		k->next= p->cur->next;
		k->prev = p->cur;
		p->cur->next->prev = k;
		p->cur->next = k;
		p->cur = p->cur->next;*/
		//完成
		e->cur->prev->next = e->cur->next;
		e->cur->next->prev = e->cur->prev;
		e->cur = e->cur->next;
	}
}
int n=0;
void ebuf_yank(ebufp e,ebufp p){
	if(n >=1){p->cur = p->cur->prev;}else{p->cur = p->head->prev;n+=1;}
	struct line *l = (struct line*)malloc(sizeof(struct line)); 
		strncpy(l->str, p->cur->str, MAXSTR); 
		l->str[MAXSTR-1] = '\0';
		l->prev = e->cur->prev;
		l->next = e->cur;
		e->cur->prev->next = l;
		e->cur->prev = l;
}
void check(ebufp p){
	p->cur = p->head->next;
}

void expect_str(char *s1, char *s2, char *msg) {
	printf("%s ’%s’:’%s’ %s\n", strcmp(s1, s2)?"NG":"OK", s1, s2, msg); 
}

int main(void) {
	ebufp e = ebuf_new();ebufp p = ebuf_new();strcpy(p->cur->str , "EOF");ebuf_insert(e, "1");//printf("%s\n",ebuf_str(e));
	ebuf_insert(e, "aaa");ebuf_insert(e,"bbb");ebuf_insert(e,"ccc");ebuf_insert(e,"2");ebuf_insert(e,"3");
	//ebuf_insert(e,"ccc");ebuf_insert(e,"2");ebuf_insert(e,"3");
	ebuf_top(e); 		//expect_str(ebuf_str(e), "1", "line 1: abc"); printf("%s\n",ebuf_str(e));
	ebuf_forward(e); 	//expect_str(ebuf_str(e), "aaa", "line 2: def");printf("%s\n",ebuf_str(e));
	ebuf_delete(e,p);printf("一回目の削除%s\n",ebuf_str(p));printf("%s\n",ebuf_str(p));
	ebuf_delete(e,p);printf("二回目の削除%s\n",ebuf_str(p));printf("%s\n",ebuf_str(p));//printf("%s\n",ebuf_str(e));
	ebuf_delete(e,p);printf("三回目の削除%s\n",ebuf_str(p));printf("%s\n",ebuf_str(p));//printf("%s\n",ebuf_str(e));
	ebuf_forward(e); ebuf_forward(e); //check(p);
	//printf("%s\n",ebuf_str(p));
	ebuf_yank(e,p);ebuf_yank(e,p);ebuf_yank(e,p);

//ebuf_yank(e,p);ebuf_yank(e,p);ebuf_yank(e,p);
//	ebuf_insert(e, "ghi"); 

ebuf_top(e);		expect_str(ebuf_str(e), "1", "new line 1: ghi");//printf("%s\n",ebuf_str(e));
	ebuf_forward(e); 	expect_str(ebuf_str(e), "2", "new line 2: ghi");//printf("%s\n",ebuf_str(e));
	ebuf_forward(e); 	expect_str(ebuf_str(e), "3", "new line 3: def");// printf("%s\n",ebuf_str(e));
	ebuf_forward(e); 	expect_str(ebuf_str(e), "aaa", "new line 4: def");
	ebuf_forward(e); 	expect_str(ebuf_str(e), "bbb", "new line 5: def");
	ebuf_forward(e); 	expect_str(ebuf_str(e), "ccc", "new line 6: def");
//	ebuf_replace(e,"qwe");printf("replaceの結果は%s\n",ebuf_str(e));
//	ebuf_top(e);
//	ebuf_delete(e,p); 	//expect_str(ebuf_str(e),"ghi",  "new line 1: abc");printf("%s\n",ebuf_str(e));
//	ebuf_forward(e);	//expect_str(ebuf_str(e), "qwe", "new line 2: ghi");printf("%s\n",ebuf_str(e));
//	ebuf_forward(e); 	//expect_str(ebuf_str(e), "EOF", "new line 3: def"); printf("%s\n",ebuf_str(e));
	return 0;
}