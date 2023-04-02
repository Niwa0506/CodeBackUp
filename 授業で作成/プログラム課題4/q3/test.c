#include <stdio.h>
int main(void){
	char str[] = {'P', 'R', 'O', '2', 'U', 'E', 'C', '\0'};
char *ptr = str;

ptr[3] = '\0';


printf("%s\n", ptr++);     /* (1) */
printf("%s\n", ++ptr);     /* (2) */
printf("%s\n", ptr+2);     /* (3) */ 
}