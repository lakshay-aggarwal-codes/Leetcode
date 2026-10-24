class Solution {
public:
    int solve(int k, int n, vector<vector<int>>& dp) {
        if (n == 1)
            return 1;
        if (n == 0)
            return 0;
        if (k == 1) {
            return n;
        }
        if (dp[k][n] != -1)
            return dp[k][n];

        int ans = INT_MAX;
        int low = 1;
        int high = n;
        while (low <= high) {
            int x = low + (high - low) / 2;

            int cost1 = solve(k - 1, x - 1, dp);
            int cost2 = solve(k, n - x, dp);
            int curr = max(cost1, cost2);
            ans = min(1 + curr, ans);
            if (cost1 < cost2) {
                low = x + 1;
            } else
                high = x - 1;
        }

        return dp[k][n] = ans;
    }
    int superEggDrop(int k, int n) {
        vector<vector<int>> dp(k + 1, vector<int>(n + 1, -1));
        return solve(k, n, dp);
    }
};