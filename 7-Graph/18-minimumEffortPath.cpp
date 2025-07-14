class Solution {
public:
    bool is_safe(int x, int y, int n, int m) {
        return x >= 0 && y >= 0 && x < n && y < m;
    }

    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> effort(n, vector<int>(m, INT_MAX));
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;

        pq.push({0, 0, 0}); // (effort, row, col)
        effort[0][0] = 0;

        int dx[4] = {0, 0, -1, 1};
        int dy[4] = {-1, 1, 0, 0};

        while (!pq.empty()) {
            auto [currEffort, x, y] = pq.top();
            pq.pop();

            if (x == n - 1 && y == m - 1) return currEffort;

            for (int i = 0; i < 4; ++i) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (is_safe(nx, ny, n, m)) {
                    int diff = abs(heights[x][y] - heights[nx][ny]);
                    int maxEffort = max(currEffort, diff);

                    if (effort[nx][ny] > maxEffort) {
                        effort[nx][ny] = maxEffort;
                        pq.push({maxEffort, nx, ny});
                    }
                }
            }
        }

        return 0; 
    }
};
