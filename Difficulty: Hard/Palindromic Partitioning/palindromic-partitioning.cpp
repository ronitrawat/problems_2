class Solution {
public:
    int palPartition(string &s) {

        int n = s.length();

        // Precompute palindrome table
        vector<vector<bool>> pal(n, vector<bool>(n, false));

        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {

                if (s[i] == s[j]) {

                    if (j - i <= 1)
                        pal[i][j] = true;
                    else
                        pal[i][j] = pal[i + 1][j - 1];
                }
            }
        }

        // dp[i] = minimum cuts needed for s[i...n-1]
        vector<int> dp(n + 1, 0);

        dp[n] = -1;

        for (int i = n - 1; i >= 0; i--) {

            int ans = INT_MAX;

            for (int j = i; j < n; j++) {

                if (pal[i][j]) {
                    ans = min(ans, 1 + dp[j + 1]);
                }
            }

            dp[i] = ans;
        }

        return dp[0];
    }
};