class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        if (grid[0][0] + 1 < grid[1][0] && grid[0][0] + 1 < grid[0][1]) {
            return -1;
        }

        vector<vector<bool>> vis(m, vector<bool>(n, false));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>
            pq;

        vector<int> dir = {-1, 0, 1, 0, -1};

        pq.push({0, 0, 0});

        while (!pq.empty()) {
            auto cur = pq.top();
            pq.pop();
            int t = cur[0];
            int r = cur[1];
            int c = cur[2];

            if (vis[r][c]) {
                continue;
            }
            if (c == n - 1 && r == m - 1) {
                return t;
            }
            vis[r][c] = true;

            for (int i = 0; i < 4; i++) {
                int nr = r + dir[i];
                int nc = c + dir[i + 1];

                int newt = 0;
                if (nr >= 0 && nc >= 0 && nc < n && nr < m) {
                    if (grid[nr][nc] > t+1) {
                        newt = (grid[nr][nc]-t) % 2 ? grid[nr][nc] 
                                                : grid[nr][nc]+1 ;
                    }
                    pq.push({max(newt,t+1), nr, nc});
                }
            }
        }
        return -1;
    }
};