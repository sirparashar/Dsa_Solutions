class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int m = maxCost;
        int size = s.size();
        int l = 0;
        int r = 0;
        int cost = 0;
        int count = 0;
        int maxcount = 0;

        while ( r < size) {
            cost += abs(s[r]-t[r]);

            while(cost>maxCost){
                cost-=abs(s[l]-t[l]);
                l++;
            }

            maxcount = max(maxcount,r-l+1);
            r++;

        }
        return maxcount;
    }
};