class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> list = {{}};

        for (auto num : nums) {
            int n = list.size();
            for (int i = 0; i < n; i++) {
                list.push_back(list[i]);
                list.back().push_back(num);
            }
        }

        return list;
    }
};