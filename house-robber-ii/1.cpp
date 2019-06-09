// time: O(n)
class Solution {
private:
    int aux(vector<int>& nums, int beginIdx, int endIdx) {
        int amounts[2] = {};
        for (int i = beginIdx; i <= endIdx; i++) {
            if (i%2 == 0) {
                amounts[0] = max(amounts[0] + nums[i], amounts[1]);
            } else {
                amounts[1] = max(amounts[1] + nums[i], amounts[0]);
            }
        }
        return max(amounts[0], amounts[1]);
    }
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        return max(
            aux(nums, 1, nums.size() - 1),
            aux(nums, 0, nums.size() - 2)
        );
    }
};
