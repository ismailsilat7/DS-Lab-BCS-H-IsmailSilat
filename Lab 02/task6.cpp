#include <iostream>
using namespace std;

class SafePointer {
    private:
        int* ptr;
    public:
        SafePointer() {
            ptr = new int(0);
        }

        void setValue(int v) {
            if(ptr) {
                *ptr = v;
            }
        }

        int getValue() const {
            if (ptr) {
                return *ptr;
            } else {
                cerr << "Error, Pointer is null/alr released" << endl;
                return 0;
            }
        }

        void release() {
            if (ptr != nullptr) {
                delete ptr;
                ptr = nullptr;
            }
        }
        ~SafePointer() {
            release();
        }
};

int main() {
    const int n = 5;
    SafePointer students[n];

    cout << "Enter marks of " << n << " students" << endl;
    for (int i = 0; i < n; i++) {
        int mark;
        cout << "Student " << i + 1 << ": ";
        cin >> mark;
        students[i].setValue(mark);
    }

    cout << "Displaying marks stored safely " << endl;
    for (int i = 0; i < n; i++) {
        cout << "Student " << i + 1 << ": " << students[i].getValue() << endl;
    }
}


