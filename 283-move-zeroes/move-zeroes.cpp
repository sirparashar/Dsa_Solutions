class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j=nums.size()-1;
        vector<int>n(j+1);
        int i=0;
         

         for(auto num:nums){
            if(num==0){
                n[j]=0;
                j--;
            }
            else{
                n[i]=num;
                i++;
            }
         }

         nums=n;

    }
};