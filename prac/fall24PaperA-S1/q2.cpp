#include <iostream>
using namespace std;

class Plant {
    public:
    string name;
    string category;
    int price;
    Plant* left;
    Plant* right;
    int height;
    Plant(string n, string c, int p) : name(n), category(c), price(p), left(nullptr), right(nullptr), height(0) {}
};

class AVL {

public:
    Plant* root;
    AVL() : root(nullptr) {}
    int getHeight(Plant* r) {
        return (r) ? r->height : 0;
    }
    int getBalance(Plant* r) {
        return (getHeight(r->left) - getHeight(r->right));
    }

    Plant* leftRotate(Plant* r) {
        Plant* right = r->right;
        Plant* T2 = right->left;

        right->left = r;
        r->right = T2;

        r->height = 1 + max(getHeight(r->right), getHeight(r->left));
        right->height = 1 + max(getHeight(right->right), getHeight(right->left));

        return right;
    }

    Plant* rightRotate(Plant* r) {
        Plant* left = r->left;
        Plant* T2 = left->right;

        left->right = r;
        r->left = T2;

        r->height = 1 + max(getHeight(r->right), getHeight(r->left));
        left->height = 1 + max(getHeight(left->right), getHeight(left->left));

        return left;
    }

    Plant* insert(string n, string c, int p, Plant* r) {
        if(!r) {
            r = new Plant(n,c,p);
            return r;
        }
        if(r->price < p) {
            r->right = insert(n,c,p, r->right);
        } else {
            r->left = insert(n,c,p, r->left); 
        }
        r->height = 1 + max(getHeight(r->left), getHeight(r->right));
        int balance = getBalance(r);

        if(balance < -1 && p > r->right->price) {
            // right right
            return leftRotate(r);

        } else if (balance > 1 && p < r->left->price) {
            // left left
            return rightRotate(r);

        } else if(balance > 1 && p > r->left->price) {
            // left right
            r->left = leftRotate(r->left);
            return rightRotate(r);
        } else if(balance < -1 && p < r->right->price) {
            // right left
            r->right = rightRotate(r->right);
            return leftRotate(r);
        }

        return r;
    }

    // delete based on price as the question states
    Plant* deletePlant(int p, Plant* r) {
        if(!r) {
            return nullptr;
        } 
        if(p < r->price) {
            r->left = deletePlant(p, r->left);
        } else if (p > r->price) {
            r->right = deletePlant(p, r->right);
        }
        // found
        if(!r->left && !r->right) {
            delete r;
            return nullptr;
        }
        if(!r->left) {
            Plant* temp = r->right;
            delete r;
            r = temp;
        }else if(!r->right) {
            Plant* temp = r->left;
            delete r;
            r = temp;
        } else {
            Plant* temp = r->right;
            while(temp->left) {
                temp = temp->left;
            }
            r->name = temp->name;
            r->price = temp->price;
            r->category = temp->category;
            r->right = deletePlant(temp->price, r->right);
        }

        if(!r) {
            return r;
        }

        r->height = 1 + max(getHeight(r->left), getHeight(r->right));

        int balance = getBalance(r);

        // LL
        if (balance > 1 && getBalance(r->left) >= 0) {
            return rightRotate(r);
        } else if(balance < -1 && getBalance(r->right) <= 0) { // RR
            return leftRotate(r);
        } else if(balance > 1 && getBalance(r->left) < 0) { // LR
            r->left = leftRotate(r->left);
            return rightRotate(r);
        } else if(balance < -1 && getBalance(r->right) > 0) { // RL
            r->right = rightRotate(r->right);
            return leftRotate(r);
        }
        return r;
    }

    bool searchPlant(int p, Plant* r) {
        if(!r) {
            return false;
        } 

        if(p > r->price) {
            return searchPlant(p, r->right);
        } else if(p < r->price) {
            return searchPlant(p, r->left);
        }
        return true;
    }

};
