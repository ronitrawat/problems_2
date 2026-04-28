class Solution {
  public:
    string firstNonRepeating(string &s) {
        // code here
        deque<int> q;
        string ans="";
        unordered_map<char,int> a;
        
        for(char c: s){
            a[c]++;
            q.push_back(c);
            
            //ans
            while(!q.empty()){
                char d=q.front();
                if(a[d]==1){
                    
                    ans+=d;
                    break;
                    
                }
                else{
                    q.pop_front();
                }
                
            }
            if(q.empty()){
                    ans+='#';
                }
            
        }
        return ans;
    }
};