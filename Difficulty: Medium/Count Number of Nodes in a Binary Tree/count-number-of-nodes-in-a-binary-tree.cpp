// User function Template for C++

class Solution {
  public:
    int countNodes(Node* root) {
        // Write your code here
        queue<Node*> q;
        if(!root){
          return 0;
        }
        int count=0;
        q.push(root);
        while(!q.empty()){
        int s=q.size();
        count=count+s;
        while(s--){
            Node* node=q.front();
            q.pop();
            if(node->left){
            q.push(node->left);
            }
            if(node->right){
                q.push(node->right);
        }
        }
           
        }
        return count;
    }
};