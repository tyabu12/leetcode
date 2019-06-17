class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> st1, st2;
        st1.reserve(nums1.size());
        st2.reserve(nums2.size());
        for (int i = 0; i < nums1.size(); i++) st1.insert(nums1[i]);
        for (int i = 0; i < nums2.size(); i++) st2.insert(nums2[i]);
        vector<int> ans;
        ans.reserve(min(st1.bucket_count(), st2.bucket_count()));
        for (auto it1 = st1.begin(); it1 != st1.end(); it1++) {
            if (st2.find(*it1) != st2.end()) {
                ans.push_back(*it1);
            }
        }
        return ans;
    }
};
