#include <iostream>
#include <cstdlib>
#include <ctime>
#define MIN 1

int main(){

    int num;       // the number of digits
    int* arr;      // generated number
    FILE* wf = fopen("input_sort.txt", "w");    // write file (input to sort)

    scanf("%d", &num);
    fprintf(wf, "%d\n", num);
    arr = (int*)malloc(num * sizeof(int));

    srand((unsigned int)time(NULL));
    for(int i=0; i<num; i++){
        // rand로 나온 숫자를 max으로 나눈 나머지 (0부터 max-1까지)에 max을 더해주므로 min부터 max까지의 숫자가 랜덤하게 뽑힘
        // rand()%(MAX - MIN +1) + MIN
        arr[i] = rand() % (num-MIN + 1) + MIN;
        fprintf(wf, "%d ", arr[i]);
        printf("%d ", arr[i]);

    }

    fclose(wf);
    free(arr);
}
