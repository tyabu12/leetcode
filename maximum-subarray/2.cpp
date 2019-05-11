class Solution {
public:
    // O(N)
    int maxSubArray(vector<int>& nums) {
        vector<int> dp(nums.size());
        dp[0] = nums[0];
        int maxVal = dp[0];
        for (int i = 1; i < nums.size(); i++) {
            if (dp[i-1] < 0) {
                dp[i] = nums[i];
            } else {
                dp[i] = nums[i] + dp[i-1];
            }
            maxVal = max(maxVal, dp[i]);
        }
        return maxVal;
    }
};
