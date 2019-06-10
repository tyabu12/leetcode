class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int> tmp;
        tmp.reserve(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i]) tmp.push_back(nums[i]);
        }
        for (int i = tmp.size(); i < nums.size(); i++) tmp.push_back(0);
        copy(tmp.begin(), tmp.end(), nums.begin());
    }
};
