class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> arr;
        
            k %= m * n;
        vector<vector<int>> ans(n , vector<int>(m,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int index = i * m + j;
                int newIndex = (index + k) % (m * n);
                int row = newIndex / m;
                int col = newIndex % m;

                ans[row][col] = grid[i][j];
            }
        }
        return ans;
    }
};