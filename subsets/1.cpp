class Solution {
private:
    vector<vector<int>> aux(vector<int>& nums, int start) {
        if (nums.size() == start) return {{}};
        auto ans = aux(nums, start + 1);
        auto ansSize = ans.size();
        for (int i = 0; i < ansSize; i++) {
            vector<int> tmp(ans[i]);
            tmp.push_back(nums[start]);
            ans.push_back(tmp);
        }
        return ans;
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        return aux(nums, 0);
    }
};
