class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_map<char,int>m;
        for(char c:stones){
            m[c]++;
        }
        int count=0;
        for(char c : jewels){
            count+=m[c];
        }
        return count;
    }
};