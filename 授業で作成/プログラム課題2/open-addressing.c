#include <stdio.h>
#include <stdlib.h>

typedef int elementtype;   /* �f�[�^��int�^ */

/*--- ���(Status) --- */
/* Occupied = 0, Empty = 1, Deleted = 2 */
typedef enum {
	Occupied, Empty, Deleted
} Status;   

/*---�o�P�b�g�p�\���� ---*/
typedef struct {
	elementtype   element;  /* �f�[�^ */
	Status stat;  /* �v�f�̏�� */
} Bucket;


/*--- �n�b�V���\ ---*/
typedef struct {
	int  size;     /* �n�b�V���\�̑傫�� */
	Bucket *table;  /* �n�b�V���\�̐擪�v�f�ւ̃|�C���^ */
} Hash;

/*--- �n�b�V���֐��ikey�̃n�b�V���l��Ԃ��j ---*/
int hash(int key)
{
	return (key % 13);
}

/*--- �ăn�b�V���֐� ---*/
int rehash(int key)
{
	return ((key + 1) % 13);
}


/*--- �m�[�h�̊e�����o�ɒl��ݒ� ---*/
void SetBucket(Bucket *n, elementtype x, Status stat)
{
	n->element = x;
	n->stat = stat;
}


/*--- �n�b�V���\�������� ---*/
Hash* InitHash(int size)
{
	Hash *h = NULL;
	int i;

	if ((h = calloc(1, sizeof(Hash))) == NULL)  /* calloc = �q�[�v���烁�������m�� */
		return (0);

	h->size = 0;
	if ((h->table = calloc(size, sizeof(Bucket))) == NULL)  /* calloc = �q�[�v���烁�������m�� */
		return (0);

	h->size = size;         /* �o�P�b�g�����Z�b�g */
	for (i = 0; i < size; i++) 
		h->table[i].stat = Empty;   /* �S�o�P�b�g�������� */

	return (h);
}


/*--- �T�� ---*/
Bucket *SearchBucket(Hash *h, elementtype x)
{
	int i;
	int key = hash(x);          /* �T������f�[�^�̃n�b�V���l */
	Bucket *p = &h->table[key];    /* ���ڃo�P�b�g */

	for (i = 0; (p->stat != Empty) && (i < h->size); i++) {
		if (p->stat == Occupied && p->element == x)
			return (p);
		key = rehash(key);
		p = &h->table[key];
	}
	return (NULL);               /* �T�����s */

}

/*--- �f�[�^�̒ǉ� ---*/
int InsertBucket(Hash *h, elementtype x)
{
	int i;
	int key = hash(x);               /* �ǉ�����f�[�^�̃n�b�V���l */
	Bucket *p = &h->table[key];         /* ���ڃo�P�b�g */

	if (SearchBucket(h, x))              /* ���̃L�[�͓o�^�ς� */
		return (1);

	for (i = 0; i < h->size; i++) {
		if (p->stat == Empty || p->stat == Deleted) {  /* �󂩍폜�ς݂Ȃ�Ώ������� */
			SetBucket(p, x, Occupied);
			return (0);
		}
		key = rehash(key);
		p = &h->table[key];
	}

	return (2);    /* �n�b�V���\�����t */
}


/*--- �f�[�^�̍폜 ---*/
int DeleteBucket(Hash *h, elementtype x)
{
	Bucket *p = SearchBucket(h, x);

	if (p == NULL)
		return (1);             /* ���̃L�[�l�͑��݂��Ȃ� */

	p->stat = Deleted;
	return (0);
}


/* �n�b�V���\��\�� */
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