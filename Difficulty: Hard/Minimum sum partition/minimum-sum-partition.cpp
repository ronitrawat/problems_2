class Solution {
  public:
    int minDifference(vector<int>& arr) {
        // code here
        int sum=0;
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
        }
        
        
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
        int i=arr.size();
        int ans=0;
        for(int j=sum/2;j>=0;j--){
            if(dp[i][j]){
                ans =j;
                break;
            }
        }
        return sum-2*ans;
    
    }
};
