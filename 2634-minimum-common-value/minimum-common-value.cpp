#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        // Convert nums2 to a set for faster lookup
        unordered_set<int> nums2Set(nums2.begin(), nums2.end());

        // Iterate through nums1 and check if the element exists in nums2Set
        for (auto num : nums1) {
            if (nums2Set.find(num) != nums2Set.end()) {
                return num;
            }
        }

        return -1;
    }
};
