#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    int height;
    Node(int d) : data(d), height(0) {
        left = right = nullptr;
    }
};

class AVL {
public:
    Node* root;
    AVL() {
        root = nullptr;
    }    
    int getHeight(Node* r) {
        return r ? r->height : 0;
    }
    int getBalance(Node* r) {
        return getHeight(r->left) - getHeight(r->right);
    } 

    Node* leftRotate(Node* r) {
        Node* left = r->left;
        Node* T2 = left->right;

        left->right = r;
        r->left = T2;

        r->height = 1 + max(getHeight(r->left), getHeight(r->right));
        left->height = 1 + max(getHeight(left->left), getHeight(left->right));

        return left;
    }

    Node* rightRotate(Node* r) {
        Node* right = r->right;
        Node* T2 = right->left;

        right->left = r;
        r->right = T2;

        r->height = 1 + max(getHeight(r->left), getHeight(r->right));
        right->height = 1 + max(getHeight(right->left), getHeight(right->right));

        return right;
    }

    Node* insert(Node* r, int d) {
        if(!r) {
            r = new Node(d);
            return r;
        } 
        if(d < r->data) {
            r->left = insert(r->left, d);
        } else {
            r->right = insert(r->right, d);
        }
        r->height = 1 + max(getHeight(r->left), getHeight(r->right));

        int balance = getBalance(r);

        if(balance > 1 && d < root->left->data) {
            return rightRotate(r);
        } else if(balance > 1 && d >= root->left->data) {
            root->left = leftRotate(root->left);
            return rightRotate(r);
        } else if(balance < -1 && d > root->right->data) {
            return leftRotate(r);
        } else if(balance < -1 && d <= root->right->data) {
            root->right = rightRotate(root->right);
            return leftRotate(r);
        }
        return r;
    }

    Node* deleteNode(Node* r, int d) {
        if(!r) {
            return nullptr;
        }
        if(d < r->data) {
            r->left = deleteNode(r->left, d);
        } else if(d > r->data) {
            r->right = deleteNode(r->right, d);
        } else {
            // found
            if(!r->left && !r->right) {
                delete root;
                return nullptr;
            } else if(!r->left) {
                Node* temp = r->right;
                delete r;
                return temp;
            } else if(!r->right) {
                Node* temp = r->left;
                delete r;
                return temp;
            } else {
                Node* temp = r->right;
                while(temp->left) {
                    temp = temp->left;
                }
                r->data = temp->data;
                r->right = deleteNode(r->right, temp->data);
            }
        }

        r->height = 1 + max(getHeight(r->left), getHeight(r->right));

        int balance = getBalance(r);

        if(balance > 1 && getBalance(r->left) >= 0) {
            return rightRotate(r);
        } else if(balance > 1 && getBalance(r->left) < 0) {
            r->left = leftRotate(r->left);
            return rightRotate(r);
        } else if(balance < -1 && getBalance(r->right) <= 0) {
            return leftRotate(r);
        } else if(balance < -1 && getBalance(r->right) > 0) {
            r->right = rightRotate(r->right);
            return leftRotate(r);
        }

        return r;
    }

};
