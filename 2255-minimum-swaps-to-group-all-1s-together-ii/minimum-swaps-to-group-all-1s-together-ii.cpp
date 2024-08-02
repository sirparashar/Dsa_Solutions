class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int k = accumulate(nums.begin(),nums.end(),0);
        int n = nums.size();
        int oneinW = accumulate(nums.begin(),nums.begin()+k,0);
        int max1 = oneinW;

        for(int i=k; i<n+k; i++){
            oneinW += nums[i%n] - nums[(i-k+n)%n];
            max1 = max(max1, oneinW);
        }
        return k-max1;
    }
};