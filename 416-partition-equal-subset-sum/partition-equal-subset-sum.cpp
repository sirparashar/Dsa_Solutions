class Solution {
public:
    bool canPartition(vector<int>& nums) {
         
    int resSum =0 ;
    for (int i:nums){
        resSum +=i;
    }
    if(resSum%2){
        return false;
    }

    resSum/=2;

    vector<bool>dp(resSum+1,false);
    dp[0]=true;

    for(int x:nums){
        for(int i=resSum; i>=x; i--){
            dp[i]=dp[i] || dp[i-x];
        }
    } 
    return dp[resSum];

    }
};