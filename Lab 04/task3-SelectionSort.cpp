#include <bits/stdc++.h>
using namespace std;

void selectionSort(int a[], int n) {

    for(int i = 0; i < n - 1; i++) {
        int k = i;
        for(int j = i + 1; j < n; j++) {
            if(a[j] < a[k]) {
                k = j;
            }
        }
        swap(a[i], a[k]);
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
    selectionSort(a, size);
    cout << endl << "Sorted Array" << endl;
    display(a, size);

    return 0;
}
