// time: O(n^2)
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        map<int, vector<vector<int>>> mp;
        long maxSum = LONG_MIN;
        int cnt = 0;
        for (int i = 0; i < nums1.size(); i++) {
            if (nums1[i] >= maxSum && cnt > k) break;
            for (int j = 0; j < nums2.size(); j++) {
                const int sum = nums1[i] + nums2[j];
                if (sum >= maxSum && cnt > k) break;
                auto it = mp.find(sum);
                vector<int> p = { nums1[i], nums2[j] };
                if (it == mp.end()) {
                    mp[sum] = vector<vector<int>>{p};
                } else {
                    it->second.push_back(p);
                }
                maxSum = max(maxSum, (long)sum);
                cnt++;
            }
        }
        vector<vector<int>> ans;
        auto it = mp.begin();
        cnt = 0;
        while (cnt < k && it != mp.end()) {
            const int n = min((int)it->second.size(), k - cnt);
            ans.insert(ans.end(), it->second.begin(), it->second.begin() + n);
            it++;
            cnt += n;
        }
        return ans;
    }
};
