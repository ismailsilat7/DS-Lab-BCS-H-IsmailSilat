#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
        string val;
        Node* next;
        Node(string val = "") : val(val), next(nullptr) {}
};

class Stack {

    public:
        Node* head;
        Node* tail;

        Stack() : head(nullptr), tail(nullptr) {}

        bool push(string val) {
            Node* temp = new Node(val);
            if(!temp) {
                cout << "Couldn't allocate memory - can't push" << endl;
                return false;
            }
            if(!head) {
                head = temp;
                tail = head;
            } else {
                tail->next = temp;
                tail = tail->next;
            }
            return true;
        }

        void pop() {
            if(!head) {
                cout << "Cannot pop - stack is empty" << endl;
                return;
            }
            if(head == tail) {
                delete head;
                head = tail = nullptr;
                return;
            }
            if(tail) {
                Node* it = head;
                while(it->next != tail) {
                    it = it->next;
                }
                it->next = nullptr;
                delete tail;
                tail = it;
            }
        }

        string peek() {
            if(tail) {
                cout << "Peeking... " << tail->val << endl;
                return tail->val;
            } else {
                cout << "Stack is empty - couldn't peek" << endl;
                return "";
            }
        }

        void display() {
            if(!head) {
                cout << "Stack is empty - cannot display" << endl;
                return;
            }

            Node* it = head;
            cout << "Displaying stack values..." << endl;
            while(it) {
                cout << it->val << ", ";
                it = it->next;
            }
            cout << endl;

        }

        ~Stack() {
            while (head) {
                Node* temp = head;
                head = head->next;
                delete temp;
            }
        }

};

int main() {
    Stack history;

    history.push("google.com");
    history.push("stackoverflow.com");
    history.push("github.com");

    cout << "Current page: " << history.peek() << endl;

    cout << "Clicking back..." << endl;
    history.pop();
    cout << "Current page: " << history.peek() << endl;

    cout << "Visiting new page: reddit.com" << endl;
    history.push("reddit.com");
    cout << "Current page: " << history.peek() << endl;

    history.display();

    return 0;
}

