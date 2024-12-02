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
              cout<<'p';
            
                if(temp.substr(0,n)==searchWord){
                    return res;
                }
                temp="";
                continue;
            }
            temp+=sentence[i];
            cout<<temp<<"\n";


        }
        return -1;
    }
};