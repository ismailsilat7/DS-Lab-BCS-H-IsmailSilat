#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
    int rollNum;
    Node* left;
    Node* right;
    int height;
    Node(int d=0, int h=1) : rollNum(d), height(h), left(nullptr), right(nullptr) {}
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

    cout << "Performed Left Rotation on " << root->rollNum << endl;
    return right;
}

Node* rightRotate(Node* root) {
    Node* left = root->left;
    Node* rightChild = left->right;

    left->right = root;
    root->left = rightChild;

    root->height = 1 + max(height(root->left), height(root->right));
    left->height = 1 + max(height(left->left), height(left->right));

    cout << "Performed Right Rotation on " << root->rollNum << endl;
    return left;
}

int getBalance(Node* root) {
    if(!root) return 0;
    return height(root->left) - height(root->right);
}

Node* Insert(Node* root, int rollNum) {
    if(!root) {
        root = new Node(rollNum);
        return root;
    }
    if(rollNum < root->rollNum) {
        root->left = Insert(root->left, rollNum);
    } else {
        root->right = Insert(root->right, rollNum);
    }

    root->height = 1 + max(height(root->left), height(root->right));

    int balance = getBalance(root);
    // Left Left
    if(balance > 1 && rollNum < root->left->rollNum) {
        return rightRotate(root);
    }
    // Right Right
    if(balance < -1 && rollNum > root->right->rollNum) {
        return leftRotate(root);
    }
    // Left Right
    if(balance > 1 && rollNum > root->left->rollNum){
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    // Right Left
    if(balance < -1 && rollNum < root->right->rollNum){
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    cout << "Node " << root->rollNum << ", height: " << root->height << ", balance: " << getBalance(root) << endl;
    return root;
}

Node* Delete(Node* root, int rollNum) {
    if (root == nullptr) return root;
    if(rollNum < root->rollNum) {
        root->left = Delete(root->left, rollNum);
    } else if(rollNum > root->rollNum) {
        root->right = Delete(root->right, rollNum);
    } else {
        if(root->left == nullptr && root->right == nullptr) {
            delete root;
            return nullptr;
        }
        if(root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        if(root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        Node* temp = root->right;
        while(temp->left) {
            temp = temp->left;
        }
        root->rollNum = temp->rollNum;
        root->right = Delete(root->right, temp->rollNum);
    
    }
    
    if(!root) return root;

    root->height = 1 + max(height(root->left), height(root->right));

    int balance = getBalance(root);
    // Left Left
    if(balance > 1 && getBalance(root->left) >= 0) {
        return rightRotate(root);
    }    
    // Right Right
    if(balance < -1 && getBalance(root->right) <= 0) {
        return leftRotate(root);
    }
    // Left Right
    if(balance > 1 && getBalance(root->left) < 0){
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    // Right Left
    if(balance < -1 && getBalance(root->right) > 0){
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    cout << "Node " << root->rollNum << ", height: " << root->height << ", balance: " << getBalance(root) << endl;

    return root;
}

void inorder(Node* root) {
    if(!root) return;
    inorder(root->left);
    cout << root->rollNum << " ";
    inorder(root->right);
}

int main() {
    Node* root = nullptr;

    int rollNums[] = {30, 20, 40, 10, 25, 35, 50};
    for(int i = 0; i < 7; i++) {
        int r = rollNums[i];
        root = Insert(root, r);
    }

    cout << "Inorder after inserts: ";
    inorder(root);
    cout << endl << endl;

    cout << "Deleting student with rollNum 20" << endl;
    root = Delete(root, 20);
    cout << "Deleting student with rollNum 40" << endl;
    root = Delete(root, 40);
    cout << "Deleting student with rollNum 25" << endl;
    root = Delete(root, 25);
    cout << "Deleting student with rollNum 30" << endl;
    root = Delete(root, 30);

    cout << "Inorder after deletes: ";
    inorder(root);
    cout << endl;

}
