/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
  public:
    vector<int> diagonal(Node *root) {
        // code here
        vector<int> ans;
        queue<Node*> q;
        if(root){
            q.push(root);
            
        }
        while(!q.empty()){
            Node* n=q.front();
            q.pop();
           
            while(n){
                 ans.push_back(n->data);
               if(n->left){ q.push(n->left);}
                 n=n->right;
            }
       
            
        }
           return ans;
    }
};