class Solution {
public:
vector<vector<int>>ans;

   void helper(int idx, int k , vector<int> pair, int n){
    if(pair.size()==k){
        ans.push_back(pair);
        return;
    }

    for(int i =idx; i<n+1; i++){
        pair.push_back(i);
        helper(i+1,k,pair,n);
        pair.pop_back();
    }
   }
    vector<vector<int>> combine(int n, int k) {
        vector<int> pair;
        helper(1,k,pair,n);
        return ans;

    }
};