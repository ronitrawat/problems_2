class Solution {
  public:


    bool dfs(int node,vector<vector<int>> &graph,vector<int> &visited,int parent){
        visited[node]=1;
        
        for(int neigh:graph[node]){
            if(!visited[neigh] ){
                bool ans=dfs(neigh,graph,visited,node);
                
                if(ans){
                    return true;
                }
            }
            else if(visited[neigh] && neigh!=parent){
                return true;
            }
        }
        return false;
    }
  
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>> graph(V);
        vector<int> visited(V,0);
      
        
        for(auto it: edges){
            int a=it[0];
            int b=it[1];
            
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        
        for(int i=0;i<V;i++){
          if(!visited[i]){
              bool ans=dfs(i,graph,visited,-1);
              if(ans){
                  return true;
              }
          }  
        }
        return false;
    }
};