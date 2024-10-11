class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        vector<int> ttime = times[targetFriend];
        sort(times.begin(), times.end());

        int n = times.size();

        vector<int> chair(n);
        for (auto t : times) {
            for (int i = 0; i < n; i++) {
                if (chair[i] <= t[0]) {
                    chair[i] = t[1];
                    if (t == ttime) {
                        return i;
                    }
                    break;
                }
            }
        }
        return 0;
    }
};