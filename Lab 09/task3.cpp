#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int severity;
    Node* left;
    Node* right;
    int height;
    Node(int d=0) : severity(d), height(1), left(nullptr), right(nullptr) {}
};

int height(Node* n) {
    return n ? n->height : 0;
}

// --- ROTATIONS ---
Node* leftRotate(Node* root) {
    Node* right = root->right;
    Node* leftChild = right->left;

    right->left = root;
    root->right = leftChild;

    root->height = 1 + max(height(root->left), height(root->right));
    right->height = 1 + max(height(right->left), height(right->right));

    cout << "Performed Left Rotation on patient with severity " 
         << root->severity << endl;

    return right;
}

Node* rightRotate(Node* root) {
    Node* left = root->left;
    Node* rightChild = left->right;

    left->right = root;
    root->left = rightChild;

    root->height = 1 + max(height(root->left), height(root->right));
    left->height = 1 + max(height(left->left), height(left->right));

    cout << "Performed Right Rotation on patient with severity " 
         << root->severity << endl;

    return left;
}

int getBalance(Node* root) {
    if(!root) return 0;
    return height(root->left) - height(root->right);
}

// --- INSERT ---
Node* Insert(Node* root, int severity) {
    if(!root) 
        return new Node(severity);

    if(severity < root->severity)
        root->left = Insert(root->left, severity);
    else
        root->right = Insert(root->right, severity);

    root->height = 1 + max(height(root->left), height(root->right));

    int balance = getBalance(root);

    if(abs(balance) > 1)
        cout << "AVL Tree became unbalanced. Balancing..." << endl;

    if(balance > 1 && severity < root->left->severity)
        return rightRotate(root);

    if(balance < -1 && severity > root->right->severity)
        return leftRotate(root);

    if(balance > 1 && severity > root->left->severity) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if(balance < -1 && severity < root->right->severity) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// --- DELETE ---
Node* Delete(Node* root, int severity) {
    if(!root) return root;

    if(severity < root->severity)
        root->left = Delete(root->left, severity);
    else if(severity > root->severity)
        root->right = Delete(root->right, severity);
    else {
        if(!root->left && !root->right) {
            delete root;
            return nullptr;
        }
        if(!root->left) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        if(!root->right) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        Node* temp = root->right;
        while(temp->left)
            temp = temp->left;

        root->severity = temp->severity;
        root->right = Delete(root->right, temp->severity);
    }

    if(!root) return root;

    root->height = 1 + max(height(root->left), height(root->right));

    int balance = getBalance(root);

    if(balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    if(balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    if(balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if(balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void inorder(Node* root) {
    if(!root) return;
    inorder(root->left);
    cout << root->severity << " ";
    inorder(root->right);
}

int highestSeverity(Node* root) {
    if(!root) return -1;
    while(root->right)
        root = root->right;
    return root->severity;
}

int main() {
    Node* root = nullptr;

    int severities[] = {30, 40, 50, 10, 20, 35, 25};

    for(int i = 0; i < 7; i++) {
        int s = severities[i];
        cout << "Inserting patient with severity " << s << endl;
        root = Insert(root, s);
        cout << "Tree height: " << height(root) << " | Highest severity: " << highestSeverity(root) << endl;
    }

    cout << endl << "Inorder after inserts: ";
    inorder(root);
    cout << endl;

    int discharge[] = {20, 40, 25, 30};

    for(int i = 0; i < 4; i++) {
        int s = discharge[i];
        cout << "Discharging patient with severity " << s << endl;
        root = Delete(root, s);
        cout << "Tree height: " << height(root) << " | Highest severity: " << highestSeverity(root) << endl;
    }

    cout << "Inorder after discharges: ";
    inorder(root);
    cout << endl;
}