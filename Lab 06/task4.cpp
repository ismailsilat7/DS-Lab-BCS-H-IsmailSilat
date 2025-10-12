#include <bits/stdc++.h>
using namespace std;

class CircularQueue {
public:
    int rear;
    int front;
    int* arr;
    int size;

    CircularQueue(int n = 0) {
        rear = front = -1;
        size = n;  
        while (size <= 0) {
            cout << "Enter size (must be > 0): ";
            cin >> size;
        }
        arr = new int[size];
    }

    bool isFull() {
        return ((rear + 1) % size) == front;
    }

    bool isEmpty() {
        return (front == -1 && rear == -1);
    }

    bool enqueue(int j) {
        if (isFull()) {
            cout << "Queue is full - cannot enqueue" << endl;
            return false;
        }

        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % size;
        }

        arr[rear] = j;
        return true;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Cannot dequeue - queue is empty" << endl;
            return -1;
        }

        int j = arr[front];

        if (front == rear) {
            front = rear = -1; // queue is now empty
        } else {
            front = (front + 1) % size;
        }

        return j;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty - cannot display" << endl;
            return;
        }

        cout << "Displaying circular queue contents..." << endl;

        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % size;
        }
        cout << endl;
    }

    ~CircularQueue() {
        delete[] arr;
    }
};

int main() {
    int n;
    cout << "Enter queue size: ";
    cin >> n;

    CircularQueue q(n);

    int choice, value;

    do {
        cout << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Display" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> value;
                if (q.enqueue(value))
                    cout << value << " enqueued successfully." << endl;
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

    return 0;
}
