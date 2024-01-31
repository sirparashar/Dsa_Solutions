class Solution {
public:
    vector<int> parent;
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
         
        for(int i=0;i<=edges.size(); i++){
            parent.push_back(i);
        }

        for(const auto &edge:edges){
            int p1 = find(edge[0]);
            int p2 = find(edge[1]);

            if(p1!=p2){
                parent[p1]=p2;
            }
            else
              return edge;
        }
        return {};
    }
    int find(int edge){
        return parent[edge]==edge?edge:find(parent[edge]);
    }
};