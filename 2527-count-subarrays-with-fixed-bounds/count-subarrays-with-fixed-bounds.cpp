class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK){
        int min_i = -1;
        int max_i = -1;
        long long count = 0;
        int st = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]<minK || nums[i]>maxK){
                min_i = -1;
                max_i = -1;
                st = i+1;
            }
            if(nums[i] == minK){
                min_i = i;
            }
            if(nums[i] == maxK){
                max_i = i;
            }            
            count += max(0,min(min_i,max_i)-st+1);
        }
        return count;
    }
};