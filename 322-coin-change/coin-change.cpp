class Solution {
public:
    int solve(vector<int>& coins, vector<int>& dp, int x) {
        if (x == 0)
            return 0;

        if (dp[x] != -1)
            return dp[x];

        int ans = INT_MAX;

        for (int coin : coins) {
            if (coin <= x) {
                int sub = solve(coins, dp, x - coin);

                if (sub != INT_MAX)
                    ans = min(ans, sub + 1);
            }
        }

        return dp[x] = ans;
    }

    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, -1);
        dp[0] = 0;

        int ans = solve(coins, dp, amount);

        return ans == INT_MAX ? -1 : ans;
    }
};