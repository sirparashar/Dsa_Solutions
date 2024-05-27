class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int magic = -1;
        while (true) {
            magic++;
            int count=0;
            for (auto num : nums) {
                if (magic <= num) {
                    count++;
                }
            }
            if (magic == count) {
                cout<<magic<<count;
                cout<<'p';
                return magic;
                break;
            }
            if (magic >= nums.size()) {
                cout<<'o';
                break;
            }
            cout << magic;
        }
        return -1;
    }
    
};