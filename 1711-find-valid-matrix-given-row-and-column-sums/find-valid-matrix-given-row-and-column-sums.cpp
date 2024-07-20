class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {

       int rows = rowSum.size();
       int cols = colSum.size();

       vector<vector<int>> res(rows,vector<int>(cols,0));

       for(int i =0; i<rows; i++){
        for(int j=0; j<cols; j++){
            int val = min(rowSum[i],colSum[j]);
            res[i][j]=val;
            rowSum[i]-=val;
            colSum[j]-=val;
        }
       }   
       return res;
    }
};