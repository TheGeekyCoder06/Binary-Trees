#include <iostream>
#include<vector>
#include<queue>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

void inorderTraversal(Node* root){ // Left Root Right
    if(!root) return;
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

void preorderTraversal(Node* root){ // Root Left Right
    if(!root) return;
    cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void postorderTraversal(Node* root){ // Left Right Root
    if(!root) return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->data << " ";
}

void levelOrderTraversal(Node* root) {
    if (!root) return;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()) {
        int n = q.size();
        for(int i = 0; i < n; i++) {
            Node* curr = q.front();
            q.pop();
            cout << curr->data << " ";
            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
        }
        cout << endl; // separates levels
    }
}


int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    cout << "Inorder Traversal: ";
    inorderTraversal(root);
    cout << "\nPreorder Traversal: ";
    preorderTraversal(root);
    cout << "\nPostorder Traversal: ";
    postorderTraversal(root);
    cout << "\nLevel Order Traversal: ";
    levelOrderTraversal(root);
    return 0;
}