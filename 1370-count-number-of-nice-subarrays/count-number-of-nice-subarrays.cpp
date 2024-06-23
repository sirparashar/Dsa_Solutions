class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int start = 0;
        int end = 0;
        int count = 0;
        int res = 0;
        vector<int> prefix(nums.size() + 1, 0);
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] % 2 != 0) {
                nums[i] = 1;
            } else {
                nums[i] = 0;
            }
        }
        prefix[0] = 1;
        int s = 0;
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            s += nums[i];
            ans += (s >= k) ? prefix[s - k] : 0;
            prefix[s]++;
        }
        return ans;

        return nums[0];
    }
};