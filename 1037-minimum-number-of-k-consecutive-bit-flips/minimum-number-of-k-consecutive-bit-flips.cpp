class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        int flipped =0;
        int ans =0;
        deque<int> out;

        for(int i=0 ;i<n ; i++){
            if(!out.empty() && out[0]==i){
                out.pop_front();
                flipped = !flipped;
            }

            if(flipped == nums[i]){
                flipped^=1;
                ans+=1;
                out.push_back(i+k);
            }
        }
        if(out.size()>0 && out[0]==n){
            out.pop_front();
        }
        if(out.size()>0){
            return -1;
        }
        return ans;
    }
};