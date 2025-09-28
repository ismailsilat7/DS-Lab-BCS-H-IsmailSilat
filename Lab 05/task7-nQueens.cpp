#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(int row, int col, vector<int> &currentSol) {
        for (int r = 0; r < row; r++) {
            int c = currentSol[r];
            if (c == col) {
                return false;
            }
            if (abs(r - row) == abs(c - col)) {
                return false;
            }
        }
        return true;
    }


    void print(vector<vector<string>>& queens) {
        for (int i = 0; i < queens.size(); i++) {
            cout << "Solution " << i + 1 << ":" << endl;
            for (int j = 0; j < queens[i].size(); j++) {
                cout << queens[i][j] << endl;
            }
            cout << endl;
        }
    }

    vector<string> getComplete(vector<int> &sol, int n) {
        vector<string> queens;
        for(int i = 0; i < n; i++) {
            string queen = "";
            for(int j = 0; j < n; j++) {
                if(sol[i] == j) {
                    queen.push_back('Q');
                } else {
                    queen.push_back('.');
                }
            }
            queens.push_back(queen);
        }
        return queens;
    }

    void backtrack(int row, int n, vector<int> &currentSol, vector<vector<string>> &queens) {
        if (row == n) {
            queens.push_back(getComplete(currentSol, n));
            return;
        }

        for (int col = 0; col < n; col++) {
            if (isValid(row, col, currentSol)) {
                currentSol[row] = col;
                backtrack(row + 1, n, currentSol, queens);
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> queens;
        vector<int> currentSol(n);
        backtrack(0, n, currentSol, queens);
        return queens;
    }
};

int main() {
    Solution s;
    int n = 4;

    vector<vector<string>> solutions = s.solveNQueens(n);

    cout << "Total solutions: " << solutions.size() << endl << endl;
    s.print(solutions);

    return 0;
}
