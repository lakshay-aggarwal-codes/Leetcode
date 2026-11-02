class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int ans  = 0;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int mn = nums[n/2];
        for(int x : nums){
            ans += abs(x - mn);
        }
        return ans;
    }
};