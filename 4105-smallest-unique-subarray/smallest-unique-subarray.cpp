class Solution {
public:
    // hash fn
    const long long mod = 1e9 + 7;
    const long long base = 37;
    bool check(vector<int>& nums, int len) {
        unordered_map<long long, int> m;
        int n = nums.size();
        long long old_hash = 0;
        for (int i = 0; i < len; i++) {
            old_hash = (old_hash * base + nums[i]) % mod;
        }
        m[old_hash]++;
        long long power = 1;
        for (int i = 1; i < len; i++) {
            power = (power * base) % mod;
        }
        for (int i = len; i < n; i++) {
            long long outgoing = nums[i - len];
            long long incoming = nums[i];
            long long new_hash =
                (((old_hash - outgoing * power % mod + mod) * base) +
                 incoming) %    
                mod;

            m[new_hash]++;
            old_hash = new_hash;
        }

        for (auto it : m) {
            if (it.second == 1)
                return true;
        }
        return false;
    }
    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        int l = 1;
        int r = n;
        int ans = INT_MAX;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (check(nums, mid)) {
                ans = min(mid, ans);
                r = mid - 1;
            } else
                l = mid + 1;
        }
        return ans;
    }
};