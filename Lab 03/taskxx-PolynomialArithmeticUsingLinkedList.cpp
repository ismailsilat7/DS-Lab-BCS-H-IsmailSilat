#include <bits/stdc++.h>
using namespace std;

// Leetcode like starter code
// assuming that linked lists are sorted in descending order of exponents

// Definition for singly-linked list node of polynomial
struct PolyNode {
    int coeff;
    int exp;
    PolyNode* next;
    PolyNode(int c, int e) : coeff(c), exp(e), next(nullptr) {}
};

class Solution {
public:
    // Add two polynomials represented as linked lists
    PolyNode* addPoly(PolyNode* p1, PolyNode* p2) {
        if(!p1) {
            return p2;
        }
        if(!p2) {
            return p1;
        }
        PolyNode* result;
        PolyNode* it1 = p1;
        PolyNode* it2 = p2;
        if(it1->exp == it2->exp) {
            result = new PolyNode(it1->coeff + it2->coeff, it1->exp);
            it1 = it1->next;
            it2 = it2->next;
        } else if(it1->exp > it2->exp) {
            result = new PolyNode(it1->coeff, it1->exp);
            it1 = it1->next;
        } else {
            result = new PolyNode(it2->coeff, it2->exp);
            it2 = it2->next;
        }

        PolyNode* it = result;
        while (it1 && it2) {
            if(it1->exp == it2->exp) {
                it->next = new PolyNode(it1->coeff + it2->coeff, it1->exp);
                it1 = it1->next;
                it2 = it2->next;
            } else if(it1->exp > it2->exp) {
                it->next = new PolyNode(it1->coeff, it1->exp);
                it1 = it1->next;
            } else {
                it->next = new PolyNode(it2->coeff, it2->exp);
                it2 = it2->next;
            }
            it = it->next;
        }

        if(it1) {
            it->next = it1;
        }
        if(it2) {
            it->next = it2;
        }

        return result;
    }

    // Multiply two polynomials represented as linked lists
    PolyNode* multiplyPoly(PolyNode* p1, PolyNode* p2) {

        if(!p1 || !p2) {
            return nullptr;
        }
        PolyNode* it1 = p1;
        PolyNode* result = nullptr;
        while(it1) {
            PolyNode* mul = nullptr;
            PolyNode* mulIt = nullptr;
            PolyNode* it2 = p2;
            while(it2) {
                if(!mul) {
                    mul = new PolyNode(it2->coeff * it1->coeff, it2->exp + it1->exp);
                    mulIt = mul;
                } else {
                    mulIt->next = new PolyNode(it2->coeff * it1->coeff, it2->exp + it1->exp);
                    mulIt = mulIt->next;
                }
                it2 = it2->next;
            }
            result = addPoly(mul, result);
            it1 = it1->next;
        }
        return result;
    }
};

void printPoly(PolyNode* head) {
    PolyNode* curr = head;
    bool first = true;
    while (curr) {
        if (!first && curr->coeff >= 0) cout << "+";
        cout << curr->coeff << "x^" << curr->exp << " ";
        curr = curr->next;
        first = false;
    }
    cout << endl;
}

PolyNode* createPoly(const vector<pair<int,int>>& terms) {
    PolyNode* head = nullptr;
    PolyNode* tail = nullptr;
    for (auto [c, e] : terms) {
        PolyNode* node = new PolyNode(c, e);
        if (!head) head = tail = node;
        else {
            tail->next = node;
            tail = node;
        }
    }
    return head;
}

int main() {
    Solution sol;

    // Example: P1 = 3x^2 + 2x + 1
    PolyNode* P1 = createPoly({{3,2}, {2,1}, {1,0}});
    // Example: P2 = x^2 + x
    PolyNode* P2 = createPoly({{1,2}, {1,1}});

    cout << "P1 = "; printPoly(P1);
    cout << "P2 = "; printPoly(P2);

    PolyNode* sum = sol.addPoly(P1, P2);
    cout << "P1 + P2 = "; printPoly(sum);

    PolyNode* product = sol.multiplyPoly(P1, P2);
    cout << "P1 * P2 = "; printPoly(product);

    return 0;
}
