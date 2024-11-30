class Solution {
public:
    unordered_map<int,int>m;
    int fib(int n) {
        if( n == 1){
            return 1;
        }
        if( n == 0){
            return 0;
        }
        if(m.find(n)!=m.end()){
            return m[n];
        }
        m[n] = fib(n-1) + fib(n-2);

        return m[n];
    }
};