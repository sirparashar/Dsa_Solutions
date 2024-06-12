class Solution {
public:
    void sortColors(vector<int>& nums) {
        int fre[3]={0};
        for (int x:nums){
            fre[x]++;
        }
        int count=0;
        nums.clear();
        for(int i=0; i<3;i++){
          for(int j=0; j<fre[i];j++){
           nums.push_back(i);
          }
        }

    }
};