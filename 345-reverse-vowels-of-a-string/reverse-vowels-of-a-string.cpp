class Solution {
public:
    string reverseVowels(string s) {
        stack<char> v;
        string res="";
        for (auto ch : s) {
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
                ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U'){
                    v.push(ch);
                }
        }

        for (auto ch : s) {
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
                ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U'){
                    res+=v.top();
                    v.pop();
                }
                else{
                    res+=ch;
                }
        }

        return res;


    }
};