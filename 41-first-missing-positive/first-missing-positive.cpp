class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();

        int i = 0;
        while (i < n) {
            if (nums[i] > 0 && nums[i] <= n) {
                if (nums[i] == i + 1) {
                    i++;
                } else {
                    if (nums[nums[i] - 1] != nums[i]) {
                        swap(nums[i], nums[nums[i] - 1]);
                    }
                    else i++;
                }
            } else
                i++;
        }

        for (int i = 0; i < n; i++) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }
        return n + 1;
    }
};