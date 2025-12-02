#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Node {
    public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
  public:
    vector<int> zigZagTraversal(Node* root) {
        vector<int> result;
        if(!root) return result;

        queue<Node*> q;
        q.push(root);
        bool leftToRight = true;

        while(!q.empty()) {
            int size = q.size();
            vector<int> level(size);

            for(int i = 0; i < size; i++) {
                Node* node = q.front();
                q.pop();

                int idx = leftToRight ? i : (size - 1 - i);
                level[idx] = node->data;

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }

            leftToRight = !leftToRight;

            // push flattened
            for(int val : level) result.push_back(val);
        }

        return result;
    }
};

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    Solution sol;
    vector<int> res = sol.zigZagTraversal(root);
    for(int val : res) {
        cout << val << " ";
    }
    return 0;
}