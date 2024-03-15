class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int pre=1;
        vector<int> preprod(nums.size(),1);

        for(int i=0; i<nums.size(); i++){
            preprod[i]=pre;
            pre=pre*nums[i];
        }
        int post=1;
        for(int i= nums.size()-1; i>=0; i--){
             preprod[i]=preprod[i]*post;
            post*=nums[i];
        }
        return preprod;
    }
};