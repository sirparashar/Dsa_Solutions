class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        vector<int> res(nums.size() - k + 1);

        for (int i = 0; i <= nums.size()-k ; i++) {
            bool flag = true;
            for (int j = i; j < k + i-1; j++) {

                if (nums[j+1] != nums[j]+1) {
                    flag = false;
                     break;
                }

            }

            if(flag){
                res[i]=nums[i+k-1];
            }
            else{
                res[i]=-1;
            }
        }
        return res;
    }
};