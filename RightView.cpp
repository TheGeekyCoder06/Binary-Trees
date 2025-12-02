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

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    return 0;
}
class Solution {
  public:
  
  void recursion(Node *root , int level , vector<int>& res){
      if(!root) return;
      if(res.size() == level) res.push_back(root->data);
      recursion(root->right , level + 1 , res);
      recursion(root->left , level + 1 , res);
  }
    vector<int> rightView(Node *root) {
        vector<int> res;
        recursion(root , 0 , res);
        return res;
        
    }
};