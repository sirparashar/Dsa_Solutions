class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        unordered_map<int, int> memo;
        int result = changePossible(coins, amount, memo);
        return (result == INT_MAX) ? -1 : result;
    }

    int changePossible(vector<int>& coins, int amount, unordered_map<int, int>& memo) {
        if (amount == 0) {
            return 0;
        }

        if (memo.find(amount) != memo.end()) {
            return memo[amount];
        }

        int minCount = INT_MAX;

        for (int coin : coins) {
            if (amount >= coin) {
                int subproblem = changePossible(coins, amount - coin, memo);
                if (subproblem != INT_MAX) {
                    minCount = min(minCount, subproblem + 1);
                }
            }
        }

        memo[amount] = minCount;
        return minCount;
    }
};