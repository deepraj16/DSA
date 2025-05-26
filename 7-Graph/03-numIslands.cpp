class Solution {
public:
    bool is_safe(int f, int l, vector<vector<char>>& grid, vector<vector<bool>>& visited, int m, int n) {
        return f >= 0 && l >= 0 && f < m && l < n && !visited[f][l] && grid[f][l] == '1';
    }

    void BFS(vector<vector<char>>& grid, vector<vector<bool>>& visited, int i, int j, int n, int m) {
        visited[i][j] = true;
        queue<pair<int, int>> q;
        q.push({i, j});

        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, 1, 0, -1};

        while (!q.empty()) {
            auto [f, l] = q.front(); q.pop();
            for (int k = 0; k < 4; ++k) {
                int ni = f + dx[k], nj = l + dy[k];
                if (is_safe(ni, nj, grid, visited, n, m)) {
                    visited[ni][nj] = true;
                    q.push({ni, nj});
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        vector<vector<bool>> visited(n, vector<bool>(m, false));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!visited[i][j] && grid[i][j] == '1') {
                    BFS(grid, visited, i, j, n, m);
                    count++;
                }
            }
        }
        return count;
    }
};
