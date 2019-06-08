// time: O(n * m), memory: O(n)
class Solution {
private:
    int aux(vector<int>& nums, vector<int>& memo, int idx, int amounts) {
        if (idx >= nums.size()) return amounts;
        if (memo[idx] < 0) {
            const int amount1 = aux(nums, memo, idx + 1, 0);
            const int amount2 = aux(nums, memo, idx + 2, nums[idx]);
            memo[idx] = max(amount1, amount2);
        }
        return amounts + memo[idx];
    }
public:
    int rob(vector<int>& nums) {
        vector<int> memo(nums.size(), -1);
        return aux(nums, memo, 0, 0);
    }
};
