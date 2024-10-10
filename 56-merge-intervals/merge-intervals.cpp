class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> merged; 
        sort(intervals.begin(), intervals.end());

        merged.push_back(intervals.front());


        for( auto i :intervals){
            if(i[0]<= merged.back()[1]){
                merged.back()[1] = max(i[1],merged.back()[1]);
            }else{
                merged.push_back(i);
            }
        }
        return merged;

    }
};