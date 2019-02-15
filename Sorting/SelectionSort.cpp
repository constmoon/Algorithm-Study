#include <iostream>
#include <cstdlib>
#include <ctime>

void SelectionSort(int arr[], int size) {
    for(int i=0; i<size; i++){
        int min_idx = i;
        for(int j=min_idx+1; j<size; j++){
            if(arr[j] < arr[min_idx]){
                min_idx = j;
            }
        }
        int tmp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = tmp;
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
    SelectionSort(array, n);
    for(int i=0; i<n; i++){
        printf("%d\t", array[i]);
    }
    printf("\n");
}
