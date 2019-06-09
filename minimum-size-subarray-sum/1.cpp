// time: O(n)
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int beginIdx = 0, sum = 0;
        long minLen = LONG_MAX;
        for (int i = 0; i < nums.size(); i++) {
            int newSum = sum + nums[i];
            if (newSum >= s) {
                while (newSum - nums[beginIdx] >= s) newSum -= nums[beginIdx++];
                minLen = min(minLen, (long)(i - beginIdx + 1));
            }
            sum = newSum;
        }
        return (minLen == LONG_MAX ? 0 : (int)minLen);
    }
};
