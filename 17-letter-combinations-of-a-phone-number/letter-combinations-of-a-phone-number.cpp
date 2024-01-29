class Solution {
public:
    vector<string> letterCombinations(string digits) {
          if (digits.empty()) {
            return {};
        }
        vector<string> res;
        string par="";
         unordered_map<char, string> m = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };
         getcom(digits,0,m,par, res);
         return res;
    }

    void getcom(string digits, int start,  unordered_map<char, string> m,string &par, vector<string> &res){
       
       if (start == digits.size()){
           res.push_back(par);
           return;
       }
       string str = m[digits[start]];

       for (int i=0; i<str.size(); i++){
           
        par.push_back(str[i]);
        getcom(digits,start+1,m,par, res);
        par.pop_back();
       }

    }
};