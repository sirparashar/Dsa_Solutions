class Solution {
public:
    char parseOR(string temp) {
        cout << 'o';
        bool res=false;
        //cout << temp;
        for (char c : temp) {
           
            if (c == 'f') {
                res = res || false;
            } else if (c == 't') {
                res = res || true;
            }
         //    cout<<res;
        }
        // cout<<res;
        return res == false ? 'f' : 't';
    }
    char parseA(string temp) {
        bool res=true;
        cout << 'a';
        for (char c : temp) {
            if (c == 'f') {
                res = res && false;
            } else {
                res = res && true;
            }
        }
        return res == false ? 'f' : 't';
    }

    char parseN(string temp) {
        cout << 'n';
        bool res = temp == "f" ? false : true;
        //  cout<<temp;
        // cout<<res;
        for (char c : temp) {
            if (c == 'f') {
                res = !res;
            } else {
                res = !res;
            }
        }
        //  cout<<res;
        return res == 0 ? 'f' : 't';
    }
    bool parseBoolExpr(string exp) {

        stack<char> s;

        for (int i = 0; i < exp.size(); i++) {
            if (exp[i] == ')') {
                string temp = "";
                while (s.top() != '(') {
                    // cout << s.top();
                    temp += s.top();
                    s.pop();
                }
                // cout<<temp;
                s.pop();
                char parse;
                if (s.top() == '|' && !s.empty()) {
                    parse = parseOR(temp);
                    s.pop();
                } else if (s.top() == '&' && !s.empty()) {
                    parse = parseA(temp);
                    s.pop();
                }

                else if (s.top() == '!' && !s.empty()) {
                    // cout<<temp;
                    parse = parseN(temp);
                    cout << parse;
                    s.pop();
                }
                // cout<<parse;
                s.push(parse);
                // cout<<s.top();
            } else {
                s.push(exp[i]);
            }
        }
        if (s.top() == 'f') {
            cout << s.top();
            return false;
        } else {
            return true;
        }
        return false;
    }
};