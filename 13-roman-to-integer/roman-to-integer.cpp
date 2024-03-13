class Solution {
public:
    int romanToInt(string s) {
        int res=0;
        int lastno=INT_MAX;
        for(auto c:s){
            int x = getno(c);
 
            if(lastno<x){
                x=x-2*lastno;
                cout<<x;
            }
            lastno=x;
            res += x;
            cout<<"\n";
            cout<<res;
        }
        return res;
    }

    int getno(char n){
        switch(n){
            case 'I' : 
               return 1;
            case 'V': 
               return 5;
             case 'X': 
               return 10;
            case 'L': 
               return 50;
            case 'C': 
               return 100;
            case 'D': 
               return 500;
            case 'M': 
               return 1000;
        }
        return 1;
    }
};