class Solution {
public:
    int jump(vector<int>& nums) {
        
     int n= nums.size(), i=0, lastjump=0,maxreach=0,jumps=0;
     while(lastjump<n-1){
         maxreach=max(maxreach,i+nums[i]);
         if(i==lastjump){
             lastjump = maxreach;
             jumps++;
         }
         i++;
     }
       return jumps;
    }
};