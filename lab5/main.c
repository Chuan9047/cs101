#include <stdio.h>
#include <stdlib.h>

int* get_int_array(int n){
    return (int*)calloc(n,sizeof(int));
}

void set_value(int* p,int v){
    *p = v;
}

void print_arr(int* p,int n){
    printf("[");
    for(int i=0;i<n;i++){
        int temp = *p++;
        printf("%d",temp);
        if(temp<n){
            printf(", ");
        }
    }
    printf("]\n");
}

typedef struct arr_list{
    int n;
    int* (*func_gt_i_a)(int);
    void (*func_st_v)(int*,int);
    void (*func_pf_a)(int*,int);
}arry_list_t;
arry_list_t arrl;

char* func(char* a,char* b){
    int a_amount = 0;
    int b_amount = 0;
    while(*(a+a_amount)) a_amount++;
    while(*(b+b_amount)) b_amount++;
    char* p = (char*)calloc(a_amount+b_amount , sizeof(char) );
    for(int i=0;i<a_amount;i++){
        p[i] = *a++;
    }
    for(int i=a_amount;i<a_amount+b_amount;i++){
        p[i] = *b++;
    }
    
    return p;
}

char* add_func(char* a ,char* b,char* (*func_prt)(char* ,char*)){
    return func_prt(a,b);
}






int main(){
    printf("No.1 --------------------\n");
    int n =10;
    int* ip = get_int_array(n);
    for(int i=0;i<n;i++){
        set_value(ip+i,i+1);
    }
    print_arr(ip,n);
    free(ip);
    printf("No.2 --------------------\n");
    arrl.n = 20;
    arrl.func_gt_i_a = get_int_array;
    arrl.func_st_v = set_value;
    arrl.func_pf_a = print_arr;
    
    ip = arrl.func_gt_i_a(arrl.n);
    for(int i=0;i< arrl.n;i++){
        arrl.func_st_v(ip+i,i+1);
    }
    print_arr(ip, arrl.n);
    free(ip);
    printf("No.3 --------------------\n");
    char a[] = "IU!IU!";
    char b[] = "@CGU";
    printf("add_func = %s\n",add_func(a,b,func));
    
    
    
    return 0;
}
