class Solution {
  public:
    vector<int> findLeastGreater(vector<int>& arr) {
        
        set<int> s;
        int n= arr.size();
        
        
        vector<int> ans(n);
        
        for(int i = n - 1; i >= 0; i--) {
            
            auto it = s.upper_bound(arr[i]);
            
            if(it == s.end()) {
                ans[i] = -1;
            }
            else {
                ans[i] = *it;
            }
            
            s.insert(arr[i]);
        }
        
        return ans;
    }
};