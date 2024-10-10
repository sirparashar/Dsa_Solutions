class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> pre ;
        pre.push_back(1);
        int prod=1;

        for(int i = 1; i<nums.size(); i++){
             prod *= nums[i-1];
             pre.push_back(prod);
             cout<< pre[i];
        }
        prod = 1;
        int n;
        for(int j=nums.size()-1; j>=0; j--){
            n=nums[j];
            nums[j] = pre[j]*prod;
            prod *= n;
        }

        return nums;
    }
};