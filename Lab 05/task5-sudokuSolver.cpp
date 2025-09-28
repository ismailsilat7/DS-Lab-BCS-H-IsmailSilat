#include <bits/stdc++.h>
using namespace std;

bool isValid(int arr[9][9], int i, int j, int val) {
    for(int k = 0; k < 9; k++) {
        if(arr[i][k] == val) {
            return false;
        }
    }

    for(int k = 0; k < 9; k++) {
        if(arr[k][j] == val) {
            return false;
        }
    }

    int rowStart = (i / 3) * 3;
    int colStart = (j / 3) * 3;
    for(int m = rowStart; m < rowStart + 3; m++) {
        for(int n = colStart; n < colStart + 3; n++) {
            if(arr[m][n] == val) {
                return false;
            }
        }
    }
    return true;

}

bool sudokuSolver(int arr[9][9]) {

    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            if(arr[i][j] == 0) {
                for(int k = 1; k <= 9; k++) {
                    if(isValid(arr, i, j, k)) {
                        arr[i][j] = k;
                        if(!sudokuSolver(arr)) {
                            arr[i][j] = 0;
                        } else {
                            return true;
                        }
                    }
                }
                return false;
            }
        }
    }

    return true;
}

void printSudoku(int arr[9][9]) { 
    for(int i = 0; i < 9; i++) { 
        for(int j = 0; j < 9; j++) { 
            cout << arr[i][j] << " "; 
        } cout << endl; 
    } 
}

int main() { 
    int sudoku[9][9] = { {5,3,0, 0,7,0, 0,0,0}, {6,0,0, 1,9,5, 0,0,0}, {0,9,8, 0,0,0, 0,6,0}, {8,0,0, 0,6,0, 0,0,3}, {4,0,0, 8,0,3, 0,0,1}, {7,0,0, 0,2,0, 0,0,6}, {0,6,0, 0,0,0, 2,8,0}, {0,0,0, 4,1,9, 0,0,5}, {0,0,0, 0,8,0, 0,7,9} }; 
    cout << "Sudoku Before Solving:\n";
    printSudoku(sudoku); 
    if(sudokuSolver(sudoku)) { 
        cout << "\nSudoku After Solving:\n"; printSudoku(sudoku); 
    } else { 
        cout << "\nNo solution exists.\n"; 
    }

}

