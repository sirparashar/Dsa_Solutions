

class Solution {
public:
    string decodeString(string s) {
        string res = "";
        stack<char> m;
        for (auto ch : s) {
            if (ch == ']') {
                string temp = "";
                while (!m.empty() && m.top() != '[') {
                    temp = m.top() + temp;
                    m.pop();
                }
                m.pop(); // Pop '['
                
                string mulStr = "";
                while (!m.empty() && isdigit(m.top())) {
                    mulStr = m.top() + mulStr;
                    m.pop();
                }
                int mul = stoi(mulStr);
                
                string decoded = "";
                for (int i = 0; i < mul; ++i) {
                    decoded += temp;
                }
                
                // Push the decoded string back to stack
                for (char c : decoded) {
                    m.push(c);
                }
            } else {
                m.push(ch);
            }
        }
        
        // Construct the result string from stack contents
        while (!m.empty()) {
            res = m.top() + res;
            m.pop();
        }
        
        return res;
    }
};

