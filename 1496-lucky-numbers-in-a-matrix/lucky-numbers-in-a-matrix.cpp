class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> minr;
        vector<int> maxc;

        for (auto row : matrix) {
            int mr = INT_MAX;
            for (auto n : row) {
                if (mr > n) {
                    mr = n;
                }
            }
            minr.push_back(mr);
        }

        for (int i = 0; i < n; i++) {
            int mc = INT_MIN;
            for (int j = 0; j < m; j++) {
                if (matrix[j][i] > mc) {
                    mc = matrix[j][i];
                }
            }
            maxc.push_back(mc);
        }
        vector<int> res;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j]==minr[i] && matrix[i][j]==maxc[j]){
                    res.push_back(minr[i]);
                }
            }
        }
        return res;
    }
};