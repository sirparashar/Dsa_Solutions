class Solution {
public:
    int numSteps(string s) {
        int length = s.length()-1;
        int carry = 0;
        int steps =0;

        while(length>0){
            if(s[length]-'0' + carry ==0){
                carry=0;
                steps++;
            }
            else if(s[length]-'0'+carry == 2){
                carry =1;
                steps++;
            }
            else{
                carry =1;
                steps+=2;
            }
            length--;
        }

        if(carry==1){
            steps++;
        }
        return steps;
    }
};