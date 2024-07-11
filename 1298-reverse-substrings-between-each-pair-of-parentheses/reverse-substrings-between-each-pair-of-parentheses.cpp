class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> stac;
        
        int i = 0;
        while (i < s.size()) {
            string res = "";
            if (s[i] == ')') {
                while (!stac.empty() && stac.top() != '(') {
                     res += stac.top();
                     stac.pop();
                }
               // if(!stac.empty()){
                    stac.pop();
               // }
                for(int j=0 ; j<res.size(); j++){
                    stac.push(res[j]);
                }
            }
            else{
                stac.push(s[i]);
                
            }
            i++;
        }

        string res = "";

        while(!stac.empty()){
            res = stac.top()+res;
            stac.pop();
        }
        return res;
    }
};