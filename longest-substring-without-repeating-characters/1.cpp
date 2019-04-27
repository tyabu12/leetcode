class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // O(2n) by Sliding Window
        // int ml = 0, i = 0, j = 0;
        // set<char> sc;
        // while (i < s.size() && j < s.size()) {
        //     if (sc.find(s[j]) == sc.end()) {
        //         sc.insert(s[j++]);
        //         ml = max(ml, j-i);
        //     } else {
        //         sc.erase(sc.find(s[i++]));
        //     }
        // }
        // return ml;

        // O(n) by HashMap
        int ml = 0, i = 0;
        unordered_map<char, int> mc;
        for (int j=0;j<s.size();j++) {
            auto itr = mc.find(s[j]);
            if (itr != mc.end()) {
                i = max(itr->second, i);
            }
            ml = max(ml, j - i + 1);
            mc[s[j]] = j + 1;
        }
        return ml;
    }
};
