class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
 
        queue<pair<int, int>> q;
        vector<vector<int>> dist(n, vector<int>(m, -1));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0) {
                    q.push({i, j});
                    dist[i][j] = 0;
                }
            }
        }

        while (!q.empty()) {
            auto curr = q.front();
            q.pop();
            int r = curr.first;
            int c = curr.second;

            vector<int> dr = {-1, 1, 0, 0};
            vector<int> dc = {0, 0, -1, 1};

            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i]; 

                if (nr >= 0 && nr < n && nc >= 0 && nc < m) {
                     
                    if(dist[nr][nc] == -1){
                        dist[nr][nc] = dist[r][c] + 1;
                        q.push({nr,nc});
                    }

                }
            }
        }
        return dist;
    }
};