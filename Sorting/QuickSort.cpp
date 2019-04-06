#include <cstdio>
#include <cstdlib>

void Swap(int& a, int& b) {
    int tmp;
    tmp = a;
    a = b;
    b = tmp;
}

int FindPivot(int arr[], int left, int right) {     // partitioning

    int pivot = left;    // 맨 왼쪽 요소를 pivot으로 선정   
    int low = left + 1;
    int high = right;

    while (low <= high) {    // 오른쪽이 클 동안 계속 진행
        while (low <= right && arr[pivot] >= arr[low]) {    // find the value larger than pivot
            low++;
        }
        while (high >= left+1 && arr[pivot] <= arr[high]) {    // find the value smaller than pivot
            high--;
        }
        if (low <= high) {
            Swap(arr[low], arr[high]);
        }
    }

    Swap(arr[pivot], arr[high]);
    return high;
}

void QuickSort(int arr[], int left, int right) {
    if (left <= right) {
        int pivot = FindPivot(arr, left, right);
        QuickSort(arr, left, pivot - 1);
        QuickSort(arr, pivot + 1, right);
    }
}


int main(){
    int n = 10;
    int *array = new int[n];

    for(int i=0; i<n; i++){
        array[i] = rand() % 100;
        printf("%d\t", array[i]);
    }
    printf("\n");
    QuickSort(array, 0, n-1);
    for(int i=0; i<n; i++){
        printf("%d\t", array[i]);
    }
    printf("\n");
    delete array;
}