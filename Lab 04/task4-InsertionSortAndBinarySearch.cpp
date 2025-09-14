#include <bits/stdc++.h>
using namespace std;

void insertionSort(int a[], int n) {
    for(int i = 1; i < n; i++) {
        int j = i - 1;
        int x = a[i];
        while(j > -1 && a[j] > x) {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = x;

    }
}

int binarySearch(int a[], int length, int target) {

    int start = 0;
    int end = length - 1;
    while (start <= end) {
        int mid = start + (end - start)/2;
        if(a[mid] == target) {
            return mid;
        } else if(a[mid] > target) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    return -1;
}

void display(int A[], int length) {
    cout << "Displaying Elements: ";
    for(int i = 0; i < length; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
}

int main() {
    int size;
    cout << "Enter the number of elements: ";
    cin >> size;
    int a[size];
    cout << "Enter " << size << " elements: ";
    for(int i = 0; i < size; i++) {
        cin >> a[i];
    }

    cout << endl << "Original Array" << endl;
    display(a, size);
    insertionSort(a, size);
    cout << endl << "Sorted Array" << endl;
    display(a, size);

    int target;
    cout << endl << "Enter element to search: ";
    cin >> target;
    int index = binarySearch(a, size, target);
    if(index != -1) {
        cout << "Element found at index: " << index << endl;
    } else {
        cout << "Element not found!" << endl;
    }

}

