#import <stdio.h>
void tdown(int T[],int k, int m){
    int c = 2*k+1;
    if(c>=m)return;
    int r = c+1;
    if(r<=m&&T[r]<T[c])c=r;
    if(T[k]<=T[c])return;   
    int v = T[k];T[k] = T[c];T[c] = v;
    tdown(T,c,m);
}
void tup(int T[],int c){
    if(c<=0)return;
    int p = (c-1)/2;
    if(T[p]<=T[c])return;
    int v = T[p];T[p]=T[c];T[c]=v;
    tup(T,p);
}
int main(){
    int T[15] ={15,7,14,3,6,10,13,1,2,4,5,8,9,11,12};
    int X[1023];
    int seed = 123456789;
    for(int i=0;i<1023;i++){
        if(i<15)X[i]=T[i];
        else{
            X[i]=seed%i+15;
        }
    }
    for(int i=6;i>=0;i--)
        tdown(X,i,14);
    for(int i=15;i<1023;i++){
        tup(X,i);
    }
    for(int i=1022;i>=0;i--){
        for(int j=i;j>=0;j--)
            tdown(X,(j-1)/2,i);
        int v = X[0];X[0]=X[i];X[i]=v;
    }
    for(int i=0;i<1023;i++)
        printf("%d ",X[i]); 
    printf("\n");

}