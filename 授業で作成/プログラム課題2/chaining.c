#include <stdio.h>
#include <stdlib.h>

typedef int elementtype;   /* �f�[�^��int�^ */

/* ���X�g�̎����ɕK�v�Ȋ֐��Q */
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
/* �����܂ł����X�g�֌W */


/* �X�^�b�N�̎����ɕK�v�Ȋ֐��Q */

/*--- �n�b�V���\ ---*/
typedef struct {
	int  size;     /* �n�b�V���\�̑傫�� */
	Node *table;  /* �n�b�V���\�̐擪�v�f�ւ̃|�C���^ */
} Hash;


/*--- �n�b�V���֐��ikey�̃n�b�V���l��Ԃ��j ---*/
int hash(int key)
{
	return (key % 13);
}

/*--- �m�[�h�̊e�����o�ɒl��ݒ� ---*/
void SetNode(Node n, elementtype x, Node next)
{
	n->element = x;     
	n->next = next;  
}

/*--- �n�b�V���\�������� ---*/
Hash* InitHash(int size)
{
	Hash *h = NULL;
	int i;

	if ((h = calloc(1, sizeof(Hash))) == NULL)  /* calloc = �q�[�v���烁�������m�� */
		return (0);

	h->size = 0;
	if ((h->table = calloc(size, sizeof(Node))) == NULL)  /* calloc = �q�[�v���烁�������m�� */
		return (0);

	h->size = size;         /* �o�P�b�g�����Z�b�g */
	for (i = 0; i < size; i++) 
		h->table[i] = initlist();   /* �S�o�P�b�g�������� */

	return (h);
}


/*--- �T�� ---*/
Node SearchNode(Hash *h, elementtype x)
{
	int key = hash(x);        /* �T������f�[�^�̃n�b�V���l */
	Node p = h->table[key];     /* ���ڃm�[�h */

	while (p->next != NULL) {
		if (p->next->element == x)     /* ���̃L�[�͓o�^�ς� */
			return (p->next);
		p = p->next;               /* �㑱�m�[�h�ɒ��� */
	}
	return (NULL);               /* �T�����s */
}

/*--- �f�[�^�̒ǉ� ---*/
int InsertNode(Hash *h, elementtype x)
{
	int key = hash(x);               /* �ǉ�����f�[�^�̃n�b�V���l */
	Node p = h->table[key];            /* ���ڃm�[�h */
	while (p->next != NULL) {
		if (p->next->element == x)            /* ���̃L�[�͓o�^�ς� */
			return (1);
		p = p->next;                      /* �㑱�m�[�h�ɒ��� */
	}

	insert(h->table[key], x);        /* ���X�g����̊֐��𗘗p */

	return (0);
}


/*--- �f�[�^�̍폜 ---*/
int DeleteNode(Hash *h, elementtype x)
{
	int key = hash(x);       /* �폜����f�[�^�̃n�b�V���l */
	Node p = h->table[key];    /* ���ڃm�[�h */

	while (p->next != NULL) {
		if (p->next->element== x) {   /* �������� */
			delete(p);        /* list����p�̊֐��𗘗p */
			return (0);
		}
		p = p->next;
	}
	return (1);                 /* ���̃L�[�l�͑��݂��Ȃ� */
}


/* �n�b�V���\��\�� */
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
