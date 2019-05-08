class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m;
        for (int i = 0; i < strs.size(); i++) {
            string sortedStr(strs[i]);
            sort(sortedStr.begin(), sortedStr.end());
            m[sortedStr].push_back(strs[i]);
        }
        vector<vector<string>> ans;
        for (auto itr = m.begin(); itr != m.end(); itr++) {
            ans.push_back(itr->second);
        }
        return ans;
    }
};
