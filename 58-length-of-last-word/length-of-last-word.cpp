class Solution {
public:
    int lengthOfLastWord(string s) {
        int endstart=s.size();
        for(int i=s.size()-1; i>=0; i--){
          if(s[i]!=' '){
             endstart =i;
             break;
          }
        }
        cout<<endstart;
        int count = 0;
        for(int i=endstart; i>=0; i--){
           if(s[i]== ' '){
            break;
           }
           count++;
        }
        return count;
    }
};