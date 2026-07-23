class Solution {
public:
    void solve(vector<int>& nums, vector<int>& curr, vector<vector<int>>& ans) {
        int n = nums.size();
        unordered_set<int> used;
        if (n == 0) {
            ans.push_back(curr);
            return;
        }
        for (int i = 0; i < n; i++) {
            int x = nums[i];
            if (used.count(x))
                continue;
            used.insert(x);
            vector<int>nextNums;
            for(int j  =0 ;j< n;j++){
                if(j!=i) nextNums.push_back(nums[j]);
            }
            curr.push_back(x);
            solve(nextNums, curr, ans);
            curr.pop_back();
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        solve(nums,curr,ans);
        return ans;
    }
};