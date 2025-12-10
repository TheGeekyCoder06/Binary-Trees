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
    // 1. Insert into BST
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
};

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    Solution sol;
    Node* root = nullptr;

    int keys[] = {8, 3, 10, 1, 6, 14, 4, 7};
    int n = sizeof(keys) / sizeof(keys[0]);

    for (int i = 0; i < n; i++) {
        root = sol.insert(root, keys[i]);
    }

    cout << "Inorder traversal after insertions: ";
    inorder(root);
    cout << "\n";

    return 0;
}
