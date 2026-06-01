/*The Node structure is
class Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};*/

class Solution {
  public:
    bool solve(Node* root,int low,int high){
        if(root==NULL){
            return false ;
        }
        if(low==high){
            return true;
        }
        bool left=solve(root->left,low,root->data-1);
        bool right=solve(root->right,root->data+1,high);
        
        return left || right;
    }
    bool isDeadEnd(Node *root) {
        // Code here
        bool ans=solve(root,1,INT_MAX);
        return ans;
    }
};