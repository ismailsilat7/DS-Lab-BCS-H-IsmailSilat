#include <iostream>
using namespace std;

class Book {
public:
    int year;
    string name;
};

class MinHeap {
public:
    Book arr[51];
    int n;
    MinHeap() {
        arr[0].year = -1;
        arr[0].name = "";
        n = 0;
    }
    void insert(int y, string name) {
        if(n >= 50) {
            cout << "Heap is full, cannot insert" << endl;
            return;
        }
        Book b;
        b.year = y;
        b.name = name;
        n++;
        arr[n] = b;
        int i = n;
        while(i > 1 && arr[i].year < arr[i/2].year) {
            swap(arr[i], arr[i/2]); i/=2;
        }
    }
    void deleteBook() {
        if(n < 1) {
            return;
        }
        arr[1] = arr[n]; 
        n--;
        int i = 1;
        while(true) {
            int left = 2 * i;
            int right = (2 * i) + 1;
            if(left > n) break;
            int smallest = left;
            if(right <= n && arr[left].year > arr[right].year) {
                smallest = right;
            }
            if(arr[i].year <= arr[smallest].year) break;
            swap(arr[i], arr[smallest]);
            i = smallest;
        }
    }

    void heapifyUp(int i) {
        while(i > 1 && arr[i].year < arr[i/2].year) {
            swap(arr[i], arr[i/2]);
            i /= 2;
        }
    }

    void heapifyDown(int i) {
        while(true) {
            int left = 2 * i;
            int right = 2 * i + 1;
            if(left > n) break;

            int smallest = left;
            if(right <= n && arr[right].year < arr[left].year) {
                smallest = right;
            }

            if(arr[i].year <= arr[smallest].year) break;

            swap(arr[i], arr[smallest]);
            i = smallest;
        }
    }

    void buildHeap(Book a[], int k) {
        if(k > 50) {} {
            cout << "array provided is very large, cannot build heap" << endl;
            return;
        }
        n = k;
        for(int i = 1; i <= k; i++) {
            arr[i] = a[i - 1];
        }

        for(int i = n/2; i >= 1; i--) {
            heapifyDown(i);
        }
    }
};

class MaxHeap {
public:
    Book arr[51];
    int n;
    MaxHeap() {
        arr[0].year = -1;
        arr[0].name = "";
        n = 0;
    }
    void insert(int y, string name) {
        if(n >= 50) {
            cout << "Heap is full, cannot insert" << endl;
            return;
        }
        Book b;
        b.year = y;
        b.name = name;
        n++;
        arr[n] = b;
        int i = n;
        while(i > 1 && arr[i].year > arr[i/2].year) {
            swap(arr[i], arr[i/2]); i/=2;
        }
    }
    void deleteBook() {
        if(n < 1) {
            return;
        }
        arr[1] = arr[n]; 
        n--;
        int i = 1;
        while(true) {
            int left = 2 * i;
            int right = (2 * i) + 1;
            if(left > n) break;
            int largest = left;
            if(right <= n && arr[left].year < arr[right].year) {
                largest = right;
            }
            if(arr[i].year >= arr[largest].year) break;
            swap(arr[i], arr[largest]);
            i = largest;
        }
    }
};

