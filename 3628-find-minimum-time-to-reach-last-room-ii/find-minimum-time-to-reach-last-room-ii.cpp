class Solution {
public:
    int minTimeToReach(vector<vector<int>>& nums) {
        int n = nums.size();
        int m = nums[0].size();

        vector<vector<bool>> vis(n, vector<bool>(m, false));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>
            pq;
        vector<int> dir = {-1, 0, 1, 0, -1};

        pq.push({0, 0, 0,true});

        while (!pq.empty()) {
            auto cur = pq.top();
            pq.pop();

            int time = cur[0];
            int r = cur[1];
            int c = cur[2];
            int tog = cur[3];
            int add = tog?1:2;


            if (vis[r][c] == true) {
                continue;
            }

            if (r == n - 1 && c == m - 1) {
                return time;
            }
            vis[r][c] = true;

            for (int i = 0; i < 4; i++) {
                int nr = r + dir[i];
                int nc = c + dir[i + 1];

                if (nc >= 0 && nr >= 0 && nr < n && nc < m) {

                    pq.push({max(time, nums[nr][nc]) + add, nr, nc,!tog});
                }
            }
        }
        return -1;
    }
};