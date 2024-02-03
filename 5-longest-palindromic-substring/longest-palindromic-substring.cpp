class Solution {
public:
    string longestPalindrome(string s) {
        int ms = 0;
        int ml = 1;
        for (int i = 0; i < s.size() - 1; i++) {
            middleOut(s, i, i, ms, ml);     // odd
            middleOut(s, i, i + 1, ms, ml); // even
        }

        return s.substr(ms, ml);
    }

    void middleOut(string s, int i, int j, int& ms, int& ml) {
        while (i >= 0 && j <= s.size() - 1 && s[i] == s[j]) {
            i--;
            j++;
        }
        if (j - i - 1 > ml) {
            ms = i + 1;
            ml = j - i + -1;
        }
    }
};