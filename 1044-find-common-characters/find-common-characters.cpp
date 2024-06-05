class Solution {
public:
    vector<string> commonChars(vector<string>& words) {

        vector<string> res;

        for (char ch = 'a'; ch<='z'; ch++) {
            int mincount=INT_MAX;
            for (auto s : words) {
                int count = 0;
                for (char c:s) {
                    if(c==ch){
                        count++;
                    }
                }
                mincount=min(mincount,count);
            }

            for(int i=0; i<mincount; i++){
                res.push_back({ch});
            }
        }

        return res;
    }
};