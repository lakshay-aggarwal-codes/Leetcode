class Solution {
public:
 const int INF = 1e9;
    int minCost(int n, vector<int>& costs, vector<int>& dp) {
            if (n < 0)
    return INF;
        if (n == 0)
            return 0;
        
        if (dp[n] != -1)
            return dp[n];

        int c1 = costs[n-1] + 1 + minCost(n - 1, costs, dp);
        int c2 = costs[n-1] + 4 + minCost(n - 2, costs, dp);
        int c3 = costs[n-1] + 9 + minCost(n - 3, costs, dp);

        dp[n] = min(c1, min(c2, c3));

        return dp[n];
    }
    int climbStairs(int n, vector<int>& costs) {
        vector<int> dp(n + 1, -1);
        int ans = minCost(n, costs, dp);
        return ans;
    }
};