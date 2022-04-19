#include <stdio.h>
#include <stdlib.h>

void swap(int* i,int* j){
    int tmp;
    tmp = *i;
    *i = *j;
    *j = tmp;
}

int swapArray(int a[],int b[],int size){
    int tmp;
    for(int i = 0;i < size; i++){
        tmp = a[i];
        a[i] = b[i];
        b[i] = tmp;
    }
}

int printArray(int a[],int size){
    for(int i = 0;i < size; i++){
        if(i == size-1){
            printf("%d]\n",a[i]);
        }
        else{
            printf("%d,", a[i]);
        }
    }
}

char* copy_string(char s[]){
    int len = 0,i = 0;
    while(s[i] != '\0'){
        len++;
        i++;
    }
    char* ptr =(char*)calloc(len,sizeof(char));
    for(int i = 0; i < len; ++i){
        ptr[i] = s[i];
    }
    ptr[len] = '\0';
    return ptr;
}


int main(){
    printf("No.1------------------\n");
    int n=1,m=2;
    swap(&n,&m);
    printf("after swap, n=%d, m=%d\n", n, m);
    
    printf("No.2------------------\n");
    int size = 10;
    int source[10] ={0,9,8,7,6,5,4,3,2,1};
    int dest[10] ={10,20,30,40,50,60,70,80,90,100};
    swapArray(source,dest,size);
    printf("after swap array, source array =[");
    printArray(source,size);
    printf("after swap array, dest array =[");
    printArray(dest,size);
    
    printf("No.3------------------\n");
    char str[]="IU!IU!IU!IU!";
    char* cp_str = copy_string(str);
    printf("copy string = %s\n",cp_str);
    free(cp_str);
    
    return 0;
}
