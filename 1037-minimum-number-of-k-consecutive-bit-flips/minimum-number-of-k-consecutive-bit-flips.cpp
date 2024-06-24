#include <vector>
#include <deque>
using namespace std;

class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        deque<int> flipIndices;

        for (int i = 0; i < n; ++i) {
            // Remove elements from the deque which are out of the current window
            if (!flipIndices.empty() && flipIndices.front() <= i) {
                flipIndices.pop_front();
            }

            // Check if the current bit needs to be flipped
            if (flipIndices.size() % 2 == nums[i]) {
                // If we can't flip the window of k bits, return -1
                if (i + k > n) return -1;
                // Perform the flip operation
                flipIndices.push_back(i + k);
                ans++;
            }
        }

        return ans;
    }
};
