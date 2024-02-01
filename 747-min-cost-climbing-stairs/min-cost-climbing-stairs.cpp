class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int top1 =0;
        int top2=0;

        for(int i=2; i<=cost.size(); i++){
            int temp = top1;
            top1 = min(top1+cost[i-1],top2+cost[i-2]);
            top2= temp;
        }
        return top1;
    }
};