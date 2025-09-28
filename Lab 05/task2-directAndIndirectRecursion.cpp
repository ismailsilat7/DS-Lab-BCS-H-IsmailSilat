#include <bits/stdc++.h>
using namespace std;

// 1
void printNumbers(int n) {
    if(n <= 0) {
        cout << "\n" << endl;
        return;
    }
    cout << n << " ";
    printNumbers(n - 1);
}

// 2 
void functionB(int n);
void functionA(int n) {
    if(n <= 0) {
        cout << "\n" << endl;
        return;
    }
    cout << n << " ";
    functionB(n + 1);
}

void functionB(int n) {
    if(n <= 0) {
        cout << "\n" << endl;
        return;
    }
    cout << 2 * n << " ";
    functionA(n - 2);
}

int main() {
    printNumbers(10);
    functionA(10);
}

