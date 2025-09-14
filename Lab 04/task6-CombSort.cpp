#include <bits/stdc++.h>
using namespace std;

void combSort(int a[], int n) {

    int comparisons = 0;
    int swaps = 0;

    int gap = n;
    while(gap > 1) {
        bool flag = false;
        gap /= 1.3;
        if(gap < 1) gap = 1;
        for(int i = 0; i + gap < n; i++) {
            comparisons++;
            if(a[i] > a[i + gap]) {
                swap(a[i], a[i + gap]);
                swaps++;
                flag = true;
            }
        }
        if(!flag) break;
    }

    cout << "Complexity Analysis for Comb Sort" << endl;
    cout << "Total Comparisons: " << comparisons << endl;
    cout << "Total Swaps: " << swaps << endl;

} 

void display(int A[], int length) {
    cout << "Displaying Elements: ";
    for(int i = 0; i < length; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
}

int main() {
    int size = 20;
    int a[size];

    srand(time(0));
    for(int i = 0; i < size; i++) {
        int val = rand() % 10000;
        a[i] = val;
    }

    cout << endl << "Original Array" << endl;
    display(a, size);
    combSort(a, size);
    cout << endl << "Sorted Array" << endl;
    display(a, size);

    return 0;
}
