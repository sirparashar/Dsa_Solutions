class Solution {
public:
    int lengthOfLastWord(string s) {
        
        int right = s.size()-1;
        while(s[right]==' '){
            right--;
        }

        int count=0;
        for (int i = right; i>=0; i--){
            if(s[i]==' '){
                break;
            }
            count++;
        }
        return count;

    }
};