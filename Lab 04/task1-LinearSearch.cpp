#include <bits/stdc++.h>
using namespace std;

int linearSearch(int a[], int n, int target) {
    for(int i = 0; i < n; i++) {
        if(a[i] == target) {
            return i;
        }
    }
    return -1;
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

    int target;
    cout << endl << "Enter element to search: ";
    cin >> target;
    int index = linearSearch(a, size, target);
    if(index != -1) {
        cout << "Element found at index: " << index << endl;
    } else {
        cout << "Element not found!" << endl;
    }
}
