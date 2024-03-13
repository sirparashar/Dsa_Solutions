class Solution {
public:
    int pivotInteger(int n) {

        int sum = n*(n+1)/2;
        int sroot = sqrt(sum);
        return (sroot*sroot)==sum?sroot:-1; 

        
    }
};