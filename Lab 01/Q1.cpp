#include <iostream>
using namespace std;

class BankAccount {
    private:
        int balance;
    public:
        BankAccount() : balance(200){
            cout << "BankAccount created with default constructor - Inititial Balance: " << balance << endl;
        }
        BankAccount(int b) : balance(b) {
            cout << "BankAccount created with parameterized constructor - Initial Balance: " << balance << endl;
        }
        BankAccount(BankAccount& acc) {
            balance = max(acc.balance - 200, 0);
            cout << "BankAccount created with copy constructor - Initial Balance: " << balance << ", Balance of acc: " << acc.balance << endl;
        }
        int getBalance() {
            return balance;
        }
};

int main() {
    BankAccount account1;
    BankAccount account2(1000);
    BankAccount account3(account2);

    cout << "End of Program Balance" << endl;
    cout << "Account1: " << account1.getBalance() << endl << "Account2: " << account2.getBalance() << endl << "Account3: " << account3.getBalance() << endl;
}
