class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i =0;
        int j=0;
        int count=0;
        while (i<t.size()){
            if(s[j]==t[i]){
                j++;
                count++;
            }
            i++;

        }
        cout<<count;

        if(count==s.size()){
            return true;
        }
        return false;

    }
};