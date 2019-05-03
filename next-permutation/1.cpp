class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size() <= 1) return;
        // find first decreasing element
        int border = nums.size() - 2;
        while (border >= 0 && nums[border] >= nums[border+1]) border--;
        // not possible (ex. [3,2,1], [1,1])
        if (border < 0 || nums[border] == nums[border+1]) {
            reverse(nums.begin(), nums.end()); // ascending order
            return;
        }
        // find just larger than border
        int justLargerThanBorder = nums.size() - 1;
        while (justLargerThanBorder >= 0 && nums[justLargerThanBorder] <= nums[border]) {
            justLargerThanBorder--;
        }
        swap(nums[border], nums[justLargerThanBorder]);
        reverse(nums.begin()+border+1, nums.end()); // ascending order
    }
};
