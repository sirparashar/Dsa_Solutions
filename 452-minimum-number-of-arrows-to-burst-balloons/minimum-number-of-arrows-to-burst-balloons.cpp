class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), comp);
        vector<int> interval = points[0];
        int ans = 1;
        for(int i = 1; i < points.size(); i ++){

            if(interval[1] >= points[i][0]){
                interval[0] = max(interval[0], points[i][0]);
                interval[1] = min(interval[1], points[i][1]);
            }else{
                interval = points[i];
                ans += 1;
            }
        }

        return ans;
    }

    static bool comp(const vector<int>& vec1, const vector<int>& vec2){
        return vec1[0] < vec2[0];
}
};