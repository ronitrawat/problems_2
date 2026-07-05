class Solution {
  public:
    int minCoins(vector<int> &coins, int sum) {
        // code here
         vector<vector<int>> dp(coins.size()+1,vector<int>(sum+1));
         
     
         for(int j=0;j<=sum;j++){
             
                 dp[0][j]=INT_MAX-1;
             
         }
         for(int i=1;i<=coins.size();i++){
             
                 dp[i][0]=0;
             
         }
         for(int j=1;j<=sum;j++){
             if(j%coins[0]==0){
                 dp[1][j]=j/coins[0];
             }
             else{
                 dp[1][j]=INT_MAX-1;
             }
         }
     
     for(int i=2;i<=coins.size();i++){
         for(int j=1;j<=sum;j++){
             if(coins[i-1]<=j){
                 dp[i][j]=min(1+dp[i][j-coins[i-1]],dp[i-1][j]);
             }
             else{
                 dp[i][j]=dp[i-1][j];
             }
         }
     }
      if (dp[coins.size()][sum] == INT_MAX - 1)
            return -1;
     return dp[coins.size()][sum];
    
    }
};