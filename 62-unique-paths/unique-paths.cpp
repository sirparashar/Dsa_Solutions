class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> grid(m, vector<int>(n, 0));

        // Set the last row and last column to 1
        for (int i = 0; i < m; i++) {
            grid[i][n - 1] = 1;
        }
        for (int i = 0; i < n; i++) {
            grid[m - 1][i] = 1;
        }

        // Fill in the rest of the grid
        for (int i = m - 2; i >= 0; i--) {
            for (int j = n - 2; j >= 0; j--) {
                grid[i][j] = grid[i + 1][j] + grid[i][j + 1];
            }
        }

        return grid[0][0];
    }
};
