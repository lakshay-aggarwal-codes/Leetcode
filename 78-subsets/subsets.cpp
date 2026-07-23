class Solution {
public:
    void solve(int idx, vector<int>& curr, vector<vector<int>>& ans,
               vector<int>& nums) {
        int n = nums.size();
        if (idx == n) {
            ans.push_back(curr);
            return;
        }
        curr.push_back(nums[idx]);
        solve(idx + 1, curr, ans, nums);
        curr.pop_back();
        solve(idx + 1, curr, ans, nums);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;

        solve(0, curr, ans, nums);
        return ans;
    }
};