#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
    int price;
    string productName;
    Node* left;
    Node* right;
    int height;
    Node(int d=0, string name = "unknown") : price(d), productName(name), height(1), left(nullptr), right(nullptr) {}
};

int height(Node* n) {
    return n ? n->height : 0;
}

Node* leftRotate(Node* root) {

    Node* right = root->right;
    Node* leftChild = right->left;

    right->left = root;
    root->right = leftChild;

    root->height = 1 + max(height(root->left), height(root->right));
    right->height = 1 + max(height(right->left), height(right->right));
    return right;
}

Node* rightRotate(Node* root) {
    Node* left = root->left;
    Node* rightChild = left->right;

    left->right = root;
    root->left = rightChild;

    root->height = 1 + max(height(root->left), height(root->right));
    left->height = 1 + max(height(left->left), height(left->right));
    return left;
}

int getBalance(Node* root) {
    if(!root) return 0;
    return height(root->left) - height(root->right);
}

Node* Insert(Node* root, int price, string name) {
    if(!root) {
        root = new Node(price, name);
        return root;
    }
    if(price < root->price) {
        root->left = Insert(root->left, price, name);
    } else {
        root->right = Insert(root->right, price, name);
    }

    root->height = 1 + max(height(root->left), height(root->right));

    int balance = getBalance(root);
    // Left Left
    if(balance > 1 && price < root->left->price) {
        return rightRotate(root);
    }
    // Right Right
    if(balance < -1 && price > root->right->price) {
        return leftRotate(root);
    }
    // Left Right
    if(balance > 1 && price > root->left->price){
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    // Right Left
    if(balance < -1 && price < root->right->price){
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}

void inorder(Node* root) {
    if(!root) return;
    inorder(root->left);
    cout << root->productName << ", $" << root->price << " ";
    inorder(root->right);
}

void findInRange(Node* root, int startRange, int EndRange) {
    if(startRange > EndRange) {
        return;
    }
    if(!root) return;
    if (root->price > startRange) {
        findInRange(root->left, startRange, EndRange);
    } 
    if(root->price >= startRange && root->price <= EndRange) {
        cout << root->productName << ", $" << root->price << " ";
    } 
    if (root->price < EndRange){
        findInRange(root->right, startRange, EndRange);
    }
}

int main() {
    Node* root = nullptr;

    int prices[] = {30, 20, 40, 10, 25, 35, 50};
    string names[] = {"Biscuit", "Chips", "Milk", "Eggs", "Bread", "Chocolate", "Juice"};
    for(int i = 0; i < 7; i++) {
        int r = prices[i];
        root = Insert(root, r, names[i]);
    }

    cout << "Inorder after inserts: ";
    inorder(root);
    cout << endl << endl;

    cout << "Finding in range 25-40" << endl;
    findInRange(root, 25, 40);
}
