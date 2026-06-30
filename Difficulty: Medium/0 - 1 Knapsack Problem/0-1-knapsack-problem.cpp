class Solution {
  public:
    int solve(vector<int>& wt,vector<int>& val,int w, int index,vector<vector<int>>& dp){
          if(index==wt.size()){
            return 0;
            
        }
        if(dp[w][index]!=-1){
            return dp[w][index];
        }
        
        int exclude=solve(wt,val,w,index+1,dp);
        int  include=0;
        if(wt[index]<=w){
            include=val[index]+solve(wt,val,w-wt[index],index+1,dp);
        }
        dp[w][index]= max(include,exclude);
        return dp[w][index];
    }
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        vector<vector<int>> dp(wt.size()+1,vector<int>(W+1,-1));
        
        for(int i=0;i<dp.size();i++){
            for(int j=0;j<dp[0].size();j++){
                 if(i==0 || j==0){
                     dp[i][j]=0;
                    
                 }
            }
        }
        for(int i=1;i<dp.size();i++){
            for(int j=1;j<dp[0].size();j++){
                 if(wt[i-1]<=j){
                     dp[i][j]=max(val[i-1]+dp[i-1][j-wt[i-1]],dp[i-1][j]);
                    
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[wt.size()][W];
      
    }
};