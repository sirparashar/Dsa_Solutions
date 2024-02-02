class Solution {
public:
int sum=0;
unordered_map<int,int> robsum;
    int rob(vector<int>& nums) {
       return getrob(nums,nums.size()-1);
    }

    int getrob(vector<int>&nums,int i){
        if(i<0){
            return 0;
        }
        if(robsum.find(i)!=robsum.end()){
            return robsum[i];
        }
        int result =  max(getrob(nums,i-2)+nums[i],getrob(nums,i-1));
        robsum[i]=result;
        return result;
    }
};