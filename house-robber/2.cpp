// time: O(n), space: O(1)
class Solution {
public:
    int rob(vector<int>& nums) {
        int amounts[2] = {};
        for (int i = 0; i < nums.size(); i++) {
            const int idx1 = i%2;
            const int idx2 = 1 - idx1;
            amounts[idx1] = max(amounts[idx1] + nums[i], amounts[idx2]);
        }
        return max(amounts[0], amounts[1]);
    }
};
