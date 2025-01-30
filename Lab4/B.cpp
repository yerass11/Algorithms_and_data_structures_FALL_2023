#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node*left, *right;
    Node (int data) {
        this->data = data;
        this->left = this->right = NULL;
    }
};

struct BST {
    Node*root;
    BST() {
        this->root = NULL;
    }
    Node*add(Node*cur, int x) {
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
            } else {
                add(cur->right, x);
            }
        }
        return cur;
    }
    Node*search(Node*cur, int x) {
        if (cur == NULL) {
            return NULL;
        } else if (cur->data == x) {
            return cur;
        } else if (cur->data > x) {
            return search(cur->left, x);
        } else {
            return search(cur->right, x);
        }
    }

    int count(Node*cur) {
        if (cur == NULL) return 0;
        int cnt = 0;
        if (cur != NULL) {
            cnt++;
            cnt+=count(cur->right);
            cnt+=count(cur->left);
        }
        return cnt;
    }
};

int main(){
    int n; cin >> n;
    BST*bst = new BST();
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        if (bst->root == NULL) {
            bst->root = bst->add(bst->root, x);
        } else {
            bst->add(bst->root, x);
        }
    }
    int k; cin >> k;
    Node*cur = bst->search(bst->root, k);
    cout << bst->count(cur);
    return 0;
}