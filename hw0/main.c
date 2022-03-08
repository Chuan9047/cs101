#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    FILE* fp;
    time_t curtime;
    time(&curtime);
	int arr_num[5][7],group,flag,temp;
    srand((unsigned) time(NULL));
	printf("歡迎光臨長庚樂透彩購買機台,請問您要買幾組樂透彩:");
    scanf("%d",&group);
    fp = fopen("lotto.txt","w+");
	fprintf(fp,"======= lotto649 =======\n");
    fprintf(fp,"%s",ctime(&curtime));
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
                        else if(j<6 && arr_num[i][j]<arr_num[i][k]){
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
        fprintf(fp,"[%d] : ",i+1);
        for(int j=0; j<=6; j++){
            if(group>=(i+1)){
                fprintf(fp,"%02d ",arr_num[i][j]);
            }
            else{
                fprintf(fp,"-- ");
            }
        }
        fprintf(fp,"\n");
    }
    fprintf(fp,"======= csie@CGU =======\n");
    printf("已為您購買的%d組樂透組合輸出至lotto.txt\n",group);
    fclose(fp);
}