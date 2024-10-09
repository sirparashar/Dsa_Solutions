class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size();

        vector<string> res;
        string t = "";

        for (int l = 0; l < n; l++) {
          int r = l;

          while(r+1<n && nums[r]+1==nums[r+1]){
            r++;
          }

          if(r>l){
            t+=to_string(nums[l]);
            t+="->";
            t+=to_string(nums[r]);
          }
          else{
            t+=to_string(nums[l]);
          }

          l=r;
          res.push_back(t);
          t="";

        }
        return res;

    }
};