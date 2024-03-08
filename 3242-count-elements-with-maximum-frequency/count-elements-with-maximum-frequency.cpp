#include <vector>
#include <algorithm>

class Solution {
public:
    int maxFrequencyElements(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());

        int maxFrequency = 0;
        int curFrequency = 1;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i - 1] == nums[i]) {
                curFrequency++;
            } else {
                maxFrequency = std::max(maxFrequency, curFrequency);
                curFrequency = 1; // Reset current frequency for the new element
            }
        }

        // Update maxFrequency after the loop in case the last element has the maximum frequency
        maxFrequency = std::max(maxFrequency, curFrequency);

        // Count the number of elements with maximum frequency
        int maxFreqElements = 0;
        curFrequency = 1; // Reset current frequency for counting elements
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i - 1] == nums[i]) {
                curFrequency++;
            } else {
                if (curFrequency == maxFrequency) {
                    maxFreqElements++;
                }
                curFrequency = 1; // Reset current frequency for the new element
            }
        }

        // Check the last element in case it has the maximum frequency
        if (curFrequency == maxFrequency) {
            maxFreqElements++;
        }

        int totalFrequency = maxFrequency * maxFreqElements;

        return totalFrequency;
    }
};
