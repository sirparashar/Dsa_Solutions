class Solution {
public:
    vector<int> per;
    vector<vector<int>> res;

    void helper(vector<int> nums, int i) {
        if (i == nums.size()) {
            res.push_back(nums);
            return;
        }
        for (int p = i; p < nums.size(); p++) {
            swap(nums[p], nums[i]);
            helper(nums, i+1);
            swap(nums[p],nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        helper(nums, 0);
        return res;
    }
};