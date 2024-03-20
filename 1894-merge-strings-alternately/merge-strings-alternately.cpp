class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string s = "";
        int i=0; int j=0;
        while(i<word1.size() && word2.size()>j){
            s+=word1[i++];
            s+=word2[j++];
        }
        if(i<word1.size()){
            s+=word1.substr(i);
        }
        else{
            s+=word2.substr(j);
        }

        return s;
    }
};