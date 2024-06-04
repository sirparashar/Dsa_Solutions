class Solution {
public:
    int longestPalindrome(string s) {

        unordered_set<char> m;

        int len = 0;

        for (auto c : s) {
            if (m.find(c) != m.end()) {
                len += 2;
                m.erase(c);
            } else {
                m.insert(c);
            }
        }

        if(!m.empty()){
            len+=1;
        }
        return len;
    }
};