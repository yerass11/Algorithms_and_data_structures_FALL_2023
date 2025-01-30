#include <bits/stdc++.h>

using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    int cnt;

    Node(int val) : val(val), left(nullptr), right(nullptr), cnt(1) {}
};

class BST {
public:
    Node* root;

    BST() : root(nullptr) {}

    Node* push(Node* cur, int val) {
        if (!cur) return new Node(val);

        if (val < cur->val)
            cur->left = push(cur->left, val);
        if (val > cur->val)
            cur->right = push(cur->right, val);

        return cur;
    }

    Node* find(Node* cur, int tar) {
        if (!cur)
            return nullptr;
        else if (cur->val == tar)
            return cur;
        else if (cur->val > tar)
            return find(cur->left, tar);
        else
            return find(cur->right, tar);
    }

    void preOrder(Node* cur) {
        if (cur) {
            int sum = 0;
            preOrder(cur->left);
            preOrder(cur->right);
        }
    }

    void sol(Node* cur) {
        vector<int> v;
        if (!cur) return;
        queue<Node*> q;
        q.push(cur);
        while (!q.empty()) {
            int sz = q.size();
            int sum = 0;
            for (int i = 0; i < sz; i++) {
                Node* temp = q.front();
                q.pop();
                if (temp->left) q.push(temp->left);
                if (temp->right) q.push(temp->right);
                sum += temp->val;
            }
            v.push_back(sum);
        }
        cout << v.size() << endl;
        for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
    }

    int size(Node* cur) {
        if (!cur) return 0;
        else return size(cur->left) + size(cur->right) + 1;
    }

    void push(int val) {
        root = push(root, val);
    }

    Node* find(int val) {
        return find(root, val);
    }

    int size() {
        return size(root);
    }

    void preOrder() {
        preOrder(root);
    }

    void sol() {
        sol(root);
    }
};

int main() {
    BST tree;
    int n;
    cin >> n;
    while (n--) {
        int x;
        cin >> x;
        tree.push(x);
    }
    tree.sol();

    return 0;
}
