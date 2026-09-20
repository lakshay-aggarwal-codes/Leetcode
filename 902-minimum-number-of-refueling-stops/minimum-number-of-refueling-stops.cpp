class Solution {
public:
    void solve(vector<vector<int>>& stations, vector<long long>& dp) {
        int n = stations.size();
        for (int i = 0; i < n; i++) {
            for (int k = i; k >=0; k--) {
                if (dp[k] >= stations[i][0]) {
                    dp[k+1] = max(dp[k + 1], stations[i][1] + dp[k]);
                }
            }
        }
    }
    int minRefuelStops(int target, int startFuel,
                       vector<vector<int>>& stations) {
        int n = stations.size();
        
        vector<long long> dp(n + 1, 0);
        dp[0] = startFuel;
        solve(stations, dp);
        for (int i = 0; i<n+1; i++) {
            if (dp[i] >= target) {
                return i;
            }
        }
        return -1;
    }
};