class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int jump=0;
        while (i < n-1) {
          
          if(i+nums[i]>=n-1){
              jump++;
              break;
          }
          int maxind=i+1;
          int maxval=0;

          for(int j=i+1; j<i+1+nums[i]; j++){
            if(j+nums[j]>maxval){
                maxind =j;
                maxval=j+nums[j];
            }
          }
          i=maxind;
          jump++;

        }
        return jump;
    }
};