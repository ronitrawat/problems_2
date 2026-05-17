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
    void leftBoundary(Node *root,vector<int>& ans){
    if(root==NULL){
        return ;
    }
    if(root->left==NULL && root->right==NULL){
       return ;}
        ans.push_back(root->data);
        if(root->left!=NULL){
            leftBoundary(root->left,ans);
        }
        else{
            leftBoundary(root->right,ans);
        }
    }
    
    void rightBoundary(Node *root,vector<int>& ans){
      if(root==NULL){
        return ;
    }
    if(root->left==NULL && root->right==NULL){
        return ;}
        
        if(root->right!=NULL){
            rightBoundary(root->right,ans);
        }
        else{
            rightBoundary(root->left,ans);
        }
    ans.push_back(root->data);
    }
    
    void leafBoundary(Node *root,vector<int>& ans){
       if(root==NULL){
        return ;}
    if(root->left==NULL && root->right==NULL){
        
      ans.push_back(root->data);
        }
        
        leafBoundary(root->left,ans);
        leafBoundary(root->right,ans);
    
    }
    
    vector<int> boundaryTraversal(Node *root) {
        // code here
        
        
        vector<int> ans;
        
        if(root!=NULL){
            ans.push_back(root->data);
            
        }
        
        leftBoundary(root->left,ans);
        
        leafBoundary(root->left,ans);
        
        leafBoundary(root->right,ans);
        
        rightBoundary(root->right,ans);
        
        
        return ans;
    }
};