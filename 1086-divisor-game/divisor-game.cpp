class Solution {
public:
    bool divisorGame(int n) {
        int count = 1;
        int x=1;

        while(n%x==0 && n>0){
            n-=x;
            count++;
        }
        return count%2;
    }
};