#include <iostream>
#include <cstdlib>
#include <ctime>

void Merge(int arr[], int left, int mid, int right) {
    int* sorted = new int[right+1];
    int posA, posB, k;
    posA = left, posB = mid+1, k = left;
    
    while (posA <= mid && posB <= right) {
        if (arr[posA] <= arr[posB]) {
            sorted[k] = arr[posA++];
        }
        else {
            sorted[k] = arr[posB++];
        }
        k++;
    }
    if (posA > mid) {
        for (int i = posB; i <= right; i++) {
            sorted[k] = arr[i];
            k++;
        }
    }
    else {
        for (int i=posA; i<=mid; i++) {
            sorted[k] = arr[i];
            k++;
        }
    }
    
    for (int i=left; i<=right; i++) {
        arr[i] = sorted[i];
    }
    
    delete[] sorted;
}

void MergeSort(int arr[], int left, int right) {
    int mid;
    if (left < right) {
        mid = (left + right) / 2;    // split to 2 array
        MergeSort(arr, left, mid);
        MergeSort(arr, mid+1, right);
        Merge(arr, left, mid, right);
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
    MergeSort(array, 0, n);
    for(int i=0; i<n; i++){
        printf("%d\t", array[i]);
    }
    printf("\n");
}
