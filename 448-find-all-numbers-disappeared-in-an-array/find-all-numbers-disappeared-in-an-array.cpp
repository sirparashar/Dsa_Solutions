class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;
        set<int>s;
        s.insert(nums.begin(),nums.end());
        for(int i =1; i<=nums.size(); i++){
            if(s.find(i)==s.end()){
                res.push_back(i);
            }
        }
        return res;
    }
};