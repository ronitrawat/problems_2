class Solution {
  public:
    int count(vector<int>& coins, int sum) {
        // code here.
        vector<vector<int>> dp(coins.size()+1,vector<int>(sum+1));
     dp[0][0]=1;
     
         for(int j=1;j<=sum;j++){
             
                 dp[0][j]=0;
             
         }
         for(int i=1;i<=coins.size();i++){
             
                 dp[i][0]=1;
             
         }
     
     for(int i=1;i<=coins.size();i++){
         for(int j=0;j<=sum;j++){
             if(coins[i-1]<=j){
                 dp[i][j]=dp[i][j-coins[i-1]]+dp[i-1][j];
             }
             else{
                 dp[i][j]=dp[i-1][j];
             }
         }
     }
     return dp[coins.size()][sum];
    }
};