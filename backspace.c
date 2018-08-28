#include <stdio.h>
#include <time.h>

int sleep(unsigned long x){
    clock_t c1 = clock(),c2;

    do{
        if((c2 = clock()) == (clock_t)-1)return 0;//エラー
    }while(1000.0 * (c2 - c1) / CLOCKS_PER_SEC < x);
    return 1;
}

int main(void){

    int i;
    char c = 'z';
    int del = 6;
    int time_s = 500;

    printf("ABCDEFG");

    for(i = 0;i < del; i++){
        sleep(time_s);
        printf("\b%c\b",c);
        fflush(stdout);
    }
    //printf("\n");
    return 0;
}
