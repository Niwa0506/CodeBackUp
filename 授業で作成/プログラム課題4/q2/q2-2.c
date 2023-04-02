#include <stdio.h>
#include <string.h>

char *findfirst(char*str, char*sub) {
    char *a, *b;
    if (*sub == 0) {
        return str;
    }
    for (; *str != 0; str += 1) {
        if (*str != *sub) {
            continue;
        }

        if(*str == *sub && sub  != 0){
            sub +=1;a = str;
        }
    /*            if(*sub == *str){
                    continue;
                }else{break;}
            }
        }*/   
        }  
        if(*sub == 0){
            sub -=1;
            for(;*sub != 0;sub -=1){
                a -=1;
            }
            a += 1;
            return a;  
    }
    return NULL;
}


int main(int argc, char *argv[]) {
    char *s1, *s2, *s;

    s1 = argv[1];
    s2 = argv[2];
    if((s=findfirst(s1, s2))) {
        printf("%s\n", s);
    }
    else {
        printf("\n");
    }
    return 0;
}
