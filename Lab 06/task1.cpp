#include <bits/stdc++.h>
using namespace std;

class Stack {
    public:
        int* arr;
        int size;
        int top;
        Stack(int n = 0) {
            top = -1;
            size = n;  
            while(size <= 0) {
                cout << "Enter size (must be > 0) : ";
                cin >> size;
            }
            arr = new int[size];
        } 

        bool push(int val) {
            if(top < size - 1) {
                arr[++top] = val;
                return true;
            }
            cout << "Stack is already full - couldn't add " << val << endl;
            return false;
        }

        int pop() {
            if(top > -1) {
                int val = arr[top];
                cout << "Removing " << val << endl;
                top--;
                return val;
            }
            cout << "Couldn't pop - stack is empty" << endl;
            return -1;
        }

        int peek() {
            if(top > -1) {
                cout << "Peeking top..." << arr[top] << endl;
                return arr[top];
            }
            cout << "Couldn't peek - stack is empty" << endl;
            return -1;
        }

        void displayStack() {
            if(top == -1) {
                cout << "Stack is empty - cannot display" << endl;
                return;
            }
            cout << "Displaying stack elements..." << endl;
            for(int i = 0; i <= top; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }

        ~Stack() {
            delete[] arr;
        }

};

int main() {
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);
    s.displayStack();

    s.peek();
    s.pop();
    s.displayStack();

    s.pop();
    s.pop();
    s.pop();  // trying pop when empty

    return 0;
}

