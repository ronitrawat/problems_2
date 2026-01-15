class Solution {
  public:
    int countMinReversals(string s) {
        // code here
        int ans=0;
        if(s.size()&1){
            return -1;
        }
        stack<int> st;
        for(char c :s){
            if(c=='{'){
                st.push(c);
                
            }
            else{
                if(!st.empty() && st.top()=='{') {
                st.pop();
                }
                else{
                    st.push(c);
                }
            }
        }
        while(!st.empty()){
           char a =st.top();
           st.pop();
           char b=st.top();
           st.pop();
           if(a==b){
               ans+=1;
           }
           else{
               ans+=2;
           }
        }
        return ans;
    }
};