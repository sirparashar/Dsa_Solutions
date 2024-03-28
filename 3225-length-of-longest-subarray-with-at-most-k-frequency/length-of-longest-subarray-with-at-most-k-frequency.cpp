class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> m;

        int n = nums.size();
        int count = 0;

        int left = 0;
        int right = 0;
        int len = 0;

        while (right < n) {
            int cur = nums[right++];
            m[cur]++;

            while (left < right && m[cur] > k) {
                m[nums[left++]]--;
            }
            len = max(len,right-left);
        }

        return len;
    }
};