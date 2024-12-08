class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pair<double,double>>>adj(n);

        for(int i =0; i<edges.size(); i++){
            adj[edges[i][0]].push_back({succProb[i],edges[i][1]});
            adj[edges[i][1]].push_back({succProb[i],edges[i][0]});
            
        }

        priority_queue<pair<double,double>> pq;

        vector<double>p(n,0);
        p[start]=1.0;

        pq.push({1.0,start});

        while(!pq.empty()){
            auto t= pq.top();
            pq.pop();

            if(t.second==end){
                return t.first;
            }

            for( auto i  : adj[t.second]){
                   if(p[i.second]<t.first*i.first){
                    p[i.second]=t.first*i.first;
                    pq.push({p[i.second],i.second});
                   }
            }
        }

        return 0.0;
    }
};