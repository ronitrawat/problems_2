/*
class Node {
public:
    int data;
    Node *left, *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
  
   bool solve(Node* p,Node* q){
          if(!p && !q ){
            return true;
        }
        if(p && q){
        return p->data==q->data && solve(p->left,q->right) && solve(p->right,q->left);
            
        }
        return false;
    }
    bool isSymmetric(Node* root) {
        // code here
        if(root==NULL){
            return true;
        }
        return solve(root->left,root->right);
        
    }
};