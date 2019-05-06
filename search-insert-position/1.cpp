class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int begin = 0, end = nums.size();
        while (end - begin > 1) {
            int mid = (begin + end)/2;
            if (nums[mid] == target) return mid;
            if (nums[mid] < target)
                begin = mid;
            else
                end = mid;
        }
        return (nums[begin] >= target ? begin : end);
    }
};
