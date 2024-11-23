class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m = box.size();       // Original number of rows
        int n = box[0].size();    // Original number of columns

        // Initialize the rotated box with dimensions n x m
        vector<vector<char>> rotate(n, vector<char>(m, '.'));

        // Step 1: Rotate the box 90 degrees clockwise
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                rotate[j][m - 1 - i] = box[i][j];
            }
        }

        // Step 2: Simulate gravity in the rotated box
        for (int j = 0; j < m; j++) { // Iterate over each column in the rotated box
            int emptyRow = n - 1;     // Start from the bottom of the column
            for (int i = n - 1; i >= 0; i--) { // Move upward in the column
                if (rotate[i][j] == '*') {
                    // Hit an obstacle; reset the emptyRow pointer
                    emptyRow = i - 1;
                } else if (rotate[i][j] == '#') {
                    // Move the stone to the lowest available position
                    rotate[i][j] = '.';
                    rotate[emptyRow][j] = '#';
                    emptyRow--; // Update the emptyRow pointer
                }
            }
        }

        return rotate;
    }
};
