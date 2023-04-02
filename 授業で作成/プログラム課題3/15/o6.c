#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SETMAX 10600
char buf[256];
struct station { int eki; char name[64], rosen[64]; };
int main() {
  int i=0, ekisize, l, r, m;
  struct station *ekidata[SETMAX], *st;
  char ekiname[64];
  FILE *fp = fopen("./ekisen.txt","r");
  while(fgets(buf,sizeof(buf),fp)!=NULL && i<SETMAX) {
    st = (struct station*) malloc(sizeof(struct station));
    sscanf(buf, "%[^:]:%d:%[^\n]*c", st->name, &st->eki, st->rosen);
    ekidata[i] = st;
    ++i;
  }
  fclose(fp);
  ekisize = i;
  scanf("%[^\n]%*c",ekiname);
  l=0; r=ekisize-1;
  /* ここから二分探索 */ 
  while(l<=r) {
    if(l==r){
        if(strcmp(ekidata[l]->name,ekiname)!=0){
          ekidata[l]->eki=0;
        }
      break;}
    if(strcmp(ekidata[l]->name,ekiname)!=0){
      ekidata[l]->eki=0;
    }
    if(strcmp(ekidata[r]->name,ekiname)!=0){
      ekidata[r]->eki=0;
    }
    if(l<r){r--;}
    if(l<r){l++;}
  }
  if(r<l) { /* 駅名がない場合 */
  fprintf(stderr, "%s: 駅名がありません\n", ekiname); exit(1);
  }else { /* 駅名がある場合 */
  int i;
    for(i=0;i<ekisize;i++){
      if(ekidata[i]->eki!=0){
        printf("%d:%s\n",ekidata[i]->eki,ekidata[i]->rosen);
      }
    }
  }
return 0; 
}