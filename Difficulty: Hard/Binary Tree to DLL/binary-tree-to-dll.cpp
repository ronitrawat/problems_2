class Solution {
public:

    Node* prev = NULL;

    Node* head = NULL;

    void solve(Node* root){

        if(root == NULL){
            return;
        }

        solve(root->left);

        
        if(prev == NULL){

            head = root;
        }

        else{

            prev->right = root;

            root->left = prev;
        }

        prev = root;

        solve(root->right);
    }

    Node * bToDLL(Node *root) {

        solve(root);

        
        if(prev){
            prev->right = NULL;
        }

        return head;
    }
};