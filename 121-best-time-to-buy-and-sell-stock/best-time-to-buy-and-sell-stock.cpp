class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0;

        int left=0; int right=1;

        while(left<prices.size() && right<prices.size()){
             int p = prices[right]-prices[left];
             if(p<=0){
                cout<<p;
                left=right;
             }
             profit = max(profit,p);
             right++;;
        }
        return profit;
    }
};