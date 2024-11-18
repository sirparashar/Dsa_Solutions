class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        vector<int> res(code.size(), 0);
        if (k >= 0) {
            for (int i = 0; i < code.size(); i++) {
                int sum = 0;
                for (int j = i + 1; j < (k + i + 1); j++) {
                    sum += code[j % code.size()];
                    cout << 'p';
                }
                res[i] = sum;
            }
        } else {
            for (int i = 0; i < code.size(); i++) {
                int sum = 0;
                for (int j = 0; j < abs(k); j++) {
                    cout << j;
                    sum += code[(code.size() - j + i - 1) % code.size()];
                }
                res[i] = sum;
            }
        }
        return res;
    }
};