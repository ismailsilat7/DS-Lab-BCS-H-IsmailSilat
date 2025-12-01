#include <iostream>
using namespace std;

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for(int j = low; j < high; j++) {
        if(pivot < arr[j]) { // descending order - if arr[j] > pivot then put it on the left side :(
            swap(arr[++i], arr[j]);
        }
    }
    swap(arr[high], arr[++i]);
    return i;
}

void quickSort(int arr[], int low, int high) {
    if(low < high) {
        int pivot = partition(arr, low, high);
        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}
