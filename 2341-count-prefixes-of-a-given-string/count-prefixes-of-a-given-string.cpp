class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
        int count=0;
        for(auto word:words){
            int n = word.size();
            if(s.substr(0,n)==word){
                count++;
            }
        }
        return count++;
    }
};