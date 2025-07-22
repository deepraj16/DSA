class Solution {
  public:

    void dfs(vector<vector<int>>& grid, int i, int j, int n, int m) {
        if (i < 0 || j < 0 || i >= n || j >= m || grid[i][j] != 1) return;

        grid[i][j] = -1; // mark visited with -1

        int dx[4] = {0, 0, -1, 1};
        int dy[4] = {-1, 1, 0, 0};

        for (int k = 0; k < 4; ++k) {
            int ni = i + dx[k];
            int nj = j + dy[k];
            dfs(grid, ni, nj, n, m);
        }
    }

    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        vector<vector<int>> grid(n, vector<int>(m, 0));
        vector<int> ans;

        for (int op = 0; op < operators.size(); ++op) {
            int x = operators[op][0];
            int y = operators[op][1];

            if (grid[x][y] == 1) {

                ans.push_back(ans.empty() ? 0 : ans.back());
                continue;
            }

            grid[x][y] = 1; 

            int count = 0;
            vector<vector<int>> temp = grid; 
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    if (temp[i][j] == 1) {
                        dfs(temp, i, j, n, m);
                        count++;
                    }
                }
            }

            ans.push_back(count);
        }

        return ans;
    }
};
