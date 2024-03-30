

class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return countArray(nums, k) - countArray(nums, k - 1);
    }
    
    int countArray(vector<int>& nums, int k) {
        int count = 0;
        vector<int> occur(nums.size() + 1, 0);
        int i = 0, j = 0, unique = 0;
        while (j < nums.size()) {
            if (occur[nums[j]] == 0)
                unique++;
            occur[nums[j]]++;
            while (i <= j && unique > k) {
                occur[nums[i]]--;
                if (occur[nums[i++]] == 0)
                    unique--;
            }
            count += j - i + 1;
            j++;
        }
        return count;
    }
};