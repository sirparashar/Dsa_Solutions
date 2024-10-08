class Solution {
public:
    
    void getsub(vector<int> nums,int index,vector<int>& sub,  vector<vector<int>>& res ){
          
          if(index==nums.size()){
            res.push_back(sub);
            return;
          }
          getsub(nums,index+1,sub,res);

          sub.push_back(nums[index]);
         getsub(nums,index+1,sub,res);
         sub.pop_back();

    }


    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> sub;
        getsub(nums,0,sub,res);
        return res;
    }
};