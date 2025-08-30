#include <iostream>
using namespace std;

int** createMatrix(int rows, int cols) {
    int** matrix = new int*[rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];
    }
    return matrix;
}

void inputMatrix(int** matrix, int rows, int cols, string name) {
    cout << "Enter values for " << name << ":" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << name << "[" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
}

void displayMatrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int** addMatrices(int** A, int** B, int rows, int cols) {
    int** result = createMatrix(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
    return result;
}

int** subtractMatrices(int** A, int** B, int rows, int cols) {
    int** result = createMatrix(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = A[i][j] - B[i][j];
        }
    }
    return result;
}

void deleteMatrix(int** matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

int main() {
    int rows, cols;
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;

    int** A = createMatrix(rows, cols);
    int** B = createMatrix(rows, cols);

    inputMatrix(A, rows, cols, "Matrix A");
    inputMatrix(B, rows, cols, "Matrix B");
    
    cout << endl << "Matrix A" << endl;
    displayMatrix(A, rows, cols);

    cout << endl << "Matrix B" << endl;
    displayMatrix(B, rows, cols);

    int** sum = addMatrices(A, B, rows, cols);
    cout << endl << "Addition (A + B)" << endl;
    displayMatrix(sum, rows, cols);

    int** diff = subtractMatrices(A, B, rows, cols);
    cout << endl << "Subtraction (A - B)" << endl;
    displayMatrix(diff, rows, cols);

    deleteMatrix(A, rows);
    deleteMatrix(B, rows);
    deleteMatrix(sum, rows);
    deleteMatrix(diff, rows);

    return 0;
}
