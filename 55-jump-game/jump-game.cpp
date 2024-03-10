class Solution {
public:
    bool canJump(vector<int>& nums) {
        int reach = 0;
        int n = nums.size(); // store the size to avoid recomputing it in each iteration
        for( int i=0; i<n; i++){
            if(i>reach){
             return false;
            }
            reach = max(reach,i+nums[i]);
            if(reach>=n-1){
                break;
            }
        }
        return true;
    }
};
