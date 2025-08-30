#include <iostream> 
using namespace std;

int main() {

    // Let class size by 10 with 2 rows & 5 columns
    int benches = 2;
    int columns = 5;
    int** classroom = new int*[benches];
    for(int i = 0; i < benches; i++) {
        classroom[i] = new int[columns];
    }

    for(int i = 0; i < benches; i++) {
        for(int j = 0; j < columns; j++) {
            classroom[i][j] = 0;
        }
    }

    cout << "Enter 1 for seats occupied, 0 for not occupied" << endl;
    for(int i = 0; i < benches; i++) {
        cout << "Bench " << i + 1 << endl;
        for(int j = 0; j < columns; j++) {
            cout << "Col " << j + 1 << ": ";
            cin >> classroom[i][j];
        }
        cout << endl;
    }

    cout << "Displaying final seating chart in matrix form" << endl;
    for(int i = 0; i < benches; i++) {
        for(int j = 0; j < columns; j++) {
            cout << classroom[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Deallocating memory" << endl;
    for(int i = 0; i < benches; i++) {
        delete[] classroom[i];
    }
    delete[] classroom;

}