#include <bits/stdc++.h>
using namespace std;

class Queue {

    public:
        int rear;
        int front;
        int size;
        int* arr;

        Queue(int n = 0) {
            rear = front = -1;
            size = n;  
            while(size <= 0) {
                cout << "Enter size (must be > 0) : ";
                cin >> size;
            }
            arr = new int[size];
        }

        bool isFull() {
            return (rear == size - 1);
        }

        bool isEmpty() {
            return (front == -1 || front > rear);
        }

        bool enqueue(int x) {
            if(isFull()) {
                cout << "Queue is full -  cannot enqueue" << endl;
                return false;
            }

            if(front == -1) {
                front = 0; 
            }

            arr[++rear] = x;
            return true;

        }

        int dequeue() {
            if(isEmpty()) {
                cout << "Cannot dequeue - queue is empty" << endl;
                return -1;
            }
            int val = arr[front++];
            if (front > rear) front = rear = -1;
            return val;
        }

        void display() {
            if(isEmpty()) {
                cout << "Queue is empty - cannot display" << endl;
                return;
            }

            cout << "Displaying queue contents..." << endl;
            for(int i = front; i <= rear; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }

};

int main() {
    int n;
    cout << "Enter queue size: ";
    cin >> n;

    Queue q(n);

    int choice, value;

    do {
        cout << endl << "1. Enqueue" << endl << "2. Dequeue" << endl << "3. Display" << endl << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> value;
                q.enqueue(value);
                break;

            case 2:
                value = q.dequeue();
                if (value != -1)
                    cout << "Dequeued: " << value << endl;
                break;

            case 3:
                q.display();
                break;

            case 4:
                cout << "Exiting..." << endl;
                break;

            default:
                cout << "Invalid choice, try again." << endl;
        }

    } while (choice != 4);

}
