#include <iostream> 
using namespace std;

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int * leftArr = new int[n1];
    for(int i= 0; i < n1; i++) {
        leftArr[i] = arr[i + left];
    }
    int* rightArr = new int[n2];
    for(int i = 0; i < n2; i++) {
        rightArr[i] = arr[i + mid + 1];
    }
    int i = 0; int j = 0; int k = 0;
    while(i < n1 && j < n2) {
        if(leftArr[i] < rightArr[i]) {
            arr[k++] = leftArr[i++];
        } else {
            arr[k++] = rightArr[j++];
        }
    }
    while(i < n1) {
        arr[k++] = leftArr[i++];
    } 
    while(j < n2) {
        arr[k++] = rightArr[j++];
    }
    delete[] leftArr; delete[] rightArr;
}

void mergeSort(int arr[], int left, int right) {
    if(left < right) {
        int mid = (left + right)/2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}
