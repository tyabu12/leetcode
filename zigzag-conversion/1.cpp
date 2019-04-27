class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        vector<string> rows(min(numRows, (int)s.size()), "");
        int r = 0, step = 1;
        for (int i=0;i<s.size();i++) {
            rows[r] += s[i];
            r += step;
            if (r == 0 || r == numRows-1) step = -step;
        }
        string ans = "";
        for (int i=0;i<rows.size();i++) ans += rows[i];
        return ans;
    }
};
