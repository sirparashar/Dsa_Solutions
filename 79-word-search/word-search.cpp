class Solution {
public:
    bool helper(int i, int j, vector<vector<char>>& board, string &word) {
        if (word.size() == 0) {
            return true;
        }
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() ||
            board[i][j] != word[0]) {
            return false;
        }
        // cout<<i;

        char s = board[i][j];
        board[i][j] = '#';
        //  return true;

        // cout << i;

        string sub = word.substr(1);
        bool res =
            (helper(i + 1, j, board, sub) || helper(i - 1, j, board, sub) ||
             helper(i, j + 1, board, sub) || helper(i, j - 1, board, sub));
        // cout << i;

        board[i][j] = s;
        return res;
    }
    bool exist(vector<vector<char>>& board, string word) {

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (helper(i, j, board, word)) {
                    return true;
                }
            }
        }
        return false;
    }
};