class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        vector<int>s(1);
        sort(edges[0].begin(),edges[0].end());
        sort(edges[1].begin(),edges[1].end());
        set_intersection(edges[0].begin(),edges[0].end(),edges[1].begin(),edges[1].end(),s.begin());
        return s[0];
    }
};