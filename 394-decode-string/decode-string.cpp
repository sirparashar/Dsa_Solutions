class Solution {
public:
    string decodeString(string s) {
        stack <string> st;
        for(auto ch:s)
        {
            if(ch==']')
            {
               string temp="";
               while(!st.empty() && st.top()!="[")
               {
                  string top=st.top();
                   temp+=top;
                   st.pop();
               }
               st.pop();
               string numerictimes="";
               while(!st.empty() && isdigit(st.top()[0]))
               {
                  numerictimes+=st.top();
                  st.pop();
               }
               reverse(numerictimes.begin(),numerictimes.end());
               int n=stoi(numerictimes);
               string currentdecode="";
               while(n--)
               {
                   currentdecode+=temp;
                   
               }
               st.push(currentdecode);
            }
            else
            {
                string temp(1,ch);
                st.push(temp);
            }
        }
        string ans="";
        while(!st.empty())
        {
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
         
    }
};