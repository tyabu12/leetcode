// Time: O(n^2), Space: O(n^2)
class Solution {
private:
    int aux(vector<int>& nums, int curIdx, int prevIdx, vector<vector<int>>& memo) {
        if (curIdx >= nums.size()) return 0;
        if (memo[curIdx][prevIdx + 1] < 0) {
            int maxLength = aux(nums, curIdx + 1, prevIdx, memo);
            if (prevIdx < 0 || nums[curIdx] > nums[prevIdx]) {
                maxLength = max(
                    maxLength,
                    1 + aux(nums, curIdx + 1, curIdx, memo)
                );
            }
            memo[curIdx][prevIdx + 1] = maxLength;
        }
        return memo[curIdx][prevIdx + 1];
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> memo(nums.size(), vector<int>(nums.size() + 1, -1));
        return aux(nums, 0, -1, memo);
    }
};
