class Solution {
  public:
    bool isSubSeq(string& s1, string& s2) {
        // code here
        //  int n=s1.length();
        // int m=s2.length();
        
        // vector<vector<int>> dp(n+1,vector<int>(m+1));
        
        // for(int i=0;i<=n;i++){
        //     for(int j=0;j<=m;j++){
        //       if(i==0 || j==0){
                   
        //       dp[i][j]=0;
        //     }}
        // }
        
        // for(int i=1;i<=n;i++){
        //     for(int j=1;j<=m;j++){
        //         if(s1[i-1]==s2[j-1]){
        //             dp[i][j]=1+dp[i-1][j-1];
        //         }
        //         else{
        //             dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        //         }
        //     }
        // }
        // if(n==dp[n][m]){
        //     return true;
        // }
        // return false;
      
        int i = 0, j = 0;

        while (i < s1.length() && j < s2.length()) {
            if (s1[i] == s2[j])
                i++;
            j++;
        }

        return i == s1.length();
   
    }
};