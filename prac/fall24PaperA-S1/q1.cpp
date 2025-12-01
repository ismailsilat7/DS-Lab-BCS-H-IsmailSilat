#include <iostream>
using namespace std;

class Package {
public:
    string ID;
    int time;
};

#define NUM_PACKAGES 50

class MinHeap {
    public:
    Package packages[NUM_PACKAGES + 1];
    int n;
    MinHeap() {
        n = 0;
    }

    void insert(string id, int t) {
        if(n >= NUM_PACKAGES) {
            cout << "Cannot insert, heap is full" << endl;
            return;
        }
        n++;
        packages[n].ID = id;
        packages[n].time = t;
        int i = n;
        while(i > 1 && packages[i].time < packages[i/2].time) {
            swap(packages[i], packages[i/2]); i/=2;
        }
        cout << "Package with ID " << id <<  " inserted in minHeap (earliest arrival)" << endl;
    }

    Package process(bool pFlag = true) {
        if(n == 0) {
            Package p = Package();
            p.time = -1;
            return p;
        }
        Package p = packages[1];
        packages[1] = packages[n];
        n--;
        int i = 1;
        while(true) {
            int left = i * 2;
            int right = i * 2 + 1;
            if(left > n) break;
            int smallest = left;
            if(right <= n && packages[right].time < packages[left].time) {
                smallest = right;
            }
            if(packages[i].time > packages[smallest].time) {
                swap(packages[i], packages[smallest]);
                i = smallest;
            } else {
                break;
            }
        }
        if (pFlag) {
            cout << p.ID << " ";
        }
        return p;
    }

};

class MaxHeap {
    public:
    Package packages[NUM_PACKAGES + 1];
    int n;
    MaxHeap() {
        n = 0;
    }

    void insert(string id, int t) {
        if(n >= NUM_PACKAGES) {
            cout << "Cannot insert, heap is full" << endl;
            return;
        }
        n++;
        packages[n].ID = id;
        packages[n].time = t;
        int i = n;
        while(i > 1 && packages[i].time > packages[i/2].time) {
            swap(packages[i], packages[i/2]); i/=2;
        }
        cout << "Package with ID " << id <<  " inserted (latestArrival)" << endl;
    }

    Package process(bool pFlag = true) {
        if(n == 0) {
            Package p = Package();
            p.time = -1;
            return p;
        }
        Package p = packages[1];
        packages[1] = packages[n];
        n--;
        int i = 1;
        while(true) {
            int left = i * 2;
            int right = i * 2 + 1;

            if (left > n) break;

            int largest = left;
            if (right <= n && packages[right].time > packages[left].time)
                largest = right;

            if (packages[i].time < packages[largest].time) {
                swap(packages[i], packages[largest]);
                i = largest;
            } else break;
        }
        if (pFlag) {
            cout << p.ID << " ";
        }
        return p;
    }
};

int main() {
    MinHeap mH;
    cout << "Inserting packages in MinHeap" << endl;
    mH.insert("pkg1", 45);
    mH.insert("pkg2", 20);
    mH.insert("pkg3", 35);
    mH.insert("pkg4", 10);
    mH.insert("pkg5", 50);
    mH.insert("pkg6", 30);
    mH.insert("pkg7", 25);

    cout << "First 3 Packages to Process (Earliest Arrival): ";
    mH.process();
    mH.process();
    mH.process();
    cout << endl;

    Package st[100];
    int top = -1;
    while(mH.n != 0) {
        Package p = mH.process(false);
        st[++top] = p;
    }
    MaxHeap maxH;
    cout << "Inserting packages in MaxHeap" << endl;
    while(top != -1) {
        maxH.insert(st[top].ID, st[top].time);
        top--;
    }

    cout << "Remaining Packages (Latest Arrival): ";
    while(maxH.n != 0) {
        Package p = maxH.process();
    }
    cout << endl;
}
