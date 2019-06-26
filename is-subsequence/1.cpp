class Solution {
public:
    bool isSubsequence(string s, string t) {
        int tBegin = 0;
        for (int i = 0; i < s.size(); i++) {
            auto pos = t.find_first_of(s[i], tBegin);
            if (pos == string::npos) {
                return false;
            }
            tBegin = pos + 1;
        }
        return true;
    }
};
