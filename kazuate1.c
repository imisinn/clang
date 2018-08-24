#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
    int reply = 10;
    srand((unsigned)time(NULL));
    int ans = rand() % 9;
    int count = 0;

    printf("0 ~ 9の整数を当てましょう\n");

    printf("幾つでしょう！\n");

    do{
        scanf("%d",&reply);
        if(reply == ans){
            //printf("正解です！\n");
        }else if(reply < ans){
            printf("答えより小さいです\n");
        }else{
            printf("答えより大きいです\n");
        }

        count++;
    }while(reply != ans);

    printf("\n\n%dが答えでした。\n",ans );
    printf("%d回で正解で正解しました！\n", count);
}
