class Solution {
public:

    vector<vector<int>> getadj(vector<vector<int>>& edges){
        vector<vector<int>> adj(edges.size()+1);
        for(auto i : edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        return adj;
    }

    pair<int,int> dia(int node,int parent,vector<vector<int>>& adj){
        int md1=0;
        int md2=0;
        int d=0;

        for(int nei : adj[node]){
            if(nei == parent){
                continue;
            }
            auto [childd,depth] = dia(nei,node,adj);

            d = max(d,childd);
            depth++;
            if(depth >md1){
                md2 = md1;
                md1=depth;
            }
            else if(depth>md2){
                md2 =depth;
            }

        }
        d = max(d,md1+md2);
        return {d,md1};
    }
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n= edges1.size();
        int m= edges2.size();

        vector<vector<int>> adj1(n+1);
        vector<vector<int>> adj2(m+1);

        adj1 = getadj(edges1); 
        adj2 = getadj(edges2); 

        int d1 = dia(0,-1, adj1).first;
        int d2 = dia(0,-1, adj2).first;
        int cd = ceil(d1/2.0)+ceil(d2/2.0)+1;

        return max({d1,d2,cd});


        
    }
};