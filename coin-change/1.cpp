class Solution {
private:
    int aux(vector<int>& coins, int amount, vector<int>& memo) {
        if (amount == 0) return 0;
        if (memo[amount] == 0) {
            long minCoins = LONG_MAX;
            for (int i = 0; i < coins.size() && amount >= coins[i]; i++) {
                int ret = aux(coins, amount - coins[i], memo);
                if (ret < 0) continue;
                minCoins = min(minCoins, 1L + ret);
            }
            memo[amount] = (minCoins == LONG_MAX ? -1 : minCoins);
        }
        return memo[amount];
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end());
        vector<int> memo(amount + 1, 0);
        return aux(coins, amount, memo);
    }
};
