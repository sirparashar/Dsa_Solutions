#include <algorithm>
#include <vector>

class Solution {
public:
    int transformNumber(int num, const vector<int>& mapping) {
        if (num == 0)
            return mapping[0];
        int transformed = 0, place = 1;
        while (num > 0) {
            int digit = num % 10;
            transformed = mapping[digit] * place + transformed;
            place *= 10;
            num /= 10;
        }
        return transformed;
    }

    vector<int> sortJumbled(const vector<int>& mapping,
                            vector<int>& nums) {
        // Create a vector of pairs to store original numbers and their
        // transformed values
        std::vector<std::pair<int, int>> transformedNums;
        for (int num : nums) {
            int transformed = transformNumber(num, mapping);
            transformedNums.push_back({transformed, num});
        }

        // Use stable sort to maintain relative order of equal elements
        stable_sort(transformedNums.begin(), transformedNums.end(),
                    [](const pair<int, int>& a, const pair<int, int>& b) {
                        return a.first < b.first;
                    });

        // Extract the sorted original numbers
        vector<int> sortedNums;
        for (const auto& pair : transformedNums) {
            sortedNums.push_back(pair.second);
        }

        return sortedNums;
    }
};
