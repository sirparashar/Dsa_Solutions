class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s==goal){
            return true;
        }
        for(int i =1; i<s.size(); i++){
            string cut = s.substr(0,1);
            s=s.substr(1);
            // cout<<cut;
            // cout<<s;
            // break;
            s+=cut;
           // cout<<s;
            if(s==goal){
                return true;
            }
        }
        return false;
    }
};