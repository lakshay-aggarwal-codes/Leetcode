class Solution {
public:
    void solve(int idx, vector<int>& candidates, int target, vector<int>& path,
               vector<vector<int>>& ans) {
        int n = candidates.size();
        if (target == 0) {
            ans.push_back(path);
            return;
        }
        if (idx == n || target < 0)
            return;

        path.push_back(candidates[idx]);
        solve(idx, candidates, target - candidates[idx], path, ans);
        path.pop_back();

        solve(idx + 1, candidates, target, path, ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> path;
        vector<vector<int>> ans;
        solve(0, candidates, target, path, ans);

        return ans;
    }
};