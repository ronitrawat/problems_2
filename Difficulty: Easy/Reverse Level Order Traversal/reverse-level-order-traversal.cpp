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
vector<vector<int>> ans;
    
    void level(Node* root){
        queue<Node*> q;
        if(root==NULL)
        {
            return ;
        }
        q.push(root);
        
        vector<int> a;
        while(!q.empty()){
            int k=q.size();
            for(int i=1;i<=k;i++){
            Node* ele=q.front();
            q.pop();
            a.push_back(ele->data);
                if(ele->left!=NULL){
                q.push(ele->left);}
                if(ele->right!=NULL){
                q.push(ele->right);}

            }
            ans.push_back(a);
            a.clear();
            
           
        }
    }
class Solution {
  public:
    vector<int> reverseLevelOrder(Node *root) {
        // code here
        ans.clear();
        level(root);
        
        reverse(ans.begin(),ans.end());
        vector<int> a;
        for(int i=0;i<ans.size();i++){
            int s=ans[i].size();
            for(int j=0;j<s;j++){
                a.push_back(ans[i][j]);
            }
        }
        return a;
        
    }
};