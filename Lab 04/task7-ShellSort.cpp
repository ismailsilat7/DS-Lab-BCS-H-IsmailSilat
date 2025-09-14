#include <bits/stdc++.h>
using namespace std;

int shellSort(int a[], int n) {
    int swaps = 0;
    for(int gap = n/2; gap > 0; gap /= 2) {
        for(int i = gap; i < n; i++) {
            int temp = a[i];
            int j = i;
            while(j >= gap && a[j - gap] > temp) {
                a[j] = a[j - gap];
                j -= gap;
                swaps++;
            }
            a[j] = temp;
        }
    }
    return swaps;
}

int insertionSort(int a[], int n) {
    int swaps = 0;
    for(int i = 1; i < n; i++) {
        int j = i - 1;
        int x = a[i];
        while(j > -1 && a[j] > x) {
            a[j+1] = a[j];
            j--;
            swaps++;
        }
        a[j+1] = x;
    }
    return swaps;
}

void display(int A[], int length) {
    cout << "Displaying Elements: ";
    for(int i = 0; i < length; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
}

int main() {
    int n = 1000;
    int arr1[n], arr2[n];

    srand(time(0));
    for(int i = 0; i < n; i++) {
        int val = rand() % 10000;
        arr1[i] = val;
        arr2[i] = val;
    }

    int shellSwaps = shellSort(arr1, n);
    int insertionSwaps = insertionSort(arr2, n);

    cout << "Shell Sort swaps: " << shellSwaps << endl;
    cout << "Insertion Sort swaps: " << insertionSwaps << endl;

    return 0;
}