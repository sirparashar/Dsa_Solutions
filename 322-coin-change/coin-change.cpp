class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {

        unordered_map<int, int> m;
        return helper(coins, amount, m);
    }
    int helper(vector<int>& coins, int amount, unordered_map<int, int>& m) {
        if (amount == 0) {
            return 0;
        }

        if (amount < 0) {
            return -1;
        }

        if (m.find(amount) != m.end()) {
            return m[amount];
        }
        int mincoins = -1;
        for (int i = 0; i < coins.size(); i++) {
            if (amount - coins[i] >= 0) {
                int subcoins = helper(coins, amount - coins[i], m);
                if (subcoins != -1) {
                    int numcoins = subcoins + 1;
                    if (numcoins < mincoins || mincoins == -1) {
                        mincoins = numcoins;
                    }
                }
            }
        }
        m[amount] = mincoins;
        return m[amount];
    }
};