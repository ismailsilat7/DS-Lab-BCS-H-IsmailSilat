#include <bits/stdc++.h>
using namespace std;

int sumTail(int n, int total = 0) {
    if(n == 0) {
        return total;
    }
    return sumTail(n - 1, n + total);
}

int sumNonTail(int n) {
    if(n == 0) {
        return 0;
    }

    int total = sumNonTail(n - 1);
    return total + n;
}

int main() {
    cout << "Using tail recursion: " << sumTail(10) << endl;
    cout << "Using nonTail recursion: " << sumNonTail(10) << endl;
}
