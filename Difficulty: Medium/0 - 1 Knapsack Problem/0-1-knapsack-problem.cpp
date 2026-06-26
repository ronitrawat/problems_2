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
        vector<vector<int>> dp(W+1,vector<int>(wt.size(),-1));
        return solve(wt,val,W,0,dp);
      
    }
};