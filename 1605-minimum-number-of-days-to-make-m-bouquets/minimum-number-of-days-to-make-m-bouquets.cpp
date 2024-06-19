class Solution {
public:
    bool buk(vector<int>& bloomDay, int m, int k, int mid) {
        int total = 0;

        for (int i = 0; i < bloomDay.size(); i++) {
            int count = 0;
            while (i < bloomDay.size() && count < k && bloomDay[i] <= mid) {
                count++;
                i++;
            }

            if (count == k) {
                total++;
                i--;
            }

            if (total >= m) {
                return true;
            }
        }
        return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        if ((long long)m * k > bloomDay.size()) {

            return -1;
        }
        auto [lowIt, highIt] = std::minmax_element(bloomDay.begin(), bloomDay.end());
        int low = *lowIt;
        int high = *highIt;

        while (low < high) {
            int mid = low + (high - low) / 2;

            if (buk(bloomDay, m, k, mid)) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }
};