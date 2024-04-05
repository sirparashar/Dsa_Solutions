class Solution {
public:
    string makeGood(string s) {
        stack<char> m;

        for (int i = 0; i < s.size(); i++) {
            if (!m.empty() && abs(s[i] - m.top()) == 32) {
                m.pop();
            } else {
                m.push(s[i]);
            }
        }
        string res ;
        while (!m.empty()) {
            res = m.top() + res;
            m.pop();
        }
        return res;
    }
};