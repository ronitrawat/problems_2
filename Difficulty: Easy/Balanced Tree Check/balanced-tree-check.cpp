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
    int height(Node* root,int n){
        if(root==NULL){
            return 0;
        }
        int left=height(root->left,n+1);
        int right=height(root->right,n+1);
        
        return 1+max(left,right);
    }
    bool isBalanced(Node* root) {
        // code here
        if(root==NULL){
            return true;
        }
        if( abs(height(root->left,0)-height(root->right,0))>1){
            return false;
        }
        return isBalanced(root->left) && isBalanced(root->right);
        
    }
};