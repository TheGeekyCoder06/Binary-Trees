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

int height(Node* root){ // post order traversal : TC -> O(n)
    if(!root) return 0;
    int leftHt= height(root->left);
    int rightHt = height(root->right);
    return max(leftHt , rightHt) + 1;
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    cout << "Height of the tree: " << height(root) << endl;

    return 0;
}