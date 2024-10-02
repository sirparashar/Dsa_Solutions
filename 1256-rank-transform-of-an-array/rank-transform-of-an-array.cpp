class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int>temp(arr);
        sort(temp.begin(), temp.end());

        unordered_map<int,int> rank;

        for(auto &item : temp){
            rank.emplace(item,rank.size()+1);
        }

        vector<int>res;

        for(int i =0 ; i<temp.size(); i++){
            temp[i] = rank[arr[i]];
        }
     
      return temp;
    }
};