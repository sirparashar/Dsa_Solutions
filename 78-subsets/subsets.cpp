class Solution {
public:
    void getsub(vector<int>&nums,vector<vector<int>> &res,vector<int>&sub,int i){
        
        if(i==nums.size()){
            res.push_back(sub);
            return;
        }

        getsub(nums,res,sub,i+1);
        sub.push_back(nums[i]);
        getsub(nums,res,sub,i+1);
        sub.pop_back();

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int>sub;
        getsub(nums,res,sub,0);
        return res;
    }
};