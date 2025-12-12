// Implement a class BSTIterator for a Binary Search Tree that returns the next smallest element each time you call next().
#include <stack>
#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};
class BSTIterator {
public:
    stack<Node*> s; 
    
    BSTIterator(Node* root){ 
        pushLeft(root);
    } 
    
    bool hasNext(){
        return !s.empty();
    }         
    
    int next(){
        Node* node = s.top(); 
        s.pop();
        
        int result = node->data;
        
        if (node->right) {
            pushLeft(node->right);
        }
        
        return result;
    }

private:
    void pushLeft(Node* root){
        while (root) {
            s.push(root);
            root = root->left;
        }
    }
};
