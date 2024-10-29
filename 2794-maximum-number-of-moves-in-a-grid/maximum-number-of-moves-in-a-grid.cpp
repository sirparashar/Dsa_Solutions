class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));  // DP array for memoization

        int maxMoves = 0;
        for (int i = 0; i < m; i++) {
            maxMoves = max(maxMoves, dfs(i, 0, grid, dp));  // Start DFS from each cell in the first column
        }
        return maxMoves;
    }

private:
    int dfs(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp) {
        int m = grid.size(), n = grid[0].size();

        // If we reach the last column, no further moves possible
        if (j == n - 1) return 0;

        // If the result is already computed, return it
        if (dp[i][j] != -1) return dp[i][j];

        int maxPath = 0;
        // Move right, up-right, and down-right if conditions are met
        if (i > 0 && grid[i][j] < grid[i - 1][j + 1]) { // Move to (i-1, j+1)
            maxPath = max(maxPath, 1 + dfs(i - 1, j + 1, grid, dp));
        }
        if (grid[i][j] < grid[i][j + 1]) { // Move to (i, j+1)
            maxPath = max(maxPath, 1 + dfs(i, j + 1, grid, dp));
        }
        if (i < m - 1 && grid[i][j] < grid[i + 1][j + 1]) { // Move to (i+1, j+1)
            maxPath = max(maxPath, 1 + dfs(i + 1, j + 1, grid, dp));
        }

        dp[i][j] = maxPath;  // Store the computed result in the DP array
        return maxPath;
    }
};
