class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        // code here
        stack<int> st;
        
        for(int i=0;i<mat.size();i++){
            st.push(i);
        }
        while(st.size()!=1){
            int a=st.top();
            st.pop();
            int b=st.top();
            st.pop();
            if(mat[a][b]==1){
                st.push(b);
            }
            else {
                st.push(a);
            }
            
        }
        int ans=st.top();
        for(int i=0;i<mat.size();i++){
           if(i==ans){
               continue;
           }
            else{
                if(mat[i][ans]!=1 || mat[ans][i]!=0){
                    return -1;
                }
            }
        }
        return ans;
        
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna