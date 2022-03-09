#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main(){
    FILE* fp_bin;
    FILE* fp_txt;
    int count[]={1};
    if((fp_bin=fopen("count.bin","rb")) != NULL){
        fread(count, sizeof(count), 1 ,fp_bin);
        fclose(fp_bin);
    }
    else{
        fp_bin=fopen("count.bin","wb+");
        fwrite(count, sizeof(count), 1, fp_bin);
        fclose(fp_bin);
    }
    
    time_t curtime;
    time(&curtime);
    int arr_num[5][7],group,flag,temp;
    srand((unsigned) time(NULL));
    printf("歡迎光臨長庚樂透彩購買機台,請問您要買幾組樂透彩:");
    scanf("%d",&group);

    char filename[50];
    snprintf(filename, sizeof(filename), "lotto[%04d].txt",count[0]);
    fp_txt = fopen(filename,"w+");
    fprintf(fp_txt,"========= lotto649 =========\n");
    fprintf(fp_txt,"========+ No.%05d +========\n",count[0]);
    fprintf(fp_txt,"= %.*s =\n", 24, ctime(&curtime));
    for(int i=0; i<5; i++){
        if(group>=(i+1)){
            for(int j=0; j<=6;){
                do{
                    j!=6? (arr_num[i][j] = rand()%69+1) : (arr_num[i][j] = rand()%10+1);
                    flag=0;
                    for(int k=0; k<j; k++){
                        temp=0;
                        if(arr_num[i][j]==arr_num[i][k]){
                            flag=1;
                        }
                        else if(j<5 && arr_num[i][j]<arr_num[i][k]){
                            temp=arr_num[i][j];
                            arr_num[i][j]=arr_num[i][k];
                            arr_num[i][k]=temp;
                        }
                    }
                }while(flag==1);
                j++;
            }
        }
    }

    for(int i=0; i<5; i++){
        fprintf(fp_txt,"[%d] : ",i+1);
        for(int j=0; j<=6; j++){
            if(group>=(i+1)){
                fprintf(fp_txt,"%02d ",arr_num[i][j]);
            }
            else{
                fprintf(fp_txt,"-- ");
            }
        }
        fprintf(fp_txt,"\n");
    }
    fprintf(fp_txt,"========= csie@CGU =========\n");
    printf("已為您購買的%d組樂透組合輸出至%s\n",group,filename);
    fclose(fp_txt);

    count[0]++;
    fp_bin=fopen("count.bin","wb+");
    fwrite(count,sizeof(count),1,fp_bin);
    fclose(fp_bin);
}