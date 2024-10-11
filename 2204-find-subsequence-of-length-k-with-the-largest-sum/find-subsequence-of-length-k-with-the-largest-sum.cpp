class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<int> res,temp;
        temp = nums;
        unordered_map<int,int> m;

        sort(nums.begin(),nums.end(),greater<int>());

        for(int i =0; i<k; i++){
         m[nums[i]]++;
        }

        for(auto it : temp){
            if(m[it]-- >0){
             res.push_back(it);
            }
        }
        return res;


    }
};