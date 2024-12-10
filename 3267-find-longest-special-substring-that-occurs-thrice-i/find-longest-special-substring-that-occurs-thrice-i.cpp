class Solution {
public:
    int maximumLength(string s) {
        map<string, int> m;
        for (int i = 0; i < s.size(); i++) {
            string curr;
            for (int j = i; j < s.size(); j++) {
                if(curr.empty() || curr.back()==s[j]){
                    curr.push_back(s[j]);
                    m[curr]++;
                }else{
                    break;
                }
            }
        }

        int ans=0;

        for(auto i  : m){
            string str = i.first;
            if(i.second>=3 && str.length()>ans){
                ans=str.length();
            }
        }
        if(ans==0){
            return -1;
        }
        return ans;
    }
};