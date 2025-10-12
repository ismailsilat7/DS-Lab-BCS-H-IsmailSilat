#include <bits/stdc++.h>
using namespace std;

class Process {
public:
    int id;
    int priority;
    Process(int i = 0, int p = 0) : id(i), priority(p) {}
};

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

#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Queue {
public:
    int rear;
    int front;
    int size;
    T* arr;

    Queue(int n = 0) {
        rear = front = -1;
        size = n;  
        while (size <= 0) {
            cin >> size;
        }
        arr = new T[size];
    }

    bool isFull() {
        return (rear == size - 1);
    }

    bool isEmpty() {
        return (front == -1 || front > rear);
    }

    bool enqueue(T x) {
        if (isFull()) return false;
        if (front == -1) front = 0;
        arr[++rear] = x;
        return true;
    }

    T dequeue() {
        if (isEmpty()) return T();
        T val = arr[front++];
        if (front > rear) front = rear = -1;
        return val;
    }

    void display() {
        if (isEmpty()) return;
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    ~Queue() {
        delete[] arr;
    }
};

class JobSchedulingSystem {

    public:
        Stack<Process> s;
        Queue<Process> q;
        int highestPriority;
        JobSchedulingSystem(int n) : s(n), q(n), highestPriority(-1) {}

        // (arrival order) using queue
        void addTask(Process &p) {
            if(q.isFull()) {
                cout << "Cannot add task, queue is full" << endl;
                return;
            }
            highestPriority = max(highestPriority, p.priority);
            q.enqueue(p);
        }

        // (execution handling) using stack
        void executeTask() {
            int tempHighest = -1;
            bool executed = false;
            while(!q.isEmpty()) {
                s.push(q.dequeue());
            }

            while(!s.isEmpty()) {
                Process p = s.pop();
                if(!executed && p.priority == highestPriority) {
                    executed = true;
                    cout << "Executing Process (id, priority): (" << p.id << "," << p.priority << ")" << endl;
                } else {
                    q.enqueue(p);
                    tempHighest = max(p.priority, tempHighest);
                }
            }

            highestPriority = tempHighest;
        }

};

int main() {
    int n;
    cout << "Enter total number of processes: ";
    cin >> n;

    JobSchedulingSystem system(n);

    cout << endl << "Adding Tasks: " << endl;
    for (int i = 0; i < n; i++) {
        Process p;
        cout << "Enter process ID and priority: ";
        cin >> p.id >> p.priority;
        system.addTask(p);
    }

    cout << endl << "Executing Tasks: " << endl;
    while (system.highestPriority != -1) {
        system.executeTask();
    }

    cout << endl << "All processes executed." << endl;
    return 0;
}