class Solution {
public:
    int count=0;
    set<pair<int,int>>s;
    int numIslands(vector<vector<char>>& grid) {

        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(getiland(grid,i,j)){
                    count++;
                }
            }
        }
           
           return count;
    }

    bool getiland(vector<vector<char>>& grid, int i, int j){
      
    if(i<0 || i>grid.size()-1){
        return false;
    }
    if(j<0 || j>grid[0].size()-1){
        return false;
    }

    if(grid[i][j]=='0'){
        return false;
    }    

    if(s.find({i,j})!=s.end()){
        return false;
    }

    s.insert({i,j});

    getiland(grid,i-1,j);
    getiland(grid,i+1,j);
    getiland(grid,i,j+1);
    getiland(grid,i,j-1);

    return true;
    

    }
};