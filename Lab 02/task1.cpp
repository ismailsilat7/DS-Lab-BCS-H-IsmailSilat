#include <iostream>
using namespace std;

int main() {

    int size;
    cout << "Enter size for array: ";
    cin >> size;

    int* arr = new int[size];

    for(int i = 0; i < size; i++) {
        arr[i] = 0;
    }

    cout << "Enter values for array" << endl;
    for(int i = 0; i < size; i++) {
        cout << i + 1 << ": ";
        cin >> arr[i];
    }
    cout << endl << "Displaying values for array: " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl << endl;;

    cout << "Deallocating memory" << endl;
    delete[] arr;
    cout << "Memory Deallocated." << endl;

}