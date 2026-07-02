class Solution {
  public:
    bool equalPartition(vector<int>& arr) {
        // code here
        int sum=0;
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
        }
        if(sum%2!=0){
            return false;
        }
        else{
        sum=sum/2;}
        
        vector<vector<int>> dp(arr.size()+1,(vector<int>(sum+1)));
        for(int i=0;i<=arr.size();i++){
            for(int j=0;j<=sum;j++){
                if(i==0){
                    dp[i][j]=0;
                }
                if(j==0){
                    dp[i][j]=1;
                }
            }
        }
        for(int i=1;i<=arr.size();i++){
            for(int j=0;j<=sum;j++){
                if(arr[i-1]<=j){
                    dp[i][j]=dp[i-1][j-arr[i-1]] || dp[i-1][j];
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[arr.size()][sum];
    
    }
};