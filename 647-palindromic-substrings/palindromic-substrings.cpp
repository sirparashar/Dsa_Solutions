class Solution {
public:
    int countSubstrings(string s) {
        int count =0 ;
        for(int i=0; i<=s.size()-1; i++){
            extendout(s,i,i,count);
            extendout(s,i,i+1,count);
        }

        return count;

    }

    void extendout(string &s, int i, int j, int &count){
           int flag =0;
      while (i >= 0 && j <= s.size() - 1 && s[i] == s[j]) {
            count++;  // Increment count for each iteration
            i--;
            j++;
        }
    }
};