/*
Definition for Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    vector<vector<int>> ans;
    vector<int> a;
    void level(Node *root){
        queue<Node *> q;
        if(root!=NULL){
          q.push(root);  
        }
        while(!q.empty()){
        
            int size=q.size();
            while(size--){
            Node* n=q.front();
            a.push_back(n->data);
            q.pop();
            if(n->right!=NULL){
            q.push(n->right);
            }
            if(n->left!=NULL){
            q.push(n->left);}
            }
            ans.push_back(a);
            a.clear();
        }
    }
    
    vector<int> rightView(Node *root) {
        // code here
        ans.clear();
        level(root);
        int n=ans.size();
        vector<int> b;
        for(int i=0;i<n;i++){
            b.push_back(ans[i][0]);
        }
        return b;
        
    }
};