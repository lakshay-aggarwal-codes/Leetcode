class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        vector<int> free(n, 0);
        int ans = 0;
        vector<int> dp(budget + 1, 0);
        for (int i = 0; i < n; i++) {
            int freeCopy = 0;
            for (int j = 0; j < n; j++) {
                if (items[j][0] % items[i][0] == 0 && j != i) {
                    freeCopy++;
                }
            }
            free[i] = freeCopy;
        }

        for (int i = 0; i < n; i++) {
            int price = items[i][1];
            for (int b = budget; b >= price; b--) {
                dp[b] = max(dp[b], dp[b - price] + 1 + free[i]);
            }
        }
        int minPrice = INT_MAX;
        for (int i = 0; i < n; i++) {
            minPrice = min(minPrice, items[i][1]);
        }
        for (int b = 0; b <= budget; b++) {
            ans = max(ans, dp[b] + (budget - b) / minPrice);
        }
        return ans;
    }
};
