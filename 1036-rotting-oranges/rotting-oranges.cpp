class Solution {
public:
    vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int fresh =0;
        queue<pair<int,int>> q;
        for(int i=0 ; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==2){
                 q.push({i,j});
                }
                if(grid[i][j]==1){
                    fresh++;
                }
            }
        }

        q.push({-1, -1}); 
        int result = -1;

        while(!q.empty()){
        int r = q.front().first;
        int c = q.front().second;

        q.pop();

        if(r==-1){
            result++;
            if(!q.empty()){
                q.push({-1,-1});
            }
        }
        else{

            for(int i=0; i<dirs.size(); i++){
                int x = r + dirs[i][0];
                int y = c + dirs[i][1];

                if(x<0 || y<0 || x>=m || y>=n){
                    continue;
                }

                if(grid[x][y] == 1 ){
                    grid[x][y]=2;
                    fresh--;
                    q.push({x,y});
                }
            }

        }
        }
        if(fresh == 0){
            return result;
        }
        return -1;
    }
};