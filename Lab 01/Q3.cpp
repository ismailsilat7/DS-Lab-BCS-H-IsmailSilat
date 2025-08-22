#include <iostream>
using namespace std;

class Box {
    private:
        int* val;
    public:
        Box(int v = 0) {
            val = new int(v);
        }

        // rule of 3 - copy constructor, copy assignment operator & destructor (if one is needed, make 3 of em)
        Box(Box& b) {
            val = new int(*b.val);
        }
        Box& operator=(const Box& other) {
            if(this != &other) {
                delete val;
                val = new int(*other.val);
            }
            return *this;
        }
        ~Box() {
            delete val;
        }

        void setValue(int v) {
            *val = v;
        }

        int getValue() const {
            return *val;
        }
};

int main() {
    cout << "Rule of Three" << endl;
    Box b1(10);
    Box b2 = b1;

    cout << "Initially -> b1: " << b1.getValue() << ", b2: " << b2.getValue() << endl;

    b2.setValue(20); // to show that b1 & b2 don't share same address & deep copy was successful

    cout << "After modifying b2 -> b1: " << b1.getValue() << ", b2: " << b2.getValue() << endl;
}