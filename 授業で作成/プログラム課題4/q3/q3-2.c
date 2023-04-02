#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_BUF_SIZE 1024

#define QUEUESIZE 128
typedef char elementtype;

typedef struct {
  int front, rear;
  elementtype elements[QUEUESIZE];
} queue;

void initqueue(queue *q)
{
  q->front = q->rear = 0;
}

int queueempty(queue *q)
{
  if(q->front == q->rear){return 1;}
  else{return 0;}
}

void printqueue(queue *q)
{
  char str[MAX_BUF_SIZE];
  elementtype x;
  for(int i = q->rear;i < q->front;++i){
    x = q->elements[i];
    str[i-q->rear] = x;
    if(i ==q->rear){printf("[");}
    if(i != q->front-1){
    printf("%c, ",str[i-q->rear]);
    }else{printf("%c",str[i-q->rear]);printf("]");} 
  }
  printf("\n");
}

void putq(queue *q, elementtype x)
{
  q->elements[q->front] = x;
  q->front += 1;
}

elementtype getq(queue *q)
{
  q->rear +=1;
  return q->elements[q->rear-1];
}

void test(void)
{
  elementtype x;
  queue q;
  char buf[MAX_BUF_SIZE], str[MAX_BUF_SIZE];
  int n = 0;

  initqueue(&q);

  while(fgets(buf, MAX_BUF_SIZE, stdin) != NULL){
    if (strncmp(buf, "putq ", 5) == 0){
      // putq
      x = buf[5]; // 6文字目が要素
      putq(&q, x);
      continue;
    }
    if (strncmp(buf, "getq", 4) == 0){
      // getq
      x = getq(&q);
      str[n] = x;
      n++;
      continue;
    }
    printf("Unknown command.\n");
  }

  printqueue(&q);

  for(int i = 0; i < n; i++){
    printf("%c", str[i]);
  }
  printf("\n");
}

int main(void)
{
  test();

  return 0;
}
