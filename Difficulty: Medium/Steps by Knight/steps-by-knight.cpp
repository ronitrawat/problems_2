class Solution {
public:
    int minStepToReachTarget(vector<int>& knightPos, vector<int>& targetPos, int n) {
        
        vector<vector<bool>> vis(n+1, vector<bool>(n+1, false));
        
        queue<pair<pair<int,int>, int>> q;
        
        q.push({{knightPos[0], knightPos[1]}, 0});
        vis[knightPos[0]][knightPos[1]] = true;
        
        int dx[8] = {-2,-2,2,2,1,1,-1,-1};
        int dy[8] = {1,-1,1,-1,2,-2,2,-2};
        
        while(!q.empty()){
            auto front = q.front();
            q.pop();
            
            int x = front.first.first;
            int y = front.first.second;
            int steps = front.second;
            
            // ✅ target reached
            if(x == targetPos[0] && y == targetPos[1])
                return steps;
            
            // explore all 8 moves
            for(int i=0;i<8;i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                
                if(nx>=1 && nx<=n && ny>=1 && ny<=n && !vis[nx][ny]){
                    vis[nx][ny] = true;
                    q.push({{nx, ny}, steps+1});
                }
            }
        }
        
        return -1; // should not happen
    }
};