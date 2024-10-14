class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> pq(nums.begin(), nums.end());  // Max-heap
        long long score = 0;

        for (int i = 0; i < k; i++) {
            int maxElem = pq.top();  // Get the maximum element
            pq.pop();
            score += maxElem;  // Add to score
            pq.push(ceil(maxElem / 3.0));  // Push back ceil(maxElem / 3)
        }

        return score;
    }
};
