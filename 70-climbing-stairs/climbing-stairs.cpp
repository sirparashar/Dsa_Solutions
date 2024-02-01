class Solution {
public:
    int count = 0;
    unordered_map<int, int> m;
    int climbStairs(int n) {
        if (n == 0) {
            return 1;
        }
        if (n < 0) {
            return 0;
        }

        if (m.find(n) != m.end()) {
            return m[n];
        }

        m[n] = climbStairs(n - 1) + climbStairs(n - 2);
        return m[n];
    }
};