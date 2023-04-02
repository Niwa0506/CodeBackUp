#include <stdio.h>
#include <stdlib.h>

typedef int elementtype;   /* データはint型 */

/*--- 状態(Status) --- */
/* Occupied = 0, Empty = 1, Deleted = 2 */
typedef enum {
	Occupied, Empty, Deleted
} Status;   

/*---バケット用構造体 ---*/
typedef struct {
	elementtype   element;  /* データ */
	Status stat;  /* 要素の状態 */
} Bucket;


/*--- ハッシュ表 ---*/
typedef struct {
	int  size;     /* ハッシュ表の大きさ */
	Bucket *table;  /* ハッシュ表の先頭要素へのポインタ */
} Hash;

/*--- ハッシュ関数（keyのハッシュ値を返す） ---*/
int hash(int key)
{
	return (key % 13);
}

/*--- 再ハッシュ関数 ---*/
int rehash(int key)
{
	return ((key + 1) % 13);
}


/*--- ノードの各メンバに値を設定 ---*/
void SetBucket(Bucket *n, elementtype x, Status stat)
{
	n->element = x;
	n->stat = stat;
}


/*--- ハッシュ表を初期化 ---*/
Hash* InitHash(int size)
{
	Hash *h = NULL;
	int i;

	if ((h = calloc(1, sizeof(Hash))) == NULL)  /* calloc = ヒープからメモリを確保 */
		return (0);

	h->size = 0;
	if ((h->table = calloc(size, sizeof(Bucket))) == NULL)  /* calloc = ヒープからメモリを確保 */
		return (0);

	h->size = size;         /* バケット数をセット */
	for (i = 0; i < size; i++) 
		h->table[i].stat = Empty;   /* 全バケットを初期化 */

	return (h);
}


/*--- 探索 ---*/
Bucket *SearchBucket(Hash *h, elementtype x)
{
	int i;
	int key = hash(x);          /* 探索するデータのハッシュ値 */
	Bucket *p = &h->table[key];    /* 着目バケット */

	for (i = 0; (p->stat != Empty) && (i < h->size); i++) {
		if (p->stat == Occupied && p->element == x)
			return (p);
		key = rehash(key);
		p = &h->table[key];
	}
	return (NULL);               /* 探索失敗 */

}

/*--- データの追加 ---*/
int InsertBucket(Hash *h, elementtype x)
{
	int i;
	int key = hash(x);               /* 追加するデータのハッシュ値 */
	Bucket *p = &h->table[key];         /* 着目バケット */

	if (SearchBucket(h, x))              /* このキーは登録済み */
		return (1);

	for (i = 0; i < h->size; i++) {
		if (p->stat == Empty || p->stat == Deleted) {  /* 空か削除済みならば書き込む */
			SetBucket(p, x, Occupied);
			return (0);
		}
		key = rehash(key);
		p = &h->table[key];
	}

	return (2);    /* ハッシュ表が満杯 */
}


/*--- データの削除 ---*/
int DeleteBucket(Hash *h, elementtype x)
{
	Bucket *p = SearchBucket(h, x);

	if (p == NULL)
		return (1);             /* そのキー値は存在しない */

	p->stat = Deleted;
	return (0);
}


/* ハッシュ表を表示 */
void DumpHash(Hash *h)
{
	int i;

	for (i = 0; i<h->size; i++) {
		printf("%02d  ", i);
		switch (h->table[i].stat) {
		case Occupied:
			printf("%d\n", h->table[i].element);
			break;
		case Empty:
			printf("--- Empty ---\n");  break;
		case Deleted:
			printf("--- Deleted ---\n");  break;
		}
	}

	printf("\n");
}


int main(void) {
	Hash *hash = InitHash(13);

	InsertBucket(hash, 2);
	InsertBucket(hash, 21);
	InsertBucket(hash, 47);
	InsertBucket(hash, 8);
	DumpHash(hash);     
	DeleteBucket(hash, 21);
	DumpHash(hash);     
	DeleteBucket(hash,47);
	DumpHash(hash);

}