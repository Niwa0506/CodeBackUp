#include <stdio.h>
#include <stdlib.h>

typedef int elementtype;   /* データはint型 */

/* リストの実現に必要な関数群 */
typedef struct node {
	elementtype element;
	struct node *next;
} * Node;

struct node *initlist(void) {
	struct node *n;

	n = (struct node *)malloc(sizeof(struct node));
	n->next = NULL;
	return n;
}

void insert(struct node *p, elementtype x) {
	struct node *n;

	n = (struct node *)malloc(sizeof(struct node));
	n->element = x;
	n->next = p->next;
	p->next = n; 
}

void delete(struct node *p) {
	if (p->next != NULL) {
		p->next = p->next->next;
	}
}
/* ここまでがリスト関係 */


/* スタックの実現に必要な関数群 */

/*--- ハッシュ表 ---*/
typedef struct {
	int  size;     /* ハッシュ表の大きさ */
	Node *table;  /* ハッシュ表の先頭要素へのポインタ */
} Hash;


/*--- ハッシュ関数（keyのハッシュ値を返す） ---*/
int hash(int key)
{
	return (key % 13);
}

/*--- ノードの各メンバに値を設定 ---*/
void SetNode(Node n, elementtype x, Node next)
{
	n->element = x;     
	n->next = next;  
}

/*--- ハッシュ表を初期化 ---*/
Hash* InitHash(int size)
{
	Hash *h = NULL;
	int i;

	if ((h = calloc(1, sizeof(Hash))) == NULL)  /* calloc = ヒープからメモリを確保 */
		return (0);

	h->size = 0;
	if ((h->table = calloc(size, sizeof(Node))) == NULL)  /* calloc = ヒープからメモリを確保 */
		return (0);

	h->size = size;         /* バケット数をセット */
	for (i = 0; i < size; i++) 
		h->table[i] = initlist();   /* 全バケットを初期化 */

	return (h);
}


/*--- 探索 ---*/
Node SearchNode(Hash *h, elementtype x)
{
	int key = hash(x);        /* 探索するデータのハッシュ値 */
	Node p = h->table[key];     /* 着目ノード */

	while (p->next != NULL) {
		if (p->next->element == x)     /* このキーは登録済み */
			return (p->next);
		p = p->next;               /* 後続ノードに着目 */
	}
	return (NULL);               /* 探索失敗 */
}

/*--- データの追加 ---*/
int InsertNode(Hash *h, elementtype x)
{
	int key = hash(x);               /* 追加するデータのハッシュ値 */
	Node p = h->table[key];            /* 着目ノード */
	while (p->next != NULL) {
		if (p->next->element == x)            /* このキーは登録済み */
			return (1);
		p = p->next;                      /* 後続ノードに着目 */
	}

	insert(h->table[key], x);        /* リスト操作の関数を利用 */

	return (0);
}


/*--- データの削除 ---*/
int DeleteNode(Hash *h, elementtype x)
{
	int key = hash(x);       /* 削除するデータのハッシュ値 */
	Node p = h->table[key];    /* 着目ノード */

	while (p->next != NULL) {
		if (p->next->element== x) {   /* 見つけたら */
			delete(p);        /* list操作用の関数を利用 */
			return (0);
		}
		p = p->next;
	}
	return (1);                 /* そのキー値は存在しない */
}


/* ハッシュ表を表示 */
void DumpHash(Hash *h)
{
	int i;

	for (i = 0; i<h->size; i++) {
		Node p = h->table[i];
		printf("%02d: ", i);
		while (p->next != NULL) {
			printf(" -> %d", p->next->element);
			p = p->next;
		}
		putchar('\n');
	}
	putchar('\n');
}

int main(void) {
	Hash *hash = InitHash(13);

	InsertNode(hash, 2);
	InsertNode(hash, 21);
	InsertNode(hash, 47);
	InsertNode(hash, 8);
	
	DumpHash(hash);      
	DeleteNode(hash, 47);
	DumpHash(hash);     

}
