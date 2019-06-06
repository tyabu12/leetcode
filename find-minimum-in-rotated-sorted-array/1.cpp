// time: O(log n)
class Solution {
public:
    int findMin(vector<int>& nums) {
        int beginIdx = 0, endIdx = nums.size() - 1;
        while (nums[beginIdx] > nums[endIdx]) {
            int midIdx = (beginIdx + endIdx) / 2;
            if (nums[beginIdx] <= nums[midIdx]) {
                beginIdx = midIdx + 1;
            } else {
                endIdx = midIdx;
            }
        }
        return nums[beginIdx];
    }
};
