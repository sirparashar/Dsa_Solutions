class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int n = searchWord.size();
        string temp="";
        int res=0;
        sentence+=" ";
        
        for(int i =0; i<sentence.size(); i++){
            if(sentence[i]==' '){
             res++;
            
                if(temp.substr(0,n)==searchWord){
                    return res;
                }
                temp="";
                continue;
            }
            temp+=sentence[i];


        }
        return -1;
    }
};