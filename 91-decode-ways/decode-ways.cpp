class Solution {
public:
    int numDecodings(string s) {
        if(s[0]=='0'){
            return 0;
        }
        int n = s.size();
        vector<int> dp(n+1);
        dp[0]=1;
        dp[1]=1; 

        for(int i=2; i<=n; i++){
            int one = stoi(s.substr(i-1,1));
            if(one >=1 && one <=9){
                dp[i]+=dp[i-1];
            }

            int ten = stoi(s.substr(i-2,2));
            if(ten >=10 && ten<=26){
                dp[i]+=dp[i-2];
            }
        }
        return dp[n];
        
    }
};