class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        int W = amount;
        vector<vector<long long>> dp(n + 1, vector<long long>(W + 1, 0));
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= W; j++) {
                int x = coins[i-1];
                if (x <= j) {
                   long long way= dp[i - 1][j] + dp[i][j - x];
                   dp[i][j] = min(way, (long long)INT_MAX);
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[n][W];
    }
};