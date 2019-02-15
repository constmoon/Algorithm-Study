#include <iostream>
#include <cstdlib>
#include <ctime>

void InsertionSort(int arr[], int num) {
    int  i, j, key;
    for (i = 1; i<num; i++) {
        key = arr[i];
        for (j = i; j>0; j--) {
            if (arr[j - 1] > key) {
                arr[j] = arr[j - 1];
            }
            else {
                arr[j] = key;
                break;
            }
        }
        if (arr[0] > key) {
            arr[0] = key;
        }
    }
}

int main(){
    int n = 10;
    int *array = new int[n];
    srand(time(NULL));
    
    for(int i=0; i<n; i++){
        array[i] = rand() % 100;
        printf("%d\t", array[i]);
    }
    printf("\n");
    InsertionSort(array, n);
    for(int i=0; i<n; i++){
        printf("%d\t", array[i]);
    }
    printf("\n");
}
