#include <iostream>
using namespace std;

class Student {
public:
    int ID;
    int score;
};

bool compare(Student& s1, Student& s2) {
    if (s1.score != s2.score)
        return s1.score > s2.score;
    return s1.ID < s2.ID;
}

int partition(Student arr[], int low, int high) {
    Student pivot = arr[high];
    int i = low - 1;
    for(int j = low; j < high; j++) {
        if(compare(arr[j], pivot)) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(Student arr[], int low, int high) {
    if(low < high) {
        int pivot = partition(arr, low, high);
        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}

class HashTable {
public:
    Student* table;
    int capacity;
    int size;
    HashTable(int c) {
        capacity = c;
        size = 0;
        table = new Student[c];
        for(int i = 0; i < c; i++) {
            table[i].ID = -1;
            table[i].score = -1;
        }
    } 
    int hash(int id) {
        return id % capacity;
    }
    float loadFactor() {
        return (float)size/capacity;
    }

    void rehash() {
        int oldCapacity = capacity;
        Student* oldTable = table;
        size = 0;
        capacity = capacity*2 + 1;
        table = new Student[capacity];
        for(int i = 0; i < capacity; i++) {
            table[i].ID = -1;
            table[i].score = -1;
        }

        for(int i = 0; i < oldCapacity; i++) {
            if(oldTable[i].ID != -1) {
                Student t = oldTable[i];
                insert(t.ID, t.score);
            }
        }
        delete[] oldTable;
    }

    void insert(int id, int score) {
        if(loadFactor() > 0.7) {
            rehash();
        }
        int index = hash(id);
        int start = index;
        while(table[index].score != -1) {
            index = (index + 1) % capacity;
            if(index == start) {
                cout << "Hash table is full, cannot insert" << endl;
            }
        }
        table[index].ID = id;
        table[index].score = score;
        size++;
    }

    void displayAllSorted() {
        Student* arr = new Student[size];
        int j = 0;
        for(int i = 0; i < capacity; i++) {
            if(table[i].ID != -1) {
                arr[j++] = table[i];
            }
        }
        quickSort(arr, 0, j - 1);
        for(int i = 0; i < j; i++) {
            cout << "ID: " << arr[i].ID << ", Score: " << arr[i].score << endl;
        }
        delete[] arr;
    }

};



int main() {
    HashTable ht(5); // small initial capacity so rehash gets tested

    ht.insert(101, 85);
    ht.insert(55, 92);
    ht.insert(200, 92); 
    ht.insert(77, 60);
    ht.insert(333, 85);
    ht.insert(999, 100);

    cout << "\nSorted Students:\n";
    ht.displayAllSorted();

    return 0;
}



