class Solution {
public:
    vector<int> occurence(string word)
    {
        vector<int> occ(26, 0);
        
        for (char c : word)
            occ[c - 'a']++;
        
        return occ;
    }
    vector<string> commonChars(vector<string>& words) {
        vector<string> chars;
        vector<int> occ(26, INT_MAX);
        
        for (string word : words)
        {
            auto temp = occurence(word);
            
            for (int i = 0; i < 26; i++)
                occ[i] = min(occ[i], temp[i]);
        }
        
        for (int i = 0; i < 26; i++)
        {
            char c = 'a' + i;
            for (int j = 0; j < occ[i]; j++)
            {
                string s = "";
                s += c;
                chars.push_back(s);
            }
        }
        
        return chars;
    }
};