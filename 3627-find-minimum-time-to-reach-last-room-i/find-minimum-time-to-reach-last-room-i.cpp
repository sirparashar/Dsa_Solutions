class Solution {
public:
    int minTimeToReach(vector<vector<int>>& nums) {
        int n = nums.size();
        int m = nums[0].size();

        priority_queue<vector<int>> pq;

        pq.push({0,0,0});

        vector<vector<bool>> vis(n,vector<bool>(m,false));
        vector<int> dir = {-1,0,1,0,-1};

        while(!pq.empty()){
            auto cur = pq.top();
            pq.pop();
            int time =  cur[0];
            time*=-1;
            int r = cur[1];
            int c = cur[2];
            if(vis[r][c]){
                continue;
            }

            if(r==n-1 && c==m-1){
                return time;
            }

            vis[r][c]=true;

            for(int i=0; i<4; i++){
                int nr = r+dir[i];
                int nc = c+dir[i+1];
                if(nr>=0 && nc>=0 && nr<n &&nc<m){
                    pq.push({-1*(max(time,nums[nr][nc])+1),nr,nc});
                }

            }


        }
        return -1;
    }
};