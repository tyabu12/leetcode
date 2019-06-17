class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> st;
        st.reserve(nums1.size());
        for (int i = 0; i < nums1.size(); i++) st.insert(nums1[i]);
        sort(nums2.begin(), nums2.end());
        auto nums2End = unique(nums2.begin(), nums2.end());
        vector<int> ans;
        for (auto it = nums2.begin(); it != nums2End; it++) {
            if (st.find(*it) != st.end()) {
                ans.push_back(*it);
            }
        }
        return ans;
    }
};
