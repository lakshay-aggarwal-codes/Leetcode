class Solution {
public:
    int minMoves(vector<int>& nums) {
        int ans = 0;
        int mn = *min_element(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            ans += nums[i] - mn;
        }
        return ans;
    }
};