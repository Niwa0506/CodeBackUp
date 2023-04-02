#include <stdio.h>
#include <stdlib.h>

void dump_byte(unsigned int n){
 int buf[8];
 int i;
 // 下位から順に二進数にして配列に格納
 for(i=0; i<8; i++){
 buf[i] = n % 2;
 n = n / 2;
 //printf("%d %d\n",buf[i],n);
 }
 // 変換結果を上位から順に出力
 for(i=7; i>=0; i--){
 if(buf[i] == 0){
 printf("0");
 } else {
 printf("1");
 }
 }
 }
void dump_bytes(unsigned char cp[], int nbyte){
int i;
for(i=0; i<nbyte; i++){
	dump_byte(cp[nbyte-i-1]); // little endian -> 逆 順
 // dump_byte(cp[i]); // big endian -> 番地順
 printf(" ");
 }
 printf("\n");
 }


 int main(int ac, char **av){
 /*struct ch { unsigned char b[4];};
 union {
    float a;
    struct ch c;
} u;*/
 float f; // 単精度浮動小数点型 (32 bit)
 double d; // 倍精度浮動小数点型 (64 bit)
 // av[1]: プログラム実行の第一引数の文字列
 // atof: 引数で指定した値を倍精度浮動小数点数に変換
// u.a = atof(av[1]); // 代入の際に単精度に変換される
 f = atof(av[1]);
 d = atof(av[1]); // 倍精度そのまま

 dump_bytes((unsigned char *)&f, sizeof f);
 dump_bytes((unsigned char *)&d, sizeof d);
 
exit(0);
 }