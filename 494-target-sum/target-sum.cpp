#include <vector>

class Solution {
public:
    int findTargetSumWays(std::vector<int>& nums, int target) {
        count = 0;
        getWays(nums, 0, target, 0);
        return count;
    }

    int count;

    void getWays(std::vector<int>& nums, int index, int target, int total) {
        if (index == nums.size()) {
            count += (target == total ? 1 : 0);
            return;
        }

        getWays(nums, index + 1, target, total + nums[index]);
        getWays(nums, index + 1, target, total - nums[index]);
    }
};
