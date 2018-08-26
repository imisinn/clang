/*
p23
例文を複数の関数に分けている。
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_COUNT 20
#define RIGHT 0
#define LESS 1
#define OVER 2
#define MAX_NUMBWE 30

int make_rand_number(int);
void print_init(int,int);
int check_answer(int ,int);
void print_result(int , int[],int);

int main(void){
    int reply = -1;//回答
    int ans;//答え
    int count = 0;//答えた回数
    int nums[MAX_COUNT];
    int max = MAX_NUMBWE;//答えの最大数
    int try_num = MAX_COUNT;//答えることのできる回数
    int result = 0;

    ans = make_rand_number(max);

    print_init(max,try_num);

    do{
        printf("%d回目：",count );
        scanf("%d",&reply);
        result = check_answer(reply,ans);
        nums[count] = reply;
        count++;
    }while(result != RIGHT);

    print_result(ans,nums,count);

}

int make_rand_number(int max){
    srand((unsigned)time(NULL));
    return rand() % (max + 1);
}

void print_init(int max,int try_num){
    printf("%d回チャレンジできます\n",try_num);
    printf("0 ~ %d の整数を当てましょう\n",max);
    printf("幾つでしょう！\n");
}

int check_answer(int reply,int ans){
    if(reply == ans){
        return RIGHT;
    }else if(reply < ans){
        printf("答えより小さいです\n\n");
        return LESS;
    }else{
        printf("答えより大きいです\n\n");
        return OVER;
    }
}

void print_result(int ans, int nums[],int count){
    printf("\n\n%dが答えでした。\n",ans);
    printf("%d回で正解しました！\n", count);
    printf("回答履歴が");
    for(int i = 0;i < count;i++){
        printf(" %d回目:%d     ",i,nums[i]);
        if(i % 5 == 0 && i != 0)printf("\n　　　　　 ");;
    }
    printf("です。\n");
}
