class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>>m;
        for(auto str : strs){
            auto ana = str;
            sort(str.begin(), str.end());
            m[str].push_back(ana);
        }
        vector<vector<string>> res;

        for(auto str:m){
             res.push_back(str.second);
        }
        return res;

    }
};