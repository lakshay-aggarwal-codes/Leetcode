class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1)
            return 0;

        int left = 0;
        int n = nums.size();
        int ans = 0;
        int pro = 1;

        for (int right = 0; right < n; right++) {
            pro *= nums[right];
            while (pro >= k) {
                pro /= nums[left];
                left++;
            }
            ans += right - left + 1;
        }
        return ans;
    }
};