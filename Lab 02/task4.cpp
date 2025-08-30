#include <iostream>
using namespace std;

class MonthlyExpenseTracker {
    private:
        int* expenses;
        int n;
    public:
        MonthlyExpenseTracker(int months) : n(months) {
            expenses = new int[n];
            cout << "Enter monthly expenses" << endl;
            for(int i = 0; i < n; i++) {
                cout << "Month " << i + 1 << ": ";
                cin >> expenses[i];
            } 
            cout << endl;
        }
        void AddMoreMonths(int months) {
            int* temp = expenses;
            expenses =  new int[n + months];
            for(int i = 0; i < n; i++) {
                expenses[i] = temp[i];
            }
            cout << "Enter monthly expenses for new months added (" << n << "-" << n + months << ")" << endl;
            for(int i = n; i < n + months; i++) {
                cout << "Month " << i + 1 << ": ";
                cin >> expenses[i];
            }
            cout << endl;
            delete[] temp;
            n += months;
        }

        void DisplayExpenses() {
            int total = 0;
            cout << "Displaying expenses: " << endl;
            for (int i = 0; i < n; i++) {
                cout << "Month " << i + 1 << ": " << expenses[i] << endl;
                total += expenses[i];
            }
            cout << "---------------------------" << endl;
            cout << "Total: " << total << " | Average: " << (float)total / n << endl;
        }

        ~MonthlyExpenseTracker() {
            delete[] expenses;
        }
};

int main() {
    MonthlyExpenseTracker tracker(3);
    tracker.DisplayExpenses();

    tracker.AddMoreMonths(2);
    tracker.DisplayExpenses();
}
