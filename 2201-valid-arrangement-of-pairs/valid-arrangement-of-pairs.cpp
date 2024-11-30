class Solution {
public:
    unordered_map<int, vector<int>> adj;
    unordered_map<int, int> deg;

    void build(vector<vector<int>>& pairs){
        for( auto edge : pairs){
            int start = edge[0];
            int end = edge[1];
            adj[start].push_back(end);
            deg[start]++;
            deg[end]--;
        }
    }

    vector<int>rpath;
    void eular(int i){
        vector<int> stk ={i};
        while(!stk.empty()){
            i = stk.back();
            if(adj[i].empty()){
                rpath.push_back(i);
                stk.pop_back();
            }
            else{
                int j = adj[i].back();
                adj[i].pop_back();
                stk.push_back(j);
            }
        }
    }

    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {

        int n = pairs.size();

        build(pairs);

        int start = deg.begin()->first;

        for (auto [v, d] : deg) {
            if (d == 1) {
                start = v;
                break;
            }
        }

        eular(start);

        vector<vector<int>> ans;

        for(int i = rpath.size()-2;i>=0; i--){
            ans.push_back({rpath[i+1],rpath[i]});
        }
        return ans;
    }
};