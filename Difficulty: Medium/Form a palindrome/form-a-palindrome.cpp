class Solution {
  public:
  
    string rev(string s){
        int j=s.length()-1;
        int i=0;
        while(i<j){
            swap(s[i],s[j]);
            i++;
            j--;
        }
        return s;
    }
    
    int findMinInsertions(string &s) {
        // code here
         string s2=rev(s);
          int n=s.length();
        int m=s2.length();
        
        vector<vector<int>> dp(n+1,vector<int>(m+1));
        
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
               if(i==0 || j==0){
                   
               dp[i][j]=0;
            }}
        }
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==s2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        
        return s.length()-dp[n][m];
    }
};