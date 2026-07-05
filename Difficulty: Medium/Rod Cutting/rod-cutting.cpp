class Solution {
  public:
    int cutRod(vector<int> &price) {
        // code here
     vector<vector<int>> dp(price.size()+1,vector<int>(price.size()+1));
     
     for(int i=0;i<=price.size();i++){
         for(int j=0;j<=price.size();j++){
             if(i==0 || j==0){
                 dp[i][j]=0;
             }
         }
     }
     for(int i=1;i<=price.size();i++){
         for(int j=1;j<=price.size();j++){
             if(i<=j){
                 dp[i][j]=max(price[i-1]+dp[i][j-i],dp[i-1][j]);
             }
             else{
                 dp[i][j]=dp[i-1][j];
             }
         }
     }
     return dp[price.size()][price.size()];
     
    }
};