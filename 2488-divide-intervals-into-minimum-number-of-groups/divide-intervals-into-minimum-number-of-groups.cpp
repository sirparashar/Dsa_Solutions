class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        // Sort intervals based on start time
        sort(intervals.begin(), intervals.end());

        // Min-heap to track the end times of the groups
        priority_queue<int, vector<int>, greater<int>> pq;

        for (const auto& interval : intervals) {
            // If the current interval starts after the earliest ending group
            if (!pq.empty() && pq.top() < interval[0]) {
                pq.pop();  // Remove that group from the heap
            }
            // Add the current interval's end time to the heap (create/update group)
            pq.push(interval[1]);
        }

        // The size of the heap represents the number of groups required
        return pq.size();
    }
};
