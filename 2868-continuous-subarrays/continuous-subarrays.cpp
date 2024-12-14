class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        long long count = 0, winl = 0;
        int right = 0;
        int left = 0;
        int curmax, curmin;
        curmin = curmax = nums[left];

        while (right < nums.size()) {
            curmin = min(curmin, nums[right]);
            curmax = max(curmax, nums[right]);

            if (curmax - curmin > 2) {
                winl = right - left;
                count += (winl * (winl + 1) / 2);
                left = right;
                curmin = curmax = nums[left];

                while (left > 0 && abs(nums[right] - nums[left-1]) <= 2) {
                    left--;
                    curmin = min(curmin, nums[left]);
                    curmax = max(curmax, nums[left]);
                }

                if (left < right) {
                    winl = right - left;
                    count -= (winl * (winl + 1) / 2);
                }
            }
            right++;
        }
        winl = right - left;
        count += (winl * (winl + 1) / 2) ;
        return count;
    }
};