class Solution {
public:
    int numTeams(vector<int>& rating) {
        int res = 0;
        for (int i = 1; i < rating.size() - 1; i++) {
            int ls = 0, rl = 0;
            for (int j = 0; j < i; j++) {
                if (rating[j] < rating[i]) {
                    ls++;
                }
            }
            for (int j = i + 1; j < rating.size(); j++) {
                if (rating[j] > rating[i]) {
                    rl++;
                }
            }
            res += ls * rl;

            int ll=i-ls;
            int rs=rating.size()-i-rl-1;


            res += ll * rs;
        }
        return res;
    }
};