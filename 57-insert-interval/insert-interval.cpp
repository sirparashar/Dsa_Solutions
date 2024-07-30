class Solution {
public:
    void merge(vector<vector<int>>& temp, vector<vector<int>>& res) {
        res.push_back(temp[0]);
        for(int i = 1; i < temp.size(); i++) {
            if(res.back()[1] >= temp[i][0]) {
                res.back()[1] = max(res.back()[1], temp[i][1]);
            } else {
                res.push_back(temp[i]);
            }
        }
    }

    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if(intervals.size() == 0) {
            return {newInterval};
        }

        vector<vector<int>> temp, res;
        bool inserted = false;

        for(int i = 0; i < intervals.size(); i++) {
            if(!inserted && intervals[i][0] >= newInterval[0]) {
                temp.push_back(newInterval);
                inserted = true;
            }
            temp.push_back(intervals[i]);
        }

        // If newInterval has not been inserted, insert it at the end
        if(!inserted) {
            temp.push_back(newInterval);
        }

        merge(temp, res);
        return res;
    }
};
