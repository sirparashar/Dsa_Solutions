class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        if(s.size()==1){
            return false;
        }
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                stk.push(s[i]);
            } else if (!stk.empty()) {
                char t = stk.top();
                stk.pop();
                cout << s[i] << t;
                if ((s[i] == ']' && t != '[') || (s[i] == '}' && t != '{') ||
                    (s[i] == ')' && t != '(')) {
                    cout << 'p';
                    return false;
                }
            }
            else{
                return false;
            }
        }
        return stk.empty();
    }
};