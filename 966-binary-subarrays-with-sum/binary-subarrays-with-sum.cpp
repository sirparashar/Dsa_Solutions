class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atmost(nums,goal) - atmost(nums,goal-1);
    }

    int atmost(vector<int>& nums, int goal){
        if(goal<0){
            return 0;
        }

        int res=0; int i=0; int n = nums.size();
        for(int j=0; j<n; j++){
            goal-=nums[j];
            while(goal<0){
                goal+=nums[i++];
            }
            res+=j-i+1;
        }
        return res;
    }
};