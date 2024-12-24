class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==0){
            return {};
        }
        if(n==1){
            return {0};
        }

        vector<int> res;
        vector<int>deg(n,0); 

        vector<vector<int>>adj(n);
        for(auto i : edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
            deg[i[0]]++;
            deg[i[1]]++;
        }

        queue<int>q;
        for(int i =0; i<n; i++){
            if(deg[i]==1){
                q.push(i);
            }
        }

        while(!q.empty()){
            res.clear();
            int size = q.size();
            for(int i =0; i<size; i++){
                int cur = q.front();
                 q.pop();
                 res.push_back(cur);

                 for(auto e:adj[cur]){
                    deg[e]--;
                    if(deg[e]==1){
                        q.push(e);
                    }
                 }
            }
        }
        return res;
    }
};