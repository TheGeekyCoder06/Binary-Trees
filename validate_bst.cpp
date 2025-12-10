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

    // 5. Validate BST
    bool isValid(Node* root, long long minVal, long long maxVal) {
        if (!root) return true;

        if (root->data <= minVal || root->data >= maxVal) {
            return false;
        }

        return isValid(root->left, minVal, root->data) &&
               isValid(root->right, root->data, maxVal);
    }

    bool isBST(Node* root) {
        const long long MIN_VAL = -1000000000000000000LL; // -1e18
        const long long MAX_VAL =  1000000000000000000LL; //  1e18
        return isValid(root, MIN_VAL, MAX_VAL);
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

    if (sol.isBST(root)) {
        cout << "The tree is a valid BST.\n";
    } else {
        cout << "The tree is NOT a valid BST.\n";
    }

    return 0;
}
