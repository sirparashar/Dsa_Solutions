class Solution {
public:
    set<pair<int, int>> s;
    int count;
    int numIslands(vector<vector<char>>& grid) {

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {

                if(explore(grid, i, j)){
                    count++;
                }
            }
        }
        return count;
    }

    bool explore(vector<vector<char>>& grid, int r, int c ){
        if(r<0 or r>grid.size()-1) return false;
        if(c<0 or c>grid[0].size()-1) return false;
        if(grid[r][c]=='0'){
            return false;
        }

        if(s.find({r,c})!= s.end()){
            return false;
        }
        s.insert({r,c});
        explore(grid, r+1, c);
        explore(grid, r, c+1);
        explore(grid, r, c-1);
        explore(grid, r-1, c);

        return true;

    }
};