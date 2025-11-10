#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    string name;
    Node* mother; // left child
    Node* father; // right child
    Node(string n) : name(n), mother(nullptr), father(nullptr) {}
    void getParents() {
        if(!mother) {
            cout << "Enter mother's name for " << name << " ('unknown' if not known) : ";
            string n;
            cin >> n;
            if(n != "unknown") {
                mother = new Node(n);
                mother->getParents();
            }
        }
        if(!father) {
            cout << "Enter father's name for " << name << " ('unknown' if not known) : ";
            string n;
            cin >> n;
            if(n != "unknown") {
                father = new Node(n);
                father->getParents();
            }
        }
    }
};

class FamilyAncestry {
public:
    Node* root;
    FamilyAncestry(string name) {
        root = new Node(name);
        root->getParents();
    }

    void printLeafNodes(Node* root) {
        if(!root) return;
        if(!root->mother && !root->father) {
            cout << root->name << endl;
            return;
        }
        printLeafNodes(root->mother);
        printLeafNodes(root->father);
    }

    int getHeight(Node* root) {
        if(!root) {
            return 0;
        }
        int x = getHeight(root->mother);
        int y = getHeight(root->father);
        return 1 + max(x,y);
    }

    string getYoungest() {
        return root->name;
    }

    void printLevelMember(Node* root) {
        if(!root) return;
        int level = 0;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()) {
            int size = q.size();
            cout << "Level " << level << ": ";
            for(int i = 0; i < size; i++) {
                Node* child = q.front();
                q.pop();
                cout << child->name << " ";
                if(child->mother) q.push(child->mother);
                if(child->father) q.push(child->father);
            }
            cout << endl;
            level++;
        }
    }

    void displayInfo() {
        cout << endl << "Root (youngest person): " << getYoungest() << endl;
        cout << endl << "Leaf nodes (ancestors with no known parents):" << endl;
        printLeafNodes(root);
        cout << endl << "Height of tree: " << getHeight(root) << endl;
        cout << endl << "Members by level:" << endl;
        printLevelMember(root);
    }
};

int main() {
    string name;
    cout << "Enter the youngst person's name: ";
    cin >> name;

    FamilyAncestry tree(name);
    tree.displayInfo();
}
