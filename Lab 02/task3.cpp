#include <iostream>
using namespace std;

int main() {

    int numStudents;
    cout << "Enter number of students: ";
    cin >> numStudents;

    int **marks = new int*[numStudents];

    int *numCourses = new int[numStudents];
    cout << "Enter number of courses for each student" << endl;
    for(int i = 0; i < numStudents; i++) {
        cout << i + 1 << ": ";
        cin >> numCourses[i];
        marks[i] = new int[numCourses[i]];
    }

    cout << "Enter marks for each student" << endl;
    for(int i = 0; i < numStudents; i++) {
        cout << "Student " << i + 1 << endl;
        for(int j = 0; j < numCourses[i]; j++) {
            cout << "Course " << j + 1 << ": ";
            cin >> marks[i][j];
        }
        cout << endl;
    }

    cout << "Displaying marks & average for each Student" << endl;
    for(int i = 0; i < numStudents; i++) {
        cout << "Student " << i + 1 << ": ";
        int total = 0;
        for(int j = 0; j < numCourses[i]; j++) {
            cout << marks[i][j] << " ";
            total += marks[i][j];
        }
        cout << "| Average: " << (float)total/numCourses[i] << endl;
    }

    cout << "Deallocating memory" << endl;
    delete[] numCourses;
    for(int i = 0; i < numStudents; i++) {
        delete[] marks[i];
    }
    delete[] marks;

}