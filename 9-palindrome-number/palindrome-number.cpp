class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0){
            return false;
        }
        int original=x;
       long int sum=0;
        while(original!=0){
            int temp=original%10;
            sum=sum*10+temp;
            original=original/10;
        }
        if(x==sum){
            return true;
        }
        else{
            return false;
        }
        
    }
};