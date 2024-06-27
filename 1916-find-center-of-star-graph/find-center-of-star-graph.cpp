class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
      
      unordered_map<int,int> m;
      for(auto edge : edges){
        m[edge[0]]++;
        m[edge[1]]++;
      }

      for(auto no:m){
        cout<<no.second;
        if(no.second>=edges.size()){
            return no.first;
        }
      }
      return -1;

    }
};