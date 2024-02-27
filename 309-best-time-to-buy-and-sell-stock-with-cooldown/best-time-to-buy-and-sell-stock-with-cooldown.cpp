class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sold=0;
        int hold = INT_MIN;
        int rest = 0;

        for(int i=0; i<prices.size();++i){
            int presold = sold;
            sold = hold+prices[i];
            hold = max(hold,rest-prices[i]);
            rest = max(rest,presold);
        }
        return max(sold,rest);
    }
};