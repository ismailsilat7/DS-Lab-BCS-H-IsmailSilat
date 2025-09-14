#include <bits/stdc++.h>
using namespace std;

int interpolationSearch(int a[], int length, int target) {

    int start = 0;
    int end = length - 1;
    while (start <= end) {
        if(a[start] == a[end]) {
            if (a[start] == target) return start;
            return -1;
        }
        int pos = start + (((target - a[start]) * (end - start)) / (a[end] - a[start]));
        if(a[pos] == target) {
            return pos;
        } else if(a[pos] > target) {
            end = pos - 1;
        } else {
            start = pos + 1;
        }
    }
    return -1;
}

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
    insertionSort(a, size);

    cout << endl << "Sorted Array";
    display(a, size);

    int target;
    cout << endl << "Enter element to search: ";
    cin >> target;
    int index = interpolationSearch(a, size, target);
    if(index != -1) {
        cout << "Element found at index: " << index << endl;
    } else {
        cout << "Element not found!" << endl;
    }

}

