class Solution {
public:
    void solve(int idx, int k, int n, vector<int>& num, vector<int>& path,
               vector<vector<int>>& ans) {
        if (k == 0 && n == 0) {
            ans.push_back(path);
            return;
        }
        if (num[idx] > n)
            return;
        if (idx == num.size())
            return;
        if (k < 0 || n < 0)
            return;
        path.push_back(num[idx]);
        solve(idx + 1, k - 1, n - num[idx], num, path, ans);
        path.pop_back();
        solve(idx + 1, k, n,num,  path, ans);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> num;
        for (int i = 1; i < 10; i++) {
            num.push_back(i);
        }
        vector<int> path;
        vector<vector<int>> ans;
        solve(0, k, n, num, path, ans);
        return ans;
    }
};