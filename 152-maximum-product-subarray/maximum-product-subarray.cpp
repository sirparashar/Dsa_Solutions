class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = nums[0];
        int curmin =1, curmax=1;
        for(auto num : nums){
            if(num ==0){
                curmin =1;
                curmax=1;
            }
            int temp = curmax;
            curmax = max(max(num*curmax, num*curmin),num);
            curmin = min(min(num*curmin, num*temp),num);
            res = max(res,curmax);
        }
        return res;
    }
};