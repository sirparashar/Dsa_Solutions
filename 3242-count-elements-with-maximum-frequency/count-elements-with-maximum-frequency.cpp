class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        map<int, int> s;
        for(int i=0; i<nums.size(); i++){
            s[nums[i]]++;
        }

        int maxi=0;
        for(int i=0; i<s.size(); i++){
            maxi = max(maxi,s[i]);
        }
        int count=0;
        for(int i=0; i<s.size(); i++){
            if(s[i]==maxi){
                count+=maxi;
            }
        }
        return count;
    }
};