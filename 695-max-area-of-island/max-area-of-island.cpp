class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int marea = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    int area = explore(grid, i, j, m, n);
                    marea = max(area, marea);
                }
            }
        }
        return marea;
    }

    int explore(vector<vector<int>>& grid, int r, int c, int m, int n) {
        if (r < 0 || r >= m || c < 0 || c >= n || grid[r][c] == 0) {
            return 0;
        }

        grid[r][c] = 0;

        return 1 + explore(grid, r + 1, c, m, n) +
                   explore(grid, r, c + 1, m, n) +
                   explore(grid, r - 1, c, m, n) +
                   explore(grid, r, c - 1, m, n);
    }
};