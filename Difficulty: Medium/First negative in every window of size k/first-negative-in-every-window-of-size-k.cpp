class Solution {
  public:
    vector<int> firstNegInt(vector<int>& arr, int k) {
        // write code here
        int size=arr.size();
        deque <int> q;
        vector<int> ans;
        for (int i=0;i<k;i++){
           if(arr[i]<0){
               q.push_back(i);
           }
        }
        if(!q.empty()){
            int index=q.front();
            ans.push_back(arr[index]);
        }
        else{
            ans.push_back(0);
        }
        
        for(int i=k;i<size;i++){
            
            if(!q.empty()){
                
                int index=q.front();
                if(i-index>=k){
                    q.pop_front();
                }
                
            }
            
            if(arr[i]<0){
                q.push_back(i);
            }
            
            if(!q.empty()){
                int index=q.front();
                ans.push_back(arr[index]);
            }
            else{
                ans.push_back(0);
            }
            
        }
        return ans;
    }
};