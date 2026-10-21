class Solution {
public:
    const int mod = 1e9 + 7;
    int profitableSchemes(int n, int minProfit, vector<int>& group,
                          vector<int>& profit) {
        int W = minProfit;
        vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));
        dp[0][0] = 1;
        for (int i = 0; i < group.size(); i++) {
            int x = group[i];
            int y = profit[i];
            for (int p = n - x; p >= 0; p--) {
                for (int j = 0; j <= W; j++) {
                    int g = min(W, j + y);
                    dp[p + x][g] = (dp[p + x][g] + dp[p][j]) % mod;
                }
            }
        }
        int ans = 0;
        for (int i = 0; i <= n; i++) {
            ans = (ans + dp[i][W]) % mod;
        }
        return ans;
    }
};