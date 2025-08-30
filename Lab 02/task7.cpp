#include <iostream>
#include <climits>
using namespace std;

int main() {

    int numDepartments;
    cout << "Enter number of Departments: ";
    cin >> numDepartments;

    int **salary = new int*[numDepartments];

    int *numEmployees = new int[numDepartments];
    cout << "Enter number of employees in each department" << endl;
    for(int i = 0; i < numDepartments; i++) {
        cout << i + 1 << ": ";
        cin >> numEmployees[i];
        salary[i] = new int[numEmployees[i]];
    }

    cout << endl << "Enter salary for each employee" << endl;
    for(int i = 0; i < numDepartments; i++) {
        cout << "Department " << i + 1 << endl;
        for(int j = 0; j < numEmployees[i]; j++) {
            cout << "Employee " << j + 1 << ": ";
            cin >> salary[i][j];
        }
        cout << endl;
    }

    cout << endl << "Displaying salary details for each Department" << endl;
    float highestAvg = INT_MIN;
    for(int i = 0; i < numDepartments; i++) {
        int highest = INT_MIN;
        cout << "Department " << i + 1 << ": ";
        int total = 0;
        for(int j = 0; j < numEmployees[i]; j++) {
            cout << salary[i][j] << " ";
            total += salary[i][j];
            highest = max(salary[i][j], highest);
        }
        cout << "| Highest: " << highest << endl;
        highestAvg = max(highestAvg, (float)total/numEmployees[i]);
    }

    cout << "-------------------------------" << endl << "Highest Department Avg: " << highestAvg << endl;

    cout << endl << "Deallocating memory" << endl;
    delete[] numEmployees;
    for(int i = 0; i < numDepartments; i++) {
        delete[] salary[i];
    }
    delete[] salary;

}