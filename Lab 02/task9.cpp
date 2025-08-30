#include <iostream>
using namespace std;

int main() {
    int rows, cols;
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;

    int** matrix = new int*[rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];
    }

    cout << "Enter elements of the matrix" << endl;
    for (int i = 0; i < rows; i++) {
        cout << "Row " << i << " :" << endl;
        for (int j = 0; j < cols; j++) {
            cout << "Col " << j << ": ";
            cin >> matrix[i][j];
        }
        cout << endl;
    }

    cout << "Displaying matrix in normal form" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    cout << "Displaying matrix in compressed form ([row][col]: value) - only for non-zero value" << endl;
    int zeros = 0;
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            if(matrix[i][j] != 0) {
                cout << "[" << i << "]" << "[" << j << "]:" << matrix[i][j] << endl;
            } else {
                zeros++;
            }
        }
    }
    cout << endl << "Rows: " << rows << ", Cols: " << cols << " | Zeros: " << zeros << endl;

    cout << "Deallocating memory." << endl;
    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

}