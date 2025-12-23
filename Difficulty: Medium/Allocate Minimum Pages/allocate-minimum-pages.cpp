class Solution {
  public:
  bool check(vector<int>
  &a,int mid,int k){
      int count=1;
      int sum=0;
      
      for(int i=0;i<a.size();i++){
          
          if(a[i]>mid){
              return false;
          }
          else if(a[i]+sum>mid){
              count++;
              sum=a[i];
               if(count>k){
              return false;
          }
          }
          else{
              sum+=a[i];
             
          }
          
      }
      return true;
      
  }
  
    int findPages(vector<int> &arr, int k) {
        // code here
        
        
        int mi=*max_element(arr.begin(),arr.end());
        int ma=accumulate(arr.begin(),arr.end(),0);
        int low=mi;
        int high=ma;
        int ans=0;
        if(k>arr.size()){
            return -1;
        }
        while(low<=high){
            int mid=low+(high-low)/2;
            if(check(arr,mid,k)){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};