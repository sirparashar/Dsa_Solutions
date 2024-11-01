class Solution {
public:
    string makeFancyString(string s) {
        int l = 0;
        int count = 1;
        string res = "";
        for (int i = 0; i <= s.size() - 1; i++) {
            if (s[i] == s[i + 1]) {
                count++;
            }
            else{
                //cout<<i;
                count=1;
            }
            if (count == 3) {
              //  cout<<count;
                count--;
                continue;
            }
            res += s[i];
        }

        return res;
    }
};