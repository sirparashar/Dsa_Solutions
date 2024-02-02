class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1){
            return nums[0];
        }
        return max(robber(nums, 0, n-2),robber(nums,1,n-1));
    }

    int robber(vector<int>& nums, int start, int end){
        int prev =0;
        int cur=0;
        int next=0;
        for(int i=start; i<=end; i++){
            int next = max(prev+nums[i], cur);
            prev=cur; 
            cur=next;
        }
        return cur;
    }
};