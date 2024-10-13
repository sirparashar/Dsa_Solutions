class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int flipped = 0;  // Track the number of flipped zeros
        int l = 0;        // Left pointer of the sliding window
        int len = 0;      // Maximum length of subarray

        for (int r = 0; r < nums.size(); r++) {
            if (nums[r] == 0) {
                flipped++;  // Flip the zero
            }

            // If there are more than `k` zeros flipped, shrink the window
            while (flipped > k) {
                if (nums[l] == 0) {
                    flipped--;  // Reduce flipped count
                }
                l++;  // Move the left pointer to shrink the window
            }

            // Update the maximum length of the valid subarray
            len = max(len, r - l + 1);
        }

        return len;
    }
};
