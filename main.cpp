#include <iostream>
#include <string.h>

int main() {
   int a[100] = {0,0},i,j;
    for (int i = 2; i < 99; ++i) {
        a[i] = i;
    }
    for (int i = 2; i <= 10; ++i) {
        for (int j = i+1; j <= 99; ++j) {
            if (a[i] != 0 && a[j] != 0){
                if (a[j] % a[i] == 0){
                    a[j] = 0;
                }
            }
        }
    }
    for (int i = 0; i <= 99; ++i) {
        if(a[i]){
            printf("%3d",a[i]);
        }
    }
}
