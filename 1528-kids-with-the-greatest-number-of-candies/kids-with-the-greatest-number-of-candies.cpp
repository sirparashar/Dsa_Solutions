class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> res;
        int maxi = 0;

        for (auto candie : candies) {
            maxi = max(maxi, candie);
        }

        for (auto candie : candies) {
            if (candie + extraCandies >= maxi) {
                res.push_back(true);
            } else {
                res.push_back(false);
            }
        }
        return res;
    }
};