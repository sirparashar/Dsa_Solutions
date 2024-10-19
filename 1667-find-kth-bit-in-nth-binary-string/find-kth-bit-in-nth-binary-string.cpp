class Solution {
public:
    char findKthBit(int n, int k) {
        if(n==1){
            return '0';
        }

        int len = pow(2,n);
        if(k<len/2){
            return findKthBit(n-1,k);
        }

        else if(k==len/2){
            return '1';
        }
        else{
            char s = findKthBit(n-1,len-k);
            return s=='0'?'1':'0';
        }





    }
};