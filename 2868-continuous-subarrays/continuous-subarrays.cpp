class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        map<int,int> f;

        int left=0;
        int right =0;

        int n = nums.size();
        long long count=0;
        while(right<n){
            f[nums[right]]++;
            while(f.rbegin()->first - f.begin()->first >2){
                f[nums[left]]--;
                if(f[nums[left]]==0){
                    f.erase(nums[left]);
                }
                left++;
            }
            count+=right-left+1;
            right++;
        }
        return count;
    }
};