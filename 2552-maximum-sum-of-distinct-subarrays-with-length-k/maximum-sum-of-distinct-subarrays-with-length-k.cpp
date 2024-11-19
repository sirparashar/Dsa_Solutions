class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long res = 0, sum = 0;
        unordered_map<int, int> freq; // To track frequency of elements in the window
        int left = 0; // Sliding window's left pointer
        
        for (int right = 0; right < nums.size(); ++right) {
            sum += nums[right];
            freq[nums[right]]++;
            
            // If the window size exceeds k, shrink it from the left
            while (right - left + 1 > k) {
                sum -= nums[left];
                freq[nums[left]]--;
                if (freq[nums[left]] == 0) {
                    freq.erase(nums[left]);
                }
                left++;
            }
            
            // Check if the window is valid (size k and all unique elements)
            if (right - left + 1 == k && freq.size() == k) {
                res = max(res, sum);
            }
        }
        return res;
    }
};
