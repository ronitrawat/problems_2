class Solution {
  public:
    deque<int> dq;
    
    void dfs(int node,vector<int> &visited,vector<vector<int>> &adj){
        visited[node]=1;
        
        for(int neigh: adj[node]){
            if(!visited[neigh]){
                dfs(neigh,visited,adj);
            }
        }
        dq.push_front(node);
    }
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>> adj(V);
        vector<int> visited(V,0);
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            
        }
        for(int i=0;i<V;i++){
            if(!visited[i]){
                dfs(i,visited,adj);
            }
            
        }
        vector<int> ans;
        for(int &x:dq){
            ans.push_back(x);
        }
        return ans;
    }
};