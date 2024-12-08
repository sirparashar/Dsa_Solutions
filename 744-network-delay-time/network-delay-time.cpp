class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n+1);

        for(int i =0; i<times.size(); i++){
            adj[times[i][0]].push_back({times[i][1],times[i][2]});
        }

        vector<int> dist(n+1,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

        pq.push({0,k});
        dist[k]=0;
        while(!pq.empty()){
            auto p = pq.top();
            pq.pop();

            for(auto i : adj[p.second]){
                if(dist[i.first]>p.first+i.second){
                    dist[i.first]=p.first+i.second;
                    pq.push({dist[i.first],i.first});
                }
            }
        }

        int res=0; 

        for(int i=1; i<=n; i++){
            if(dist[i]==INT_MAX){
                return -1;
            }
            res = max(res,dist[i]);
        }
        return res;



    }
};