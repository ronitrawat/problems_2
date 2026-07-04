class Solution {
  public:
    int totalWays(vector<int>& arr, int target) {
        //  code here
         int sum=0;
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
        }
        if(target>sum){
            return 0;
        }
        if((sum-target)%2!=0){
            return 0;
        }
        sum=(sum-target)/2;
        
        vector<vector<int>> dp(arr.size()+1,(vector<int>(sum+1)));
        dp[0][0]=1;
        for(int j=1;j<=sum;j++){
            
                
                    dp[0][j]=0;
                }
            
        
        for(int i=1;i<=arr.size();i++){
            for(int j=0;j<=sum;j++){
                if(arr[i-1]<=j){
                    dp[i][j]=dp[i-1][j-arr[i-1]] + dp[i-1][j];
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[arr.size()][sum];
    }
};