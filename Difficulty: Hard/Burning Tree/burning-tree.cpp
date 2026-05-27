class Solution {
  public:

    unordered_map<Node*,Node*> parent;

    
    void parentMapping(Node* root){

        queue<Node*> q;

        q.push(root);

        parent[root] = NULL;

        while(!q.empty()){

            Node* temp = q.front();
            q.pop();

            if(temp->left){
                

                parent[temp->left] = temp;

                q.push(temp->left);
            }

            if(temp->right){

                parent[temp->right] = temp;

                q.push(temp->right);
            }
        }
    }

    
    Node* find(Node* root,int target){

        if(root == NULL){
            return NULL;
        }

        if(root->data == target){
            return root;
        }

        Node* left =
            find(root->left,target);

        if(left){
            return left;
        }

        return find(root->right,target);
    }

    int minTime(Node* root, int target) {

        parentMapping(root);

        Node* tar = find(root,target);

        unordered_map<Node*,bool> visited;

        queue<pair<Node*,int>> q;

        q.push({tar,0});

        visited[tar] = true;

        int time = 0;

        while(!q.empty()){

            auto n = q.front();
            q.pop();

            Node* temp = n.first;
            int t = n.second;

            time = max(time,t);

            
            if(parent[temp] &&
               !visited[parent[temp]]){

                visited[parent[temp]] = true;

                q.push({parent[temp],t+1});
            }

            
            if(temp->left &&
               !visited[temp->left]){

                visited[temp->left] = true;

                q.push({temp->left,t+1});
            }

            
            if(temp->right &&
               !visited[temp->right]){

                visited[temp->right] = true;

                q.push({temp->right,t+1});
            }
        }

        return time;
    }
};