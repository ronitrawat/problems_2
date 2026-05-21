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
    int sum(Node* root){
        if(root==NULL){
            return 0;
        }
        if(!root->left && !root->right){
            int temp=root->data;
            root->data=0;
            return temp;
        }
        int left=sum(root->left);
        int right=sum(root->right);
        int temp=root->data;
        root->data=left+right;
        return root->data+temp;
    }
    void toSumTree(Node *root) {
        // code here
        sum(root);
    }
};