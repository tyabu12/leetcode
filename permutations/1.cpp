class Solution {
private:
    bool next_permute(vector<int>& nums) {
        if (nums.size() <= 1) return false;
        // find first decreasing element
        int border = nums.size() - 2;
        while (border >= 0 && nums[border] > nums[border+1]) border--;
        // not found, i.e. descending order
        if (border < 0) return false;
        // find just larger than border
        int justLargerThanBorder = nums.size() - 1;
        while (justLargerThanBorder >= 0 && nums[justLargerThanBorder] < nums[border]) {
            justLargerThanBorder--;
        }
        swap(nums[border], nums[justLargerThanBorder]);
        reverse(nums.begin() + border + 1, nums.end()); // ascending order
        return true;
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        if (nums.empty()) return ans;
        vector copy_nums(nums);
        sort(copy_nums.begin(), copy_nums.end());
        do {
            ans.push_back(copy_nums);
        } while (next_permute(copy_nums));
        return ans;
    }
};
