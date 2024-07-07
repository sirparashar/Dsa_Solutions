class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int res =numBottles; 
        while(numBottles>=numExchange){
            int ex = numBottles/numExchange;
            int rem = numBottles%numExchange;
            res+=ex;
            numBottles = ex+rem;
            cout<<numBottles<<res<<"\n";
        }
        return res;
    }
};