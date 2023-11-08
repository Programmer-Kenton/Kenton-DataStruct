/**
 * @description: TODO 
 * @author Kenton
 * @date 2023/11/2 22:18
 * @version 1.0
 */

#include "time.h"
#include "stdio.h"

void test(){
    int i = 0;
    int sum = 0;
    int j = 0;
    for (int i = 0; i < 10000000; ++i) {
        sum = 0;
        for (int j = 0; j < 100; ++j) {
            sum += j;
        }
    }
}

int main(){
    time_t start_t;
    time(&start_t);

    test();

    time_t end_t;
    time(&end_t);

    double diff_t;
    diff_t = difftime(end_t,start_t);

    printf("%d\n", start_t);
    printf("%d\n", end_t);
    printf("ºÄÓÃÁË%.2fÃë\n", diff_t);
}