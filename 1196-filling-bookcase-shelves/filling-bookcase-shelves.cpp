class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
    vector<int> dp(books.size()+1,0);

        for(int i=0; i<books.size(); i++){
            dp[i+1] = dp[i] + books[i][1];

            int width = books[i][0], height = books[i][1];

            for(int j = i-1; j>=0 && width+books[j][0]<=shelfWidth; j--){
                width+=books[j][0];
                height = max(height,books[j][1]);
                dp[i+1] = min(dp[j]+height,dp[i+1]);
            }
        }
        return dp[books.size()];
    }
};