#include <bits/stdc++.h>
using namespace std;

// A hospital must always treat patients with most severe condition first. Implement a max-priority queue where:    
    // Each patient has a name, severity level (1-10) and arrival time.
    // Higher severity indicates higher priority        
    // If severity is equal, earlier arrival time
    // indicates higher priority
// Operations to perform:
    // Add a new patient
    // Get next patient to treat
    // Update a patient's severity level        
    // Display all waiting patients in order from highest to lowest priority

class Node {
    public:
    string name; int severity; int arrivalTime;
    Node* next;
    Node(string n, int s, int a) : name(n), severity(s), arrivalTime(a), next(nullptr) {}
};

class PriorityQueue {
    public:
        Node* front;
        PriorityQueue() : front(nullptr) {}
        ~PriorityQueue() { 
            while (front) {
                Node* temp = front;
                front = front->next;
                delete temp;
            }
        }
        void addPatient(string name, int severity, int arrivalTime) {
            Node* newNode = new Node(name, severity, arrivalTime);

            if(!front || severity > front->severity) {
                newNode->next = front;
                front = newNode;
            } else {
                Node* current = front;
                while (current->next) {
                    if (current->next->severity > severity) {
                        current = current->next;
                    } 
                    else if (current->next->severity == severity &&
                            current->next->arrivalTime <= newNode->arrivalTime) {
                        current = current->next;
                    }
                    else break;
                }

                newNode->next = current->next;
                current->next = newNode;
            }

            cout << "Patient " << name << " inserted." << endl;
        }

        void treatPatient() {
            if(!front) {
                cout << "Cannot treat patient - queue empty" << endl;
                return;
            }
            Node* temp = front;
            front = front->next;
            cout << "Patient " << temp->name << " treated." << endl;
            delete temp;
        }

        void updateSeverity(string name, int newSeverity) {
            if (!front) {
                cout << "Queue empty." << endl;
                return;
            }

            Node* current = front;
            Node* prev = nullptr;
            while (current && current->name != name) {
                prev = current;
                current = current->next;
            }

            if (!current) {
                cout << "Patient not found." << endl;
                return;
            }

            int oldArrival = current->arrivalTime;
            if (!prev) {
                front = current->next;
            }
            else {
                prev->next = current->next;
            }
            delete current;
            addPatient(name, newSeverity, oldArrival);
            cout << "Severity updated for " << name << "." << endl;
        }

        void display() {
            if (!front) {
                cout << "No patients waiting - Queue empty" << endl;
                return;
            }

            Node* cur = front;
            cout << "Patients (high to low priority):" << endl;

            while (cur) {
                cout << cur->name
                    << " - Severity: " << cur->severity
                    << " - Arrival Time: " << cur->arrivalTime << endl;
                cur = cur->next;
            }
        }

};

int main() {
    PriorityQueue pq;
    int choice;

    while (true) {
        cout << endl << "--- Hospital Priority Queue Menu ---" << endl;
        cout << "1. Add Patient" << endl;
        cout << "2. Treat Next Patient" << endl;
        cout << "3. Update Patient Severity" << endl;
        cout << "4. Display All Patients" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            string name;
            int severity, arrival;
            cout << "Enter patient name: ";
            cin >> name;
            cout << "Enter severity (1-10): ";
            cin >> severity;
            cout << "Enter arrival time: ";
            cin >> arrival;
            pq.addPatient(name, severity, arrival);
        }

        else if (choice == 2) {
            pq.treatPatient();
        }

        else if (choice == 3) {
            string name;
            int newSev;
            cout << "Enter patient name: ";
            cin >> name;
            cout << "Enter new severity: ";
            cin >> newSev;
            pq.updateSeverity(name, newSev);
        }

        else if (choice == 4) {
            pq.display();
        }

        else if (choice == 5) {
            cout << "Exiting program..." << endl;
            break;
        }

        else {
            cout << "Invalid choice, try agin." << endl;
        }
    }

    return 0;
}

