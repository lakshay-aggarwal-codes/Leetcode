class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();
        int m = (n - x + 1);
        multiset<int> left, right;
        vector<long long> cost(n - x + 1);
        long long sumLeft = 0;
        long long sumRight = 0;

        for (int i = 0; i < x; i++) {
            left.insert(nums[i]);
            sumLeft += nums[i];
        }

        while (left.size() > (x + 1) / 2) {
            auto it = prev(left.end());
            int val = *it;

            left.erase(it);
            sumLeft -= val;

            right.insert(val);
            sumRight += val;
        }

        int median = *prev(left.end());

        cost[0] = 1LL * median * left.size() - sumLeft + sumRight -
                  1LL * median * right.size();
        for (int i = 1; i < m; i++) {
            int out = nums[i - 1];
            int el = nums[i + x - 1];
            auto it = left.find(out);

            if (it != left.end()) {
                left.erase(it);
                sumLeft -= out;
            } else {
                right.erase(right.find(out));
                sumRight -= out;
            }

            if (left.empty() && right.empty()) {
                left.insert(el);
                sumLeft += el;
            }
            if (!left.empty() && el <= *prev(left.end())) {
                left.insert(el);
                sumLeft += el;
            } else {
                right.insert(el);
                sumRight += el;
            }

            while (left.size() > (x + 1) / 2) {
                auto it = prev(left.end());
                int val = *it;

                left.erase(it);
                sumLeft -= val;

                right.insert(val);
                sumRight += val;
            }

            while (left.size() < (x + 1) / 2) {
                auto it = right.begin();
                int val = *it;

                right.erase(it);
                sumRight -= val;

                left.insert(val);
                sumLeft += val;
            }

            int median = *prev(left.end());
            cost[i] = 1LL * median * left.size() - sumLeft + sumRight -
                      1LL * median * right.size();
        }

        const long long INF = LLONG_MAX / 4;
        vector<vector<long long>> dp(n + 1, vector<long long>(k + 1, INF));
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 0;
        }
        for (int i = m - 1; i >= 0; i--) {
            for (int j = 1; j <= k; j++) {
                dp[i][j] = dp[i + 1][j];
                if (dp[i + x][j - 1] != INF)
                    dp[i][j] = min(dp[i][j], cost[i] + dp[i + x][j - 1]);
            }
        }
        return dp[0][k];
    }
};