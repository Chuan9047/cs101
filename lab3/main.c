#include <stdio.h>

int i=0;

int my_strlen(char* s){
    while(s[i]!='\0')
    i++;
    return i;
}



int rec_strlen(char* s){
    if (s[0]=='\0'){
        return 0;
    }
    return rec_strlen(s+1)+1;
}

int main(){
    char s[]="IU123456789";
    printf("len=%d\n",my_strlen(s));
    printf("len=%d\n",rec_strlen(s));
    return 0;
}

