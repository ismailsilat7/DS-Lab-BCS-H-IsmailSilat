#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Stack {
public:
    T* arr;
    int size;
    int top;

    Stack(int n = 0) {
        top = -1;
        size = n;
        while (size <= 0) {
            cout << "Enter size (must be > 0): ";
            cin >> size;
        }
        arr = new T[size];
    }

    bool push(T val) {
        if (top < size - 1) {
            arr[++top] = val;
            return true;
        }
        return false;
    }

    T pop() {
        if (top > -1) return arr[top--];
        return T();  // this will return default value instead of -1 in the int stack I made
    }

    T peek() {
        if (top > -1) return arr[top];
        return T();
    }

    bool isEmpty() {
        return top == -1;
    }

    ~Stack() { delete[] arr; }
};

int precedence(char c) {
    if(c == '^') {
        return 3;
    }
    if(c == '*' || c == '/') {
        return 2;
    } 
    if(c == '+' || c == '-') {
        return 1;
    }
    return -1;
}

string infixToPrefix(string infix) {
    if(infix.length() == 0) {
        return infix;
    }
    string prefix = "";
    Stack<char> s(infix.length());
    for(int i = infix.length() - 1; i >= 0; i--) {
        char c = infix[i];
        if (isalnum(c)) {
            prefix = c + prefix;
        } else if(c == ')') {
            s.push(c);
        } else if (c == '(') {
            while(!s.isEmpty() && s.peek() != ')') {
                prefix = s.pop() + prefix;
            }
            if(s.peek() == ')') {
                s.pop();
            }
        } else {
            while(!s.isEmpty() && precedence(c) < precedence(s.peek())) {
                prefix = s.pop() + prefix;
            }
            s.push(c);
        }
    }
    while(!s.isEmpty()) {
        prefix = s.pop() + prefix;
    }
    return prefix;
}

int evaluatePrefix(string prefix) {
    
    Stack<int> s(prefix.length());
    for(int i = prefix.length() - 1; i >= 0; i--) {
        if(isdigit(prefix[i])) {
            s.push(prefix[i] - '0');
        } else {
            char op = prefix[i];
            int num1 = s.pop();
            int num2 = s.pop();
            if(op == '+') {
                s.push(num1 + num2);
            } else if(op == '-') {
                s.push(num1 - num2);
            } else if(op == '*') {
                s.push(num1 * num2);
            } else if(op == '/') {
                if(num2 != 0) {
                    s.push(num1 / num2);
                } else {
                    cout << "Cannot compute - Division by Zero Error!" << endl;
                    return -1;
                }
            } else if(op == '^') {
                s.push(pow(num1, num2));
            }
        }
    }
    return s.pop();
}

int main() {
    string infix = "2+(3*4)-2";
    string prefix = infixToPrefix(infix);
    cout << "Prefix: " << prefix << endl;
    int result = evaluatePrefix(prefix);
    cout << "Result: " << result << endl;
}
