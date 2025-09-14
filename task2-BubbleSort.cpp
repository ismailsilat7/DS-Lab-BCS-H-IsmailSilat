#include <bits/stdc++.h>
using namespace std;

void bubbleSort(int a[], int n) {
    for(int i = 0; i < n - 1; i++) {
        bool flag = false;
        for(int j = 0; j < n - 1 - i; j++) {
            if(a[j] > a[j+1]) {
                swap(a[j], a[j+1]);
                flag = true;
            }
        }
        if(!flag) break;
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

    cout << endl << "Original Array" << endl;
    display(a, size);
    bubbleSort(a, size);
    cout << endl << "Sorted Array" << endl;
    display(a, size);

    return 0;
}
