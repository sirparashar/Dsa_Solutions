class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int closest=INT_MAX;
        sort(nums.begin(),nums.end());
        for(auto n:nums){
            if(abs(n-0)<=abs(closest)){
                closest = n;
            }
        }
        return closest;
    }
};