class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        int ans = INT_MAX;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        ans = min(ans, nums[n - 3] - nums[0]);
        ans = min(ans, nums[n - 2] - nums[1]);
        ans = min(ans, nums[n - 1] - nums[2]);

        return ans;
    }
};