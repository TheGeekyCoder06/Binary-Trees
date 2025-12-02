#include <map>
#include <queue>
#include <vector>
#include <iostream>
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

class Solution {
  public:
    vector<vector<int>> verticalOrder(Node *root) {
        // code here
        vector<vector<int>> result;
        if(!root) return result;
        
        map<int, vector<int>> mp;
        queue<pair<Node* , int>> q;
        q.push({root , 0});
        
        while(!q.empty()){
            Node* temp = q.front().first;
            int hd = q.front().second;
            q.pop();
            
            mp[hd].push_back(temp->data);
            
            if(temp->left) q.push({temp->left , hd -1});
            if(temp->right) q.push({temp->right , hd + 1});
        }
        
        for(auto& p : mp){
            result.push_back(p.second);
        }
        return result;
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

    Solution sol;
    vector<vector<int>> res = sol.verticalOrder(root);
    for(const auto& vec : res){
        for(int val : vec){
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}