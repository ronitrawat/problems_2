class Solution {
  public:
    vector<int> mergeArrays(vector<vector<int>> &mat) {

        priority_queue<
            pair<int,pair<int,int>>,
            vector<pair<int,pair<int,int>>>,
            greater<pair<int,pair<int,int>>>
        > pq;

        for(int i = 0; i < mat.size(); i++) {
            pq.push({mat[i][0], {i, 0}});
        }

        vector<int> ans;

        while(!pq.empty()) {

            auto temp = pq.top();
            pq.pop();

            int val = temp.first;
            int row = temp.second.first;
            int col = temp.second.second;

            ans.push_back(val);

            if(col + 1 < mat[row].size()) {
                pq.push({
                    mat[row][col + 1],
                    {row, col + 1}
                });
            }
        }

        return ans;
    }
};