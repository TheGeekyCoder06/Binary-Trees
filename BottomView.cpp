#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

class Solution {
    public:
    vector<int> bottomView(Node* root) {
        vector<int> result;
        if(!root) return result;

        queue<pair<Node* , int>> q; // Pair of node and its horizontal distance
        map<int , int> mp; // Map to store the bottommost node at each horizontal distance
        q.push({root , 0});

        while(!q.empty()){
            Node* temp = q.front().first;
            int hd = q.front().second;
            q.pop();
            mp[hd] = temp->data; // Update the bottommost node at this horizontal distance

            if(temp->left) q.push({temp->left , hd - 1});
            if(temp->right) q.push({temp->right , hd + 1});
        }
        for(auto it : mp){
            result.push_back(it.second);
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
    vector<int> res = sol.bottomView(root);
    for(int val : res){
        cout << val << " ";
    }
    return 0;
}