class Solution {
public:
    bool isPalindrome(int n) {
        string s = to_string(n);

        int i=0; int j=s.size()-1;
        while(i<=j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};