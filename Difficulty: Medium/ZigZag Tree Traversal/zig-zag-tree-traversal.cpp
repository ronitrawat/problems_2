/*
Definition for Node
class Node {
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
    vector<int> zigZagTraversal(Node* root) {
        // code here
         vector<vector<int>> ans;
     vector<int> a;
     
     queue<Node* > q;
     int count=1;
     q.push(root);

     while(!q.empty()){
        int s=q.size();
        while(s--){
            Node* node=q.front();
            a.push_back(node->data);
            q.pop();
            if(node->left!=NULL){
            q.push(node->left);}
            if(node->right!=NULL){
            q.push(node->right);}

        }
        if(count%2==0){
            reverse(a.begin(),a.end());
        }
        count++;
        ans.push_back(a);
        a.clear();

     }
     for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            
         a.push_back(ans[i][j]);
     }   
    }
        return a;
    }
};