class Solution {
public:
    bool canChange(string start, string target) {
        int n = target.size();
        int i = 0;
        int j = 0;

        while (i < n && j < n) {
            // Skip underscores in both strings
            while (i < n && start[i] == '_') {
                i++;
            }
            while (j < n && target[j] == '_') {
                j++;
            }

            // Check bounds after skipping underscores
            if (i == n || j == n) {
                return i == n && j == n; // Both must reach the end
            }

            // Ensure characters match
            if (start[i] != target[j]) {
                return false;
            }

            // Check movement constraints
            if (start[i] == 'L' && j > i) { // 'L' can only move left
                return false;
            }
            if (start[i] == 'R' && i > j) { // 'R' can only move right
                return false;
            }

            // Move to the next character
            i++;
            j++;
        }

        // Ensure no remaining characters in either string
        while (i < n && start[i] == '_') {
            i++;
        }
        while (j < n && target[j] == '_') {
            j++;
        }

        return i == n && j == n;
    }
};
