#include <iostream>
using namespace std;


void generateLPS(string subS, int lps[], int n) {
    int j = 0;
    lps[0] = 0;

    for(int i = 0; i < n; ) {
        if(subS[i] == subS[j]) {
            lps[i++] = ++j;
        } else {
            if(j!= 0 ) {
                j = lps[j - 1];
            } else {
                lps[i++] = 0;
            }
        }
    }

}

void KMP(string s, string subS) {
    int n = subS.length();
    int* lps = new int[n];
    generateLPS(subS, lps, n);
    int j = 0;
    for(int i = 0; i < n; ) {
        if(subS[j] == s[i]) {
            i++;
            j++;
            if(j == n) {
                cout << "pattern found at index " << i - j << endl;
                j = lps[j - 1];
            }
        } else {
            if(j!= 0 ) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
    delete[] lps;
}