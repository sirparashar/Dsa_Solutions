class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int> cir;
        for(int i =1; i<=n; i++){
            cir.push_back(i);
        }
        int cur=0;
        while(cir.size()>1){
            int rIndex = (cur+k-1)%cir.size();
            cir.erase(cir.begin()+rIndex);
            cur = rIndex;
        }
        return cir[0];
    }
};