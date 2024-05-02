class Solution {
public:
    int findMaxK(vector<int>& nums) {
        unordered_set<int> m(nums.begin(), nums.end());

        sort(nums.begin(), nums.end());

        for (int i = nums.size() - 1; i >= 0; i--) {
            if (m.find(-nums[i]) != m.end()) {
                return nums[i];
            }
        }
        return -1;
    }
};