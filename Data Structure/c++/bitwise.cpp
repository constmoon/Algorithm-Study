#include <stdio.h>

void PrintBit(int i){
    for(int j=7; j>=0; j--){
        printf("%d", (i >> j) & 1);
        // i의 j버째 비트가 1인지 아닌지 검사
        //putchar((i & (1 << j)) ? '1' : '0');
    }
    printf(" ");
}
int main() {
    int i;
    for(i=-5; i<6; i++){
        printf("%3d = ", i);
        PrintBit(i);
        printf("\n");
    }
    return 0;
}