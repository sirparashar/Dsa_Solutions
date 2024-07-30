class Solution {
public:
    int minimumDeletions(string s) {
        int bcount =0, res=0;
        for(auto x:s){
            if(x=='a'){
                res = min(++res,bcount);
            }
            else if(x=='b'){
                bcount++;
            }
        }
        return res;
    }
};