class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,1);
        int result = 1;
        for (int i=n-1; i>=0; i--){
            for (int j=i; j<n; j++){
                if(nums[j]>nums[i])
                dp[i] = max(dp[i], 1+dp[j]);
            }
         result = max(result,dp[i]);
        }
        return result;
    }
};