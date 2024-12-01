class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words,
                                         vector<int>& groups) {
        vector<string> res = {""};
        vector<string> cur;

        if (words.size() == 1) {
            return words;
        }

        int i = 0;
        int flag = -1;

        while (i < words.size()) {
            if (groups[i] != flag) {
                flag = groups[i];  
                cur.push_back(words[i]);
            }
            i++;
        }

        return cur;
    }
};