class Solution {
  public:
    void rearrangeQueue(queue<int> &q) {
        // code here
        queue<int> q1;
        int size=q.size();
        size=size/2;
        while(size--){
            int ele=q.front();
            q.pop();
            q1.push(ele);
        }
        size=q.size();
        while(size--){
            int ele1=q1.front();
            q1.push(ele1);
            q1.pop();
            
            int ele2=q.front();
            q1.push(ele2);
            q.pop();
            
        }
        q=q1;
    }
};