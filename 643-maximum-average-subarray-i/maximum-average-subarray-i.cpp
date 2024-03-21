class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum = 0;
        double res = INT_MIN;
        for (int j = 0; j < nums.size(); j++) {
           if(j<k){
            sum+=nums[j];
           }
           else{
            res = max(sum,res);
            sum+=nums[j]-nums[j-k];
           }
        }
        res = max(sum,res);

        return res/k;
    }
};