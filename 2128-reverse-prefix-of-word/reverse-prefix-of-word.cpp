class Solution {
public:
    string reversePrefix(string word, char ch) {
        int i;
        for(i=0; i<word.size(); i++){
            if(word[i]==ch){
                break;
            }
        }

        if(i == word.size()){
            return word;
        }

        reverse(word.begin(),word.begin()+(i+1));
        cout<<word;
        return word;


    }
};