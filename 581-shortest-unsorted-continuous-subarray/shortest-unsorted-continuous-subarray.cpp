class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        int left = 0;
        int maxN = nums[0];
        int minN = nums[n - 1];
        int right = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < maxN) {
                right = i;
            }
            maxN = max(maxN, nums[i]);
        }

        for (int i = nums.size() - 2; i >= 0; i--) {
            if (nums[i] > minN) {
                left = i;
            }
            minN = min(minN, nums[i]);
        }
        if (left == 0 && right == 0)
            return 0;
        ans = right - left + 1;
        return ans;
    }
};
