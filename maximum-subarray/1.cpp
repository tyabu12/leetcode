class Solution {
public:
    // O(N^2)
    int maxSubArray(vector<int>& nums) {
        int maxVal = nums[0];
        for (int i = 0; i < nums.size(); i++) {
            int sum = 0;
            for (int j = i; j < nums.size(); j++) {
                sum += nums[j];
                maxVal = max(maxVal, sum);
            }
        }
        return maxVal;
    }
};
