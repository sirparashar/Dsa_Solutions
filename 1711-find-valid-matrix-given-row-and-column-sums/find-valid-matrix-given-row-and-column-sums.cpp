class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {

       int rows = rowSum.size();
       int cols = colSum.size();

       vector<vector<int>> res(rows,vector<int>(cols,0));

       for(int i =0; i<rows; i++){
        for(int j=0; j<cols; j++){
            res[i][j] = min(rowSum[i],colSum[j]);
            rowSum[i]-=res[i][j];
            colSum[j]-=res[i][j];
        }
       }   
       return res;
    }
};