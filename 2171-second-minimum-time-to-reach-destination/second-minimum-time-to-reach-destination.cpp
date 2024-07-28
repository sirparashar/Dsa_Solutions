class Solution {
public:
 int timet(int steps,int time,int change){
        int ans =0;
        for(int i=0; i<steps; i++){
            int t = ans/change;
            if(t&1){
                ans=(t+1)*change;

            }
                            ans+=time;
        }
        return ans;
     }
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<vector<int>> adj(n+1);

        for(auto& e:edges){
            int v=e[0], w=e[1];
            adj[v].push_back(w);
            adj[w].push_back(v);
        }

        vector<int> dist(n+1,INT_MAX), dist2(n+1,INT_MAX);
        queue<pair<int,int>> q;
        q.emplace(1,0);
        dist[1]=0;

        while(!q.empty()){
            auto[x,d]=q.front();
            q.pop();
            for(int y:adj[x]){
                int newd = d+1;
                if(newd<dist[y]){
                    dist2[y]=dist[y];
                    dist[y]=newd;
                    q.emplace(y,newd);
                }
                else if(newd>dist[y] &&newd<dist2[y]){
                    dist2[y]=newd;
                    q.emplace(y,newd);
                }
            }
        }

        int steps = dist2[n];
        if(steps == INT_MAX){
            return -1;
        }
        return timet(steps,time,change);
    }
};