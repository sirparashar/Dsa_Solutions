class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        int len = position.size() - 1;
        sort(position.begin(), position.end());

        int l = 1;
        int r = position.back() - position[0];

        int res = -1;

        while (l <= r) {
            int mid = l + (r - l) / 2;
            int lp = position[0], balls =1;

            for(int i=1 ; i<position.size(); i++){
                if(position[i]-lp >=mid){
                    lp = position[i];
                    balls++;
                }
            }
            if(balls>=m){
                res=mid;
                l = mid+1;
            }
            else{
                r=mid-1;
            }
        }
        return res;
    }
};