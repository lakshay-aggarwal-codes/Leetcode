class Solution {
public:
    void solve(int idx, vector<int>& curr, vector<vector<int>>& ans,
               const vector<int>& nums) {
        if (idx == nums.size()) {
            ans.push_back(curr);
            return;
        }
        curr.push_back(nums[idx]);
        solve(idx + 1, curr, ans, nums);
        curr.pop_back();
        while(idx+1 <= nums.size() -1 && nums[idx] == nums[idx+1] ) idx++;
        solve(idx + 1, curr, ans, nums);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end()); 
        vector<vector<int>> ans;
        vector<int> curr;
        solve(0, curr, ans, nums);
        return ans;
    }
};