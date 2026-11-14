class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int ans = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            int sum = 0;
            for (int j = i; j < nums.size() && j - i + 1 <= r; j++) {
                sum += nums[j];
                if (sum > 0 && j - i + 1 >= l)
                    ans = min(ans, sum);
            }
        }
        return ans != INT_MAX ? ans : -1;
    }
};