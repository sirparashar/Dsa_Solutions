class Solution {
public:
    bool isPossible(int n, vector<int>& quantities, int mid) {
        int stores = 0;
        for (auto x : quantities) {
            stores += ceil((double)x / mid);
        }
        return stores <= n;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        int s = 1, e = *max_element(quantities.begin(), quantities.end()),
            ans = -1;
        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (isPossible(n, quantities, mid)) {
                ans = mid;
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }
        return ans;
    }
};