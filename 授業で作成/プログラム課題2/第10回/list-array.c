#include <stdio.h>
#include <stdlib.h>

#define MAXLENGTH 1000

typedef int elementtype;

typedef int position;
typedef struct list {
  elementtype elements[MAXLENGTH];
  position last;
} * list;

list initlist(){
  list p;
  p = (list)malloc(sizeof(*p));
  p->last = -1;
  return p;
}

void insert(list l, position p, elementtype e){
  position i;
  if(l->last >= MAXLENGTH-1){
    printf("overflow\n");
    exit(1);
  }else if(p < 0 || p > l->last + 1){
    printf("illegal position\n");
    exit(1);
  }else{
    for(i = l->last; i >= p; i--){
      l->elements[i+1] = l->elements[i];
    }
    l->elements[p] = e;
    l->last++;
  }
}


void delete(list l, position p){
  if(p < 0 || p > l->last + 1){
    printf("illegal position\n");
    exit(1);
  }else if(l->last < 0){
    printf("list is empty\n");
  }else{
    for(int i = p;i <= l->last;++i){
      l->elements[i] = l->elements[i+1]; 
    }
    l->last--;
  }
}


position first(list l){
  return 0;
}

position end(list l){
  return l->last + 1;
}

position next(list l, position p){
  if(p < 0 || p > l->last){
    printf("illegal position\n");
    exit(1);
  }else{
    return p + 1;
  }
}

position previous(list l, position p){
  if(p < 1 || p > l->last){
    printf("illegal position\n");
    exit(1);
  }else{
    return p - 1;
  }
}

elementtype retrieve(list l, position p){
  if(p < 0 || p > l->last){
    printf("illegal position\n");
    exit(1);
  }

  return l->elements[p];
}


position locate(list l, elementtype e){
  for(position i = 0;i <= l->last;++i){
    if(l->elements[i] == e){
      return i;
    }
  }
  end(l);
  return 0;
}


void printlist(list l){
  position i;
  for(i = 0; i <= l->last; i++){
    printf("%c", retrieve(l, i));
  }
  printf("\n");
}

int main(void){
  list l;

  l = initlist();

  insert(l, first(l), 'U');
  insert(l, end(l), 'E');
  insert(l, end(l), 'C');
  
  //printlist(l);
  //delete(l,);
  printlist(l);
  delete(l,locate(l,'E'));
   //delete‚ðŽÀ‘•‚µ‚½‚çAˆÈ‰º‚ÌƒRƒƒ“ƒgƒAƒEƒg•”•ª‚ðŽÀs‚µ‚Ä‚Ý‚Ä‚­‚¾‚³‚¢ */
  //delete(l, locate(l, 'E')); 
  printlist(l);
  printf("%d\n",locate(l,'K'));
  /*delete(l,0);
  printlist(l);
  delete(l,0); */

  return 0;
}
