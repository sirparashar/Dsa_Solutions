class Solution {
public:
    char parseOR(string temp) {
        bool res = false;
        for (char c : temp) {

            if (c == 'f') {
                res = res || false;
            } else if (c == 't') {
                res = res || true;
            }
        }
        return res == false ? 'f' : 't';
    }
    char parseA(string temp) {
        bool res = true;
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
        bool res = temp == "f" ? false : true;

        for (char c : temp) {
            if (c == 'f') {
                res = !res;
            } else {
                res = !res;
            }
        }

        return res == 0 ? 'f' : 't';
    }
    bool parseBoolExpr(string exp) {

        stack<char> s;

        for (int i = 0; i < exp.size(); i++) {
            if (exp[i] == ')') {
                string temp = "";
                while (s.top() != '(') {
                  
                    temp += s.top();
                    s.pop();
                }
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
                    parse = parseN(temp);
                    s.pop();
                }
                s.push(parse);
            } else {
                s.push(exp[i]);
            }
        }
        if (s.top() == 'f') {
            return false;
        } else {
            return true;
        }
        return false;
    }
};