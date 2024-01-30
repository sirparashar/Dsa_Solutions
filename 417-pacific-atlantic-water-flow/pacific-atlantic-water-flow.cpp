class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        vector<vector<bool>> pac(m, vector<bool>(n));
        vector<vector<bool>> at(m, vector<bool>(n));

        for (int i = 0; i < m; i++) {
            getcell(heights, pac, i, 0, m, n);
            getcell(heights, at, i, n - 1, m, n);
        }

        for (int i = 0; i < n; i++) {
            getcell(heights, pac, 0, i, m, n);
            getcell(heights, at, m - 1, i, m, n);
        }

        vector<vector<int>> res;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pac[i][j] && at[i][j]) {
                    res.push_back({i, j});
                }
            }
        }
        return res;
    }

    void getcell(vector<vector<int>>& heights, vector<vector<bool>>& visited,
                 int i, int j, int m, int n) {
        visited[i][j] = true;

        if (i > 0 && !visited[i - 1][j] && heights[i - 1][j] >= heights[i][j]) {
            getcell(heights, visited, i - 1, j, m, n);
        }
        if (j > 0 && !visited[i][j - 1] && heights[i][j - 1] >= heights[i][j]) {
            getcell(heights, visited, i, j - 1, m, n);
        }
        if (i < m - 1 && !visited[i + 1][j] &&
            heights[i + 1][j] >= heights[i][j]) {
            getcell(heights, visited, i + 1, j, m, n);
        }
        if (j < n - 1 && !visited[i][j + 1] &&
            heights[i][j + 1] >= heights[i][j]) {
            getcell(heights, visited, i, j + 1, m, n);
        }
    }
};