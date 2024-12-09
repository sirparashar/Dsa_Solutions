class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums,
                                vector<vector<int>>& queries) {
        int n = queries.size();
        vector<bool> res;
        vector<int>temp;
        temp.push_back(0);
        int j=0;
        for(int i =1; i<nums.size(); i++){
           if(nums[i]%2==nums[i-1]%2){
            j++;
           }
           temp.push_back(j);
        }

        for(auto i : queries){
            res.push_back(temp[i[0]]==temp[i[1]]);
        }

    
      

       
        return res;
    }
};