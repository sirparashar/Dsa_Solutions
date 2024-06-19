class Solution {
public:
    void getset(vector<int>& nums, int start, vector<int> set,
                vector<vector<int>>& res) {
 res.push_back(set);
        for (int i = start; i < nums.size(); i++) {
            set.push_back(nums[i]);
            getset(nums, i + 1, set, res);
            set.pop_back();
        }
       
    }

    vector<vector<int>> subsets(vector<int>& nums) {

        vector<vector<int>> res;
        vector<int> set;
        getset(nums, 0, set, res);

        return res;
    }
};