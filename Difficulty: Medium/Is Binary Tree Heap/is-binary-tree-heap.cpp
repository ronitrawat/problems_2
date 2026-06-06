/*
class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    int countNode(Node* tree){
        if(tree==NULL){
            return 0;
        }
        return 1+countNode(tree->left)+countNode(tree->right);
    }
    
    bool isComplete(Node* tree,int n,int i){
        if(tree==NULL){
            return true;
        }
        if(i>=n){
            return false;
        }
            
        return isComplete(tree->left, n,2 * i+ 1)
            && isComplete(tree->right,n, 2 * i + 2);
    }
    
    
    bool isMaxHeap(Node* tree){
        if(tree==NULL){
            return true;
        }
        if(!tree->left && !tree->right){
            return true;
        }
        if(tree->right==NULL){
            return tree->data>=tree->left->data;
        }
        bool left=tree->data>tree->left->data;
        bool right=tree->data>tree->right->data;
        
        return left && right && isMaxHeap(tree->left) && isMaxHeap(tree->right);
    }
    bool isHeap(Node* tree) {
        // code here
        int count=countNode(tree);
        return isComplete(tree,count,0) && isMaxHeap(tree);
    }
};