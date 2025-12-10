#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
public:
    // Helper: insert to build BST for testing
    Node* insert(Node* root, int key) {
        if (!root) {
            return new Node(key);
        }

        if (key < root->data) {
            root->left = insert(root->left, key);
        } else {
            root->right = insert(root->right, key);
        }

        return root;
    }

    // 2. Search in BST
    bool search(Node* root, int key) {
        if (!root) return false;

        if (root->data == key) {
            return true;
        }

        if (key < root->data) {
            return search(root->left, key);
        }

        return search(root->right, key);
    }
};

int main() {
    Solution sol;
    Node* root = nullptr;

    int keys[] = {8, 3, 10, 1, 6, 14, 4, 7};
    int n = sizeof(keys) / sizeof(keys[0]);

    for (int i = 0; i < n; i++) {
        root = sol.insert(root, keys[i]);
    }

    int keyToSearch = 6;
    if (sol.search(root, keyToSearch)) {
        cout << "Key " << keyToSearch << " found in BST.\n";
    } else {
        cout << "Key " << keyToSearch << " not found in BST.\n";
    }

    return 0;
}
