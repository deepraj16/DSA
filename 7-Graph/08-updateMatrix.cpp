class Solution {
public:
    bool issafe(vector<vector<int>>& mat, vector<vector<int>>& visted, int i, int j, int n ,int m) {
        return (i >= 0 && j >= 0 && i < n && j < m && visted[i][j] == -1);
    }

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size(); 
        int m = mat[0].size(); 
        vector<vector<int>> visted(n, vector<int>(m, -1));
        queue<pair<int, pair<int, int>>> q;

        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0) {
                    visted[i][j] = 0;
                    q.push({0, {i, j}});
                }
            }
        }

        int dx[4] = {-1, 1, 0, 0}; 
        int dy[4] = {0, 0, -1, 1}; 

        while (!q.empty()) {
            auto [d, pos] = q.front(); 
            q.pop(); 
            int i = pos.first; 
            int j = pos.second;

            for (int k = 0; k < 4; k++) {
                int ni = i + dx[k];
                int nj = j + dy[k];
                if (issafe(mat, visted, ni, nj, n, m)) {
                    visted[ni][nj] = d + 1;
                    q.push({d + 1, {ni, nj}});
                }
            }
        }

        return visted;
    }
};
