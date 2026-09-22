class Solution {
  public:
    vector<vector<int>> geeksAndWells(vector<vector<char>> &mat) {
        // code here
        int r=mat.size();
        int c=mat[0].size();
        vector<vector<int>> result(r,vector<int>(c,0));
        
        queue<pair<int,int>> q;
        
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(mat[i][j]=='W'){
                    q.push({i,j});
                    mat[i][j]='X';
                }
            }
        }
        
        int dx[4]={-1,0,0,1};
        int dy[4]={0,1,-1,0};
        int counter=1;
        while(!q.empty()){
            int s=q.size();
            int temp=0;
            while(s--){
                auto f=q.front();
                q.pop();
                
                for(int k=0;k<4;k++){
                    int ii=f.first+dx[k];
                    int jj=f.second+dy[k];
                    
                    if(ii>=0 && jj>=0 && ii<r &&jj<c &&(mat[ii][jj]=='H' || mat[ii][jj]=='.')){
                       if(mat[ii][jj]=='H'){
                          result[ii][jj]=2*counter;
                          
                    }
                    mat[ii][jj]='X';
                    q.push({ii,jj});
                    
                        
                    }
                    
                }
                
            }
            counter++;
        }
        
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(mat[i][j]=='H'){
                    result[i][j]=-1;
                }
            }
        }
        return result;
    }
};