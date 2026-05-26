/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
}; */

class Solution {
  public:
    int maxL=0;
    int maxS=0;
    void solve(Node *root,int length,int sum){
        if(root==NULL){
            return;
        }
        sum+=root->data;
        if(!root->left && !root->right){
            
        
        if(length>maxL){
            maxL=length;
            maxS=sum;
        }
        else if(length==maxL){
            maxS=max(maxS,sum);
        }}
         solve(root->left,
              length+1,
              sum);

        solve(root->right,
              length+1,
              sum);
        
        
    }
    int sumOfLongRootToLeafPath(Node *root) {
        // code here
        solve(root,1,0);
        
        
        return maxS;
        
    }
};