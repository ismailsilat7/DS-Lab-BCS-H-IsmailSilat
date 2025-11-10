#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    string songName;
    int playCount;
    Node* left;
    Node* right;
    Node(string n, int c) : songName(n), playCount(c), left(nullptr), right(nullptr) {}
};

class MusicApp {
public:
    Node* root;
    MusicApp(string n, int c) {
        root = new Node(n, c);
    }

    void insertSong(string n, int c) {
        Node * p = new Node(n, c);
        if(!root) {
            root = p;
            return;
        }

        Node* it = root;
        while(it) {
            if(c < it->playCount) {
                if(!it->left) {
                    it->left = p;
                    return;
                } else {
                    it = it->left;
                }
            } else if(c > it->playCount) {
                if(!it->right) {
                    it->right = p;
                    return;
                } else {
                    it = it->right;
                }
            } else {
                cout << "Cannot have two songs with same play count - couldn't insert" << endl;
                return;
            }
        }
    }

    void searchSong(Node* root, int c) {
        if(!root) {
            cout << "No song found with play count " << c << endl;
            return;
        }
        if(root->playCount == c) {
            cout << "Song " << root->songName << " has play count " << c << endl;
            return;
        } 
        if(c < root->playCount) {
            searchSong(root->left, c);
        } else {
            searchSong(root->right, c);
        }
    }

    void InOrder(Node* root) {
        if(root) {
            InOrder(root->left);
            cout << root->songName << ", " << root->playCount << endl;
            InOrder(root->right);
        }
    }

    void PostOrder(Node* root) {
        if(root) {
            PostOrder(root->left);
            PostOrder(root->right);
            cout << root->songName << ", " << root->playCount << endl;
        }
    }

    Node* deleteSong(Node* root, int c) {
        if(!root) {
            cout << "Cannot delete - No song found with play count " << c << endl;
            return nullptr;
        }
        if(c > root->playCount) {
            root->right = deleteSong(root->right, c);
        } else if(c < root->playCount) {
            root->left = deleteSong(root->left, c);
        } else {

            // found
            if(!root->left && !root->right) {
                delete root;
                return nullptr;
            }
            if(!root->left) {
                Node * p = root;
                root = root->right;
                delete p;
                return root;
            }
            if(root->right) {
                Node * p = root;
                root = root->left;
                delete p;
                return root;
            }
            Node* it = root->right;
            while(it->left) {
                it = it->left;
            }
            root->playCount = it->playCount;
            root->songName = it->songName;
            root->right = deleteSong(root->right, it->playCount);
        }
        return root;
    }

};

int main() {

    MusicApp app("ShapeOfYou", 100);
    app.insertSong("BlindingLights", 150);
    app.insertSong("Levitating", 90);
    app.insertSong("Peaches", 120);
    app.insertSong("Despacito", 200);

    cout << endl << "Songs (InOrder - Least to Most Played):" << endl;
    app.InOrder(app.root);

    cout << endl << "Songs (PostORder - Removed in Reverse Popularity Order):" << endl;
    app.PostOrder(app.root);

    cout << endl << "searching for song with play count 120..." << endl;
    app.searchSong(app.root, 120);

    cout << endl << "deleting song with play count 120..." << endl;
    app.root = app.deleteSong(app.root, 120);

    cout << endl << "Updated Songs (Inorder):" << endl;
    app.InOrder(app.root);

}

