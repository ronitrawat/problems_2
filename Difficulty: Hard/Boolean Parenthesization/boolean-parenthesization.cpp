class Solution {
  public:
    vector<vector<vector<int>>> dp;
    int solve(string &s,int i ,int j,bool isTrue){
        if(i>j){
            return 0;
        }
        if(i==j){
            if(isTrue){
                return s[i]=='T';
            }
            else{
                return s[i]=='F';
            }
        }
        if(dp[i][j][isTrue]!=-1){
            return dp[i][j][isTrue];
        }
        
        int ways=0;
        for(int k=i+1;k<j;k+=2){
            int LT=solve(s,i,k-1,true);
            int RT=solve(s,k+1,j,true);
            int LF=solve(s,i,k-1,false);
            int RF=solve(s,k+1,j,false);
            
            if(s[k]=='&'){
                if(isTrue){
                    ways+=LT*RT;
                }
                else{
                    ways+=LT*RF+LF*RT+LF*RF;
                }
            }
            if(s[k]=='|'){
                if(isTrue){
                    ways+=LT*RT+LT*RF+LF*RT;
                }
                else{
                    ways+=LF*RF;
                }
            }
            if(s[k]=='^'){
                if(isTrue){
                    ways+=LT*RF+LF*RT;
                }
                else{
                    ways+=LT*RT+LF*RF;
                }
            }
        }
        return dp[i][j][isTrue]=ways;
    }


    int countWays(string &s) {
        // code here
        int n = s.length();

        dp.assign(n,
                  vector<vector<int>>(n,
                  vector<int>(2, -1)));

        return solve(s, 0, n - 1, true);
        
    }
};