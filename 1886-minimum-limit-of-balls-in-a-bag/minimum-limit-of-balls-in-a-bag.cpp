class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        sort(nums.begin(), nums.end());
        int low = 1;
        int high = nums[nums.size() - 1];

        while (low < high) {
            int mid = low + (high - low) / 2;
            int count = 0;

            for (int a : nums) {
                count += (a - 1) / mid;
            }
            if (count > maxOperations) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return low;
    }
};