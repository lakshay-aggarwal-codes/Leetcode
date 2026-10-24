class Solution {
public:
    int mergeStones(vector<int>& stones, int k) {
        int n = stones.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, INT_MAX));
        if (n == 1 && k == 1) {
            return 0;
        }
        if (k == 1 && n > 1) {
            return -1;
        }
        for (int i = 0; i < n; i++) {
            dp[i][i] = 0;
        }
        int ans = INT_MAX;
        if ((n - 1) % (k - 1) != 0) {
            return -1;
        }
        vector<int> prefix(n + 1);
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + stones[i];
        }

        for (int len = 2; len <= n; len++) {
            for (int i = 0; i + len <= n; i++) {
                int j = i + len - 1;

                for (int m = i; m < j; m += k - 1) {
                    if (dp[i][m] != INT_MAX && dp[m + 1][j] != INT_MAX)
                        dp[i][j] = min(dp[i][m] + dp[m + 1][j], dp[i][j]);
                }

                if ((j - i) % (k - 1) == 0 && dp[i][j] != INT_MAX) {
                    dp[i][j] += prefix[j + 1] - prefix[i];
                }
            }
        }
        return dp[0][n - 1];
    }
};
