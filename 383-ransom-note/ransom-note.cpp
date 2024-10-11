class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {

        if(ransomNote.size()>magazine.size()){
            return false;
        }

        unordered_map<int,int> r,m;


        for(char c: magazine){
            m[c]++;
        }
        
        for(char c: ransomNote){
            if(m[c]--<=0){
                return false;
            }
        }
        
        return true;


        
    }
};