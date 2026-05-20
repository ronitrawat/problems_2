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
    int height(struct Node* root,int n){
    if(root==NULL){
        return 0;
    }
    int left=height(root->left,n+1);
    int right=height(root->right,n+1);
    
    return 1+max(left,right);
    
}
    int diameter(Node* root)  {
    // code here
    if(root==NULL){
        return 0;
    }
    int left=diameter(root->left);
    int right=diameter(root->right);
    int total= height(root->left,0)+height(root->right,0);
    
    return max(left,max(right,total));
    

    }
};