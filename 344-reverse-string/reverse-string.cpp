class Solution {
public:
    void reverseString(vector<char>& s) {
        int k=0;
        for(int i= s.size()-1; i>=k;i--){
            int temp = s[i];
            s[i]=s[k];
            s[k]=temp;
            k++;
        }
    }
};