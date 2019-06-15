class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> countMap;
        for (int i = 0; i < nums.size(); i++) {
            const int num = nums[i];
            if (countMap.find(num) == countMap.end()) {
                countMap[num] = 1;
            } else {
                countMap[num]++;
            }
        }
        multiset<pair<int, int>> orderdNums;
        for (auto it = countMap.begin(); it != countMap.end(); it++) {
            orderdNums.insert(pair<int, int>(it->second, it->first));
        }
        vector<int> ans;
        ans.reserve(k);
        auto it = orderdNums.rbegin();
        for (int i = 0; i < k; i++) {
            ans.push_back(it->second);
            it++;
        }
        return ans;
    }
};
