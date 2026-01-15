class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        int n = mat.size();
        if (n == 0) return -1;
        if (n == 1) return 0;

        stack<int> s;
        for (int i = 0; i < n; i++) {
            s.push(i);
        }

        while (s.size() > 1) {
            int a = s.top(); s.pop();
            int b = s.top(); s.pop();

            if (mat[a][b] == 1)
                s.push(b);
            else
                s.push(a);
        }

        int celeb = s.top();

        
        for (int i = 0; i < n; i++) {
            if (i != celeb && mat[celeb][i] != 0)
                return -1;
        }

       
        for (int i = 0; i < n; i++) {
            if (i != celeb && mat[i][celeb] == 0)
                return -1;
        }

        return celeb;
    }
};
