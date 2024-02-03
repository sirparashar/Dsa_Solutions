class Solution {
public:\
  int ms = 0;
        int ml = 1;
    string longestPalindrome(string s) {
      
        for (int i = 0; i < s.size() - 1; i++) {
            middleOut(s, i, i);     // odd
            middleOut(s, i, i + 1); // even
        }

        return s.substr(ms, ml);
    }

    void middleOut(string s, int i, int j) {
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