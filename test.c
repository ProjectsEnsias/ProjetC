#include <stdio.h>
#include <stdlib.h>


int main(){
    int *k;
    int *b = k;
    k = (int*)malloc(sizeof(int));
    *b = 5;
    *k = 6;
    printf("%d",*k);
    return 0;
}