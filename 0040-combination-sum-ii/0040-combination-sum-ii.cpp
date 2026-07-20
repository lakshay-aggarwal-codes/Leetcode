class Solution {
public:
    void solve(int idx, vector<int>& candidates, int target, vector<int>& path,
               vector<vector<int>>& ans) {
        int n = candidates.size();
        if (target == 0) {
            ans.push_back(path);
            return;
        }
        if (target < 0 || idx == n)
            return;

        path.push_back(candidates[idx]);
        solve(idx + 1, candidates, target - candidates[idx], path, ans);
        path.pop_back();

        while(idx < n-1 && candidates[idx] == candidates[idx+1]){
            idx++;
        }
        solve(idx + 1, candidates, target, path, ans);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> path;
        vector<vector<int>> ans;
        sort(candidates.begin(), candidates.end());
        solve(0, candidates, target, path, ans);
        return ans;
    }
};