#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node*left, *right;
    Node(int data) {
        this->data = data;
        this->left = this->right = NULL;
    }
};

struct BST {
    Node* root;
    BST() {
        this->root = NULL;
    }
    Node*add(Node* cur, int x) {
        if (cur == NULL) {
            cur = new Node(x);
        } else if (x < cur->data) {
            if (cur->left == NULL) {
                cur->left = add(cur->left, x);
            } else {
                add(cur->left, x);
            }
        } else {
            if (cur->right == NULL) {
                cur->right = add(cur->right, x);
            }
            else {
                add(cur->right, x);
            }
        }
        return cur;
    }
    Node* search(Node* cur, int x) {
        if (cur == NULL) {
            return NULL;
        } else if (x == cur->data) {
            return cur;
        } else if (x < cur->data) {
            return search(cur->left, x);
        } else {
            return search(cur->right, x);
        }
    }
};

int main(){
    int n, m; cin >> n >> m;
    BST *bst = new BST();
    while (n--) {
        int x; cin >> x;
        if (bst->root == NULL) {
            bst->root = bst->add(bst->root, x);
        } else {
            bst->add(bst->root, x);
        }
    }

    while (m--) {
        string s; cin >> s;
        Node*cur = bst->root;
        for (int i = 0; i < s.size(); ++i) {
            if (cur == NULL) break;
            else if (s[i] == 'L') {
                cur = cur->left;
            } else {
                cur = cur->right;
            }
        }
        if (cur != NULL) {
            cout << "YES\n";
        } else cout << "NO\n";

    }
    return 0;
}