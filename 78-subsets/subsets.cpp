class Solution {
public:
    
    void getsub(vector<int> nums,int index,vector<int>& sub,  vector<vector<int>>& res ){
       res.push_back(sub);

       for(int i =index; i<nums.size(); i++){
        sub.push_back(nums[i]);
        getsub(nums,i+1,sub,res);
        sub.pop_back();
       }


    }


    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> sub;
        getsub(nums,0,sub,res);
        return res;
    }
};