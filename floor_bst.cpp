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

    // 3. Floor in BST (largest value <= x)
    int findFloor(Node* root, int x) {
        int ans = -1;

        while (root) {
            if (root->data == x) {
                return x;
            }

            if (root->data < x) {
                ans = root->data;
                root = root->right;
            } else {
                root = root->left;
            }
        }

        return ans;
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

    int x = 5;
    int floorVal = sol.findFloor(root, x);
    cout << "Floor of " << x << " in BST = " << floorVal << "\n";

    return 0;
}
