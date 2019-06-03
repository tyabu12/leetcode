// time: O(n)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        int ans = 0, i = 0;
        while (i < prices.size() - 1) {
            while (i < prices.size() - 1 && prices[i] >= prices[i+1]) i++;
            const int valley = prices[i];
            while (i < prices.size() - 1 && prices[i] <= prices[i+1]) i++;
            const int peak = prices[i];
            ans += peak - valley;
        }
        return ans;
    }
};
